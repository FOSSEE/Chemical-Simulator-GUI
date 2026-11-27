from collections import defaultdict
import datetime
import threading
import html
import os, sys

from PyQt5.QtCore import QObject, pyqtSignal, Qt
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget
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
    msg_signal = pyqtSignal(str)
    results_ready = pyqtSignal()
    simulation_finished = pyqtSignal(bool) # Emitted when simulation results are ready


# ----------------- Container -----------------
class Container(QObject):
    def __init__(self, msgbrowser, graphicsView):
        super().__init__()

        self.signals = SimulationSignals(self)
        self.msg = msgbrowser
        self.signals.msg_signal.connect(self.msg.append)
        self.signals.results_ready.connect(self._populate_results)
        self.signals.simulation_finished.connect(
            self._on_simulation_finished
        )
        self.unit_operations = []
        self.thermo_package = None
        self.compounds = None
        self.flowsheet = None
        self.simulation_successful = False
        self.conn = defaultdict(list)
        self.op = defaultdict(list)
        self.ip = defaultdict(list)
        self.graphicsView = graphicsView
        self.msg.setText("")
        self.opl = []
        self.result = []
        self.graphics = Graphics(self, self.graphicsView)
        self.scene = self.graphics.get_scene()
        print(f"[DEBUG] Scene check -> container.scene id={id(self.scene)}, graphics.scene id={id(self.graphics.scene)}")
        

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

    def _on_simulation_finished(self, succeeded):
        """Apply all GUI updates after the worker finishes."""
        try:
            self.simulation_successful = succeeded

            for item in self.graphics.scene.items():
                if not isinstance(item, NodeItem):
                    continue

                item.simulation_valid = succeeded

                if succeeded and item.type == "MaterialStream":
                    try:
                        item.update_tooltip_selectedVar()
                    except Exception as e:
                        print(
                            "[DEBUG] Tooltip update failed:",
                            item.name,
                            e
                        )

            if succeeded:
                self._populate_results()
            else:
                self.update_components_editability()

        except Exception as e:
            print("[DEBUG] Simulation completion UI update failed:", e)

        finally:
            self.disableInterfaceforSimulation(False)

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
                        # Invalidate simulation for both connected components.
                        # After connection removal, both affected components
                        # should become editable until simulation runs again.

                        if item.source and item.source.parent:
                            source_node = item.source.parent
                            source_node.simulation_valid = False

                        if item.target and item.target.parent:
                            target_node = item.target.parent
                            target_node.simulation_valid = False
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
                self.update_components_editability()
                self.graphics.push_snapshot()

        except Exception as e:
            print("[DEBUG] delete: outer exception:", e)

    def prepare_simulation(self):
        """
        Collect all GUI/scene information on the main thread
        before starting the simulation worker.
        """
        self._simulation_nodes = [
            item for item in self.graphics.scene.items()
            if isinstance(item, NodeItem)
        ]

        self.ip = defaultdict(list)
        self.op = defaultdict(list)

        # Clear previous results on the GUI thread.
        for item in self._simulation_nodes:
            try:
                if item.dock_widget:
                    item.dock_widget.clear_results()
            except Exception as e:
                print("[DEBUG] Failed to clear results:", e)

        def get_other_node(ln, this_item):
            for a, b in [
                ("start_item", "end_item"),
                ("end_item", "start_item"),
                ("source", "target"),
                ("target", "source"),
                ("from_node", "to_node"),
                ("to_node", "from_node"),
            ]:
                try:
                    if hasattr(ln, a) and hasattr(ln, b):
                        a_val = getattr(ln, a)
                        b_val = getattr(ln, b)

                        if a_val is this_item:
                            other = b_val
                        elif b_val is this_item:
                            other = a_val
                        else:
                            continue

                        if other:
                            return getattr(
                                getattr(other, "obj", other),
                                "name",
                                getattr(other, "name", None)
                            )
                except Exception:
                    continue

            return getattr(ln, "name", "UnknownLine")

        missing_connections = []
        warnings_html = ""

        for item in self._simulation_nodes:
            total_in = sum(
                len(getattr(sock, "in_lines", []))
                for sock in getattr(item, "input", [])
            )
            total_out = sum(
                len(getattr(sock, "out_lines", []))
                for sock in getattr(item, "output", [])
            )

            if item.type in ['MaterialStream', 'EngStm']:
                if total_in == 0 and total_out == 0:
                    missing_connections.append((item.name, "unconnected"))
            else:
                for sock in getattr(item, "input", []):
                    if not getattr(sock, "in_lines", []):
                        missing_connections.append((item.name, "input"))

                for sock in getattr(item, "output", []):
                    if not getattr(sock, "out_lines", []):
                        missing_connections.append((item.name, "output"))

            # Build input/output maps.
            uo_name = getattr(
                item.obj, "name", getattr(item, "name", None)
            )

            if not uo_name:
                continue

            for idx, port in enumerate(getattr(item, "input", [])):
                for ln in getattr(port, "in_lines", []):
                    self.ip[uo_name].append(
                        (idx, get_other_node(ln, item))
                    )

            for idx, port in enumerate(getattr(item, "output", [])):
                for ln in getattr(port, "out_lines", []):
                    self.op[uo_name].append(
                        (idx, get_other_node(ln, item))
                    )

        for name, connection_type in missing_connections:
            warnings_html += (
                f"<br><span style='color:#999900'>"
                f"Warning: {name} - Missing Socket Connection(s)."
                f"</span>"
            )

        if warnings_html:
            self.signals.msg_signal.emit(warnings_html)

        print(
            "[DEBUG] GUI preparation complete:",
            "Nodes:", len(self._simulation_nodes),
            "IP:", len(self.ip),
            "OP:", len(self.op)
        )


    def update_components_editability(self):
        """
        A component becomes read-only only when:
        - Simulation was successful
        - Component has an incoming connection
        - Component has no outgoing connection

        All components remain editable before simulation.
        Components become editable again when their connection
        state changes and they are no longer valid output nodes.
        """
        try:
            scene = getattr(self, "scene", None)

            if scene is None and hasattr(self, "graphics"):
                scene = getattr(self.graphics, "scene", None)

            if scene is None:
                return

            for item in scene.items():
                if not isinstance(item, NodeItem):
                    continue

                dw = getattr(item, "dock_widget", None)

                if dw is None:
                    continue

                if hasattr(dw, "refresh_connections"):
                    dw.refresh_connections()

                input_sockets = getattr(item, "input", [])
                output_sockets = getattr(item, "output", [])

                has_incoming_connection = any(
                    len(getattr(sock, "in_lines", [])) > 0
                    for sock in input_sockets
                )

                has_outgoing_connection = any(
                    len(getattr(sock, "out_lines", [])) > 0
                    for sock in output_sockets
                )

                is_output_component = (
                    has_incoming_connection
                    and not has_outgoing_connection
                )

                read_only = (
                    self.simulation_successful
                    and getattr(item, "simulation_valid", False)
                    and is_output_component
                )

                # MaterialStream has its own input-data tab handling.
                if item.type == "MaterialStream":
                    if read_only:
                        item.obj.disableInputDataTab(dw)
                    else:
                        item.obj.enableInputDataTab(dw)

                if hasattr(dw, "set_read_only"):
                    dw.set_read_only(read_only)

        except Exception as e:
            print(f"[DEBUG] update_components_editability failed: {e}")



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

        # Reset simulation state before every new attempt
        self.simulation_successful = False

        simulation_succeeded = False
        try:
            print("[DEBUG] ==== Starting Container.simulate ====")
            print("[DEBUG] mode:", mode)
            print("[DEBUG] prepared nodes count:", len(self._simulation_nodes))
            print("[DEBUG] unit_operations (len):", len(self.unit_operations))
            print("[DEBUG] compounds:", getattr(self, 'compounds', None))

            self.signals.msg_signal.emit(
                f"<span>[{self.current_time()}] <b>Starting simulation</b> (mode={mode})</span>"
            )

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
                    f"<span style='color:red'>[{self.current_time()}] "
                    f"Failed to prepare Flowsheet: {e}</span>"
                )
                print("[DEBUG] Failed to create Flowsheet:", e)
                return

            # ----------------------------
            # Step 4: Add Unit Operations
            # ----------------------------
            for uo in self.unit_operations:
                try:
                    self.flowsheet.add_unit_operations(uo)
                except Exception as e:
                    print(
                        "[DEBUG] Failed to add unit operation:",
                        getattr(uo, "name", uo),
                        e
                    )

            print("[DEBUG] Added unit operations:", len(self.unit_operations))

            # ----------------------------
            # Step 6: Simulation
            # ----------------------------
            print("[DEBUG] Calling Flowsheet simulate.")
            self.result = None

            if mode == 'SM':
                self.signals.msg_signal.emit(
                    f"<span>[{self.current_time()}] "
                    f"Simulating in <b>Sequential</b> mode ... </span>"
                )

                try:
                    self.flowsheet.simulate_SM(self.ip, self.op)
                    self.result = getattr(
                        self.flowsheet,
                        "result_data",
                        []
                    )

                except Exception as e:
                    print("[DEBUG] Sequential Mode Simulation failed:", e)

                    self.signals.msg_signal.emit(
                        f"<span style='color:red'>[{self.current_time()}] "
                        f"Sequential Mode failed: {e}</span>"
                    )

                    self.result = None

            else:
                self.signals.msg_signal.emit(
                    f"<span>[{self.current_time()}] "
                    f"Simulating in <b>Equation</b> mode ... </span>"
                )

                self.flowsheet.simulate_EQN(self.msg)

                self.result = getattr(
                    self.flowsheet,
                    "result_data",
                    []
                )

            # ----------------------------
            # Step 7: Success / Failure Report
            # ----------------------------
            simulation_succeeded = (
                isinstance(self.result, (list, tuple))
                and len(self.result) >= 2
            )

            if simulation_succeeded:

                self.simulation_successful = True
                # Mark all components as valid after successful simulation.

                self.signals.msg_signal.emit(
                    f"<span style='color:green'>[{self.current_time()}] "
                    f"Simulation <b>Successful.</b></span>"
                )

            else:

                self.simulation_successful = False

                self.signals.msg_signal.emit(
                    f"<span style='color:red'>[{self.current_time()}] "
                    f"Simulation <b>Failed.</b></span>"
                )

                try:
                    error_detail = getattr(
                        self.flowsheet,
                        "last_error",
                        ""
                    )

                    if error_detail:
                        safe_error = html.escape(error_detail).replace(
                            "\n",
                            "<br/>"
                        )

                        self.signals.msg_signal.emit(
                            f"<span style='color:red'>"
                            f"<b>OpenModelica Error:</b><br/>"
                            f"{safe_error}</span>"
                        )

                except Exception as msg_err:
                    print(
                        "[DEBUG] Failed to display simulation error detail:",
                        msg_err
                    )

        except Exception as e:

            self.simulation_successful = False

            print("[DEBUG] Simulation crashed:", e)

            self.signals.msg_signal.emit(
                f"<span style='color:red'>[{self.current_time()}] "
                f"Simulation error: {e}</span>"
            )

        finally:
            self.signals.simulation_finished.emit(simulation_succeeded)
            print("[DEBUG] ==== Container.simulate finished ====")


    # Results Population 
    def _populate_results(self):
        """Slot called on the main thread when simulation results are ready."""
        try:
            DockWidget.show_result(dock_widget_lst)
            
            # Re-apply read-only state because show_result recreates the input fields
            # Keep recreated input fields editable after results are populated
            for dw in dock_widget_lst:
                if hasattr(dw, 'set_read_only'):
                    dw.set_read_only(False)

            # Preserve connection-based restrictions for all components
            self.update_components_editability()

            # Make all result table items non-editable
            for dw in dock_widget_lst:
                for tw in dw.findChildren(QTableWidget):
                    for row in range(tw.rowCount()):
                        for col in range(tw.columnCount()):
                            item = tw.item(row, col)
                            if item:
                                item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
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
