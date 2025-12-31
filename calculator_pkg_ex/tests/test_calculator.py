from ..calculator import Calculator
# from calculator_pkg_ex import Calculator

import pytest


class TestCalculator:
    def test_add(self) -> None:
        assert Calculator().add(1, 2) == 3, "Add failed"

    def test_subtract(self) -> None:
        assert Calculator().subtract(1, 2) == -1, "Subtract failed"

    def test_multiply(self) -> None:
        assert Calculator().multiply(3, 2) == 6, "Multiply failed"

    def test_divide(self) -> None:
        assert Calculator().divide(8, 2) == 4, "Divide Failed"

    def test_divide_zero(self) -> None:
        with pytest.raises(ZeroDivisionError):
            Calculator().divide(8, 0)
