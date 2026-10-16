import os
import sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)

sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType

from python.utils.ComponentSelector import *
from python.utils.Graphics import *
from python.DockWidgets.DockWidget import BaseDockWidget


ui_dialog, _ = loadUiType(
    parentPath + '/ui/DockWidgets/DockWidgetSplitter.ui'
)


class DockWidgetSplitter(BaseDockWidget, ui_dialog):

    def __init__(self, name, comptype, obj, container, parent=None):

        BaseDockWidget.__init__(self, parent)

        self._has_autosized = False

        self.setupUi(self)

        self.setWindowTitle(obj.name)

        self.name = name
        self.obj = obj
        self.type = comptype
        self.container = container

        _name_widget = self.setup_name_editor()
        _name_widget.setParent(self)
        _name_widget.setGeometry(10, 25, 341, 30)

        self.input_dict = []
        self.dict = {}

        self.stream_labels = []
        self.stream_edits = []
        self.stream_units = []
        self.stream_names = []

        # Build initial UI
        self.input_params_list()

        self.btn.clicked.connect(self.param)
        self.equalize_btn.clicked.connect(
            self.equalize_streams
        )

        self.normalize_btn.clicked.connect(
            self.normalize_streams
        )

    # ---------------------------------------------------------
    # Build / rebuild Stream fields
    # ---------------------------------------------------------


    def get_default_split_values(self, count):

        count = max(2, min(6, int(count)))

        value = round(
            1.0 / count,
            6
        )

        values = [
            value
            for _ in range(count - 1)
        ]

        last_value = round(
            1.0 - sum(values),
            6
        )

        values.append(last_value)

        return values


    def get_stream_unit(self):

        calc_type = self.cb2.currentText()

        if calc_type == "Molar_Flow":

            return "mol/s"

        elif calc_type == "Mass_Flow":

            return "g/s"

        return ""
        
    def rebuild_stream_fields(self, count):

        count = max(2, min(6, int(count)))

        grid = self.gridLayout

        # --------------------------------------------------
        # Remove previously created dynamic widgets
        # --------------------------------------------------

        for widget in self.stream_labels:
            grid.removeWidget(widget)
            widget.deleteLater()

        for widget in self.stream_edits:
            grid.removeWidget(widget)
            widget.deleteLater()

        for widget in self.stream_units:
            grid.removeWidget(widget)
            widget.deleteLater()

        for widget in self.stream_names:
            grid.removeWidget(widget)
            widget.deleteLater()

        self.stream_labels.clear()
        self.stream_edits.clear()
        self.stream_units.clear()
        self.stream_names.clear()

        # --------------------------------------------------
        # Remove old hard-coded Stream 1 / Stream 2 widgets
        # --------------------------------------------------

        old_widgets = [
            self.l3,
            self.le3,
            self.u3,
            self.l4,
            self.le4,
            self.u4
        ]

        for widget in old_widgets:

            grid.removeWidget(widget)

            widget.hide()
            widget.setParent(None)

        # --------------------------------------------------
        # Layout spacing
        # --------------------------------------------------

        grid.setVerticalSpacing(5)
        grid.setHorizontalSpacing(8)

        # --------------------------------------------------
        # Default values
        # --------------------------------------------------

        calc_type = self.cb2.currentText()

        if calc_type == "Split_Ratio":

            values = self.get_default_split_values(count)

        else:

            values = [0.0] * count

        # --------------------------------------------------
        # Create Stream 1 ... Stream N
        # --------------------------------------------------

        for i in range(count):

            row = 2 + i

            # ------------------------------
            # Stream label
            # ------------------------------

            label = QLabel(
                f"Stream {i + 1} :"
            )

            name_label = QLabel("Not Connected")

            name_label.setMinimumWidth(180)
            name_label.setSizePolicy(
                QSizePolicy.Expanding,
                QSizePolicy.Fixed
            )

            name_label.setAlignment(
                Qt.AlignLeft | Qt.AlignVCenter
            )
            name_label.setMinimumWidth(140)
            name_label.setMaximumWidth(170)

            name_label.setSizePolicy(
                QSizePolicy.Expanding,
                QSizePolicy.Fixed
            )
            name_label.setMinimumWidth(120)

            # ------------------------------
            # Value field
            # ------------------------------

            edit = QLineEdit(
                f"{values[i]:.6f}"
            )

            # ------------------------------
            # Unit
            # ------------------------------

            unit = QLabel(
                self.get_stream_unit()
            )

            # --------------------------------------------------
            # Widget sizing
            # --------------------------------------------------

            label.setMinimumHeight(24)
            label.setMaximumHeight(28)

            edit.setMinimumHeight(24)
            edit.setMaximumHeight(28)

            unit.setMinimumHeight(24)
            unit.setMaximumHeight(28)

            # Keep value field readable
            edit.setMinimumWidth(140)

            # --------------------------------------------------
            # Add widgets to grid
            # --------------------------------------------------

            grid.addWidget(
                label,
                row,
                0
            )

            grid.addWidget(
                name_label,
                row,
                1
            )

            grid.addWidget(
                edit,
                row,
                2
            )

            grid.addWidget(
                unit,
                row,
                3
            )

            # --------------------------------------------------
            # Explicit row height
            # --------------------------------------------------

            grid.setRowMinimumHeight(
                row,
                26
            )

            # --------------------------------------------------
            # Save references
            # --------------------------------------------------

            self.stream_labels.append(label)
            self.stream_edits.append(edit)
            self.stream_units.append(unit)
            self.stream_names.append(name_label)

        # --------------------------------------------------
        # Make columns behave properly
        # --------------------------------------------------

        grid.setColumnMinimumWidth(
            0,
            70
        )

        grid.setColumnMinimumWidth(
            1,
            220
        )

        grid.setColumnMinimumWidth(
            2,
            145
        )

        grid.setColumnMinimumWidth(
            3,
            40
        )

        # --------------------------------------------------
        # Calculate required GroupBox height
        # --------------------------------------------------

        # Existing rows:
        #
        # Row 0 -> No. of Output
        # Row 1 -> Calculation Type
        #
        # Row 2 onward -> Stream 1 ... Stream N

        header_height = 70

        stream_height = (
            count * 26
        )

        spacing_height = (
            (count + 1) * 5
        )

        margin_height = 25

        group_height = (
            header_height
            + stream_height
            + spacing_height
            + margin_height
        )

        # --------------------------------------------------
        # GroupBox sizing
        # --------------------------------------------------

        group_width = 360

        self.groupBox.setMinimumWidth(
            group_width
        )

        self.groupBox.setMaximumWidth(
            group_width
        )

        self.groupBox.setMinimumHeight(
            group_height
        )

        self.groupBox.setMaximumHeight(
            group_height
        )

        self.groupBox.setSizePolicy(
            QSizePolicy.Fixed,
            QSizePolicy.Fixed
        )

        # --------------------------------------------------
        # IMPORTANT:
        # Force actual GroupBox size
        # --------------------------------------------------

        self.groupBox.resize(
            group_width,
            group_height
        )

        # --------------------------------------------------

        # --------------------------------------------------
        # Position Equalize, Normalize and Submit buttons
        # --------------------------------------------------

        self.groupBox.move(
            self.groupBox.x(),
            60
        )

        group_rect = self.groupBox.geometry()

        button_x = group_rect.x()
        button_width = group_rect.width()
        button_height = 30
        button_gap = 8

        # Equalize button: below GroupBox
        button_y = group_rect.y() + group_rect.height() + 12

        self.equalize_btn.setGeometry(
            button_x,
            button_y,
            button_width,
            button_height
        )
        self.equalize_btn.show()

        # Normalize button: below Equalize
        button_y += button_height + button_gap

        self.normalize_btn.setGeometry(
            button_x,
            button_y,
            button_width,
            button_height
        )
        self.normalize_btn.show()

        # Submit button: below Normalize
        button_y += button_height + button_gap

        self.btn.setGeometry(
            button_x,
            button_y,
            button_width,
            button_height
        )
        self.btn.show()
        self.btn.setEnabled(True)

        # --------------------------------------------------
        # Resize window to fit all buttons
        # --------------------------------------------------

        total_width = max(
            380,
            button_x + button_width + 15
        )

        total_height = button_y + button_height + 20

        self.setMinimumSize(
            total_width,
            total_height
        )

        self.setMaximumSize(
            16777215,
            16777215
        )

        self.resize(
            total_width,
            total_height
        )

        # --------------------------------------------------
        # Refresh Qt geometry
        # --------------------------------------------------

        grid.activate()
        self.groupBox.updateGeometry()
        self.equalize_btn.updateGeometry()
        self.normalize_btn.updateGeometry()
        self.btn.updateGeometry()
        self.updateGeometry()
                

    def input_params_list(self):

        try:

            self.l1.setText(
                self.obj.variables['No']['name'] + ":"
            )

            # ---------------------------------------------
            # Number of Outputs ComboBox
            # ---------------------------------------------

            self.no_combo = QComboBox()

            for v in range(2, 7):
                self.no_combo.addItem(str(v))

            current_no = int(
                self.obj.variables['No']['value']
            )

            self.no_combo.setCurrentText(
                str(current_no)
            )

            grid = self.gridLayout

            idx = grid.indexOf(self.le1)

            if idx >= 0:

                row, col, rowspan, colspan = \
                    grid.getItemPosition(idx)

                grid.removeWidget(self.le1)

                self.le1.hide()
                self.le1.setParent(None)

                grid.addWidget(
                    self.no_combo,
                    row,
                    col
                )

            self.u1.setText(
                self.obj.variables['No']['unit']
            )

            # ---------------------------------------------
            # Calculation Type
            # ---------------------------------------------

            self.l2.setText(
                self.obj.variables['CalcType']['name'] + ":"
            )

            self.cb2.clear()

            for mode in self.obj.CalcType_modes:
                self.cb2.addItem(str(mode))

            self.cb2.setCurrentText(
                self.obj.variables['CalcType']['value']
            )

            # ---------------------------------------------
            # Dynamic stream fields
            # ---------------------------------------------

            self.rebuild_stream_fields(
                current_no
            )

            self.no_combo.currentIndexChanged.connect(
                self.on_output_count_changed
            )

            self.cb2.currentIndexChanged.connect(
                self.fun
            )

            self.input_dict = [
                self.no_combo,
                self.cb2
            ]

            self.input_dict.extend(
                self.stream_edits
            )

        except Exception as e:

            print(
                f"[UI] input_params_list failed for "
                f"{self.name}: {e}"
            )

    # ---------------------------------------------------------
    # Number of output changed
    # ---------------------------------------------------------


    def on_output_count_changed(self):
        try:
            count = int(self.no_combo.currentText())

            self.rebuild_stream_fields(count)

            self.input_dict = [
                self.no_combo,
                self.cb2
            ]
            self.input_dict.extend(self.stream_edits)

            # Recalculate outlet flows after changing output count.
            calc_type = self.cb2.currentText()

            if calc_type in ("Molar_Flow", "Mass_Flow"):
                QTimer.singleShot(
                    0,
                    self.auto_distribute_from_input
                )

            elif calc_type == "Split_Ratio":
                values = self.get_default_split_values(count)

                for edit, value in zip(self.stream_edits, values):
                    edit.setText(f"{value:.6f}")

        except Exception as e:
            print("[UI] Output count update failed:", e)


    # ---------------------------------------------------------
    # Calculation type changed
    # ---------------------------------------------------------


    def fun(self):
        try:
            calc_type = self.cb2.currentText()

            # Update unit labels
            if calc_type == "Molar_Flow":
                unit = "mol/s"
            elif calc_type == "Mass_Flow":
                unit = "g/s"
            else:
                unit = ""

            for label in self.stream_units:
                label.setText(unit)

            # Split ratio should always initialize with valid ratios.
            if calc_type == "Split_Ratio":
                values = self.get_default_split_values(
                    len(self.stream_edits)
                )

                for edit, value in zip(self.stream_edits, values):
                    edit.setText(f"{value:.6f}")

            # For flow modes, recalculate from the connected inlet.
            elif calc_type in ("Molar_Flow", "Mass_Flow"):
                QTimer.singleShot(
                    0,
                    self.auto_distribute_from_input
                )

        except Exception as e:
            print("[Splitter] Calculation type update failed:", e)


    # ---------------------------------------------------------
    # Submit
    # ---------------------------------------------------------

    def equalize_streams(self):

        try:

            count = int(
                self.no_combo.currentText()
            )

            calc_type = self.cb2.currentText()


            if calc_type == "Split_Ratio":

                value = 1.0 / count

                for edit in self.stream_edits:

                    edit.setText(
                        f"{value:.6f}"
                    )


            else:

                inlet_flow = self.get_input_flow(calc_type)


                if inlet_flow is None:

                    QMessageBox.warning(
                        self,
                        "Input Missing",
                        "Connect Material Stream to Splitter input."
                    )

                    return


                value = inlet_flow / count


                for edit in self.stream_edits:

                    edit.setText(
                        f"{value:.6f}"
                    )
                


        except Exception as e:

            print(
                "Equalize failed:",
                e
            )



    def normalize_streams(self):

        try:

            calc_type = self.cb2.currentText()

            values = []

            for edit in self.stream_edits:

                values.append(
                    float(edit.text())
                )


            total = sum(values)


            if total == 0:

                QMessageBox.warning(
                    self,
                    "Invalid",
                    "Cannot normalize zero values."
                )

                return


            if calc_type == "Split_Ratio":

                for i,value in enumerate(values):

                    self.stream_edits[i].setText(
                        f"{value/total:.6f}"
                    )


            else:

                inlet_flow = self.get_input_flow(calc_type)


                if inlet_flow is None:

                    QMessageBox.warning(
                        self,
                        "Input Missing",
                        "Connect Material Stream to Splitter input."
                    )

                    return


                factor = inlet_flow / total


                for i,value in enumerate(values):

                    self.stream_edits[i].setText(
                        f"{value * factor:.6f}"
                    )


        except Exception as e:

            print(
                "Normalize failed:",
                e
            )



    def auto_distribute_from_input(self):

        try:
            calc_type = self.cb2.currentText()

            # Split Ratio has its own calculation.
            if calc_type not in ("Molar_Flow", "Mass_Flow"):
                return

            count = len(self.stream_edits)

            if count == 0:
                return

            inlet_flow = self.get_input_flow(calc_type)

            # No connected input: keep flow values at zero.
            if inlet_flow is None:
                for edit in self.stream_edits:
                    edit.setText("0.000000")
                return

            if inlet_flow < 0:
                print("[Splitter] Invalid negative inlet flow.")
                return

            # Distribute the inlet flow equally.
            value = inlet_flow / count

            values = [
                round(value, 6)
                for _ in range(count)
            ]

            # Adjust the last outlet to preserve the total
            # as closely as possible at six decimal places.
            values[-1] = round(
                inlet_flow - sum(values[:-1]),
                6
            )

            for edit, flow in zip(self.stream_edits, values):
                edit.setText(f"{flow:.6f}")

            print(
                f"[Splitter] Auto-distributed {calc_type}: "
                f"inlet={inlet_flow}, outlets={values}, "
                f"sum={sum(values)}"
            )

        except Exception as e:
            print("[Splitter] Automatic distribution failed:", e)



    def get_input_flow(self, flow_type):

        try:

            node_item = None

            graphics_view = self.container.graphics.graphicsView

            for item in graphics_view.items():

                if hasattr(item, "obj") and item.obj is self.obj:
                    node_item = item
                    break


            if node_item is None:
                return None


            if len(node_item.input) == 0:
                return None


            input_socket = node_item.input[0]


            if not input_socket.in_lines:
                return None


            line = input_socket.in_lines[0]


            source_stream = line.source.parent.obj


            if flow_type == "Molar_Flow":

                print("SOURCE STREAM:", source_stream.name)

                print(
                    "F_p[1]:",
                    source_stream.variables['F_p[1]']['value']
                )

                print(
                    "ALL FLOW VARIABLES:",
                    source_stream.variables
                )

                return float(
                    source_stream.variables['F_p[1]']['value']
                )


            elif flow_type == "Mass_Flow":

                return float(
                    source_stream.variables['Fm_p[1]']['value']
                )


        except Exception as e:

            print(
                "[Splitter] Input flow fetch failed:",
                e
            )

            return None        
        

    def param(self):

        try:
            if hasattr(self, 'check_and_rename_if_needed'):
                if not self.check_and_rename_if_needed():
                    return

            new_no = int(
                self.no_combo.currentText()
            )

            calc_type = self.cb2.currentText()

            spec_values = []

            # --------------------------------------------------
            # Read Stream values
            # --------------------------------------------------

            for i in range(new_no):

                text = self.stream_edits[i].text().strip()

                if not text:

                    QMessageBox.warning(
                        self,
                        "Invalid Input",
                        f"Please enter value for Stream {i + 1}."
                    )

                    return

                value = float(text)

                if value < 0:

                    QMessageBox.warning(
                        self,
                        "Invalid Input",
                        f"Stream {i + 1} cannot be negative."
                    )

                    return

                spec_values.append(value)

            # --------------------------------------------------
            # Split Ratio validation
            # --------------------------------------------------

            if calc_type == "Split_Ratio":

                total = sum(spec_values)

                if abs(total - 1.0) > 1e-5:

                    QMessageBox.warning(
                        self,
                        "Invalid Split Ratio",
                        f"Split ratios must sum to 1.0.\n\n"
                        f"Current sum = {total:.6f}"
                    )

                    return

            elif calc_type in ["Molar_Flow","Mass_Flow"]:

                inlet_flow = self.get_input_flow(calc_type)

                if inlet_flow is None:
                    QMessageBox.warning(
                        self,
                        "Input Missing",
                        "Connect Material Stream to Splitter input."
                    )
                    return

                total = sum(spec_values)

                # Auto distribute if all outlets are zero
                if total == 0:

                    value = inlet_flow / new_no

                    spec_values = [
                        round(value,6)
                        for _ in range(new_no)
                    ]

                    print(
                        "[Splitter] Auto calculated outlet flow:",
                        spec_values
                    )

                    total = sum(spec_values)


                if abs(total - inlet_flow) > 1e-5:

                    QMessageBox.warning(
                        self,
                        "Invalid Flow",
                        f"Outlet flow must equal inlet flow.\n\n"
                        f"Inlet = {inlet_flow}\n"
                        f"Outlet Sum = {total}"
                    )

                    return

            # --------------------------------------------------
            # Send parameters to UnitOperation
            # --------------------------------------------------

            params = [
                new_no,
                calc_type
            ]

            params.extend(spec_values)

            self.obj.param_setter(params)

            # --------------------------------------------------
            # Update graphical output ports
            # --------------------------------------------------

            node_item = None

            try:

                graphics_view = self.container.graphics.graphicsView

                for item in graphics_view.items():

                    if hasattr(item, "obj") and item.obj is self.obj:

                        node_item = item
                        break

            except Exception as e:

                print(
                    "[UI] Could not find Splitter graphics item:",
                    e
                )

            if node_item is not None:

                node_item.update_output_ports(new_no)

                QTimer.singleShot(
                    100,
                    self.update_connected_component_names
                )

                print(
                    f"[UI] Updated Splitter outputs to {new_no}"
                )

            else:

                print(
                    f"[UI] Graphics node not found for {self.obj.name}"
                )

            # --------------------------------------------------
            # Close properties window
            # --------------------------------------------------

            self.hide()

        except ValueError as e:

            QMessageBox.warning(
                self,
                "Invalid Input",
                "Please enter valid numeric values."
            )

        except Exception as e:

            print(
                f"[UI] Submit failed for {self.name}: {e}"
            )

            import traceback
            traceback.print_exc()


    def showEvent(self,event):

        super().showEvent(event)

        self.update_connected_component_names()

        if not self._has_autosized:
            QTimer.singleShot(0,self._autosize)

    def _autosize(self):

        if self._has_autosized:
            return

        try:

            QApplication.processEvents()

            self.layout().activate()
            self.adjustSize()

            screen = QApplication.primaryScreen().availableGeometry()

            hint = self.sizeHint()

            width = min(
                max(380, hint.width() + 30),
                int(screen.width() * 0.4)
            )

            height = min(
                max(450, hint.height() + 50),
                int(screen.height() * 0.85)
            )


            mw = self.parent()

            if isinstance(mw, QMainWindow) and not self.isFloating():

                mw.resizeDocks(
                    [self],
                    [width],
                    Qt.Horizontal
                )

                mw.resizeDocks(
                    [self],
                    [height],
                    Qt.Vertical
                )

            else:

                self.resize(
                    width,
                    height
                )


            self._has_autosized = True


        except Exception as e:

            print("[Splitter] autosize failed:", e)


    def update_connected_component_names(self):

        print("========== UPDATE NAMES ==========")

        node_item = None

        graphics_view = self.container.graphics.graphicsView

        for item in graphics_view.items():

            if hasattr(item, "obj") and item.obj is self.obj:
                node_item = item
                break

        if node_item is None:
            print("Splitter node not found")
            return


        print("OUTPUT COUNT:", len(node_item.output))
        print("STREAM LABEL COUNT:", len(self.stream_names))


        for i, socket in enumerate(node_item.output):

            print(
                f"OUTPUT {i} ID: {socket.id} LINES: {len(socket.out_lines)}"
            )

            component_name = "Not Connected"


            if socket.out_lines:

                line = socket.out_lines[0]


                try:

                    target_socket = line.target

                    print(
                        "TARGET SOCKET:",
                        target_socket
                    )


                    target_node = target_socket.parent


                    print(
                        "TARGET NODE:",
                        target_node
                    )


                    if hasattr(target_node, "obj"):

                        component_name = target_node.obj.name


                    elif hasattr(target_node, "parent"):

                        if hasattr(target_node.parent, "obj"):

                            component_name = (
                                target_node.parent.obj.name
                            )


                except Exception as e:

                    print(
                        "Name fetch error:",
                        e
                    )


            print(
                f"OUTPUT {i+1}: {component_name}"
            )


            if i < len(self.stream_names):

                self.stream_names[i].setText(
                    component_name
                )

                self.stream_names[i].setToolTip(
                    component_name
                )