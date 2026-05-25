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

'''
    MainApp class is responsible for all the main App Ui operations
'''
class MainApp(QMainWindow,ui):
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

        # box for selected compounds
        self.selectedElementsDock = QDockWidget("Selected Compounds", self)
        self.selectedElementsDock.setFeatures(
            QDockWidget.DockWidgetFloatable |
            QDockWidget.DockWidgetMovable |
            QDockWidget.DockWidgetClosable
        )
        self.selectedElementsDock.setMinimumSize(180, 150)
        self.selectedElementsDock.setMaximumWidth(250)

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

        self.dockWidget.setFeatures(QDockWidget.DockWidgetFloatable |
                                    QDockWidget.DockWidgetMovable |
                                    QDockWidget.DockWidgetClosable)
        self.dockWidget_2.setFeatures(QDockWidget.DockWidgetFloatable |
                                      QDockWidget.DockWidgetMovable |
                                      QDockWidget.DockWidgetClosable)

        self.dockWidget.setMinimumSize(200, 200)
        self.dockWidget_2.setMinimumSize(200, 200)

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

        
        # Calling initialisation 
        self.menu_bar()
        
        # after self.menu_bar()
        self.actionUndo.setEnabled(True)
        self.actionRedo.setEnabled(True)

        self.button_handler()
        self.comp.show()
        self.comp.raise_()          # Bring to front
        self.comp.activateWindow()

        # Setting up keyboard shortcuts for undo and redo
        from PyQt5.QtWidgets import QShortcut
        from PyQt5.QtGui import QKeySequence

        undo_shortcut = QShortcut(QKeySequence("Ctrl+Z"), self)
        undo_shortcut.activated.connect(self.undo)

        redo_shortcut = QShortcut(QKeySequence("Ctrl+Y"), self)
        redo_shortcut.activated.connect(self.redo)

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
        self.actionViewSelectedElements.setChecked(True)
        self.actionViewSelectedElements.triggered.connect(self.toggle_selected_elements_view)
        self.menuView.addAction(self.actionViewSelectedElements)

        self.actionSequentialMode.setEnabled(True)
        self.actionEquationOriented.setEnabled(True)

        
    '''
        Handles all the buttons of different components.
    '''
    def button_handler(self):
        # --- Streams ---
        self.pushButton.clicked.connect(partial(self.component, 'MaterialStream'))
        self.pushButton.setToolTip("Represents a flow of material (mixture of compounds) between unit operations, carrying properties like temperature, pressure, and composition.")
    
        # --- Mixer/Splitter ---
        self.pushButton_7.clicked.connect(partial(self.component, 'Mixer'))
        self.pushButton_7.setToolTip("Combines two or more input streams into a single output stream by mixing their compositions and energy.")

        self.pushButton_10.clicked.connect(partial(self.component, 'Splitter'))
        self.pushButton_10.setToolTip("Divides one input stream into multiple output streams based on specified split ratios.")

        # --- Exchangers ---
        self.pushButton_11.clicked.connect(partial(self.component, 'Heater'))
        self.pushButton_11.setToolTip("Increases the temperature of a process stream by adding heat energy.")

        self.pushButton_12.clicked.connect(partial(self.component, 'Cooler'))
        self.pushButton_12.setToolTip("Decreases the temperature of a process stream by removing heat energy.")

        # --- Separator ---
        self.pushButton_9.clicked.connect(partial(self.component, 'Flash'))
        self.pushButton_9.setToolTip("Separates a vapor–liquid mixture into vapor and liquid phases at a given temperature and pressure.")

        self.pushButton_13.clicked.connect(partial(self.component, 'CompoundSeparator'))
        self.pushButton_13.setToolTip("Splits a mixture into components based on composition, typically an ideal separation.")

        # --- Pressure Change ---
        self.pushButton_25.clicked.connect(partial(self.component, 'Valve'))
        self.pushButton_25.setToolTip("Reduces the pressure of a fluid stream (throttling process) without performing work or heat exchange.")

        self.pushButton_14.clicked.connect(partial(self.component, 'CentrifugalPump'))
        self.pushButton_14.setToolTip("Increases the pressure of a liquid stream using mechanical work (energy input).")

        self.pushButton_15.clicked.connect(partial(self.component, 'AdiabaticCompressor'))
        self.pushButton_15.setToolTip("Compresses a gas stream without heat exchange; increases pressure and temperature.")

        self.pushButton_16.clicked.connect(partial(self.component, 'AdiabaticExpander'))
        self.pushButton_16.setToolTip("Expands a gas stream to produce work output, lowering pressure and temperature.")

        # --- Columns ---
        self.pushButton_26.clicked.connect(partial(self.component, 'DistillationColumn'))
        self.pushButton_26.setToolTip("Separates mixtures into products based on volatility differences using vapor–liquid equilibrium.")

        self.pushButton_18.clicked.connect(partial(self.component, 'ShortcutColumn'))
        self.pushButton_18.setToolTip("Performs approximate distillation using shortcut (simplified) column calculations.")
        
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
                self.container.flowsheet.generate_modelica_file()
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
        os.chdir(self.container.flowsheet.root_dir)
        if self.thrd:
            thread_id = self.thrd.ident
            # print('____________________Going to terminate simulation thread with Thread ID:',thread_id,'____________________')
            # print('____________________Going to terminate the new process created for omc____________________')
            self.container.flowsheet.process.terminate()
            print('____________________New process created for omc is terminated.____________________')
            res = ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, ctypes.py_object(SystemExit)) 
            self.textBrowser.append("<span style=\"color:red\">["+str(self.current_time())+"]<b>Simulation Terminated.</b></span>")
            self.container.disableInterfaceforSimulation(False)
            # print('____________________Simulation thread terminated____________________')
            if res > 1: 
                ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, 0) 
                # print('Exception raise (Thread termination) failure')

    '''
        Resets the zoom level to default scaling
    '''
    def zoom_reset(self):
        if(self.zoom_count>0):
            for i in range(self.zoom_count):
                self.zoomout()
        elif(self.zoom_count<0): 
            for i in range(abs(self.zoom_count)):
                self.zoomin()

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

    def component(self, unit_operation_type):
        print("[DEBUG] component() called with:", unit_operation_type)

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

        # --- Step 4: Add the new unit operation ---
        before_ids = {id(it) for it in self.scene.items()}  # Snapshot before adding
        node_item = self.container.add_unit_operation(obj)
        print("[DEBUG] add_unit_operation returned:", node_item)

        # --- Step 5: Direct placement if returned item ---
        if node_item is not None and hasattr(node_item, "setPos"):
            node_item.setPos(self.component_offset)
            print("[DEBUG] Set position on returned item:", self.component_offset)

            self.graphicsView.centerOn(node_item)
            print("[DEBUG] Centered view on new component.")
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
                        it.setPos(self.component_offset)
                        print("[DEBUG] Positioned new item:", it, "at", self.component_offset)
                        self.graphicsView.centerOn(it)
                        print("[DEBUG] Centered fallback component in viewport.")
                        positioned = True
                        break
                except Exception as e:
                    print("[DEBUG] Exception while positioning item:", e)

            if not positioned:
                print("[DEBUG] No suitable QGraphicsItem found to position (fallback failed).")

        # --- Step 7: Schedule fallback positioning ---
        QTimer.singleShot(50, find_and_position_new)

    def new_project(self):
        self.new()  # reset everything
        # Show compound selector properly
        self.comp.show()
        self.comp.raise_()
        self.comp.activateWindow()
        clean_file('Undo')
        clean_file('Redo')


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

            # Clear old dock widgets
            for dw in dock_widget_lst:
                dw.hide()
                dw.setParent(None)
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
            if event.key() == QtCore.Qt.Key_Delete:
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
        try:
            from python.utils.undo_manager import pop, push, get_last_list
            print("\n[UNDO] Requested → Start")

            # Save current scene as redo candidate
            try:
                s_cur = self.container.graphics.save_canvas()
                if s_cur is not None:
                    push("Redo", s_cur)
                    print(f"[DEBUG] Undo: pushed current snapshot to Redo (items={len(s_cur.get('items', []))})")
            except Exception as e:
                print("[DEBUG] Undo: push current to Redo failed:", e)

            # Pop last Undo (this is the snapshot we want to restore)
            snap = pop("Undo")
            if not snap:
                print("[UNDO] Nothing to undo.")
                return

            # Use load_canvas_from_snapshot for snapshot dict
            self.undo_redo_helper()
            self.container.graphics.load_canvas_from_snapshot(snap, self.container)
            print(f"[UNDO] Scene restored → {len(snap.get('items', []))} items")

        except Exception as e:
            print("[DEBUG] Undo failed:", e)
        finally:
            # Update action states
            self.actionUndo.setEnabled(get_last_list('Undo') is not None)
            self.actionRedo.setEnabled(get_last_list('Redo') is not None)

    def redo(self):
        try:
            from python.utils.undo_manager import pop, push, get_last_list
            print("\n[REDO] Requested → Start")

            # Save current scene into Undo before redo (so redo can be undone)
            try:
                s_cur = self.container.graphics.save_canvas()
                if s_cur is not None:
                    push("Undo", s_cur)
                    print(f"[DEBUG] Redo: pushed current snapshot to Undo (items={len(s_cur.get('items', []))})")
            except Exception as e:
                print("[DEBUG] Redo: push current to Undo failed:", e)

            snap = pop("Redo")
            if not snap:
                print("[REDO] Nothing to redo.")
                return

            self.undo_redo_helper()
            self.container.graphics.load_canvas_from_snapshot(snap, self.container)
            print(f"[REDO] Scene restored → {len(snap.get('items', []))} items")

        except Exception as e:
            print("[DEBUG] Redo failed:", e)
        finally:
            self.actionUndo.setEnabled(get_last_list('Undo') is not None)
            self.actionRedo.setEnabled(get_last_list('Redo') is not None)


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
    