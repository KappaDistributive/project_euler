#include "../../utils/numbers/primes.hpp"

int main() {
  auto primes = utils::numbers::primes_below(1000000);

  std::cout << primes[10000] << std::endl;
}
