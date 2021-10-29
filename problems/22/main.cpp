#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <regex>  // NOLINT
#include <string>
#include <vector>

std::vector<std::string> read_file() {
  std::fstream file;
  file.open("../problems/22/names.txt", std::ios::in);
  std::string lines;
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      lines += line;
      lines += "\n";
    }
    file.close();
  }
  std::smatch matches;
  std::regex name_regex{"\"(\\w+)\""};
  std::vector<std::string> names;
  std::string name;

  for (std::sregex_iterator it =
           std::sregex_iterator(lines.begin(), lines.end(), name_regex);
       it != std::sregex_iterator(); ++it) {
    name = it->str();
    std::regex_match(name, matches, name_regex);
    assert(matches.size() == 2);
    names.push_back(matches[1].str());
  }

  return names;
}

int main() {
  auto names = read_file();
  std::sort(names.begin(), names.end());
  size_t total_score{0}, score;
  for (size_t index{0}; index < names.size(); ++index) {
    score = 0;
    for (auto character : names[index]) {
      score += 1 + character - 'A';
    }
    total_score += (index + 1) * score;
  }

  std::cout << total_score << std::endl;
}
