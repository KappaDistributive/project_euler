def fac(n: int) -> int:
    if n < 2:
        return 1
    return n * fac(n - 1)


if __name__ == "__main__":
    print(sum([int(digit) for digit in str(fac(100))]))
