// File:          EPuckPlusGreenRobot.cpp
// Date:          XX/XX/XXXX
// Description:   Example in Lecture 9.2
// Author:        Leo Wu
// Modifications:

#include "EPuckPlusGreenRobot.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double PI{ 3.14159265358979323846};

EPuckPlusGreenRobot::EPuckPlusGreenRobot()
  : mGPS{getGPS("gps")}
  , mCompass{getCompass("compass")}
  , mLidar{getLidar("lidar")}
  , mDisplay1{getDisplay("display1")}
  , mDisplay2{getDisplay("display2")}
  {
  mGPS->enable(TIME_STEP);
  mCompass->enable(TIME_STEP);

  mLidar->enable(TIME_STEP);
  mLidar->enablePointCloud();

  mDP1Width = mDisplay1->getWidth();
  mDP1Height = mDisplay1->getHeight();
  mDP2Width = mDisplay2->getWidth();
  mDP2Height = mDisplay2->getHeight();
}

void EPuckPlusGreenRobot::readGPS() {
  const double* gpsValues{mGPS->getValues()};
  mPosition = {gpsValues[0], gpsValues[1]};
  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Position: X: " << mPosition.first << " Y: " << mPosition.second << " ";
}

void EPuckPlusGreenRobot::displayTrajectory() const {
  mDisplay1->drawPixel((WORLD_WIDTH/2 + mPosition.first) / WORLD_WIDTH * mDP1Width,
                       (WORLD_HEIGHT/2 - mPosition.second) / WORLD_HEIGHT * mDP1Height);
}

void EPuckPlusGreenRobot::readCompass() {
  const double* compassValues{mCompass->getValues()};
  mHeading = atan2(compassValues[1], compassValues[0]);
  std::cout << std::fixed << std::setprecision(3);
  std::cout << "Heading: " << mHeading / PI * 180 << std::endl;
}

void EPuckPlusGreenRobot::readLidar() {
  const webots::LidarPoint* pointCloud{mLidar->getLayerPointCloud(0)};

  mPointCloud.clear();
  for (int i{0}; i < mLidar->getNumberOfPoints(); ++i) {
    mPointCloud.push_back({pointCloud[i].x, pointCloud[i].y});
  }
}

void EPuckPlusGreenRobot::displayMap() const {
  for (const auto& elem : mPointCloud) {
    const double xLocal{elem.first};
    const double yLocal{elem.second};

    const double xWorld{mPosition.first + xLocal * sin(mHeading) - yLocal * cos(mHeading)};
    const double yWorld{mPosition.second + xLocal * cos(mHeading) + yLocal * sin(mHeading)};

    mDisplay2->drawPixel((WORLD_WIDTH/2 + xWorld) / WORLD_WIDTH * mDP2Width,
                         (WORLD_WIDTH/2 - yWorld) / WORLD_WIDTH * mDP2Height);
  }
}

void EPuckPlusGreenRobot::run() {
  while (step(TIME_STEP) != -1) {
    telecontrol();

    readGPS();
    displayTrajectory();

    readCompass();
    readLidar();
    displayMap();
  }
}