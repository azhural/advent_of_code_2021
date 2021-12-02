#include <aoc2021/tasks/Dive.h>

#include <aoc2021/util/ListReader.h>
#include <iostream>

namespace aoc2021 {

Dive::Dive() {
  require_input_ = true;
}

void Dive::setInputPath(const std::string& s) {
  input_file_path_ = s;
}

void Dive::run() {
  ListReader reader(input_file_path_);

  auto commands = reader.get<std::string>();

  auto str_to_cmd = [](const std::string& s){
    if(s == "forward") return Submarine::Command::FORWARD;
    if(s == "up") return Submarine::Command::UP;
    if(s == "down") return Submarine::Command::DOWN;
    throw std::runtime_error{"Unknown steering command."};
  };

  for(const auto& command : commands) {
    std::string delimiter = " ";
    auto split = command.find(delimiter);
    auto cmd = str_to_cmd(command.substr(0, split));
    auto value = std::stoi(command.substr(split + 1, command.size()));
    sub_.steer(cmd, value);
  }
}

void Dive::output() {
  std::cout << "Submarine position:\n" << "Horizontal: " << sub_.getHorizontal() << "\nDepth: " << sub_.getDepth() << std::endl;
  std::cout << "Product: " << sub_.getDepth() * sub_.getHorizontal() << std::endl;
}

void Submarine::steer(Command dir, int value) {
  switch(dir) {
  case Command::FORWARD:
    horizontal_ += value;
    depth_ += aim_ * value;
    break;
  case Command::UP:
    aim_ -= value;
    break;
  case Command::DOWN:
    aim_ += value;
  }
}

}
