#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

int solution(std::vector<int> people, int limit) {
  int boat_count = 0;
  std::sort(people.begin(), people.end());
  auto low = people.cbegin();
  auto high = people.cend() - 1;
  while (low <= high) {
    if (*low + *high <= limit) {
      ++low;
    }
    --high;
    ++boat_count;
  }
  return boat_count;
}