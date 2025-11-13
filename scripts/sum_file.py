from tqdm import tqdm
from pathlib import Path
def func() -> int:
    with tqdm(total=100_000_000, desc="running") as pbar:
        total = None
        with open("/home/anon/Desktop/nums.csv") as f:
            for line in f:
                if total is None:
                    total = line
                    continue
                total += line
                pbar.update()
        return total
# func()
from calculator_pkg_ex import CPPFileCalculator
import time
start = time.perf_counter()
CPPFileCalculator().sum_file(str(Path("~/Desktop/nums.csv").expanduser()))
print(time.perf_counter() - start)
