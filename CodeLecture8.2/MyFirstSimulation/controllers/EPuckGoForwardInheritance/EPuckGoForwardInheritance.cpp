// File:          EPuckGoForwardInheritance.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#include "EPuckRobot.hpp"

#include <memory>

int main(int argc, char **argv) {

  // on heap
  std::unique_ptr<EPuckRobot> ePuckRobot{std::make_unique<EPuckRobot>()};
  ePuckRobot->run();
  
  // or on stack
  // EPuckRobot ePuckRobot{};
  // ePuckRobot.run();
  
  return 0;
}