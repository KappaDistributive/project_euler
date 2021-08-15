#include <gtest/gtest.h>

#include "../utils/numbers/primes.hpp"

namespace {

TEST(PrimesBelow, Small) {
  std::vector<size_t> want{{2, 3, 5, 7}};
  auto got = utils::numbers::primes_below(10);

  EXPECT_EQ(want, got);
}

TEST(PrimesBelow, Medium) {
  std::vector<size_t> want{
      {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
       47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
       109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
       191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
       269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
       353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
       439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
       523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
       617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
       709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
       811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
       907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}};
  auto got = utils::numbers::primes_below(1000);
  std::cout << "want:" << std::endl;
  for (auto it = want.begin(); it != want.end(); ++it) {
    std::cout << *it;
    if (std::next(it) != want.end()) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;

  std::cout << "got:" << std::endl;
  for (auto it = got.begin(); it != got.end(); ++it) {
    std::cout << *it;
    if (std::next(it) != got.end()) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;

  EXPECT_EQ(want, got);
}

TEST(PrimeFactorization, Small) {
  std::vector<std::pair<size_t, size_t>> want{{{2, 1}, {3, 2}, {5, 3}}};
  auto got = utils::numbers::prime_factorization(2250);

  EXPECT_EQ(want, got);
}

TEST(Divisors, Trivial) {
  std::vector<size_t> want;
  auto got = utils::numbers::divisors(0);

  EXPECT_EQ(want, got);
}

TEST(Divisors, Proper) {
  std::vector<size_t> want{{1, 2, 3}};
  auto got = utils::numbers::divisors(6, true);

  EXPECT_EQ(want, got);
}

TEST(Divisors, Imroper) {
  std::vector<size_t> want{{1, 2, 3, 6}};
  auto got = utils::numbers::divisors(6);

  EXPECT_EQ(want, got);
}

}  // namespace
