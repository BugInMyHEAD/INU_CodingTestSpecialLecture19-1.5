// https://programmers.co.kr/learn/courses/30/lessons/12921
// Memory optimized version

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int solution(int n) {
  if (n < 2) {
    return 0;
  }

  std::vector<bool> prime_checks;
  const int sqrt_of_n = std::sqrt(n);

  // Only odd numbers are in `prime_checks`
  prime_checks.assign((n + 1) / 2, true);
  // 1 is not a prime number
  prime_checks[0] = false;

  for (int i1 = 3; i1 <= sqrt_of_n; i1 += 2)
    if (prime_checks[i1 / 2])
      for (int i3 = 3 * i1; i3 <= n; i3 += 2 * i1) {
        prime_checks[i3] = false;
      }

  // Add 1 because prime number 2 is not in `prime_checks`
  return std::count(prime_checks.cbegin(), prime_checks.cend(), true) + 1;
}