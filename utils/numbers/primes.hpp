#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace utils {
namespace numbers {

// Returns a sorted vector of all primes strictly below `strict_upper_bound`.
std::vector<size_t> primes_below(size_t strict_upper_bound);

}  // namespace numbers
}  // namespace utils
