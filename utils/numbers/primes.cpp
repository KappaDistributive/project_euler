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

std::vector<std::pair<size_t, size_t>> prime_factorization(size_t number) {
  auto primes = primes_below(static_cast<size_t>(std::sqrt(number)) + 1);
  std::vector<std::pair<size_t, size_t>> factorization;

  for (auto prime : primes) {
    std::pair<size_t, size_t> factor{prime, 0};
    while (number % static_cast<size_t>(std::pow(factor.first, factor.second + 1)) == 0) {
      factor.second++;
    }
    if (factor.second > 0) {
      factorization.push_back(factor);
    }
  }

  return factorization;
}

}  // namespace numbers
}  // namespace utils
