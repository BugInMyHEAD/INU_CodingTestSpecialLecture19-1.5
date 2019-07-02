// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

int solution(std::vector<int> scoville, int K) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> foods;
  for (const auto& el : scoville) {
    foods.push(el);
  }

  int answer = 0;
  while (foods.top() < K) {
    // Select two foods which have lowest scoville
    std::array<int, 2> lowest;
    if (foods.size() < lowest.max_size()) {
      return -1;
    }
    for (auto& el : lowest) {
      el = foods.top();
      foods.pop();
    }

    // Mix two foods
    foods.push(lowest[0] + 2 * lowest[1]);
    ++answer;
  }
  return answer;
}