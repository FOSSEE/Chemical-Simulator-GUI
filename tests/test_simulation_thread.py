import os
import sys
import unittest
from unittest.mock import MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication
app = QApplication.instance() or QApplication([])

from python.utils.SimulationThread import SimulationThread


class TestSimulationThread(unittest.TestCase):
    """Unit tests for background SimulationThread execution and signal emissions."""

    def setUp(self):
        self.mock_container = MagicMock()
        self.thread = SimulationThread(self.mock_container, mode="dynamic", mo_path="/tmp/test.mo")

    def tearDown(self):
        if self.thread.isRunning():
            self.thread.quit()
            self.thread.wait(1000)

    def test_initialization(self):
        """Verify thread stores container, mode, and mo_path correctly."""
        self.assertIs(self.thread.container, self.mock_container)
        self.assertEqual(self.thread.mode, "dynamic")
        self.assertEqual(self.thread.mo_path, "/tmp/test.mo")

    def test_successful_simulation_run(self):
        """Verify successful simulate_non_gui call emits success log and finished signal."""
        logs = []
        finished_called = []

        self.thread.log.connect(lambda msg: logs.append(msg))
        self.thread.finished.connect(lambda: finished_called.append(True))

        self.thread.run()

        self.mock_container.simulate_non_gui.assert_called_once_with("dynamic", "/tmp/test.mo")
        self.assertIn("Simulation finished successfully", logs)
        self.assertTrue(finished_called)

    def test_failed_simulation_run(self):
        """Verify exception during simulate_non_gui emits error log and finished signal."""
        self.mock_container.simulate_non_gui.side_effect = RuntimeError("OpenModelica compilation failed")

        logs = []
        finished_called = []

        self.thread.log.connect(lambda msg: logs.append(msg))
        self.thread.finished.connect(lambda: finished_called.append(True))

        self.thread.run()

        self.mock_container.simulate_non_gui.assert_called_once_with("dynamic", "/tmp/test.mo")
        self.assertTrue(any("Simulation failed: OpenModelica compilation failed" in msg for msg in logs))
        self.assertTrue(finished_called)

    def test_thread_start_and_wait(self):
        """Verify asynchronous QThread lifecycle (start, execution, and event loop completion)."""
        finished_called = []
        self.thread.finished.connect(lambda: finished_called.append(True))

        self.thread.start()
        self.thread.wait(2000)
        app.processEvents()

        self.assertFalse(self.thread.isRunning())
        self.assertTrue(finished_called)


if __name__ == '__main__':
    unittest.main()
