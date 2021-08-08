#include "primes.hpp"

namespace utils {
namespace numbers {

std::vector<size_t> primes_below(size_t strict_upper_bound) {
  std::vector<size_t> primes;
  if (strict_upper_bound <= 2) {
    return primes;
  }
  primes.push_back(2);

  for (size_t candidate{3}; candidate < strict_upper_bound; ++candidate) {
    bool is_prime = true;
    for (auto prime : primes) {
      if (prime > static_cast<size_t>(std::sqrt(candidate))) {
        break;
      }
      if (candidate % prime == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      primes.push_back(candidate);
    }
  }
  return primes;
}

}  // namespace numbers
}  // namespace utils
