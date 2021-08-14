#include <algorithm>
#include <iostream>
#include <string>

bool same_digits(size_t lhs, size_t rhs) {
  auto lhs_str = std::to_string(lhs);
  auto rhs_str = std::to_string(rhs);
  std::sort(lhs_str.begin(), lhs_str.end());
  std::sort(rhs_str.begin(), rhs_str.end());
  return lhs_str == rhs_str;
}

int main() {
  for (size_t number{1};; ++number) {
    bool done = true;
    for (size_t factor{2}; factor <= 6 && done; ++factor) {
      done = same_digits(number, factor * number);
    }
    if (done) {
      std::cout << number << std::endl;
      return 0;
    }
  }
}
