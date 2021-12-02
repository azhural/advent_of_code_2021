#include <iostream>
#include <aoc2021/tasks/task.h>

int main(int argc, char** argv)
{
  if(argc < 2) {
    std::cout << "Task # required as first argument." << std::endl;
    return -1;
  }
  auto task = aoc2021::Task::create(std::stoi(argv[1]));
  if(task->isInputRequired()) {
    if(argc < 3) {
      std::cout << "Task requires input file path." << std::endl;
      return -1;
    }
    task->setInputPath(argv[2]);
  }

  task->run();
  task->output();
}
