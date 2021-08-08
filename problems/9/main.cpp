#include <iostream>

int main() {
  for (size_t a{1}; a < 1000; ++a) {
    for (size_t b{1}; b < 1000 - a; ++b) {
      size_t c = 1000 - a - b;
      if (a * a + b * b == c * c) {
        std::cout << a * b * c << std::endl;
        return 0;
      }
    }
  }
}
