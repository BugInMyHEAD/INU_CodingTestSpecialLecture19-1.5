#include <string>
#include <vector>
#include <numeric>
#include <limits>

long long solution(int n, std::vector<int> times) {
  long long low = 0;
  long long high = 1000000000LL * 1000000000LL / times.size();
  long long estimated;
  while (true) {
    estimated = (low + high) / 2;
    if (low >= high) {
      break;
    }
    const auto authorized = std::accumulate(
      times.cbegin(), times.cend(), 0LL,
      [estimated](long long acc, long long el) { return acc + estimated / el; }
    );
    if (authorized < n) {
      low = estimated + 1;
    } else {
      high = estimated;
    }
  }
  return estimated;
}