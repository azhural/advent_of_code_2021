#ifndef AOC2021_UTIL_LIST_READER_H
#define AOC2021_UTIL_LIST_READER_H

#include <fstream>
#include <sstream>
#include <vector>

namespace aoc2021 {
  class ListReader {
  public:
    ListReader(const std::string& file);

    template<class T> std::vector<T> get();

  private:
    std::ifstream fs_;
  };

  template<class T>
  std::vector<T> ListReader::get() {
    std::vector<T> v;
    std::string s;
    T value;
    while(std::getline(fs_, s)) {
      std::stringstream iss {s};
      iss >> value;
      v.push_back(value);
    }
    return v;
  }

  template<>
  inline std::vector<std::string> ListReader::get() {
    std::vector<std::string> v;
    std::string s;
    while(std::getline(fs_, s)) {
      v.push_back(s);
    }
    return v;
  }
}

#endif

