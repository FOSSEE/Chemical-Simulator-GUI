import os
import sys
import unittest

# Ensure headless Qt
os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QGraphicsScene
from PyQt5.QtCore import QPointF

# Initialize QApplication once
app = QApplication.instance()
if app is None:
    app = QApplication(sys.argv)

# Container must be imported before Graphics (the two modules import each other)
import python.utils.Container  # noqa: F401
from python.utils.Graphics import NodeLine

R = NodeLine.HOP_RADIUS


class LineCrossingTestBase(unittest.TestCase):

    def setUp(self):
        self.scene = QGraphicsScene()
        self.lines = []

    def tearDown(self):
        self.scene.clear()
        self.lines = []

    def add_line(self, a, b, scene=True):
        """Create a line the way Graphics does: add to the scene, then set the end points."""
        line = NodeLine(QPointF(*a), QPointF(*b), 'op')
        if scene:
            self.scene.addItem(line)
        line.pointA = QPointF(*a)
        line.pointB = QPointF(*b)
        self.lines.append(line)
        return line

    def horizontal(self):
        # Route: (0,100) -> (200,100) -> (200,100) -> (400,100), a straight horizontal line
        return self.add_line((0, 100), (400, 100))

    def vertical(self, x=150):
        # Route: (x-100,0) -> (x,0) -> (x,200) -> (x+100,200), vertical part at x
        return self.add_line((x - 100, 0), (x + 100, 200))

    def has_hop(self, line, y):
        """A hop is a semicircle above the line, so the path rises R above y."""
        return abs(line.path().boundingRect().top() - (y - R)) < 0.01

    def path_points(self, line):
        path = line.path()
        return [(path.elementAt(i).x, path.elementAt(i).y) for i in range(path.elementCount())]


# =============================================================================
# 1. Route geometry
# =============================================================================

class TestRoute(LineCrossingTestBase):

    def test_forward_route(self):
        line = self.add_line((0, 0), (200, 100))
        self.assertEqual(line._route, [(0, 0), (100, 0), (100, 100), (200, 100)])

    def test_backward_route_goes_around(self):
        line = self.add_line((300, 0), (250, 60))
        # Step out 13px, drop to the vertical midpoint, step back in 13px before the target
        self.assertEqual(line._route, [(300, 0), (313, 0), (313, 30), (237, 30), (237, 60), (250, 60)])

    def test_far_backward_route_detours_below(self):
        line = self.add_line((400, 0), (0, 50))
        self.assertEqual(line._route, [(400, 0), (413, 0), (413, 100), (-13, 100), (-13, 50), (0, 50)])

    def test_path_starts_and_ends_at_sockets(self):
        line = self.add_line((10, 20), (300, 180))
        points = self.path_points(line)
        self.assertEqual(points[0], (10, 20))
        self.assertEqual(points[-1], (300, 180))

    def test_path_is_continuous(self):
        """The route is one sub-path: only the first element is a move."""
        line = self.add_line((10, 20), (300, 180))
        path = line.path()
        moves = [i for i in range(path.elementCount()) if path.elementAt(i).isMoveTo()]
        self.assertEqual(moves, [0])

    def test_line_outside_scene_draws_without_hops(self):
        line = self.add_line((0, 100), (400, 100), scene=False)
        self.assertFalse(line.path().isEmpty())
        self.assertEqual(line._find_hops(), {})


# =============================================================================
# 2. Hops at crossings
# =============================================================================

class TestHops(LineCrossingTestBase):

    def test_horizontal_line_hops_over_vertical_line(self):
        h = self.horizontal()
        v = self.vertical(150)

        self.assertEqual(h._find_hops(), {0: [150]})
        self.assertTrue(self.has_hop(h, 100))

    def test_only_one_line_hops_per_crossing(self):
        h = self.horizontal()
        v = self.vertical(150)
        self.assertEqual(v._find_hops(), {})
        self.assertEqual(v.path().boundingRect().top(), 0)

    def test_result_does_not_depend_on_drawing_order(self):
        v = self.vertical(150)
        h = self.horizontal()
        self.assertEqual(h._find_hops(), {0: [150]})
        self.assertTrue(self.has_hop(h, 100))
        self.assertEqual(v._find_hops(), {})

    def test_hop_is_centered_on_crossing(self):
        h = self.horizontal()
        self.vertical(150)
        points = self.path_points(h)
        # The straight part stops R before the crossing and resumes R after it
        self.assertIn((150 - R, 100), points)
        self.assertIn((150 + R, 100), points)

    def test_multiple_crossings_on_one_segment(self):
        h = self.horizontal()
        self.vertical(60)
        self.vertical(150)
        self.assertEqual(sorted(h._find_hops()[0]), [60, 150])
        points = self.path_points(h)
        for x in (60, 150):
            self.assertIn((x - R, 100), points)
            self.assertIn((x + R, 100), points)

    def test_crossings_on_different_segments(self):
        h = self.horizontal()
        self.vertical(150)   # crosses the first half (0..200)
        self.vertical(300)   # crosses the second half (200..400)
        self.assertEqual(h._find_hops(), {0: [150], 2: [300]})

    def test_right_to_left_segment_also_hops_upward(self):
        # Backward line whose middle segment runs right-to-left at y=100
        back = self.add_line((400, 0), (0, 50))
        self.vertical(200)
        self.assertEqual(back._find_hops(), {2: [200]})
        points = self.path_points(back)
        self.assertIn((200 + R, 100), points)
        self.assertIn((200 - R, 100), points)
        self.assertLess(back.path().boundingRect().top(), 0 + 0.01)  # still starts at y=0
        # The hop rises above the segment, never below it
        hop_ys = [y for x, y in points if 200 - R < x < 200 + R]
        self.assertTrue(hop_ys and all(y <= 100 for y in hop_ys))

    def test_no_hop_without_crossing(self):
        h = self.horizontal()
        self.add_line((0, 300), (400, 400))   # entirely below
        self.assertEqual(h._find_hops(), {})
        self.assertEqual(h.path().boundingRect().height(), 0)

    def test_touching_lines_from_same_socket_do_not_hop(self):
        # Two streams leaving the same outlet: they share the start, they don't cross
        a = self.add_line((0, 100), (200, 300))
        b = self.add_line((0, 100), (400, 0))
        self.assertEqual(a._find_hops(), {})
        self.assertEqual(b._find_hops(), {})

    def test_vertical_ending_on_line_is_not_a_crossing(self):
        h = self.horizontal()
        # Vertical part runs from y=0 down to exactly y=100 and stops (T-junction)
        self.add_line((50, 0), (250, 100))
        self.assertEqual(h._find_hops(), {})

    def test_crossing_too_close_to_corner_is_skipped(self):
        h = self.horizontal()                  # first segment ends at x=200
        self.vertical(200 - R + 1)             # crossing within R of the corner
        self.assertEqual(h._find_hops(), {})

    def test_parallel_overlapping_lines_do_not_hop(self):
        a = self.horizontal()
        b = self.add_line((50, 100), (350, 100))
        self.assertEqual(a._find_hops(), {})
        self.assertEqual(b._find_hops(), {})


# =============================================================================
# 3. Hops stay correct as the canvas changes
# =============================================================================

class TestHopUpdates(LineCrossingTestBase):

    def test_moving_crossing_line_away_removes_hop(self):
        h = self.horizontal()
        v = self.vertical(150)
        self.assertTrue(self.has_hop(h, 100))

        # Same as NodeItem._update_connected_lines when the node is dragged
        v.pointA = QPointF(50, 300)
        v.pointB = QPointF(250, 500)

        self.assertEqual(h._find_hops(), {})
        self.assertEqual(h.path().boundingRect().height(), 0)

    def test_moving_line_onto_another_adds_hop(self):
        h = self.horizontal()
        v = self.add_line((50, 300), (250, 500))
        self.assertEqual(h.path().boundingRect().height(), 0)

        v.pointA = QPointF(50, 0)
        v.pointB = QPointF(250, 200)

        self.assertTrue(self.has_hop(h, 100))

    def test_moving_hopping_line_recomputes_its_own_hops(self):
        h = self.horizontal()
        self.vertical(150)
        h.pointA = QPointF(0, 250)
        h.pointB = QPointF(400, 250)
        self.assertEqual(h._find_hops(), {})
        self.assertEqual(h.path().boundingRect().height(), 0)

    def test_removing_crossing_line_removes_hop(self):
        h = self.horizontal()
        v = self.vertical(150)
        self.scene.removeItem(v)
        self.assertEqual(h._find_hops(), {})
        self.assertEqual(h.path().boundingRect().height(), 0)

    def test_removed_line_loses_its_own_hops(self):
        h = self.horizontal()
        self.vertical(150)
        self.scene.removeItem(h)
        self.assertEqual(h._find_hops(), {})

    def test_adding_line_to_scene_after_points_are_set(self):
        h = self.horizontal()
        v = self.vertical(150)
        self.scene.removeItem(v)
        self.assertEqual(h.path().boundingRect().height(), 0)

        self.scene.addItem(v)
        self.assertTrue(self.has_hop(h, 100))

    def test_lines_in_other_scenes_are_ignored(self):
        h = self.horizontal()
        other_scene = QGraphicsScene()
        v = NodeLine(QPointF(50, 0), QPointF(250, 200), 'op')
        other_scene.addItem(v)
        v.updatePath()
        self.assertEqual(h._find_hops(), {})
        other_scene.clear()

    def test_clearing_scene_with_crossing_lines(self):
        self.horizontal()
        self.vertical(150)
        self.scene.clear()
        self.assertEqual(self.scene.items(), [])


if __name__ == "__main__":
    unittest.main()
