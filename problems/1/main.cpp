#include <iostream>

int main() {
  size_t result{0};
  for (size_t number{1}; number < 1000; ++number) {
    if (number % 3 == 0 || number % 5 == 0) {
      result += number;
    }
  }
  std::cout << result << std::endl;
}
