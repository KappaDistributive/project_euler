#include <iostream>
#include <vector>

auto fibonacci(size_t upper_bound) {
  std::vector<size_t> fibonacci_sequence{1, 2};
  size_t candidate = fibonacci_sequence[fibonacci_sequence.size() - 1] +
                     fibonacci_sequence[fibonacci_sequence.size() - 2];
  while (candidate <= upper_bound) {
    fibonacci_sequence.push_back(candidate);
    candidate = fibonacci_sequence[fibonacci_sequence.size() - 1] +
                fibonacci_sequence[fibonacci_sequence.size() - 2];
  }
  return fibonacci_sequence;
}

int main() {
  auto fibonacci_sequence = fibonacci(4000000);
  size_t result{0};
  for (auto fib : fibonacci_sequence) {
    if (fib % 2 == 0) {
      result += fib;
    }
  }
  std::cout << result << std::endl;
}
