import random

if __name__ == "__main__":
    ARRAY_SIZE = 50
    array = [random.randint(1, 100) for _ in range(ARRAY_SIZE)]
    with open("array.txt", "w") as f:
        f.write(f"{ARRAY_SIZE}\n")
        f.write("\n".join(map(str, array)))