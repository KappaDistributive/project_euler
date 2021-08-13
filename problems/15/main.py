def fac(n: int) -> int:
  if n < 2:
    return 1
  else:
    return n * fac(n-1)


def bin(n: int, k: int) -> int:
  return fac(n) // (fac(k) * fac(n-k))


if __name__ == "__main__":
  print(bin(40, 20))
