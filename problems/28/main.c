#include <stdio.h>
#include<stdlib.h>


int spiral(int x, int y) {
  // (x, y) = (0, 0) represents the center.
  // adapted from: https://math.stackexchange.com/questions/888361/given-coordinates-find-the-number-at-that-coordinates-in-spiral-matrix
  if (x > 0 && abs(x) > abs(y)) {
    return 4 * x * x - 3 * x + y + 1;
  } else if (x <= 0 && abs(x) > abs(y)) {
    return 4 * x * x - x - y + 1;
  } else if (y > 0) {
    return 4 * y * y - y - x + 1;
  } else {
    return 4 * y * y - 3 * y + x + 1;
  }
}

int main() {
  int result = -1;  // account for double counting
  for (int offset = -500; offset <= 500; ++offset) {
    result += spiral(offset, offset) + spiral(offset, -offset);
  }
  printf("The answer is: %d\n", result);
}
