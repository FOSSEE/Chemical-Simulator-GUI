import pytest


@pytest.fixture(autouse=True)
def flush_qt_events():
    """Process pending Qt events after every test, while the test's widgets
    still exist. Otherwise events queued for objects that are later garbage
    collected get delivered in a following test and crash with an access
    violation."""
    yield
    try:
        from PyQt5.QtWidgets import QApplication
    except ImportError:
        return
    app = QApplication.instance()
    if app is not None:
        app.processEvents()
