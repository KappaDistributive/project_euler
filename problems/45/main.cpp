#include <iostream>

size_t triangle_number(size_t n) { return (n * (n + 1)) / 2; }

size_t pentagonal_number(size_t n) { return (n * (3 * n - 1)) / 2; }

size_t hexagonal_number(size_t n) { return n * (2 * n - 1); }

int main() {
  size_t index_triangle{286};
  size_t number_triangle{triangle_number(index_triangle)};
  size_t index_pentagonal{166};
  size_t number_pentagonal{pentagonal_number(index_pentagonal)};
  size_t index_hexagonal{144};
  size_t number_hexagonal{hexagonal_number(index_hexagonal)};

  while (number_triangle != number_pentagonal ||
         number_triangle != number_hexagonal ||
         number_pentagonal != number_hexagonal) {
    if (number_triangle < std::max(number_hexagonal, number_pentagonal)) {
      number_triangle = triangle_number(++index_triangle);
    } else if (number_pentagonal <
               std::max(number_triangle, number_hexagonal)) {
      number_pentagonal = pentagonal_number(++index_pentagonal);
    } else {
      number_hexagonal = hexagonal_number(++index_hexagonal);
    }
  }

  std::cout << number_triangle << std::endl;
}
