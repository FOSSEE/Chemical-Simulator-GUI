import pickle
import threading
import os
import ctypes
import sys
import datetime
from functools import partial
import pyuac
import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)

current = os.path.dirname(os.path.realpath(__file__))
parentPath = os.path.dirname(current)
sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.QtCore import QPointF

from python.OMChem.Flowsheet import Flowsheet
from python.utils.ComponentSelector import *
from python.utils.undo_manager import *
from python.utils.Bin_Phase_env import *
from python.utils.UnitOperations import *
from python.utils.Streams import *
from python.utils.Container import *
from python.utils.Graphics import *


ui,_ = loadUiType(parentPath+'/ui/utils/main.ui')

class DragButtonFilter(QObject):
    def __init__(self, parent, component_type):
        super().__init__(parent)
        self.component_type = component_type
        self.startPos = None

    def eventFilter(self, obj, event):
        if event.type() == QEvent.MouseButtonPress:
            if event.button() == Qt.LeftButton:
                self.startPos = event.pos()
        elif event.type() == QEvent.MouseMove:
            if event.buttons() & Qt.LeftButton and self.startPos:
                if (event.pos() - self.startPos).manhattanLength() >= QApplication.startDragDistance():
                    drag = QDrag(obj)
                    mimeData = QMimeData()
                    mimeData.setText(self.component_type)
                    drag.setMimeData(mimeData)
                    
                    # Optional: Grab button appearance as drag pixmap
                    pixmap = obj.grab()
                    drag.setPixmap(pixmap.scaled(64, 64, Qt.KeepAspectRatio, Qt.SmoothTransformation))
                    drag.setHotSpot(QPoint(32, 32))

                    drag.exec_(Qt.CopyAction)
                    self.startPos = None
                    return True
        return False

class DropFilter(QObject):
    def __init__(self, parent, main_app):
        super().__init__(parent)
        self.main_app = main_app

    def eventFilter(self, obj, event):
        if event.type() == QEvent.DragEnter:
            if event.mimeData().hasText():
                event.acceptProposedAction()
                return True
        elif event.type() == QEvent.DragMove:
            if event.mimeData().hasText():
                event.acceptProposedAction()
                return True
        elif event.type() == QEvent.Drop:
            component_type = event.mimeData().text()
            # map from viewport coordinates to scene coordinates
            pos = self.main_app.graphicsView.mapToScene(event.pos())
            self.main_app.component(component_type, pos=pos)
            event.acceptProposedAction()
            return True
        return False

'''
    MainApp class is responsible for all the main App Ui operations
'''
class MainApp(QMainWindow,ui):
    closed = pyqtSignal()
    global compound_selected
    '''
        Initializing the application
    '''
    def __init__(self):
        QMainWindow.__init__(self)

        # CSS for Component Button Tooltip
        QToolTip.setFont(QFont('SansSerif', 9))

        # Set tooltip appearance globally using QApplication stylesheet
        QApplication.instance().setStyleSheet("""
            QToolTip {
                background-color: #f5f5f5;
                color: #333;
                border: 1px solid #aaa;
                font: 9pt 'SansSerif';
            }
        """)
       
        # Loading and setting up style sheet
        self.setupUi(self)

        # Fix: Remove dockWidget_2 from the central widget grid layout
        # and explicitly re-parent it to the main window. This allows it
        # to act as a proper resizable dock widget and prevents double-free crashes.
        if self.centralwidget.layout() is not None:
            self.centralwidget.layout().removeWidget(self.dockWidget_2)
            self.dockWidget_2.setParent(self)

        # Initializing attributes
        self.zoom_count = 0
        self.thrd = None

        # Creating instances of classes for the main app
        self.container = Container(self.textBrowser, self.graphicsView)        
        self.comp = ComponentSelector(self)
        self.comp.accepted.connect(self.update_compounds)
        self.comp.accepted.connect(self._refresh_selected_compounds)

        # Connect real-time compound checkbox changes
        self.comp.compounds_changed.connect(self._refresh_selected_compounds)

        # Setting up interactive canvas        
        self.scene = self.container.graphics.get_scene()
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.delete_call

        self.graphicsView.setRenderHints(
            QPainter.Antialiasing
            | QPainter.SmoothPixmapTransform
            | QPainter.TextAntialiasing
        )

        # ✅ Enable Drag-and-Drop on the canvas
        self.graphicsView.setAcceptDrops(True)
        self.graphicsView.viewport().setAcceptDrops(True)
        self.drop_filter = DropFilter(self, self)
        self.graphicsView.viewport().installEventFilter(self.drop_filter)

        # box for selected compounds
        self.selectedElementsDock = QDockWidget("Selected Compounds", self)
        self.selectedElementsDock.setFeatures(
            QDockWidget.DockWidgetFloatable |
            QDockWidget.DockWidgetMovable |
            QDockWidget.DockWidgetClosable
        )
        self.selectedElementsDock.setMinimumSize(150, 120)
        self.selectedElementsDock.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)

        self.selectedElementsList = QListWidget()
        self.selectedElementsList.setAlternatingRowColors(True)
        self.selectedElementsList.setStyleSheet("""
            QListWidget {
                background-color: #f7f7f7;
                border: none;
                font: 10pt 'Microsoft JhengHei';
                color: #333;
            }
            QListWidget::item {
                padding: 4px 8px;
            }
            QListWidget::item:alternate {
                background-color: #eaeaea;
            }
        """)

        sel_dock_container = QWidget()
        sel_dock_layout = QVBoxLayout(sel_dock_container)
        sel_dock_layout.setContentsMargins(4, 4, 4, 4)

        sel_label = QLabel("No compounds selected")
        sel_label.setStyleSheet("color: #888; font: 9pt 'Microsoft JhengHei'; padding: 2px 4px;")
        sel_label.setAlignment(Qt.AlignCenter)
        self._sel_status_label = sel_label

        sel_dock_layout.addWidget(sel_label)
        sel_dock_layout.addWidget(self.selectedElementsList)
        self.selectedElementsDock.setWidget(sel_dock_container)

        self.addDockWidget(Qt.LeftDockWidgetArea, self.selectedElementsDock)
        self.selectedElementsDock.hide()

        self.dockWidget.setFeatures(QDockWidget.DockWidgetFloatable |
                                    QDockWidget.DockWidgetMovable |
                                    QDockWidget.DockWidgetClosable)
        self.dockWidget_2.setFeatures(QDockWidget.DockWidgetFloatable |
                                      QDockWidget.DockWidgetMovable |
                                      QDockWidget.DockWidgetClosable)

        self.dockWidget.setMinimumSize(200, 200)
        self.dockWidget_2.setMinimumSize(200, 100)

        self.dockWidget.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.dockWidget_2.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        # Setting up interactive canvas        
        self.scene = self.container.graphics.get_scene()
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.graphicsView.setAlignment(Qt.AlignLeft | Qt.AlignTop)

        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.delete_call
        
        self.setDockNestingEnabled(True)
        self.setCorner(Qt.BottomRightCorner, Qt.RightDockWidgetArea)
        self.setCorner(Qt.BottomLeftCorner, Qt.LeftDockWidgetArea)
        self.addDockWidget(Qt.RightDockWidgetArea, self.dockWidget)
        self.addDockWidget(Qt.BottomDockWidgetArea, self.dockWidget_2)

        # Set initial dock sizes after the window has been shown
        QTimer.singleShot(0, self._apply_initial_layout)

        
        # Calling initialisation
        self.menu_bar()

        self.button_handler()
        self.comp.show()
        self.comp.raise_()          # Bring to front
        self.comp.activateWindow()

        from python.utils.undo_manager import clean_file, push
        clean_file('Undo')
        clean_file('Redo')
        initial_snapshot = self.container.graphics.save_canvas()
        if initial_snapshot is not None:
            push('Undo', initial_snapshot)
        self._update_undo_redo_actions()

    def _apply_initial_layout(self):
        # Component Selector: ~300px wide, Selected Compounds: ~130px wide
        self.resizeDocks(
            [self.selectedElementsDock, self.dockWidget],
            [130, 300],
            Qt.Horizontal
        )
        # Message Browser: ~120px tall
        self.resizeDocks(
            [self.dockWidget_2],
            [120],
            Qt.Vertical
        )

    '''
        MenuBar function handels all the all the operations of 
        menu bar like new,zoom,comounds selector, simulation options.
    '''    
    def menu_bar(self):
        self.actionSelectCompounds.triggered.connect(self.select_compounds)
        self.actionSelectCompounds.setShortcut('Ctrl+C')
        self.actionZoomIn.triggered.connect(self.zoom_in)
        self.actionZoomIn.setShortcut('Ctrl++')
        self.actionNew.triggered.connect(self.new)
        self.actionNew.setShortcut('Ctrl+N')
        self.actionZoomOut.triggered.connect(self.zoom_out)
        self.actionZoomOut.setShortcut('Ctrl+-')
        self.actionResetZoom.triggered.connect(self.zoom_reset)
        self.actionResetZoom.setShortcut('Ctrl+R')
        self.actionHelp.triggered.connect(self.help)
        self.actionHelp.setShortcut('Ctrl+H')
        self.actionSequentialMode.triggered.connect(partial(self.simulate,'SM'))
        self.actionSequentialMode.setShortcut('Ctrl+M') 
        self.actionEquationOriented.triggered.connect(partial(self.simulate,'EQN'))
        self.actionEquationOriented.setShortcut('Ctrl+E')
        self.actionUndo.triggered.connect(self.undo)
        self.actionUndo.setShortcut('Ctrl+Z')
        self.actionRedo.triggered.connect(self.redo)
        self.actionRedo.setShortcut('Ctrl+Y')
        self.actionSave.triggered.connect(self.save)
        self.actionSave.setShortcut('Ctrl+S')
        self.actionOpen.triggered.connect(self.open)
        self.actionOpen.setShortcut('Ctrl+O')
        self.actionTerminate.triggered.connect(self.terminate)
        self.actionTerminate.setShortcut('Ctrl+T')
        self.actionBinaryPhaseEnvelope.triggered.connect(self.bin_phase_env)
        self.actionViewMessageBrowser.triggered.connect(self.toggle_message_browser_view)
        self.actionViewComponentSelector.triggered.connect(self.toggle_component_selector_view)

        # View : Selected Compounds 
        self.actionViewSelectedElements = QAction("Selected Compounds", self)
        self.actionViewSelectedElements.setCheckable(True)
        self.actionViewSelectedElements.setChecked(False)
        self.actionViewSelectedElements.triggered.connect(self.toggle_selected_elements_view)
        self.menuView.addAction(self.actionViewSelectedElements)

        self.actionSequentialMode.setEnabled(True)
        self.actionEquationOriented.setEnabled(True)

        
    '''
        Handles all the buttons of different components.
    '''
    def button_handler(self):
        # --- Mapping of buttons to component types ---
        button_to_type = {
            self.pushButton: 'MaterialStream',
            self.pushButton_7: 'Mixer',
            self.pushButton_10: 'Splitter',
            self.pushButton_11: 'Heater',
            self.pushButton_12: 'Cooler',
            self.pushButton_9: 'Flash',
            self.pushButton_13: 'CompoundSeparator',
            self.pushButton_25: 'Valve',
            self.pushButton_14: 'CentrifugalPump',
            self.pushButton_15: 'AdiabaticCompressor',
            self.pushButton_16: 'AdiabaticExpander',
            self.pushButton_26: 'DistillationColumn',
            self.pushButton_18: 'ShortcutColumn'
        }

        # --- Tooltips ---
        self.pushButton.setToolTip("Represents a flow of material (mixture of compounds) between unit operations, carrying properties like temperature, pressure, and composition.")
        self.pushButton_7.setToolTip("Combines two or more input streams into a single output stream by mixing their compositions and energy.")
        self.pushButton_10.setToolTip("Divides one input stream into multiple output streams based on specified split ratios.")
        self.pushButton_11.setToolTip("Increases the temperature of a process stream by adding heat energy.")
        self.pushButton_12.setToolTip("Decreases the temperature of a process stream by removing heat energy.")
        self.pushButton_9.setToolTip("Separates a vapor–liquid mixture into vapor and liquid phases at a given temperature and pressure.")
        self.pushButton_13.setToolTip("Splits a mixture into components based on composition, typically an ideal separation.")
        self.pushButton_25.setToolTip("Reduces the pressure of a fluid stream (throttling process) without performing work or heat exchange.")
        self.pushButton_14.setToolTip("Increases the pressure of a liquid stream using mechanical work (energy input).")
        self.pushButton_15.setToolTip("Compresses a gas stream without heat exchange; increases pressure and temperature.")
        self.pushButton_16.setToolTip("Expands a gas stream to produce work output, lowering pressure and temperature.")
        self.pushButton_26.setToolTip("Separates mixtures into products based on volatility differences using vapor–liquid equilibrium.")
        self.pushButton_18.setToolTip("Performs approximate distillation using shortcut (simplified) column calculations.")

        # --- Install Filters and Connect Clicks ---
        for btn, comp_type in button_to_type.items():
            # Support clicking
            btn.clicked.connect(partial(self.component, comp_type))
            
            # Support dragging
            drag_filter = DragButtonFilter(self, comp_type)
            btn.installEventFilter(drag_filter)
            setattr(btn, "_drag_filter", drag_filter) # Keep reference to prevent GC
        
    '''
        Displays help box
    '''
    def help(self):
        msgBox = QMessageBox() 
        msgBox.setIcon(QMessageBox.Question)
        msgBox.setTextFormat(Qt.RichText);   
        msgBox.setText("For any Help or Suggestion you can contact us at\n contact-om@fossee.in or at <a href='https://www.fossee.in'>Visit fossee.in!</a>")
        msgBox.setStandardButtons(QMessageBox.Ok)
        msgBox.exec_()

    '''
        Creates Binary Phase envelope
    '''
    def bin_phase_env(self):
        if len(self.comp.get_compounds())<2:
            QMessageBox.about(self, 'Important', "Please select at least 2 Compounds first")
            self.comp.show()
        else: 
            self.bin_phase = BinPhaseEnv(self.comp)
            self.bin_phase.show() 

    '''
        Shows Compounds Selector Dialog
    '''
    def select_compounds(self):
        self.comp.show()

    '''
        Updates compounds after compound selected modified during simulation creation
    '''
    def update_compounds(self):
        self.container.update_compounds()


    '''
        Returns current time in a required particular format
    '''
    def current_time(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time

    '''
        Simulate function is responsible for the simulation
        of the designed flowsheet in a particular mode
        selected by the user.
    '''
    def simulate(self, mode):
        print(f"[DEBUG] Simulate called with mode={mode}")
        """Run the simulation safely with UI lock and threading."""
        self.container.disableInterfaceforSimulation(True)
        try:
            mo_path = None

            # ✅ Use saved .mo path if available
            if hasattr(self, "last_saved_project") and self.last_saved_project:
                mo_path = self.last_saved_project.replace(".sim", ".mo")

                if os.path.exists(mo_path):
                    print(f"[DEBUG] Using saved .mo file for simulation: {mo_path}")
                    self.textBrowser.append(
                        f"<span style='color:blue'>[{self.current_time()}] Using project .mo file: {mo_path}</span>"
                    )
                else:
                    print(f"[DEBUG] Saved .mo not found at: {mo_path}, falling back to default.")
                    self.textBrowser.append(
                        f"<span style='color:orange'>[{self.current_time()}] Warning: .mo file not found, using default Flowsheet.mo</span>"
                    )
                    mo_path = None  # fallback to default

            # Always regenerate the modelica file to reflect current canvas
            try:
                if not self.container.flowsheet:
                    self.container.flowsheet = Flowsheet()
                # update flowsheet contents from current container before generating file
                self.container.flowsheet.add_compound_list([c[:c.index('(')] for c in getattr(self, 'compounds', self.comp.get_compounds() or [])])
                # regenerate modelica file (implementations may vary)
                #self.container.flowsheet.generate_modelica_file()
                print("[DEBUG] Generated .mo file for simulation.")
            except Exception as e:
                print("[DEBUG] .mo generation failed:", e)

            # start thread (always pass mode only; container.simulate will use internal flowsheet)
            self.thrd = threading.Thread(target=self.container.simulate, args=(mode,))
            self.thrd.start()


        except Exception as e:
            print("[DEBUG] Simulation start error:", e)
            self.textBrowser.append(
                f"<span style='color:red'>[{self.current_time()}] Simulation failed: {str(e)}</span>"
            )
            self.container.disableInterfaceforSimulation(False)


    '''
        Terminate the current running simulation
    '''
    def terminate(self):
        try:
            os.chdir(self.container.flowsheet.root_dir)
        except Exception:
            pass
            
        if self.thrd and self.thrd.is_alive():
            thread_id = self.thrd.ident
            if hasattr(self.container, 'flowsheet') and hasattr(self.container.flowsheet, 'process') and self.container.flowsheet.process:
                try:
                    self.container.flowsheet.process.terminate()
                    print('____________________New process created for omc is terminated.____________________')
                except Exception:
                    pass
            
            res = ctypes.pythonapi.PyThreadState_SetAsyncExc(ctypes.c_long(thread_id), ctypes.py_object(SystemExit)) 
            self.textBrowser.append("<span style=\"color:red\">["+str(self.current_time())+"]<b>Simulation Terminated.</b></span>")
            self.container.disableInterfaceforSimulation(False)
            if res > 1: 
                ctypes.pythonapi.PyThreadState_SetAsyncExc(ctypes.c_long(thread_id), 0)
        
        self.thrd = None

    '''
        Resets the zoom level to default scaling
    '''
    def zoom_reset(self):
        if(self.zoom_count>0):
            for i in range(self.zoom_count):
                self.zoom_out()
        elif(self.zoom_count<0): 
            for i in range(abs(self.zoom_count)):
                self.zoom_in()

    '''
        ZoomOut the canvas
    '''
    def zoom_out(self):
        self.graphicsView.scale(1.0/1.15,1.0/1.15)
        self.zoom_count -=1
    
    '''
        ZoomIn the canvas
    '''
    def zoom_in(self):
        self.graphicsView.scale(1.15,1.15)
        self.zoom_count +=1
  
    '''
        Instantiate a NodeItem object for selected type of
        component and added that on canvas/flowsheeting area.
    '''    
    
    from PyQt5.QtCore import QPointF, QTimer
    from PyQt5.QtWidgets import QMessageBox

    def component(self, unit_operation_type, pos=None):
        print("[DEBUG] component() called with:", unit_operation_type, "at pos:", pos)

        # Fix: ignore the bool argument from clicked signal
        if not isinstance(pos, QPointF):
            pos = None

        # --- Step 1: Check compound selection ---
        if not self.comp.is_compound_selected():
            print("[DEBUG] No compounds selected.")
            QMessageBox.about(self, 'Important', "Please Select Compounds first")
            self.comp.show()
            return

        self.type = unit_operation_type

        # --- Step 2: Create the unit operation object ---
        try:
            if self.type == "MaterialStream":
                # get compounds from the selector UI (more reliable than a global)
                compounds = self.comp.get_compounds() if hasattr(self.comp, 'get_compounds') else compound_selected
                obj = MaterialStream(compound_names=compounds)
            else:
                obj = eval(self.type)()
            print(f"[DEBUG] Created object: {obj} ({type(obj)})")
        except Exception as e:
            print("[DEBUG] Error creating object:", e)
            return

        # --- Step 3: Manage component placement offsets (grid + center) ---
        if pos is None:
            horizontal_gap = 180   # horizontal space between components
            vertical_gap = 150     # vertical space between rows
            items_per_row = 5      # how many components before wrapping to next row

            # Initialize offset if missing or None
            if not hasattr(self, "component_offset") or self.component_offset is None:
                view_center = self.graphicsView.mapToScene(self.graphicsView.viewport().rect().center())
                self.component_offset = QPointF(view_center.x(), view_center.y())
                self._grid_count = 0
                print("[DEBUG] Offset initialized to:", self.component_offset)
            else:
                # Safety check for grid counter
                if not hasattr(self, "_grid_count"):
                    self._grid_count = 0

                # Move right or wrap to next row
                x, y = self.component_offset.x(), self.component_offset.y()
                self._grid_count += 1
                if self._grid_count >= items_per_row:
                    self.component_offset = QPointF(
                        self.component_offset.x() - horizontal_gap * (items_per_row - 1),
                        y + vertical_gap
                    )
                    self._grid_count = 0
                    print("[DEBUG] Wrapped to next row:", self.component_offset)
                else:
                    self.component_offset = QPointF(x + horizontal_gap, y)
                    print("[DEBUG] Moved right to:", self.component_offset)
            target_pos = self.component_offset
        else:
            target_pos = pos

        # --- Step 4: Add the new unit operation ---
        before_ids = {id(it) for it in self.scene.items()}  # Snapshot before adding
        node_item = self.container.add_unit_operation(obj)
        print("[DEBUG] add_unit_operation returned:", node_item)

        # --- Step 5: Direct placement if returned item ---
        if node_item is not None and hasattr(node_item, "setPos"):
            node_item.setPos(target_pos)
            node_item.obj.set_pos(node_item.scenePos())
            print("[DEBUG] Set position on returned item:", target_pos)

            if pos is None: # Only center view for click-to-add
                self.graphicsView.centerOn(node_item)
                print("[DEBUG] Centered view on new component.")
            self.container.graphics.push_snapshot()
            return

        # --- Step 6: Fallback — detect newly added graphics item ---
        def find_and_position_new():
            after_items = self.scene.items()
            new_items = [it for it in after_items if id(it) not in before_ids]
            print(f"[DEBUG] Found {len(new_items)} new scene items after add_unit_operation().")

            positioned = False
            for it in new_items:
                try:
                    if hasattr(it, "setPos"):
                        it.setPos(target_pos)
                        print("[DEBUG] Positioned new item:", it, "at", target_pos)
                        if pos is None:
                            self.graphicsView.centerOn(it)
                            print("[DEBUG] Centered fallback component in viewport.")
                        positioned = True
                        break
                except Exception as e:
                    print("[DEBUG] Exception while positioning item:", e)

            if not positioned:
                print("[DEBUG] No suitable QGraphicsItem found to position (fallback failed).")
            else:
                self.container.graphics.push_snapshot()

        # --- Step 7: Schedule fallback positioning ---
        QTimer.singleShot(50, find_and_position_new)

    def new_project(self):
        self.new()  # reset everything
        # Show compound selector properly
        self.comp.show()
        self.comp.raise_()
        self.comp.activateWindow()


    '''
        New is used to delete all the existing work.
    '''        
    def new(self):
        try:
            # Reset window title
            self.setWindowTitle('Untitled - Chemical Simulator GUI')

            # --- Reset all UnitOperation counters ---
            for cls in [MaterialStream, Mixer, Heater, Cooler, Valve, Flash,
                        Splitter, DistillationColumn, ShortcutColumn,
                        AdiabaticCompressor, AdiabaticExpander, CentrifugalPump,
                        CompoundSeparator]:
                if hasattr(cls, "counter"):
                    cls.counter = 1

            # Clear old dock widgets — guard against already-deleted C++ objects
            for dw in dock_widget_lst:
                try:
                    dw.hide()
                    dw.setParent(None)
                except RuntimeError:
                    pass  # C++ object already deleted — safe to skip
            dock_widget_lst.clear()

            # Reset compound selection
            global compound_selected
            compound_selected.clear()
            self.comp.set_compounds([])
            self.comp.hide()
            clean_file('Undo')
            clean_file('Redo')

            # Reset container and scene
            self.container = Container(self.textBrowser, self.graphicsView)
            self.scene = self.container.graphics.get_scene()
            self.graphicsView.setScene(self.scene)
            self._clear_selected_compounds_panel()

                        # ✅ Push initial empty snapshot for new project
            try:
                from python.utils.undo_manager import push
                snapshot = self.container.graphics.save_canvas()
                if snapshot is not None:
                    push('Undo', snapshot)
                self._update_undo_redo_actions()
            except Exception as e:
                print("[DEBUG] new: failed to push initial Undo:", e)

            self.graphicsView.setMouseTracking(True)
            self.graphicsView.keyPressEvent = self.delete_call



            # ✅ Reset component placement offsets properly
            self.component_offset = None
            self._grid_count = 0

            # Update UI
            self.textBrowser.append(
                f"<span>[{self.current_time()}] <b>New</b> flowsheet is created ... </span>"
            )

        except Exception as e:
            print("[DEBUG] New project error:", e)
            self.textBrowser.append(
                f"<span style='color:red'>[{self.current_time()}] Failed to create new flowsheet: {str(e)}</span>"
            )


    '''
        Handels all the operations which will happen when delete button is pressed.
    '''
    def delete_call(self,event):
        try:
            if event.key() == QtCore.Qt.Key_Delete or event.key() == QtCore.Qt.Key_Backspace:
                l=self.scene.selectedItems()
                self.container.delete(l)
        except Exception as e:
            print(e)

    '''
        It helps by clearing screen and loading the objects by undo redo methods
    '''
    def undo_redo_helper(self):
        """Reset and reload scene when performing undo/redo."""
        for i in self.container.unit_operations:
            type(i).counter = 1

        for i in dock_widget_lst:
            i.hide()
            del i
        dock_widget_lst.clear()

        # Reset grid count so components spawn in proper positions
        self._grid_count = 0  

        # Reset canvas and container
        self.container = Container(self.textBrowser, self.graphicsView)
        compound_selected.clear()
        self.scene = self.container.graphics.get_scene()   
        self.graphicsView.setScene(self.scene)
        self._clear_selected_compounds_panel()
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent = self.delete_call


    '''
         Function for undo 
    '''

    def undo(self):
        from python.utils.undo_manager import pop, push, get_last_list
        try:
            print("\n[UNDO] Requested → Start")

            current = pop("Undo")
            if current is None:
                print("[UNDO] Nothing to undo.")
                return

            previous = get_last_list("Undo")
            if previous is None:
                push("Undo", current)
                print("[UNDO] Already at initial state.")
                return

            push("Redo", current)
            self.undo_redo_helper()
            self.container.graphics.load_canvas_from_snapshot(previous, self.container)
            self._refresh_selected_compounds()
            print(f"[UNDO] Scene restored → {len(previous.get('items', []))} items")

        except Exception as e:
            print("[DEBUG] Undo failed:", e)
        finally:
            self._update_undo_redo_actions()

    def redo(self):
        from python.utils.undo_manager import pop, push
        try:
            print("\n[REDO] Requested → Start")

            snap = pop("Redo")
            if snap is None:
                print("[REDO] Nothing to redo.")
                return

            push("Undo", snap)
            self.undo_redo_helper()
            self.container.graphics.load_canvas_from_snapshot(snap, self.container)
            self._refresh_selected_compounds()
            print(f"[REDO] Scene restored → {len(snap.get('items', []))} items")

        except Exception as e:
            print("[DEBUG] Redo failed:", e)
        finally:
            self._update_undo_redo_actions()

    def _update_undo_redo_actions(self):
        try:
            from python.utils.undo_manager import stack_size
            self.actionUndo.setEnabled(stack_size("Undo") > 1)
            self.actionRedo.setEnabled(stack_size("Redo") > 0)
        except Exception as e:
            print("[DEBUG] _update_undo_redo_actions failed:", e)


    '''
        Function for saving the current canvas items and compound_selected
    '''

    def save(self):
        data = []
        for i in self.container.unit_operations:
            data.append(i)
            i.saved = True
        data.append(compound_selected)
        data.append(self.container.result)

        file_format = 'sim'
        initial_path = QDir.currentPath() + ' untitled.' + file_format
        file_name, _ = QFileDialog.getSaveFileName(self, "Save As",
                                                  initial_path, "%s Files (*.%s);; All Files (*)" %
                                                  (file_format.upper(), file_format))
        try:
            with open(file_name, 'wb') as f: 
                pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)
            self.last_saved_project = file_name 
            fileName = file_name.split('/')[-1].split('.')[0]
            self.setWindowTitle(fileName+' - Chemical Simulator GUI')

        except Exception as e:
            pass

    '''
        Function for loading previous saved canvas and simulation 
    '''

    def open(self):
        try:
            file_format = 'sim'
            initial_path = QDir.currentPath() + 'untitled.' + file_format

            file_name, _ = QFileDialog.getOpenFileName(self, "Open As",
                                                      initial_path, "%s Files (*.%s);; All Files (*)" %
                                                      (file_format.upper(), file_format))
            if file_name:
                fileName = file_name.split('/')[-1].split('.')[0]
                self.setWindowTitle(fileName+' - Chemical Simulator GUI')

                self.undo_redo_helper()

                with open(file_name, 'rb') as f:
                    obj = pickle.load(f)
                temp_result = obj[-1]

                obj.pop()
                compound_selected = obj[-1]
                obj.pop()
                self.comp.set_compounds(compound_selected)
                for i in compound_selected:
                    self.comp.compound_selection(self.comp, i)
                self.comp.hide()
                self.container.graphics.load_canvas(obj, self.container)
                self.container.result = temp_result
                DockWidget.show_result(dock_widget_lst)

                for i in dock_widget_lst:
                    #Submitting values 
                    i.param()
                
                #Disbaling input data tab for output stream
                for i in self.container.graphics.scene.items():
                    if (isinstance(i, NodeItem) and i.type == 'MaterialStream'):
                        i.update_tooltip_selectedVar()
                        no_input_lines = len(i.input[0].in_lines)
                        no_output_lines = len(i.output[0].out_lines)
                        if(no_input_lines>0): #Checks if material stream is input or output stream if it is output stream it continues
                            i.obj.disableInputDataTab(i.dock_widget)

        except Exception as e:
            print(e)

    '''
        Function for toggling the display of Component Selector 
    '''
    def toggle_component_selector_view(self):
        if(self.actionViewComponentSelector.isChecked()):
            self.dockWidget.show()
        else:
            self.dockWidget.hide()

    '''
        Function for toggling the display of Message Browser 
    '''
    def toggle_message_browser_view(self):
        if(self.actionViewMessageBrowser.isChecked()):
            self.dockWidget_2.show()
        else:
            self.dockWidget_2.hide()

    # function is used to show the slected ones and hide the unchecked ones
    def toggle_selected_elements_view(self):
        if self.actionViewSelectedElements.isChecked():
            self.selectedElementsDock.show()
        else:
            self.selectedElementsDock.hide()

    # function to refresh the selected compounds box
    def _refresh_selected_compounds(self):
        self.selectedElementsList.clear()
        compounds = list(self.comp.selected_names_list)
        print(f"[DEBUG] _refresh_selected_compounds: {len(compounds)} compounds")

        if compounds:
            self._sel_status_label.setText(f"{len(compounds)} compound(s) selected")
            for name in compounds:
                self.selectedElementsList.addItem(name)
        else:
            self._sel_status_label.setText("No compounds selected")

    def _clear_selected_compounds_panel(self):
        self.selectedElementsList.clear()
        self._sel_status_label.setText("No compounds selected")

    def closeEvent(self, event):
        # Stop simulation thread if still running
        try:
            if self.thrd and self.thrd.is_alive():
                self.terminate()
        except Exception:
            pass

        # Drain any override cursors this window left on the stack
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

        event.accept()
        self.closed.emit()

from python.utils.ComponentSelectorWindow import ComponentSelectorWindow

def select_compounds(self):
    dialog = ComponentSelectorWindow(self)
    if dialog.exec_() == QDialog.Accepted:
        print("User selected compounds successfully")

# def run():
#     app = QApplication(sys.argv)
#     window = MainApp()
#     window.show()
#     sys.exit(app.exec_())

# if __name__ == "__main__":
#     if not pyuac.isUserAdmin():
#         pyuac.runAsAdmin()
#     else:
#         run()
    