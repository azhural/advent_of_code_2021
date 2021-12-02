#include <aoc2021/tasks/SonarSweep.h>

#include <aoc2021/util/ListReader.h>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace aoc2021 {

SonarSweep::SonarSweep()
{
  require_input_ = true;
}

void SonarSweep::setInputPath(const std::string &s) {
  input_file_path_ = s;
}

void SonarSweep::run() {
  ListReader reader (input_file_path_);
  auto input = reader.get<int>();

  std::vector<int> slope (input.size() - 1);
  std::adjacent_difference(input.begin(), input.end(), slope.begin());
  p1_result_ = std::count_if(slope.begin(), slope.end(), [](int i){return i > 0;});


  std::vector<int> window_values;
  for(auto it = input.begin(); it != input.end() - 2; ++it) {
    window_values.push_back(std::accumulate(it, it + 3, 0));
  }
  std::vector<int> sliding_slope (window_values.size() - 1);
  std::adjacent_difference(window_values.begin(), window_values.end(), sliding_slope.begin());
  p2_result_ = std::count_if(sliding_slope.begin(), sliding_slope.end(), [](int i){return i > 0;});
}

void SonarSweep::output() {
  std::cout << "Part 1: Height increases " << p1_result_ << " times." << std::endl;
  std::cout << "Part 2: Height increases " << p2_result_ << " times in the sliding window." << std::endl;
}

}
