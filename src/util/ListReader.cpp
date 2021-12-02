#include <aoc2021/util/ListReader.h>

namespace aoc2021 {

ListReader::ListReader(const std::string& file) {
  fs_.open(file);
  if(!fs_.is_open())  throw std::runtime_error{"Failed to open file."};
}

}
