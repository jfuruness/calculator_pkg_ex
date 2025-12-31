from pathlib import Path

# from tqdm import tqdm

from ..calculator import Calculator
# from calculator_pkg_ex.calculator import Calculator

class FileCalculator(Calculator):
    def __init__(
        self,
        path=Path(__file__).parent / "nums.csv",
    ):
        self.path = path

    def add_file(self):
        total = None
        with open(self.path) as f:
            for line in f:
                if total is None:
                    total = line
                    continue
                else:
                    total += line
        return total