// File:          EPuckPlusGreenRobot.hpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 9.2
// Author:        Leo Wu
// Modifications:

#pragma once

#include "EPuckGreenRobot.hpp"

#include <webots/GPS.hpp>
#include <webots/Compass.hpp>
#include <webots/Lidar.hpp>
#include <webots/Display.hpp>

#include <utility>
#include <vector>

constexpr double WORLD_WIDTH{1.0};
constexpr double WORLD_HEIGHT{1.0};

class EPuckPlusGreenRobot : public EPuckGreenRobot{
public:
  EPuckPlusGreenRobot();
  void run();

protected:
  void readGPS();
  void readCompass();
  void readLidar();

  void displayTrajectory() const;
  void displayMap() const;

private:
  webots::GPS* mGPS{};
  std::pair<double, double> mPosition{};

  webots::Compass* mCompass{};
  double mHeading{};

  webots::Lidar* mLidar{};
  std::vector<std::pair<double, double>> mPointCloud{};

  webots::Display* mDisplay1{};
  int mDP1Width{};
  int mDP1Height{};

  webots::Display* mDisplay2{};
  int mDP2Width{};
  int mDP2Height{};
};