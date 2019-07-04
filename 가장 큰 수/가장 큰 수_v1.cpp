// https://programmers.co.kr/learn/courses/30/lessons/42746
// Using string concatenation

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
      return a + b > b + a;
    }
  );
  
  if (number_strings[0][0] == '0') {
    return "0";
  }
  std::ostringstream ss;
  for (const auto& el : number_strings) {
    ss << el;
  }
  return ss.str();
}