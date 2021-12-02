#ifndef AOC2021_TASK_H
#define AOC2021_TASK_H

#include <memory>

namespace aoc2021 {
  class Task {
  public:
    bool isInputRequired() const {return require_input_;};

    virtual void setInputPath(const std::string& s) {}
    virtual void run() = 0;
    virtual void output() = 0;

    static std::unique_ptr<Task> create(int day);

  protected:
    bool require_input_;
  };
}

#endif

