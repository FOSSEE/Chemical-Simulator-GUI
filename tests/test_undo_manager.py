import os
import sys
import pickle
import shutil
import tempfile
import unittest
from unittest.mock import patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))

from python.utils import undo_manager


class TestUndoManager(unittest.TestCase):
    """Unit tests for the file-based Undo/Redo stack in utils/undo_manager.py."""

    def setUp(self):
        # Redirect all stack files to a throwaway folder so tests never touch
        # the real Simulator/undo_redo directory.
        self.tmp_dir = tempfile.mkdtemp()
        self.undo_path = os.path.join(self.tmp_dir, "undo_redo")
        self.path_patch = patch.object(undo_manager, "UNDO_PATH", self.undo_path)
        self.path_patch.start()

    def tearDown(self):
        self.path_patch.stop()
        shutil.rmtree(self.tmp_dir, ignore_errors=True)

    def _stack_file(self, name):
        return os.path.join(self.undo_path, f"{name}.pkl")

    # -------------------------------------------------------------------------
    # 1. push / pop basics
    # -------------------------------------------------------------------------

    def test_pop_returns_items_in_lifo_order(self):
        undo_manager.push("Undo", {"step": 1})
        undo_manager.push("Undo", {"step": 2})
        undo_manager.push("Undo", {"step": 3})

        self.assertEqual(undo_manager.pop("Undo"), {"step": 3})
        self.assertEqual(undo_manager.pop("Undo"), {"step": 2})
        self.assertEqual(undo_manager.pop("Undo"), {"step": 1})

    def test_pop_on_empty_stack_returns_none(self):
        self.assertIsNone(undo_manager.pop("Undo"))

    def test_pop_after_stack_is_drained_returns_none(self):
        undo_manager.push("Undo", [1])
        undo_manager.pop("Undo")
        self.assertIsNone(undo_manager.pop("Undo"))
        self.assertEqual(undo_manager.stack_size("Undo"), 0)

    def test_push_none_is_ignored(self):
        undo_manager.push("Undo", None)
        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        self.assertFalse(os.path.exists(self._stack_file("Undo")))

    def test_push_accepts_falsy_but_not_none_data(self):
        undo_manager.push("Undo", [])
        undo_manager.push("Undo", 0)
        self.assertEqual(undo_manager.stack_size("Undo"), 2)

    def test_push_stores_a_deep_copy(self):
        snapshot = {"units": [{"name": "Mixer1"}]}
        undo_manager.push("Undo", snapshot)

        # Mutating the caller's object must not change the stored snapshot
        snapshot["units"][0]["name"] = "Changed"
        snapshot["units"].append({"name": "Extra"})

        self.assertEqual(undo_manager.pop("Undo"), {"units": [{"name": "Mixer1"}]})

    def test_push_creates_directory_and_file(self):
        self.assertFalse(os.path.isdir(self.undo_path))
        undo_manager.push("Undo", "snap")
        self.assertTrue(os.path.isfile(self._stack_file("Undo")))

    def test_push_leaves_no_temp_file_behind(self):
        undo_manager.push("Undo", "snap")
        self.assertEqual(os.listdir(self.undo_path), ["Undo.pkl"])

    def test_stack_persists_on_disk(self):
        undo_manager.push("Undo", "a")
        undo_manager.push("Undo", "b")
        with open(self._stack_file("Undo"), "rb") as f:
            self.assertEqual(pickle.load(f), ["a", "b"])

    def test_undo_and_redo_stacks_are_independent(self):
        undo_manager.push("Undo", "u1")
        undo_manager.push("Redo", "r1")
        undo_manager.push("Redo", "r2")

        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.stack_size("Redo"), 2)
        self.assertEqual(undo_manager.pop("Undo"), "u1")
        self.assertEqual(undo_manager.stack_size("Redo"), 2)

    # -------------------------------------------------------------------------
    # 2. get_last_list / stack_size
    # -------------------------------------------------------------------------

    def test_get_last_list_returns_top_without_popping(self):
        undo_manager.push("Undo", "first")
        undo_manager.push("Undo", "second")

        self.assertEqual(undo_manager.get_last_list("Undo"), "second")
        self.assertEqual(undo_manager.stack_size("Undo"), 2)

    def test_get_last_list_on_empty_stack_returns_none(self):
        self.assertIsNone(undo_manager.get_last_list("Undo"))

    def test_get_last_list_returns_a_copy(self):
        undo_manager.push("Undo", {"units": ["Mixer1"]})
        top = undo_manager.get_last_list("Undo")
        top["units"].append("Heater1")

        self.assertEqual(undo_manager.get_last_list("Undo"), {"units": ["Mixer1"]})

    def test_stack_size_tracks_push_and_pop(self):
        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        for i in range(5):
            undo_manager.push("Undo", i)
        self.assertEqual(undo_manager.stack_size("Undo"), 5)
        undo_manager.pop("Undo")
        self.assertEqual(undo_manager.stack_size("Undo"), 4)

    # -------------------------------------------------------------------------
    # 3. clean_file / reset_all
    # -------------------------------------------------------------------------

    def test_clean_file_removes_stack(self):
        undo_manager.push("Undo", "snap")
        undo_manager.clean_file("Undo")

        self.assertFalse(os.path.exists(self._stack_file("Undo")))
        self.assertEqual(undo_manager.stack_size("Undo"), 0)

    def test_clean_file_on_missing_file_does_not_raise(self):
        undo_manager.clean_file("DoesNotExist")

    def test_clean_file_only_affects_named_stack(self):
        undo_manager.push("Undo", "u")
        undo_manager.push("Redo", "r")
        undo_manager.clean_file("Redo")

        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.stack_size("Redo"), 0)

    def test_clean_file_swallows_os_errors(self):
        undo_manager.push("Undo", "snap")
        with patch.object(undo_manager.os, "remove", side_effect=PermissionError("locked")):
            undo_manager.clean_file("Undo")
        # File is still there because removal failed, but no exception escaped
        self.assertEqual(undo_manager.stack_size("Undo"), 1)

    def test_reset_all_clears_both_stacks(self):
        undo_manager.push("Undo", "u")
        undo_manager.push("Redo", "r")
        undo_manager.reset_all()

        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        self.assertEqual(undo_manager.stack_size("Redo"), 0)

    # -------------------------------------------------------------------------
    # 4. swap_to_redo
    # -------------------------------------------------------------------------

    def test_swap_to_redo_moves_top_snapshot(self):
        undo_manager.push("Undo", "s1")
        undo_manager.push("Undo", "s2")
        undo_manager.swap_to_redo()

        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.get_last_list("Undo"), "s1")
        self.assertEqual(undo_manager.get_last_list("Redo"), "s2")

    def test_swap_to_redo_with_empty_undo_does_nothing(self):
        undo_manager.swap_to_redo()
        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        self.assertEqual(undo_manager.stack_size("Redo"), 0)

    def test_swap_to_redo_repeatedly_reverses_order(self):
        for s in ("s1", "s2", "s3"):
            undo_manager.push("Undo", s)
        for _ in range(3):
            undo_manager.swap_to_redo()

        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        self.assertEqual(
            [undo_manager.pop("Redo") for _ in range(3)],
            ["s1", "s2", "s3"],
        )

    # -------------------------------------------------------------------------
    # 5. Error handling: corrupt or unexpected files
    # -------------------------------------------------------------------------

    def test_corrupt_file_is_treated_as_empty_stack(self):
        os.makedirs(self.undo_path)
        with open(self._stack_file("Undo"), "wb") as f:
            f.write(b"not a pickle")

        self.assertEqual(undo_manager.stack_size("Undo"), 0)
        self.assertIsNone(undo_manager.pop("Undo"))

    def test_non_list_pickle_is_treated_as_empty_stack(self):
        os.makedirs(self.undo_path)
        with open(self._stack_file("Undo"), "wb") as f:
            pickle.dump({"not": "a list"}, f)

        self.assertEqual(undo_manager.stack_size("Undo"), 0)

    def test_push_recovers_from_corrupt_file(self):
        os.makedirs(self.undo_path)
        with open(self._stack_file("Undo"), "wb") as f:
            f.write(b"garbage")

        undo_manager.push("Undo", "fresh")
        self.assertEqual(undo_manager.get_last_list("Undo"), "fresh")
        self.assertEqual(undo_manager.stack_size("Undo"), 1)

    def test_failed_save_keeps_previous_stack(self):
        undo_manager.push("Undo", "good")
        # A lambda can be deep-copied but not pickled, so the save step fails
        undo_manager.push("Undo", lambda: None)

        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.get_last_list("Undo"), "good")


if __name__ == "__main__":
    unittest.main()
