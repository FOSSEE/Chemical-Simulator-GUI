import os
import sys
import unittest
from unittest.mock import patch, MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtCore import QPointF
from PyQt5.QtWidgets import QApplication, QFormLayout, QGraphicsView, QTabWidget

app = QApplication.instance() or QApplication(sys.argv)

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils import UnitOperations
from python.utils.UnitOperations import Mixer, Heater
from python.utils.Graphics import NodeLine, lst, dock_widget_lst
from python.utils.Container import Container


class ConnectionsTabTest(unittest.TestCase):
    """Connections tab built by BaseDockWidget for every component."""

    def setUp(self):
        compound_selected[:] = ["Water(chemsep)", "Ethanol(chemsep)"]
        lst.clear()
        dock_widget_lst.clear()
        Mixer.counter = Heater.counter = MaterialStream.counter = 1
        self.container = Container(MagicMock(), QGraphicsView())
        self.snapshot_patch = patch.object(self.container.graphics, "push_snapshot")
        self.snapshot_patch.start()

    def tearDown(self):
        self.snapshot_patch.stop()
        lst.clear()
        dock_widget_lst.clear()

    def add(self, obj):
        return self.container.add_unit_operation(obj)

    def connect(self, src, src_idx, tgt, tgt_idx):
        line = NodeLine(QPointF(0, 0), QPointF(100, 0), 'op')
        line.source = src.output[src_idx]
        line.target = tgt.input[tgt_idx]
        src.output[src_idx].out_lines.append(line)
        tgt.input[tgt_idx].in_lines.append(line)
        self.container.scene.addItem(line)
        self.container.update_components_editability()
        return line

    def rows(self, node):
        """[(label, field text, disconnect enabled), ...] from the Connections tab."""
        layout = node.dock_widget.connections_layout
        result = []
        for r in range(layout.rowCount()):
            label = layout.itemAt(r, QFormLayout.LabelRole).widget().text()
            row = layout.itemAt(r, QFormLayout.FieldRole).layout()
            result.append((label, row.itemAt(0).widget().text(), row.itemAt(1).widget().isEnabled()))
        return result

    def button(self, node, row):
        layout = node.dock_widget.connections_layout
        return layout.itemAt(row, QFormLayout.FieldRole).layout().itemAt(1).widget()

    def test_shows_upstream_and_downstream_names(self):
        ms1, heater, ms2 = self.add(MaterialStream(compound_selected)), self.add(Heater()), self.add(MaterialStream(compound_selected))
        self.connect(ms1, 0, heater, 0)
        self.connect(heater, 0, ms2, 0)

        self.assertEqual(self.rows(heater), [
            ("Upstream 1:", ms1.name, True),
            ("Downstream 1:", ms2.name, True),
        ])
        self.assertEqual(self.rows(ms1)[1], ("Downstream 1:", heater.name, True))

    def test_unconnected_ports_show_not_connected(self):
        heater = self.add(Heater())
        self.assertEqual(self.rows(heater), [
            ("Upstream 1:", "Not Connected", False),
            ("Downstream 1:", "Not Connected", False),
        ])

    def test_tab_is_added_to_existing_tabs_or_wraps_single_page_docks(self):
        heater, mixer = self.add(Heater()), self.add(Mixer())
        for node in (heater, mixer):
            tabs = node.dock_widget.connections_tab.parentWidget().parentWidget()
            self.assertIsInstance(tabs, QTabWidget)
            self.assertEqual(tabs.tabText(tabs.count() - 1), "Connections")
        mixer_tabs = mixer.dock_widget.widget()
        self.assertEqual([mixer_tabs.tabText(i) for i in range(mixer_tabs.count())], ["Input Data", "Connections"])

    def test_every_component_keeps_its_input_tab_next_to_connections(self):
        objs = [MaterialStream(compound_selected)] + [getattr(UnitOperations, cls)() for cls in (
            'Heater', 'Cooler', 'Mixer', 'Splitter', 'Flash', 'CentrifugalPump', 'Valve',
            'AdiabaticCompressor', 'AdiabaticExpander', 'CompoundSeparator',
            'ShortcutColumn', 'DistillationColumn')]
        for obj in objs:
            with self.subTest(component=obj.type):
                dock = self.add(obj).dock_widget
                tabs = dock.connections_tab.parentWidget().parentWidget()
                names = [tabs.tabText(i) for i in range(tabs.count())]
                self.assertEqual(names[0], "Input Data")
                self.assertEqual(names[-1], "Connections")
                # Only one tab bar may sit at the top level of the dock
                top_level = [t for t in dock.findChildren(QTabWidget)
                             if t.parentWidget() in (dock, dock.widget()) or t is dock.widget()]
                self.assertEqual(top_level, [tabs])

    def test_rows_follow_port_count_changes(self):
        mixer = self.add(Mixer())
        self.assertEqual(len(self.rows(mixer)), 3)

        mixer.update_input_ports(4)
        self.assertEqual([r[0] for r in self.rows(mixer)],
                         ["Upstream 1:", "Upstream 2:", "Upstream 3:", "Upstream 4:", "Downstream 1:"])

        mixer.update_input_ports(2)
        self.assertEqual(len(self.rows(mixer)), 3)

    def test_disconnect_removes_only_that_connection(self):
        ms1, ms2, mixer = self.add(MaterialStream(compound_selected)), self.add(MaterialStream(compound_selected)), self.add(Mixer())
        line1 = self.connect(ms1, 0, mixer, 0)
        line2 = self.connect(ms2, 0, mixer, 1)

        self.button(mixer, 0).click()
        app.processEvents()  # the click handler runs on the next event loop pass

        self.assertIsNone(line1.scene())
        self.assertIs(line2.scene(), self.container.scene)
        self.assertEqual(ms1.output[0].out_lines, [])
        self.assertEqual(self.rows(mixer)[:2], [
            ("Upstream 1:", "Not Connected", False),
            ("Upstream 2:", ms2.name, True),
        ])
        self.assertEqual(self.rows(ms1)[1], ("Downstream 1:", "Not Connected", False))

    def test_deleting_neighbour_updates_tab(self):
        ms1, heater = self.add(MaterialStream(compound_selected)), self.add(Heater())
        self.connect(ms1, 0, heater, 0)

        self.container.delete([ms1])

        self.assertEqual(self.rows(heater)[0], ("Upstream 1:", "Not Connected", False))


if __name__ == "__main__":
    unittest.main()
