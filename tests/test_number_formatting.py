import os
import sys
import unittest

PROJECT_ROOT = os.path.abspath(
    os.path.join(os.path.dirname(__file__), '..')
)
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from python.utils.NumberFormatting import format_result


class TestNumberFormatting(unittest.TestCase):

    def test_integer(self):
        self.assertEqual(format_result(12), "12.00")

    def test_float(self):
        self.assertEqual(format_result(12.3), "12.30")

    def test_round_half_up(self):
        self.assertEqual(format_result(12.345), "12.35")

    def test_round_small_value(self):
        self.assertEqual(format_result(0.999), "1.00")

    def test_negative_number(self):
        self.assertEqual(format_result(-12.345), "-12.35")

    def test_scientific_notation(self):
        self.assertEqual(format_result("1.2345e-3"), "0.00")

    def test_non_numeric_string(self):
        self.assertEqual(format_result("Water"), "Water")

    def test_none(self):
        self.assertEqual(format_result(None), "None")

    def test_boolean(self):
        self.assertEqual(format_result(True), "True")


if __name__ == "__main__":
    unittest.main()