#include <bitset>
#include <iostream>

bool is_palindrome(const std::string& text) {
  for (size_t index{0}; index < text.size() / 2; ++index) {
    if (text[index] != text[text.size() - index - 1]) {
      return false;
    }
  }
  return true;
}

std::string strip(const std::string& text) {
  std::string result;
  size_t index{0};
  for (; index < text.size(); ++index) {
    if (text[index] != '0') {
      break;
    }
  }
  for (; index < text.size(); ++index) {
    result += text[index];
  }
  return result;
}

int main() {
  size_t answer{0};
  for (size_t number{1}; number < 1000000; ++number) {
    if (is_palindrome(std::to_string(number)) &&
        is_palindrome(
            strip(std::bitset<8 * sizeof(number)>(number).to_string()))) {
      answer += number;
    }
  }
  std::cout << answer << std::endl;
}
