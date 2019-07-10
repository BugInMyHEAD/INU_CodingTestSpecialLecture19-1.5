#include <string>
#include <iostream>
#include <sstream>

int main() {
  int n = 15;
  std::string sequence;
  if (n >= 0) {
    sequence = "1";
    std::cout << sequence << "\n";
  }
  std::stringstream next_sequence_stream;
  for (int i1 = 1; i1 < n; ++i1) {
    next_sequence_stream.clear();
    char last = sequence[0];
    size_t count = 1;
    for (size_t i3 = 1; i3 < sequence.size(); ++i3) {
      if (last == sequence[i3]) {
        ++count;
      } else {
        next_sequence_stream << last << count;
        last = sequence[i3];
        count = 1;
      }
    }
    next_sequence_stream << last << count;
    next_sequence_stream >> sequence;
    std::cout << sequence << "\n";
  }
}