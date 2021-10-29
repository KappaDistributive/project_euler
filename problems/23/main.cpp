#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#include "../../utils/numbers/primes.hpp"

size_t sum_of_divisors(size_t number) {
  auto divisors = utils::numbers::divisors(number);
  return std::accumulate(divisors.begin(), divisors.end(),
                         static_cast<size_t>(0)) -
         number;
}

int main() {
  std::vector<size_t> abundant_numbers;
  for (size_t number{1}; number <= 28123; ++number) {
    if (sum_of_divisors(number) > number) {
      abundant_numbers.push_back(number);
    }
  }

  std::set<size_t> sum_of_abundant_numbers;
  for (auto lhs : abundant_numbers) {
    for (auto rhs : abundant_numbers) {
      sum_of_abundant_numbers.insert(lhs + rhs);
    }
  }

  size_t result{0};
  for (size_t number{1}; number <= 28123; ++number) {
    if (sum_of_abundant_numbers.count(number) == 0) {
      result += number;
    }
  }

  std::cout << result << std::endl;
}
