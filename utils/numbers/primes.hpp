#pragma once
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

namespace utils {
namespace numbers {

// Returns a sorted vector of all primes strictly below `strict_upper_bound`.
std::vector<size_t> primes_below(size_t strict_upper_bound);

// Returns the prime factoriziation of `number` as a list of (prime factor,
// multiplicity) pairs sorted in increasing order of prime factors.
// E.g. 360 = 2*3 * 3**2 * 5**1 -> {(2, 3), (3, 2), (5, 1)}
std::vector<std::pair<size_t, size_t>> prime_factorization(size_t number);

std::vector<size_t> divisors(size_t number, bool is_proper = false);

}  // namespace numbers
}  // namespace utils
