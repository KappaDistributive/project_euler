#include <iostream>
#include <map>
#include <numeric>
#include <set>

#include "../../utils/numbers/primes.hpp"

int main() {
  std::map<int, int> sum_of_divisors;
  for (int number{1}; number < 10000; ++number) {
    auto divisors = utils::numbers::divisors(number);
    sum_of_divisors.insert(std::make_pair(
        number, std::accumulate(divisors.begin(), divisors.end(), 0) - number));
  }

  std::set<int> amicable_numbers;
  for (int number{1}; number < 10000; ++number) {
    for (int candidate{number + 1}; candidate < 10000; ++candidate) {
      if (sum_of_divisors[number] == candidate &&
          sum_of_divisors[candidate] == number) {
        amicable_numbers.insert(number);
        amicable_numbers.insert(candidate);
      }
    }
  }

  std::cout << std::accumulate(amicable_numbers.begin(), amicable_numbers.end(),
                               0)
            << std::endl;
}
