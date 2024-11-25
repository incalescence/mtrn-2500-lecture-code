// File:          EPuckBlackRobot.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#include "EPuckBlackRobot.hpp"

#include <iostream>
#include <string>

EPuckBlackRobot::EPuckBlackRobot() 
  : EPuckRobot() 
  {
}

void EPuckBlackRobot::backward() {
  constexpr double speedScale{0.5};
  mLeftSpeed = -speedScale * MAX_SPEED;
  mRightSpeed = -speedScale * MAX_SPEED;
  mLeftMotor->setVelocity(mLeftSpeed);
  mRightMotor->setVelocity(mRightSpeed);  
}

void EPuckBlackRobot::run() {
  bool isBackward{false};
  while (step(TIME_STEP) != -1) {
    // std::cout << receiveMessage() << std::endl;
    std::string msg{receiveMessage()};
    if(msg == "Backward") {
      isBackward = true;
    } else if(msg == "Roam") {
      isBackward = false;
    }
    
    if(isBackward) {
      backward();
    } else {
      roam();
    }
  }
}