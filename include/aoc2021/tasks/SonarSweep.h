#ifndef AOC2021_TASKS_SONAR_SWEEP_H
#define AOC2021_TASKS_SONAR_SWEEP_H

#include <aoc2021/tasks/task.h>

namespace aoc2021 {

class SonarSweep : public Task {
public:
  SonarSweep();

  virtual void setInputPath(const std::string& s);
  virtual void run();
  virtual void output();

private:
  std::string input_file_path_;

  long p1_result_;
  long p2_result_;
};

}

#endif
