#include <aoc2021/tasks/task.h>

#include <stdexcept>

#include <aoc2021/tasks/SonarSweep.h>
#include <aoc2021/tasks/Dive.h>

namespace aoc2021 {

std::unique_ptr<Task> Task::create(int day) {
  switch(day){
  case 1:
    return std::make_unique<SonarSweep>();
  case 2:
    return std::make_unique<Dive>();
  default:
    throw std::runtime_error{"Not implemented."};
  }

}

}
