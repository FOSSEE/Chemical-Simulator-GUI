import os
import pickle
import copy

_BASE_DIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
UNDO_PATH = os.path.join(_BASE_DIR, "Simulator", "undo_redo")


# -------------------- Internal Helpers -------------------- #
def _load_stack(file_name):
    """Internal: load stack from file safely."""
    file_path = os.path.join(UNDO_PATH, f"{file_name}.pkl")
    if not os.path.exists(file_path):
        return []

    try:
        with open(file_path, "rb") as f:
            stack = pickle.load(f)
            if not isinstance(stack, list):
                print(f"[DEBUG] UndoManager._load_stack → invalid format (not list)")
                return []
            return stack
    except Exception as e:
        print(f"[DEBUG] UndoManager._load_stack failed → {e}")
        return []


def _save_stack(file_name, stack):
    """Internal: save stack to file safely."""
    os.makedirs(UNDO_PATH, exist_ok=True)
    file_path = os.path.join(UNDO_PATH, f"{file_name}.pkl")

    try:
        # Use temp file for atomic writes (prevents corruption on crash)
        tmp_path = file_path + ".tmp"
        with open(tmp_path, "wb") as f:
            pickle.dump(stack, f)
        os.replace(tmp_path, file_path)
    except Exception as e:
        print(f"[DEBUG] UndoManager._save_stack failed → {e}")


# -------------------- Public Interface -------------------- #
def push(file_name, data):
    """Push snapshot to Undo/Redo stack (file-based)."""
    if data is None:
        print(f"[DEBUG] UndoManager.push → skipped (None data)")
        return

    stack = _load_stack(file_name)
    stack.append(copy.deepcopy(data))
    _save_stack(file_name, stack)
    print(f"[DEBUG] UndoManager.push → file='{file_name}', stack_size={len(stack)}")


def pop(file_name):
    """Pop last snapshot from stack and return it."""
    stack = _load_stack(file_name)
    if not stack:
        print(f"[DEBUG] UndoManager.pop → file='{file_name}', stack empty")
        return None

    data = stack.pop()
    _save_stack(file_name, stack)
    print(f"[DEBUG] UndoManager.pop → file='{file_name}', remaining={len(stack)}")
    return data


def get_last_list(file_name):
    """Return top snapshot from the stack (without popping)."""
    stack = _load_stack(file_name)
    if not stack:
        print(f"[DEBUG] UndoManager.get_last_list → {file_name} empty")
        return None
    return copy.deepcopy(stack[-1])


def stack_size(file_name):
    """Return the number of snapshots currently in the stack."""
    return len(_load_stack(file_name))


def clean_file(file_name):
    """Clear Undo/Redo stack (both memory + file)."""
    file_path = os.path.join(UNDO_PATH, f"{file_name}.pkl")
    try:
        if os.path.exists(file_path):
            os.remove(file_path)
        print(f"[DEBUG] UndoManager.clean_file → cleared {file_name}")
    except Exception as e:
        print(f"[DEBUG] UndoManager.clean_file failed → {e}")


# -------------------- Optional Convenience -------------------- #
def reset_all():
    """Utility: clear both Undo and Redo stacks."""
    clean_file("Undo")
    clean_file("Redo")


def swap_to_redo():
    """
    Utility: move current snapshot from Undo → Redo.
    Used automatically during Undo operations.
    """
    last = get_last_list("Undo")
    if last:
        push("Redo", last)
        pop("Undo")
        print("[DEBUG] UndoManager.swap_to_redo → moved top from Undo → Redo")
