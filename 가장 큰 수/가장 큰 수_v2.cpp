// https://programmers.co.kr/learn/courses/30/lessons/42746
// Using character comparison

#include <string>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <sstream>

std::string solution(std::vector<int> numbers) {
  std::vector<std::string> number_strings;
  for (int el : numbers) {
    number_strings.emplace_back(std::to_string(el));
  }
  std::sort(
    number_strings.begin(), number_strings.end(),
    [](const std::string& a, const std::string& b) -> bool {
      size_t longer = std::max(a.size(), b.size());
      for (size_t i5 = 0, j5 = 0, k5 = 0; k5 < longer; ++i5, ++j5, ++k5) {
        i5 %= a.size();
        j5 %= b.size();
        if (a[i5] > b[j5]) {
          return true;
        } else if (a[i5] < b[j5]) {
          return false;
        }
      }
      return false;
    }
  );
  std::ostringstream ss;
  if (number_strings[0][0] == '0') {
    ss << "0";
  } else for (const auto& el : number_strings) {
    ss << el;
  }
  return ss.str();
}