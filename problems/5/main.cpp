#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

auto least_common_multiple(const std::vector<size_t>& numbers,
                           std::vector<size_t> helpers) {
  assert(numbers.size() == helpers.size());
  while (1) {
    auto minimal_helper = *std::min_element(helpers.begin(), helpers.end());
    auto maximal_helper = *std::max_element(helpers.begin(), helpers.end());

    if (minimal_helper == maximal_helper) {
      return minimal_helper;
    }

    for (size_t index{0}; index < helpers.size(); ++index) {
      if (helpers[index] == minimal_helper) {
        helpers[index] += numbers[index];
      }
    }
  }
}

auto least_common_multiple(const std::vector<size_t>& numbers) {
  auto helpers = numbers;
  return least_common_multiple(numbers, helpers);
}

int main() {
  std::vector<size_t> numbers;
  for (size_t number{1}; number <= 20; ++number) {
    numbers.push_back(number);
  }
  std::cout << least_common_multiple(numbers) << std::endl;
}
