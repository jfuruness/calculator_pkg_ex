from tqdm import tqdm
def func() -> int:
    with tqdm(total=100_000_000, desc="running") as pbar:
        total = None
        with open("nums.csv") as f:
            for line in f:
                if total is None:
                    total = line
                    continue
                total += line
                pbar.update()
        return total
func()
