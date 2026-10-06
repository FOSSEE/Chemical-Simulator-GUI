import sys
import os
import pytest

# Ensure Python can find modules under src/main/python
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src', 'main', 'python')))

from utils.UnitOperations import Mixer, Splitter, Heater, Cooler, Flash, CentrifugalPump, Valve


# --------------------- MIXER TESTS --------------------- #

def test_mixer_default_initialization():
    """Verify Mixer instantiates with correct default attributes."""
    mixer = Mixer()
    assert mixer.type == 'Mixer'
    assert mixer.no_of_inputs == 2
    assert mixer.variables['NI']['value'] == 2
    assert mixer.variables['outPress']['value'] == 'Inlet_Average'
    assert 'Inlet_Minimum' in mixer.Pout_modes
    assert 'Inlet_Maximum' in mixer.Pout_modes


def test_mixer_param_setter():
    """Verify param_setter correctly updates input count and outlet pressure mode."""
    mixer = Mixer()
    mixer.param_setter([3, 'Inlet_Minimum'])
    
    assert mixer.no_of_inputs == 3
    assert mixer.variables['NI']['value'] == 3
    assert mixer.variables['outPress']['value'] == 'Inlet_Minimum'


def test_mixer_param_setter_edge_case():
    """Verify param_setter parses string input count into integer."""
    mixer = Mixer()
    mixer.param_setter(['4', 'Inlet_Maximum'])
    
    assert mixer.no_of_inputs == 4
    assert mixer.variables['NI']['value'] == 4
    assert mixer.variables['outPress']['value'] == 'Inlet_Maximum'


# --------------------- SPLITTER TESTS --------------------- #

def test_splitter_default_initialization():
    """Verify Splitter instantiates with standard defaults."""
    splitter = Splitter()
    assert splitter.type == 'Splitter'
    assert splitter.no_of_outputs == 2
    assert splitter.variables['No']['value'] == 2
    assert splitter.variables['CalcType']['value'] == 'Split_Ratio'
    assert splitter.variables['SpecVal_s']['value'] == [0.5, 0.5]


def test_splitter_param_setter_split_ratio():
    """Verify param_setter assigns split ratios correctly."""
    splitter = Splitter()
    splitter.param_setter([2, 'Split_Ratio', 0.7, 0.3])
    
    assert splitter.no_of_outputs == 2
    assert splitter.variables['CalcType']['value'] == 'Split_Ratio'
    assert splitter.variables['SpecVal_s']['value'] == [0.7, 0.3]
    assert splitter.variables['SpecVal_s']['unit'] == ''


def test_splitter_param_setter_molar_flow():
    """Verify param_setter updates units to mol/s for Molar_Flow mode."""
    splitter = Splitter()
    splitter.param_setter([2, 'Molar_Flow', 50.0, 50.0])
    
    assert splitter.variables['CalcType']['value'] == 'Molar_Flow'
    assert splitter.variables['SpecVal_s']['value'] == [50.0, 50.0]
    assert splitter.variables['SpecVal_s']['unit'] == 'mol/s'


def test_splitter_param_setter_mass_flow():
    """Verify param_setter updates units to g/s for Mass_Flow mode."""
    splitter = Splitter()
    splitter.param_setter([2, 'Mass_Flow', 10.5, 20.5])
    
    assert splitter.variables['CalcType']['value'] == 'Mass_Flow'
    assert splitter.variables['SpecVal_s']['value'] == [10.5, 20.5]
    assert splitter.variables['SpecVal_s']['unit'] == 'g/s'


# --------------------- HEATER & COOLER TESTS --------------------- #

def test_heater_default_initialization():
    """Verify Heater default state and variables."""
    heater = Heater()
    assert heater.type == 'Heater'
    assert heater.no_of_inputs == 1
    assert heater.no_of_outputs == 1
    assert heater.variables['Pdel']['value'] == 0
    assert heater.variables['Eff']['value'] == 1
    assert heater.variables['Tout']['value'] == 298.15


def test_cooler_default_initialization():
    """Verify Cooler default state and variables."""
    cooler = Cooler()
    assert cooler.type == 'Cooler'
    assert cooler.no_of_inputs == 1
    assert cooler.no_of_outputs == 1
    assert cooler.variables['Pdel']['value'] == 0
    assert cooler.variables['Eff']['value'] == 1


# --------------------- FLASH DRUM TESTS --------------------- #

def test_flash_default_initialization():
    """Verify Flash drum default specifications."""
    flash = Flash()
    assert flash.type == 'Flash'
    assert flash.no_of_inputs == 1
    assert flash.no_of_outputs == 2
    assert flash.thermo_pack_req is True
    assert flash.variables['Tdef']['value'] == 298.15
    assert flash.variables['Pdef']['value'] == 101325


def test_flash_param_setter():
    """Verify setting thermodynamic package and conditions for Flash."""
    flash = Flash()
    flash.param_setter(['Peng-Robinson', True, 350.0, True, 200000])
    
    assert flash.variables['thermo_package']['value'] == 'Peng-Robinson'
    assert flash.variables['BTdef']['value'] is True
    assert flash.variables['Tdef']['value'] == 350.0
    assert flash.variables['BPdef']['value'] is True
    assert flash.variables['Pdef']['value'] == 200000


# --------------------- PUMP & VALVE TESTS --------------------- #

def test_pump_default_initialization():
    """Verify Centrifugal Pump default parameters."""
    pump = CentrifugalPump()
    assert pump.type == 'CentrifugalPump'
    assert pump.variables['Eff']['value'] == 1
    assert 'Pdel' in pump.modes_list
    assert 'Pout' in pump.modes_list


def test_valve_default_initialization():
    """Verify Valve default parameters."""
    valve = Valve()
    assert valve.type == 'Valve'
    assert 'Pdel' in valve.modes_list
    assert 'Pout' in valve.modes_list