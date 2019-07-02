// https://programmers.co.kr/learn/courses/30/lessons/42585

#include <string>
#include <vector>

int solution(std::string arrangement) {
  int answer = 0;
  int left_paren = 0;
  bool last_was_left_paren = false;
  for (const auto& ch : arrangement) {
    switch (ch) {
      case '(' :
        ++left_paren;
        last_was_left_paren = true;
      break;

      case ')' :
        --left_paren;
        if (last_was_left_paren) {
            answer += left_paren;
            last_was_left_paren = false;
        } else {
            ++answer;
        }
      break;
    }
  }
  return answer;
}