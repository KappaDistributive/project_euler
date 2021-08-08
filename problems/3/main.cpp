#include "../../utils/numbers/primes.hpp"

int main() {
  auto prime_factors = utils::numbers::prime_factorization(600851475143);

  std::cout << prime_factors.back().first << std::endl;
}
