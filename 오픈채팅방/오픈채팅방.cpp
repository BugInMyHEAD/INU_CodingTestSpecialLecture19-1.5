// https://programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <utility>

std::vector<std::string> solution(std::vector<std::string> record) {
  std::vector<std::pair<std::string, std::string>> uid_command_pairs;
  std::unordered_map<std::string, std::string> uid_nickname_map;
  for (const auto& el : record) {
    size_t i2 = 0, j2 = 0;

    j2 = el.find(' ');
    const auto command = el.substr(i2, j2 - i2);

    ++j2;
    i2 = j2;
    j2 = el.find(' ', j2);
    if (j2 < 0) {
      j2 = el.size() - 1;
    }
    const auto uid = el.substr(i2, j2 - i2);

    if (command == "Leave") {
      uid_command_pairs.push_back(std::make_pair(uid, "님이 나갔습니다."));
    } else {
      ++j2;
      i2 = j2;
      j2 = el.find(' ', j2);
      if (j2 < 0) {
        j2 = el.size() - 1;
      }
      const auto nickname = el.substr(i2, j2 - i2);
      uid_nickname_map[uid] = nickname;

      if (command == "Enter") {
        uid_command_pairs.push_back(std::make_pair(uid, "님이 들어왔습니다."));
      } else if (command == "Change") {
      }
    }
  }

  std::vector<std::string> result;
  for (const auto& el : uid_command_pairs) {
    result.push_back(uid_nickname_map[el.first] + el.second);
  }
  return result;
}