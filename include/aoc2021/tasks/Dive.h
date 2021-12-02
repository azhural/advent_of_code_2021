#ifndef AOC2021_TASKS_DIVE_H
#define AOC2021_TASKS_DIVE_H

#include <aoc2021/tasks/task.h>

namespace aoc2021 {

class Submarine {
public:
  enum class Command {
    FORWARD, UP, DOWN
  };

  void steer(Command cmd, int value);
  long getDepth() const {return depth_;}
  long getHorizontal() const {return horizontal_;}

private:
  long depth_ = 0;
  long horizontal_ = 0;
  long aim_ = 0;
};

class Dive : public Task {
public:
  Dive();

  virtual void setInputPath(const std::string& s);
  virtual void run();
  virtual void output();

private:
  std::string input_file_path_;

  Submarine sub_;
};

}

#endif
