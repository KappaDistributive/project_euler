#include <iostream>
#include <map>
#include <set>
#include <utility>

#include "../../utils/numbers/primes.hpp"

int formula(int n, int a, int b) { return n * n + a * n + b; }

int main() {
  auto primes = utils::numbers::primes_below(1000000);
  std::set<int> prime_set;
  for (auto prime : primes) {
    prime_set.insert(static_cast<int>(prime));
  }
  std::map<std::pair<int, int>, size_t> scores;
  for (int a{-999}; a <= 999; ++a) {
    for (int b{-1000}; b <= 1000; ++b) {
      int n{0};
      bool searching{true};
      for (; n < 1000 && searching; ++n) {
        auto candidate = formula(n, a, b);
        if (prime_set.count(candidate) == 0) {
          searching = false;
        }
      }
      std::cout << "(" << a << ", " << b << ") produced " << n - 1
                << " consecutive primes." << std::endl;

      scores.insert({{a, b}, n - 1});
    }
  }

  size_t best_score{0};
  int best_a{0}, best_b{0};
  for (auto [params, score] : scores) {
    if (score > best_score) {
      best_score = score;
      best_a = std::get<0>(params);
      best_b = std::get<1>(params);
    }
  }

  std::cout << "(" << best_a << ", " << best_b << ") produced " << best_score
            << " consecutive primes." << std::endl;
  std::cout << best_a * best_b << std::endl;
}
