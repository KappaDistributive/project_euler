#include <iostream>
#include <string>
#include <vector>

bool is_palindrome(std::string candidate) {
  if (candidate.size() < 2) {
    return true;
  }
  for (size_t offset{0}; offset < candidate.size() / 2; ++offset) {
    if (candidate[offset] != candidate[candidate.size() - 1 - offset]) {
      return false;
    }
  }
  return true;
}

bool is_palindrome(size_t candidate) {
  return is_palindrome(std::to_string(candidate));
}

int main() {
  size_t result{0};

  for (size_t x{100}; x < 1000; ++x) {
    for (size_t y{100}; y < 1000; ++y) {
      auto product = x * y;
      if (product > result && is_palindrome(product)) {
        result = product;
      }
    }
  }
  std::cout << result << std::endl;
}
