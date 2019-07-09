// https://programmers.co.kr/learn/courses/30/lessons/12921

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int solution(int n) {
  std::vector<bool> prime_checks;
  const int sqrt_of_n = std::sqrt(n);
  prime_checks.assign(n + 1, true);
  prime_checks[0] = prime_checks[1] = false;
  for (int i1 = 4; i1 <= n; i1 += 2) {
    prime_checks[i1] = false;
  }
  for (int i1 = 3; i1 <= sqrt_of_n; i1 += 2)
    if (prime_checks[i1])
      for (int i3 = 3 * i1; i3 <= n; i3 += 2 * i1) {
        prime_checks[i3] = false;
      }
  return std::count(prime_checks.cbegin(), prime_checks.cend(), true);
}