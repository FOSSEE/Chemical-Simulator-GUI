from PyQt5.QtCore import QThread, pyqtSignal

class SimulationThread(QThread):
    log = pyqtSignal(str)       # Signal for logging messages to GUI
    finished = pyqtSignal()     # Signal emitted upon simulation completion

    def __init__(self, container, mode, mo_path=None):
        super().__init__()
        self.container = container
        self.mode = mode
        self.mo_path = mo_path

    def run(self):
        try:
            # Execute simulation non-gui method on container
            self.container.simulate_non_gui(self.mode, self.mo_path)
            self.log.emit("Simulation finished successfully")
        except Exception as e:
            self.log.emit(f"Simulation failed: {str(e)}")
        finally:
            self.finished.emit()
