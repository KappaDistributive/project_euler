#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> digits{{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
  std::vector<std::vector<int>> permutations;

  do {
    permutations.push_back(digits);
  } while (std::next_permutation(digits.begin(), digits.end()));
  std::sort(permutations.begin(), permutations.end());

  for (auto digit : permutations[999999]) {
    std::cout << digit;
  }
  std::cout << std::endl;
}
