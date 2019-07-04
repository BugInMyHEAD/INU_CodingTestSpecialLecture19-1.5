// https://programmers.co.kr/learn/courses/30/lessons/42746
// Using character comparison

#include <string>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <sstream>

static bool IsGreaterNumberString(const std::string& a, const std::string& b) {
  size_t a_substr_from = 0, b_substr_from = 0;
  for (
    size_t a_idx = 0, b_idx = 0;
    a_idx < a.size() || b_idx < b.size();
    ++a_idx, ++b_idx
  ) {
    if (a_idx >= a.size()) {
      b_substr_from = b_idx;
      a_idx = a_substr_from;
    } else if (b_idx >= b.size()) {
      a_substr_from = a_idx;
      b_idx = b_substr_from;
    }
    if (a[a_idx] > b[b_idx]) {
      return true;
    } else if (a[a_idx] < b[b_idx]) {
      return false;
    }
  }
  return false;
}

std::string solution(std::vector<int> numbers) {
  std::vector<std::string> number_strings;
  for (int el : numbers) {
    number_strings.emplace_back(std::to_string(el));
  }
  std::sort(number_strings.begin(), number_strings.end(), IsGreaterNumberString);
  
  if (number_strings[0][0] == '0') {
    return "0";
  }
  std::ostringstream ss;
  for (const auto& el : number_strings) {
    ss << el;
  }
  return ss.str();
}