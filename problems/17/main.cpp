#include <iostream>
#include <string>

std::string digits_to_text(size_t number) {
  std::string text;
  if (number > 1000) {
    throw std::runtime_error("Only numbers <=1000 are supported.");
  } else if (number == 1000) {
    return "one thousand";
  } else if (number < 20) {
    switch (number) {
      case 0:
        text = "";
        break;
      case 1:
        text = "one";
        break;
      case 2:
        text = "two";
        break;
      case 3:
        text = "three";
        break;
      case 4:
        text = "four";
        break;
      case 5:
        text = "five";
        break;
      case 6:
        text = "six";
        break;
      case 7:
        text = "seven";
        break;
      case 8:
        text = "eight";
        break;
      case 9:
        text = "nine";
        break;
      case 10:
        text = "ten";
        break;
      case 11:
        text = "eleven";
        break;
      case 12:
        text = "twelve";
        break;
      case 13:
        text = "thirteen";
        break;
      case 14:
        text = "fourteen";
        break;
      case 15:
        text = "fifteen";
        break;
      case 16:
        text = "sixteen";
        break;
      case 17:
        text = "seventeen";
        break;
      case 18:
        text = "eighteen";
        break;
      case 19:
        text = "nineteen";
        break;
      default:
        throw std::runtime_error("This should never happen");
        break;
    }
  } else if (number < 100) {
    switch (number / 10) {
      case 2:
        text = "twenty";
        break;
      case 3:
        text = "thirty";
        break;
      case 4:
        text = "forty";
        break;
      case 5:
        text = "fifty";
        break;
      case 6:
        text = "sixty";
        break;
      case 7:
        text = "seventy";
        break;
      case 8:
        text = "eighty";
        break;
      case 9:
        text = "ninety";
        break;
      default:
        throw std::runtime_error("This should never happen.");
        break;
    }
    if (number % 10 != 0) {
      text += "-" + digits_to_text(number % 10);
    }
  } else if (number >= 100) {
    switch (number / 100) {
      case 1:
        text = "one hundred";
        break;
      case 2:
        text = "two hundred";
        break;
      case 3:
        text = "three hundred";
        break;
      case 4:
        text = "four hundred";
        break;
      case 5:
        text = "five hundred";
        break;
      case 6:
        text = "six hundred";
        break;
      case 7:
        text = "seven hundred";
        break;
      case 8:
        text = "eight hundred";
        break;
      case 9:
        text = "nine hundred";
        break;
      default:
        throw std::runtime_error("This should never happen.");
        break;
    }
    if (number % 100 != 0) {
      text += " and " + digits_to_text(number % 100);
    }
  }

  return text;
}

size_t count_letters(const std::string& text) {
  size_t count{0};
  for (auto character : text) {
    count += character >= 'a' && character <= 'z';
  }
  return count;
}

int main() {
  std::string text = "";
  constexpr size_t upper_bound{1000};
  for (size_t number{1}; number <= upper_bound; ++number) {
    text += digits_to_text(number);
    if (number < upper_bound) {
      text += "\n";
    }
  }

  std::cout << count_letters(text) << std::endl;
}
