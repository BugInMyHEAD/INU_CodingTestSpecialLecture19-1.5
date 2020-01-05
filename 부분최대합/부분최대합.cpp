#include <iostream>
#include <iterator>

int main() {
  constexpr int input[] = {
    31, -41, 59, 26, -53, 58, 97, -93, -23, 84
  };

  int acc = 0;
  int acc_max = 0;
  size_t input_index_end = 0;
  for (size_t input_index = 0; input_index < std::size(input); ++input_index) {
    acc += input[input_index];
    if ( acc_max < acc ) {
      acc_max = acc;
      input_index_end = input_index + 1;
    }
  }
  acc = acc_max;
  for (size_t input_index = 0; input_index < input_index_end; ++input_index) {
    acc -= input[input_index];
    if ( acc_max < acc ) {
      acc_max = acc;
    }
  }

  std::cout << "expected : \"" << 187 << "\"\n" << "actual : \"" << acc_max << "\"" << "\n";
}