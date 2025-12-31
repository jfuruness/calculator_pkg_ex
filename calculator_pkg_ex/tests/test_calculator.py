from ..calculator import Calculator
# from calculator_pkg_ex import Calculator

import pytest

class TestCalculator:
    def test_add(self):
        assert Calculator().add(1, 2) == 3, "Add failed"

    def test_subtract(self):
        assert Calculator().subtract(1, 2) == -1, "Subtract failed"
    
    def test_multiply(self):
        assert Calculator().multiply(3, 2) == 6, "Multiply failed"

    def test_divide(self):
        assert Calculator().divide(8, 2) == 4, "Divide Failed"

    def test_divide_zero(self):
        with pytest.raises(ZeroDivisionError):
            Calculator().divide(8, 0)