#include <numeric>

#include "../../utils/numbers/primes.hpp"

int main() {
  auto primes = utils::numbers::primes_below(2000000);
  std::cout << std::accumulate(primes.begin(), primes.end(),
                               static_cast<size_t>(0))
            << std::endl;
}
