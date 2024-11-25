// File:          EPuckPlusGreenController.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 9.2
// Author:        Leo Wu
// Modifications:

#include "EPuckPlusGreenRobot.hpp"

#include <memory>

int main(int argc, char **argv) {

  // on heap
  std::unique_ptr<EPuckPlusGreenRobot> ePuckPlusGreenRobot{std::make_unique<EPuckPlusGreenRobot>()};
  ePuckPlusGreenRobot->run();

  // or on stack
  // EPuckPlusGreenRobot ePuckPlusGreenRobot{};
  // ePuckPlusGreenRobot.run();

  return 0;
}