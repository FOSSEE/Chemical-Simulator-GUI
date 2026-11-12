
from decimal import Decimal, InvalidOperation, ROUND_HALF_UP


def format_result(value):
    """Format numeric result values to exactly two decimal places."""
    if isinstance(value, bool):
        return str(value)

    try:
        number = Decimal(str(value).strip())

        if not number.is_finite():
            return str(value)

        return str(
            number.quantize(
                Decimal("0.01"),
                rounding=ROUND_HALF_UP
            )
        )
    except (InvalidOperation, ValueError, TypeError, AttributeError):
        return str(value)
