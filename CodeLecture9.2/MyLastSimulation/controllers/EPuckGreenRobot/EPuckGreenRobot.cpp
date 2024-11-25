// File:          EPuckGreenRobot.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#include "EPuckGreenRobot.hpp"

#include <iostream>

EPuckGreenRobot::EPuckGreenRobot() 
  : mKeyboard{getKeyboard()}
  {
  mKeyboard->enable(TIME_STEP);
}

void EPuckGreenRobot::display() const {
  std::cout << "[EPuckGreenRobot]: Press t/T and I'll turn myself." << std::endl;
  std::cout << "[EPuckGreenRobot]: Press b/B and I'll ask EPuckBlackRobot to move backward." << std::endl;
  std::cout << "[EPuckGreenRobot]: Press r/R and I'll ask EPuckBlackRobot to roam." << std::endl;
}

void EPuckGreenRobot::turn() {
  constexpr double speedScale{0.5};
  mLeftSpeed = speedScale * MAX_SPEED;
  mRightSpeed = - speedScale * MAX_SPEED;
  mLeftMotor->setVelocity(mLeftSpeed);
  mRightMotor->setVelocity(mRightSpeed);  
}

void EPuckGreenRobot::telecontrol() {
  int k {mKeyboard->getKey()};
  // std::cout << k << std::endl;
  if(k == 'T'){
    turn();
  } else if(k == 'B'){
    sendMessage("Backward");
  } else if(k == 'R'){
    sendMessage("Roam");
  } else {
    roam();
  }
}

void EPuckGreenRobot::run() {
  display();
  while (step(TIME_STEP) != -1) {
    telecontrol();
  }
}