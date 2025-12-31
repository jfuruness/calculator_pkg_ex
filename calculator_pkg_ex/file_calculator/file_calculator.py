from pathlib import Path

# from tqdm import tqdm

from ..calculator import Calculator
# from calculator_pkg_ex.calculator import Calculator

class FileCalculator(Calculator):
    def __init__(
        self,
        path: Path = Path(__file__).parent / "nums.csv",
    ) -> None:
        self.path: Path = path

    def add_file(self) -> int | None:
        total: int | None = None
        with open(self.path) as f:
            for line in f:
                if total is None:
                    total = int(line)
                    continue
                else:
                    total += int(line)
        return total