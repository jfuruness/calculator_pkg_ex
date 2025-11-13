from tqdm import trange
with open("nums.csv", "w") as f:
    for i in trange(10_000_000):
        f.write(f"{i}\n")
