from typing import List

def fibonacci_number_sequence(upper_bound: int) -> List[int]:
  result = [1, 1]
  next_entry = result[-1] + result[-2]
  while next_entry <= upper_bound:
    result.append(next_entry)
    next_entry = result[-1] + result[-2]

  return result


if __name__ == "__main__":
  fibonacci_sequence = fibonacci_number_sequence(10**999)
  print(len(fibonacci_sequence) + 1)

