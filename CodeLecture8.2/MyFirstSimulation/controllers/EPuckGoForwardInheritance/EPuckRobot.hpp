// File:          EPuckRobot.hpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 8.2
// Author:        Leo Wu
// Modifications:

#pragma once

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>

#include <memory>
#include <array>

constexpr int TIME_STEP{32};
constexpr double MAX_SPEED{6.28};
constexpr int NUM_DIST_SENSORS{8};

class EPuckRobot : public webots::Robot{
public:
  EPuckRobot();
  void run();

protected:
  void report() const;
  void roam();

private:
  std::array<webots::DistanceSensor*, NUM_DIST_SENSORS> mPs{};
  std::array<double, NUM_DIST_SENSORS> mPsValues{};
  bool mLeftObstacle{};
  bool mRightObstacle{};
  
  webots::Motor* mLeftMotor{};
  webots::Motor* mRightMotor{};
  double mLeftSpeed{};
  double mRightSpeed{};  
};