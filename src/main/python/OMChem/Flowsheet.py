import os
import platform
import csv
from subprocess import Popen, PIPE
import pandas as pd

# ===============================
# Helper: Normalize compound name
# ===============================
_CHEMSEP_DB_DIR = os.path.abspath(
    os.path.join(os.path.dirname(os.path.realpath(__file__)), '..', '..', 'Simulator', 'Simulator', 'Files', 'ChemsepDatabase')
)
_chemsep_canonical_map = {}
if os.path.exists(_CHEMSEP_DB_DIR):
    for _fname in os.listdir(_CHEMSEP_DB_DIR):
        if _fname.endswith('.mo'):
            _base = _fname[:-3]
            _chemsep_canonical_map[_base.lower()] = _base


def _normalize_compound_name(name: str) -> str:
    """
    Converts any compound name into the corresponding Modelica identifier
    matching the ChemSep database model names in Simulator.Files.ChemsepDatabase.
    Example: 'Hydrogen cyanide' -> 'Hydrogencyanide'
             '1-Butanol' -> 'Onebutanol'
             '1,2-Dichloroethane' -> 'OneTwodichloroethane'
    """
    n = name.strip()
    if '(' in n and n.endswith(')'):
        n = n[:n.rfind('(')].strip()

    # Strip common punctuation/delimiters
    for ch in [' ', '-', ',', '/', '(', ')', '+', '.']:
        n = n.replace(ch, '')

    # Replace digits 1-5 with words matching ChemsepDatabase generation
    digit_map = {
        '1': 'One',
        '2': 'Two',
        '3': 'Three',
        '4': 'Four',
        '5': 'Five',
    }
    for digit, word in digit_map.items():
        n = n.replace(digit, word)

    # Remove any other non-alphanumeric characters
    n = ''.join(c for c in n if c.isalnum() or c == '_')

    # Match exact canonical casing from ChemsepDatabase if present
    canonical = _chemsep_canonical_map.get(n.lower())
    if canonical:
        return canonical

    # Ensure it starts with a letter
    if not n or not n[0].isalpha():
        n = 'C' + n
    return n


class Flowsheet():
    def __init__(self):
        self.sim_name = 'Simulator'  # folder name relative to src/main
        self.sim_method = ''
        self.unit_operations = []
        self.data = []
        self.compounds = []
        self.interface = ''
        self.omc_path = None

        # Base directory: src/main/python/OMChem (depends on where this file is)
        self.root_dir = os.path.dirname(os.path.realpath(__file__))

        # ✅ First define sim_dir_path (inner Simulator folder)
        self.sim_dir_path = os.path.abspath(
            os.path.join(self.root_dir, '..', '..', 'Simulator', 'Simulator')
        )

        # ✅ Ensure folder exists
        if not os.path.exists(self.sim_dir_path):
            os.makedirs(self.sim_dir_path)

        # Paths for generated files
        self.Flomo_path = os.path.join(self.sim_dir_path, 'Flowsheet.mo')
        self.eqn_mos_path = os.path.join(self.sim_dir_path, 'simulateEQN.mos')
        self.sm_mos_path = os.path.join(self.sim_dir_path, 'simulateSM.mos')

        # Result placeholders
        self.result_data = []
        self.stdout = None
        self.stderr = None
        self.last_error = ''

    def _decode_process_output(self, output):
        if not output:
            return ''
        try:
            return output.decode("utf-8", errors="replace")
        except Exception:
            return str(output)

    def _extract_omc_error(self, stdout_text='', stderr_text=''):
        combined = "\n".join(text for text in [stderr_text, stdout_text] if text)
        if not combined.strip():
            return ''

        lines = [line.strip() for line in combined.splitlines() if line.strip()]
        error_lines = []
        for index, line in enumerate(lines):
            if any(marker in line.lower() for marker in ['error', 'failed', 'exception']):
                for detail_line in lines[index:index + 4]:
                    if detail_line.lower().startswith('geterrorstring()') and detail_line.endswith('""'):
                        continue
                    if detail_line not in error_lines:
                        error_lines.append(detail_line)
                    if len(error_lines) >= 6:
                        break
            if len(error_lines) >= 6:
                break

        if not error_lines:
            return ''

        return "\n".join(error_lines[:6])

    def get_omc_path(self, msg=None):
        import platform
        import glob

        if platform.system() == "Windows":
            # Try to find the latest OpenModelica installation dynamically
            pattern = r"C:\Program Files\OpenModelica*-64bit\bin\omc.exe"
            candidates = sorted(glob.glob(pattern), reverse=True)
            omc_path = candidates[0] if candidates else r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"
        else:
            omc_path = "/usr/bin/omc"

        if not os.path.exists(omc_path):
            if msg:
                msg.append(f"<span style='color:red'>OMC not found at {omc_path}</span>")
            raise FileNotFoundError(f"OMC not found at {omc_path}")

        return omc_path


    def add_unit_operations(self,unitop):
        self.unit_operations.append(unitop)

    def remove_unit_operations(self,unitop):
        self.unit_operations.remove(unitop)

    def add_compound_list(self,C):
        self.compounds = C
    
    def send_for_simulation_Eqn(self,msg):
        self.result_data = []
        self.last_error = ''
        self.omc_path = self.get_omc_path(msg)
        #print(self.omc_path)
        
        if self.sim_method == 'Eqn':
            simpath = self.eqn_mos_path
            os.chdir(self.sim_dir_path)
            csvpath = os.path.join(self.sim_dir_path,'Simulator.Flowsheet.FlowsheetSimulation_res.csv')
            if os.path.exists(csvpath):
                os.remove(csvpath)
            if platform.system() == "Windows":
                from subprocess import STARTUPINFO, STARTF_USESHOWWINDOW

                startupinfo = STARTUPINFO()
                startupinfo.dwFlags |= STARTF_USESHOWWINDOW

                self.process = Popen(
                    [self.omc_path, '-s', simpath],
                    stdout=PIPE,
                    stderr=PIPE,
                    startupinfo=startupinfo
                )
            else:
                self.process = Popen(
                    [self.omc_path, '-s', simpath],
                    stdout=PIPE,
                    stderr=PIPE
                )
            self.stdout, self.stderr = self.process.communicate()

            print("===== STDOUT =====")
            stdout_text = self._decode_process_output(self.stdout)
            print(stdout_text)

            print("===== STDERR =====")
            stderr_text = self._decode_process_output(self.stderr)
            print(stderr_text)
           
            os.chdir(self.root_dir)
            csvpath = os.path.join(self.sim_dir_path,'Simulator.Flowsheet.FlowsheetSimulation_res.csv')
            if 'timeSimulation = 0.0,\n' in stdout_text or not os.path.exists(csvpath):
                self.result_data = []
                self.last_error = self._extract_omc_error(stdout_text, stderr_text)
            else:
                with open (csvpath,'r') as resultFile:
                    self.result_data = []
                    csvreader = csv.reader(resultFile,delimiter=',')
                    for row in csvreader:
                        self.result_data.append(row)
                self.ext_data()

    def send_for_simulation_SM(self,unitop):
        self.result_data = []
        self.last_error = ''
        self.omc_path = self.get_omc_path()
        os.chdir(self.sim_dir_path)
        self.process = Popen([self.omc_path, '-s',unitop.name,'.mos'], stdout=PIPE, stderr=PIPE)
        stdout, stderr = self.process.communicate()
        stdout_text = self._decode_process_output(stdout)
        stderr_text = self._decode_process_output(stderr)
        self.stdout = stdout
        self.stderr = stderr
        # print("############### StdOut ################")
        # print(stdout)
        self.result_data = []
        #print('Simulating '+unitop.name+'...')
        csvpath = os.path.join(self.sim_dir_path,unitop.name+'_res.csv')
        if not os.path.exists(csvpath):
            self.last_error = self._extract_omc_error(stdout_text, stderr_text)
            return
        with open(csvpath,'r') as resultFile:
            csvreader = csv.reader(resultFile,delimiter=',')
            for row in csvreader:
                self.result_data.append(row)
        self.ext_data()

    def ext_data(self):
        if not self.result_data or len(self.result_data) < 2:
            print("[DEBUG] ext_data: result_data has no data rows, skipping")
            return
        for unit in self.unit_operations:
            unitop = unit[0] if isinstance(unit, list) else unit
            if unitop.type == 'MaterialStream':
                for key in list(unitop.variables.keys()):
                    property_name = unitop.name + '.' + key
                    if property_name in self.result_data[0]:
                        ind = self.result_data[0].index(property_name)
                        try:
                            unitop.variables[key]['value'] = str(self.result_data[-1][ind])
                        except (IndexError, KeyError) as e:
                            print(f"[DEBUG] ext_data: failed to read {property_name}: {e}")

             
    def simulate_EQN(self, msg):
        self.data = []
        self.sim_method = 'Eqn'

        # Use the main unit name for package naming (e.g. Mixer)
        main_unit = None
        for u in self.unit_operations:
            if hasattr(u, 'type') and u.type != 'MaterialStream':
                main_unit = u
                break

        package_name = "Flowsheet"

        # --- Start Package ---
        self.data.append("within Simulator;\n\n")
        self.data.append(f"package {package_name}\n\n")

        # --- Define reusable ms model ---
        self.data.append("  model ms\n")
        self.data.append("    extends Simulator.Streams.MaterialStream;\n")
        self.data.append("    extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;\n")
        self.data.append("  end ms;\n\n")

        # --- Start Simulation model ---
        self.data.append(f"  model {package_name}Simulation \n")
        self.data.append("    import data = Simulator.Files.ChemsepDatabase;\n")

        # --- Normalize compound names ---
        orig_compounds = self.compounds.copy()
        norm_compounds = []

        for c in orig_compounds:
            nid = _normalize_compound_name(c)
            norm_compounds.append(nid)

        Nc = len(norm_compounds)

        # --- Parameter declarations ---
        for norm in norm_compounds:
            self.data.append(f"    parameter data.{norm} {norm};\n")

        self.data.append(f"    parameter Integer Nc = {Nc};\n")
        self.data.append(f"    parameter data.GeneralProperties C[Nc] = {{{', '.join(norm_compounds)}}};\n")

        # --- Define streams and unit ops ---
        for unitop in self.unit_operations:
            if unitop.type == 'MaterialStream':
                self.data.append(f"    ms {unitop.name}(Nc = {Nc}, C = {{{', '.join(norm_compounds)}}});\n")
            else:
                self.data.append(f"    {unitop.OM_Flowsheet_Initialize()}\n")

        # --- Equations section ---
        self.data.append("\n  equation\n")
        
        # Determine output streams to avoid overdetermining the system
        output_stream_names = set()
        for unitop in self.unit_operations:
            if unitop.type != 'MaterialStream':
                outstms = getattr(unitop, 'output_stms', None)
                if isinstance(outstms, dict):
                    outstms = outstms.values()
                if outstms:
                    for stm in outstms:
                        if hasattr(stm, 'name'):
                            output_stream_names.add(stm.name)

        for unitop in self.unit_operations:
            if unitop.type == 'MaterialStream':
                if unitop.name in output_stream_names:
                    self.data.append(f"    // Output Stream {unitop.name} property equations are skipped\n")
                else:
                    self.data.append(unitop.OM_Flowsheet_Equation(norm_compounds, 'Eqn'))
            else:
                self.data.append(unitop.OM_Flowsheet_Equation())

        # --- End Simulation model ---
        self.data.append(f"  end {package_name}Simulation;\n")
        # --- End Package ---
        self.data.append(f"end {package_name};\n")

        # --- Write to file ---
        with open(self.Flomo_path, 'w') as txtfile:
            for d in self.data:
                txtfile.write(str(d))

        # --- Generate the simulation .mos file ---
        with open(self.eqn_mos_path, 'w') as mosFile:
            mosFile.write('loadModel(Modelica);\n')
            mosFile.write('loadFile("package.mo");\n')
            mosFile.write('loadFile("Flowsheet.mo");\n')
            mosFile.write(f'simulate(Simulator.{package_name}.{package_name}Simulation, outputFormat="csv", stopTime=1.0, numberOfIntervals=1);\n')
            mosFile.write('getErrorString();\n')

        # --- Ensure Flowsheet is listed in package.order ---
        # OMC v1.26.3+ (Modelica 4.x) requires all .mo files in a package
        # directory to be listed in package.order, otherwise the entire
        # package fails to load.
        order_path = os.path.join(self.sim_dir_path, 'package.order')
        if os.path.exists(order_path):
            with open(order_path, 'r') as f:
                order_lines = [line.strip() for line in f if line.strip()]
            if 'Flowsheet' not in order_lines:
                order_lines.append('Flowsheet')
                with open(order_path, 'w') as f:
                    f.write('\n'.join(order_lines) + '\n')

        # --- Clean up stray .mo files from previous runs ---
        # Files not part of the Simulator library but left in the package
        # directory will cause OMC to reject the entire package.
        known_library_entries = set(order_lines) if os.path.exists(order_path) else set()
        known_library_entries.update(['package.mo', 'package.order',
                                      'Flowsheet.mo', 'simulateEQN.mos', 'simulateSM.mos'])
        for stray in os.listdir(self.sim_dir_path):
            stray_path = os.path.join(self.sim_dir_path, stray)
            if (os.path.isfile(stray_path)
                    and stray.endswith('.mo')
                    and stray not in known_library_entries
                    and stray.replace('.mo', '') not in known_library_entries):
                os.remove(stray_path)

        # --- Run simulation ---
        self.send_for_simulation_Eqn(msg)



    def simulate_SM(self, ip, op):
        self.sim_method = 'SM'
        self.data = []
        self.result_data = []
        self.unit = []
        self.csvlist = []
        self.last_error = ''

        # --- Determine execution order based on ip and op ---
        for i in ip:
            common = ip[i]
            for k, v in op.items():
                if set(v) & set(common):
                    if (i in self.unit) and (k in self.unit):
                        pass
                    elif i in self.unit:
                        self.unit.insert(self.unit.index(i), k)
                    elif k in self.unit:
                        self.unit.append(i)
                    else:
                        self.unit.append(k)
                        self.unit.append(i)

        # Build lookup table to resolve string names to unit operation objects
        unit_map = {getattr(uo, 'name', None): uo for uo in self.unit_operations}

        # --- Helper function to safely extract stream lists ---
        def safe_streams(stms):
            if stms is None:
                return []
            if isinstance(stms, dict):
                stms = list(stms.values())
            elif not isinstance(stms, list):
                stms = [stms]
            return [s for s in stms if s is not None]

        # --- Normalize compound names once ---
        orig_compounds = self.compounds.copy() if self.compounds else []
        norm_compounds = [_normalize_compound_name(c) for c in orig_compounds]
        nc = len(norm_compounds)

        # --- Loop over each unit operation in topological order ---
        for item in self.unit:
            unitop = unit_map.get(item, item)
            if not hasattr(unitop, 'type') or unitop.type in ['MaterialStream', 'EngStm']:
                continue

            os.chdir(self.root_dir)
            self.data = []

            inpstms = safe_streams(getattr(unitop, 'input_stms', None))
            outstms = safe_streams(getattr(unitop, 'output_stms', None))
            engstms = safe_streams(getattr(unitop, 'EngStms', None))
            all_stms = inpstms + outstms + engstms

            model_name = unitop.name.lower()

            # --- Modelica Header & Definitions ---
            self.data.append("within Simulator;\n\n")
            self.data.append(f"model {model_name}\n")
            self.data.append("  import data = Simulator.Files.ChemsepDatabase;\n")
            self.data.append("  model ms\n")
            self.data.append("    extends Simulator.Streams.MaterialStream;\n")
            self.data.append("    extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;\n")
            self.data.append("  end ms;\n\n")

            # --- Define compounds & parameters ---
            for norm in norm_compounds:
                self.data.append(f"  parameter data.{norm} {norm};\n")
            self.data.append(f"  parameter Integer Nc = {nc};\n")
            self.data.append(f"  parameter data.GeneralProperties C[Nc] = {{{', '.join(norm_compounds)}}};\n\n")

            # --- Initialize Unit Operation ---
            self.data.append(f"  {unitop.OM_Flowsheet_Initialize()}\n")

            # --- Initialize Streams ---
            for stm in all_stms:
                if getattr(stm, 'type', '') == 'MaterialStream':
                    self.data.append(f"  ms {stm.name}(Nc = {nc}, C = {{{', '.join(norm_compounds)}}});\n")
                else:
                    self.data.append(f"  {stm.OM_Flowsheet_Initialize()}\n")

            # --- Equations Section ---
            self.data.append("\nequation\n")
            self.data.append(f"  {unitop.OM_Flowsheet_Equation()}\n")

            # Output streams have their state determined by the unit; only input streams get feed equations
            out_names = {s.name for s in outstms if hasattr(s, 'name')}
            for stm in all_stms:
                if stm.name not in out_names:
                    self.data.append(f"  {stm.OM_Flowsheet_Equation(norm_compounds, 'SM')}\n")

            self.data.append(f"end {model_name};\n")

            # --- Write Unit .mo File ---
            unitmofile = os.path.join(self.sim_dir_path, f"{model_name}.mo")
            with open(unitmofile, 'w', encoding='utf-8') as unitFile:
                for line in self.data:
                    unitFile.write(str(line))

            # --- Write Unit .mos Simulation Script ---
            unitmosfile = os.path.join(self.sim_dir_path, f"{model_name}.mos")
            with open(unitmosfile, 'w', encoding='utf-8') as mosFile:
                mosFile.write('loadModel(Modelica);\n')
                mosFile.write('loadFile("package.mo");\n')
                mosFile.write(f'loadFile("{model_name}.mo");\n')
                mosFile.write(f'simulate(Simulator.{model_name}, outputFormat="csv", stopTime=1.0, numberOfIntervals=1);\n')
                mosFile.write('getErrorString();\n')

            # --- Run OMC Simulation Process ---
            self.omc_path = self.get_omc_path()
            os.chdir(self.sim_dir_path)
            self.process = Popen([self.omc_path, '-s', f"{model_name}.mos"], stdout=PIPE, stderr=PIPE)
            self.stdout, self.stderr = self.process.communicate()
            os.chdir(self.root_dir)

            stdout_text = self._decode_process_output(self.stdout)
            stderr_text = self._decode_process_output(self.stderr)

            # --- Process CSV Results ---
            csvpath = os.path.join(self.sim_dir_path, f"Simulator.{model_name}_res.csv")
            if not os.path.exists(csvpath):
                # Fallback to alternate naming convention
                csvpath = os.path.join(self.sim_dir_path, f"{model_name}_res.csv")

            if os.path.exists(csvpath):
                self.csvlist.append(csvpath)
                with open(csvpath, 'r', encoding='utf-8') as resultFile:
                    csvreader = csv.reader(resultFile, delimiter=',')
                    self.result_data = list(csvreader)
            else:
                self.last_error = self._extract_omc_error(stdout_text, stderr_text)
                print(f"[DEBUG] Sequential unit {model_name} simulation produced no CSV.")
                return

            # --- Transfer Output Properties to Successor Streams ---
            for stm in all_stms:
                if not hasattr(stm, 'Prop') or stm.Prop is None:
                    continue
                for key in list(stm.Prop.keys()):
                    property_name = f"{stm.name}.{key}"
                    if self.result_data and property_name in self.result_data[0]:
                        ind = self.result_data[0].index(property_name)
                        stm.Prop[key] = str(self.result_data[-1][ind])

        # --- Aggregate All Results into FlowsheetSEQ.csv ---
        self.dataframes = [pd.read_csv(f) for f in self.csvlist if os.path.exists(f)]
        os.chdir(self.sim_dir_path)
        if self.dataframes:
            dffinal = pd.concat(self.dataframes, axis=1)
            dffinal.to_csv('FlowsheetSEQ.csv', index=False)
            self.result_data.clear()
            with open(os.path.join(self.sim_dir_path, 'FlowsheetSEQ.csv'), 'r', encoding='utf-8') as resultFile:
                csvreader = csv.reader(resultFile, delimiter=',')
                self.result_data = list(csvreader)