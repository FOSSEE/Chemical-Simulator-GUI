from collections import defaultdict
import datetime
import os, sys

from PyQt5.QtCore import QObject, pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5.QtGui import QCursor

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from python.OMChem.Flowsheet import Flowsheet
from python.utils.undo_manager import *
from python.utils.ComponentSelector import *
from python.utils.Graphics import NodeItem, NodeLine, Graphics, dock_widget_lst, lst
from python.DockWidgets.DockWidget import DockWidget

# ----------------- Signals -----------------
class SimulationSignals(QObject):
    msg_signal = pyqtSignal(str)  # Thread-safe message signal
    results_ready = pyqtSignal()  # Emitted when simulation results are ready


# ----------------- Container -----------------
class Container():
    def __init__(self, msgbrowser, graphicsView):
        self.signals = SimulationSignals()
        self.msg = msgbrowser
        self.signals.msg_signal.connect(self.msg.append)
        self.signals.results_ready.connect(self._populate_results)

        self.unit_operations = []
        self.thermo_package = None
        self.compounds = None
        self.flowsheet = None
        self.conn = defaultdict(list)
        self.op = defaultdict(list)
        self.ip = defaultdict(list)
        self.graphicsView = graphicsView
        self.msg.setText("")
        self.opl = []
        self.result = []
        self.graphics = Graphics(self, self.graphicsView)
        self.scene = self.graphics.get_scene()
        print(f"[DEBUG] Scene check → container.scene id={id(self.scene)}, graphics.scene id={id(self.graphics.scene)}")
        

    # ----------------- Utility -----------------
    def current_time(self):
        now = datetime.datetime.now()
        return f"{now.hour}:{now.minute}:{now.second}"

    # ----------------- Unit Operations -----------------
    def add_unit_operation(self, obj):
        """
        Adds a unit operation node to the scene.
        The Undo snapshot is pushed by the caller after the node is positioned.
        """
        try:
            self.obj = obj
            box = self.graphics.create_node_item(obj, self)
            if not box:
                print("[DEBUG] add_unit_operation: create_node_item returned None")
                return None

            self.scene.addItem(box)
            self.scene.update()
            QApplication.processEvents()

            if obj not in self.unit_operations:
                self.unit_operations.append(obj)
                self.signals.msg_signal.emit(
                    f"<span style='color:blue'>[{self.current_time()}] "
                    f"<b>{obj.name}</b> is instantiated.</span>"
                )

            self.scene.update()
            QApplication.processEvents()
            print("[DEBUG] add_unit_operation: completed add")
            return box

        except Exception as e:
            print("[DEBUG] add_unit_operation failed:", e)
            return None



    def delete(self, l):
        """
        Delete items in list `l` from the scene and model.
        Push a post-delete snapshot for Undo and clear Redo.
        """
        try:
            # --- Now actually perform deletions ---
            items_to_delete = list(l)
            
            # 1. Collect all connected lines if we're deleting nodes
            additional_lines = set()
            for item in items_to_delete:
                if isinstance(item, NodeItem):
                    for socket in (item.input + item.output):
                        for line in (socket.in_lines + socket.out_lines):
                            if line not in items_to_delete:
                                additional_lines.add(line)
            items_to_delete.extend(list(additional_lines))

            # 2. Process deletions
            for item in items_to_delete:
                try:
                    if isinstance(item, NodeLine):
                        # Logical cleanup
                        if item.source and item.source.parent and hasattr(item.source.parent.obj, "remove_connection"):
                            item.source.parent.obj.remove_connection(0, item.source.id)
                        if item.target and item.target.parent and hasattr(item.target.parent.obj, "remove_connection"):
                            item.target.parent.obj.remove_connection(1, item.target.id)
                        
                        # Graphical cleanup
                        if item.source and item in item.source.out_lines:
                            item.source.out_lines.remove(item)
                        if item.target and item in item.target.in_lines:
                            item.target.in_lines.remove(item)
                        
                        if item.scene():
                            item.scene().removeItem(item)

                    elif isinstance(item, NodeItem):
                        # Remove from model
                        if item.obj in self.unit_operations:
                            self.unit_operations.remove(item.obj)
                        
                        # Cleanup DockWidget
                        if hasattr(item, "dock_widget") and item.dock_widget:
                            item.dock_widget.hide()
                            if item.dock_widget in dock_widget_lst:
                                dock_widget_lst.remove(item.dock_widget)
                        
                        # Remove from global tracking
                        if item in lst:
                            lst.remove(item)
                        
                        # Remove from scene
                        if item.scene():
                            item.scene().removeItem(item)

                except Exception as e:
                    print(f"[DEBUG] delete: error deleting item {getattr(item, 'name', None)}: {e}")

            if items_to_delete:
                self.graphics.push_snapshot()

        except Exception as e:
            print("[DEBUG] delete: outer exception:", e)

    def fetch_object(self, name):
        for i in self.unit_operations:
            if i.name == name:
                return i

    def add_compounds(self, comp):
        self.compounds = comp

    def update_compounds(self):
        self.graphics.update_compounds()

    def add_thermo_package(self, thermo):
        self.thermo_package = thermo

    # ----------------- Message Browser -----------------
    def msg_browser(self):
        if not self.flowsheet:
            return
        if self.flowsheet.stdout:
            stdout = self.flowsheet.stdout.decode("utf-8").replace("\n", "<br/>")
            self.signals.msg_signal.emit(f"<span style=\"color:green\">{stdout}</span>")
        if self.flowsheet.stderr:
            stderr = self.flowsheet.stderr.decode("utf-8").replace("\n", "<br/>")
            self.signals.msg_signal.emit(f"<span style=\"color:red\">{stderr}</span>")

    # ----------------- Simulation -----------------
    def simulate(self, mode):
        """Run simulation (safe + verbose)."""

        # Lock UI while simulating
        self.disableInterfaceforSimulation(True)

        try:
            print("[DEBUG] ==== Starting Container.simulate ====")
            print("[DEBUG] mode:", mode)
            print("[DEBUG] scene items count:", len(self.graphics.scene.items()))
            print("[DEBUG] unit_operations (len):", len(self.unit_operations))
            print("[DEBUG] compounds:", getattr(self, 'compounds', None))

            self.signals.msg_signal.emit(
                f"<span>[{self.current_time()}] <b>Starting simulation</b> (mode={mode})</span>"
            )

            # ----------------------------
            # Step 1: Check Missing Connections
            # ----------------------------
            missing_connections = []
            warnings_html = ''

            for item in self.graphics.scene.items():
                if isinstance(item, NodeItem):
                    try:
                        # Clear old results (if any)
                        try:
                            item.dock_widget.clear_results()
                        except Exception:
                            pass

                        show_warning = False
                        for ip in getattr(item, "input", []):
                            if len(getattr(ip, "in_lines", [])) == 0:
                                show_warning = True
                                missing_connections.append((item.name, "input"))
                        for op in getattr(item, "output", []):
                            if len(getattr(op, "out_lines", [])) == 0:
                                show_warning = True
                                missing_connections.append((item.name, "output"))

                        if show_warning:
                            warnings_html += f"<br><span style='color:#999900'>Warning: {item.name} - Missing Socket Connection(s).</span>"
                    except Exception as e:
                        print("[DEBUG] Error checking connections:", item, e)

            if warnings_html:
                self.signals.msg_signal.emit(warnings_html)
                print("[DEBUG] Connection warnings emitted.")

            # ----------------------------
            # Step 2: Prepare Compounds
            # ----------------------------
            compounds = getattr(self, "compounds", None)
            if not compounds:
                try:
                    compounds = globals().get("compound_selected", None)
                except Exception:
                    compounds = None

            if not compounds:
                print("[DEBUG] No compounds found.")
            else:
                print("[DEBUG] Compounds:", compounds)

            # ----------------------------
            # Step 3: Create and Populate Flowsheet
            # ----------------------------
            try:
                self.flowsheet = Flowsheet()
                if compounds:
                    compound_names = [
                        c[:c.index('(')].strip() if '(' in c else c.strip()
                        for c in compounds
                    ]
                    self.flowsheet.add_compound_list(compound_names)
                    print("[DEBUG] Flowsheet compounds added:", compound_names)
            except Exception as e:
                self.signals.msg_signal.emit(
                    f"<span style='color:red'>[{self.current_time()}] Failed to prepare Flowsheet: {e}</span>"
                )
                print("[DEBUG] Failed to create Flowsheet:", e)
                self.disableInterfaceforSimulation(False)
                return

            # ----------------------------
            # Step 4: Add Unit Operations
            # ----------------------------
            for uo in self.unit_operations:
                try:
                    self.flowsheet.add_unit_operations(uo)
                except Exception as e:
                    print("[DEBUG] Failed to add unit operation:", getattr(uo, "name", uo), e)

            print("[DEBUG] Added unit operations:", len(self.unit_operations))

            # ----------------------------
            # Step 5: Build Input/Output Maps
            # ----------------------------
            self.ip = defaultdict(list)
            self.op = defaultdict(list)

            def try_get_other_node_from_line(ln, this_item):
                for a, b in [
                    ("start_item", "end_item"), ("end_item", "start_item"),
                    ("source", "target"), ("target", "source"),
                    ("from_node", "to_node"), ("to_node", "from_node"),
                ]:
                    try:
                        if hasattr(ln, a) and hasattr(ln, b):
                            a_val, b_val = getattr(ln, a), getattr(ln, b)
                            if a_val is this_item:
                                other = b_val
                            elif b_val is this_item:
                                other = a_val
                            else:
                                continue
                            if other:
                                return getattr(getattr(other, "obj", other), "name", getattr(other, "name", None))
                    except Exception:
                        continue
                return getattr(ln, "name", "UnknownLine")

            for it in self.graphics.scene.items():
                if isinstance(it, NodeItem):
                    uo_name = getattr(it.obj, "name", getattr(it, "name", None))
                    if not uo_name:
                        continue
                    for idx, port in enumerate(getattr(it, "input", [])):
                        for ln in getattr(port, "in_lines", []):
                            other = try_get_other_node_from_line(ln, it)
                            self.ip[uo_name].append((idx, other))
                    for idx, port in enumerate(getattr(it, "output", [])):
                        for ln in getattr(port, "out_lines", []):
                            other = try_get_other_node_from_line(ln, it)
                            self.op[uo_name].append((idx, other))

            print("[DEBUG] Built ip/op maps. IP:", len(self.ip), "OP:", len(self.op))

            # ----------------------------
            # Step 6: Simulation
            # ----------------------------
            print("[DEBUG] Calling Flowsheet simulate.")
            if mode == 'SM':
                self.signals.msg_signal.emit(
                    f"<span>[{self.current_time()}] Simulating in <b>Sequential</b> mode ... </span>"
                )
                try:
                    self.flowsheet.simulate(self.msg)  # ✅ Actual Sequential simulation
                    self.result = getattr(self.flowsheet, "result_data", [])
                except Exception as e:
                    print("[DEBUG] Sequential Mode Simulation failed:", e)
                    self.signals.msg_signal.emit(
                        f"<span style='color:red'>[{self.current_time()}] Sequential Mode failed: {e}</span>"
                    )
            else:
                self.signals.msg_signal.emit(
                    f"<span>[{self.current_time()}] Simulating in <b>Equation</b> mode ... </span>"
                )
                self.flowsheet.simulate_EQN(self.msg)
                self.result = getattr(self.flowsheet, "result_data", [])

            # ----------------------------
            # Step 7: Success / Failure Report
            # ----------------------------
            if isinstance(self.result, (list, tuple)) and len(self.result) >= 4:
                self.signals.msg_signal.emit(
                    f"<span style='color:green'>[{self.current_time()}] Simulation <b>Successful.</b></span>"
                )
            else:
                self.signals.msg_signal.emit(
                    f"<span style='color:red'>[{self.current_time()}] Simulation <b>Failed.</b></span>"
                )

            # ----------------------------
            # Step 8: Post-Simulation Updates (only on success)
            # ----------------------------
            if isinstance(self.result, (list, tuple)) and len(self.result) >= 4:
                for it in self.graphics.scene.items():
                    if isinstance(it, NodeItem) and getattr(it, "type", "") == 'MaterialStream':
                        try:
                            it.update_tooltip_selectedVar()
                        except Exception as tooltip_err:
                            print(f"[DEBUG] update_tooltip_selectedVar failed for {it.name}: {tooltip_err}")
                        try:
                            if len(it.input[0].in_lines) > 0:
                                it.obj.disableInputDataTab(it.dock_widget)
                        except Exception:
                            pass

                # Step 9: Populate Results Tabs (via signal for thread-safety)
                self.signals.results_ready.emit()

        except Exception as e:
            print("[DEBUG] Simulation crashed:", e)
            self.signals.msg_signal.emit(
                f"<span style='color:red'>[{self.current_time()}] Simulation error: {e}</span>"
            )

        finally:
            # Always re-enable UI
            self.disableInterfaceforSimulation(False)
            print("[DEBUG] ==== Container.simulate finished ====")



    # Results Population 
    def _populate_results(self):
        """Slot called on the main thread when simulation results are ready."""
        try:
            DockWidget.show_result(dock_widget_lst)
        except Exception as e:
            print(f"[DEBUG] _populate_results failed: {e}")

    # ----------------- Toolbar -----------------
    def enableToolbar(self, status):
        self.graphicsView.parent().parent().actionNew.setProperty('enabled', status)
        self.graphicsView.parent().parent().actionZoomIn.setProperty('enabled', status)
        self.graphicsView.parent().parent().actionZoomOut.setProperty('enabled', status)
        self.graphicsView.parent().parent().actionResetZoom.setProperty('enabled', status)
        self.graphicsView.parent().parent().actionEquationOriented.setProperty('enabled', status)
        self.graphicsView.parent().parent().actionTerminate.setProperty('enabled', not status)
        self.graphicsView.parent().parent().actionSelectCompounds.setProperty('enabled', status)

    def disableInterfaceforSimulation(self, status):
        self.graphicsView.parent().parent().menubar.setProperty('enabled', not status)
        self.enableToolbar(not status)
        self.graphicsView.parent().parent().dockWidget.setProperty('enabled', not status)
        self.graphicsView.setInteractive(not status)
        if status:
            QApplication.instance().setOverrideCursor(QCursor(Qt.WaitCursor))
        else:
            QApplication.instance().restoreOverrideCursor()
            QApplication.instance().setOverrideCursor(QCursor(Qt.ArrowCursor))

# ----------------- Helpers -----------------
def flat_list(lst):
    return [item for sublist in lst for item in sublist]
