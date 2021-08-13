#include <iostream>
#include <set>

#include "../../utils/numbers/primes.hpp"

int main() {
  constexpr size_t num_primes{7100};
  constexpr size_t upper_bound{50000000};
  std::cout << "Preparing prime sequence..." << std::endl;
  auto primes = utils::numbers::primes_below(num_primes);
  size_t candidate;
  size_t comp_a, comp_b, comp_c;

  std::cout << "Calculating..." << std::endl;
  std::set<size_t> numbers;
  for (size_t a{0}; a < num_primes; ++a) {
    comp_a = primes[a];
    comp_a = comp_a * comp_a * comp_a * comp_a;
    if (comp_a > upper_bound) {
      break;
    }
    for (size_t b{0}; b < num_primes; ++b) {
      comp_b = primes[b];
      comp_b = comp_b * comp_b * comp_b;
      if (comp_a + comp_b > upper_bound) {
        break;
      }
      for (size_t c{0}; c < num_primes; ++c) {
        comp_c = primes[c];
        comp_c = comp_c * comp_c;
        candidate = comp_a + comp_b + comp_c;
        if (candidate < upper_bound) {
          numbers.insert(candidate);
        } else {
          break;
        }
      }
    }
  }

  std::cout << numbers.size() << std::endl;
}
