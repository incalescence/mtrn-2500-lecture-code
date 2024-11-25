// File:          EPuckBlackController.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#include "EPuckRobot.hpp"
#include "EPuckBlackRobot.hpp"

#include <memory>

int main(int argc, char **argv) {

  // on heap
  std::unique_ptr<EPuckBlackRobot> ePuckBlackRobot{std::make_unique<EPuckBlackRobot>()};
  ePuckBlackRobot->run();
  
  // or on stack
  // EPuckBlackRobot ePuckBlackRobot{};
  // ePuckBlackRobot.run();
  
  return 0;
}