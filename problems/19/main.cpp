#include <iostream>

size_t zellers_algorithm(size_t day, size_t month, size_t year) {
  // Monday ~ 0, Tuesday ~ 1, ... Sunday ~ 6
  if (month < 3) {
    month += 12;
    year -= 1;
  }

  return ((day + ((13 * (month + 1)) / 5) + (year % 100) + ((year % 100) / 4) +
           (((year / 100) % 100) / 4) + (((year / 100) % 100) * 5)) +
          5) %
         7;
}
int main() {
  size_t result{0};
  for (size_t year{1901}; year <= 2000; ++year) {
    for (size_t month{1}; month <= 12; ++month) {
      result += zellers_algorithm(1, month, year) == 6;
    }
  }
  std::cout << result << std::endl;
}

