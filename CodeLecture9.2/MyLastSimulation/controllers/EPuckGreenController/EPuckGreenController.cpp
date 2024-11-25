// File:          EPuckGreenController.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#include "EPuckGreenRobot.hpp"

#include <memory>

int main(int argc, char **argv) {

  // on heap
  std::unique_ptr<EPuckGreenRobot> ePuckGreenRobot{std::make_unique<EPuckGreenRobot>()};
  ePuckGreenRobot->run();
  
  // or on stack
  // EPuckGreenRobot ePuckGreenRobot{};
  // ePuckGreenRobot.run();

  return 0;
}