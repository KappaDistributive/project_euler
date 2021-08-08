#include <iostream>

int main() {
  size_t sum_of_squares{0};
  size_t square_of_sums{0};

  for (size_t number{1}; number <= 100; ++number) {
    sum_of_squares += number * number;
    square_of_sums += number;
  }
  square_of_sums *= square_of_sums;

  std::cout << square_of_sums - sum_of_squares << std::endl;
}
