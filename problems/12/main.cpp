#include <iostream>

size_t num_divisor(size_t number) {
  size_t result{0};
  for (size_t divisor{1}; divisor <= number; ++divisor) {
    result += static_cast<size_t>(number % divisor == 0);
  }

  return result;
}

int main() {
  size_t candidate{0};
  size_t step{1};
  while (true) {
    if (num_divisor(candidate) > 500) {
      std::cout << candidate << ": " << num_divisor(candidate) << std::endl;
      return 0;
    }
    candidate += step++;
  }
}
