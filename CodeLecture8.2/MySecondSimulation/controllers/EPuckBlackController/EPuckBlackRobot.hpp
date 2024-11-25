// File:          EPuckBlackRobot.hpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#pragma once

#include "EPuckRobot.hpp"

#include <webots/keyboard.hpp>

class EPuckBlackRobot : public EPuckRobot {
public:
  EPuckBlackRobot();
  void run();
protected:
  void backward();
};