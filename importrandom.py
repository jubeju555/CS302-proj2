import random

sizes = [100000, 500000, 1000000, 10000000, 25000000]

for size in sizes:
    with open(f"input_{size}.txt", "w") as f:
        for _ in range(size):
            f.write(f"{random.randint(0, 1000000000)}\n")
