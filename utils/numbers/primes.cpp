#include "primes.hpp"

namespace utils {
namespace numbers {

std::vector<size_t> primes_below(size_t strict_upper_bound) {
  std::vector<bool> prime_candidates(strict_upper_bound, true);
  prime_candidates[0] = false;
  prime_candidates[1] = false;
  std::vector<size_t> primes;
  if (strict_upper_bound <= 2) {
    return primes;
  }
  size_t candidate{2};
  primes.push_back(candidate);

  while (candidate < strict_upper_bound) {
    size_t number = candidate;
    while (number < strict_upper_bound) {
      number += candidate;
      if (number < prime_candidates.size()) {
        prime_candidates[number] = 0;
      }
    }
    while (!prime_candidates[++candidate]) {
    }
    if (candidate < strict_upper_bound) {
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
    while (number %
               static_cast<size_t>(std::pow(factor.first, factor.second + 1)) ==
           0) {
      factor.second++;
    }
    if (factor.second > 0) {
      factorization.push_back(factor);
    }
  }

  return factorization;
}

std::vector<size_t> divisors(size_t number, bool is_proper) {
  std::vector<size_t> result;
  if (number == 0) {
    return result;
  }
  for (size_t factor{1}; factor < number; ++factor) {
    if (number % factor == 0) {
      result.push_back(factor);
    }
  }
  if (!is_proper) {
    result.push_back(number);
  }
  return result;
}

}  // namespace numbers
}  // namespace utils
