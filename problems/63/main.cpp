#include <cmath>
#include <iostream>

size_t my_pow(const size_t base, const size_t exponent) {
  if (exponent == 0) {
    return 1;
  }
  return base * my_pow(base, exponent - 1);
}

int main() {
  size_t answer{0};
  for (size_t base{1}; base < 10; ++base) {
    for (size_t exponent{1}; exponent < 22; ++exponent) {  // log_10(9^22) < 21
      size_t num_digits =
          static_cast<size_t>(1.L + static_cast<double>(exponent) *
                                        log10(static_cast<double>(base)));
      if (num_digits == exponent) {
        std::cout << "log_10(" << base << "**" << exponent << ") = "
                  << static_cast<double>(exponent) *
                         log10(static_cast<double>(base))
                  << std::endl;
        ++answer;
      }
    }
  }
  std::cout << "\n" << answer << std::endl;
}
