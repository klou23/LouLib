/**
 * TwoSensorIMUOdom.cpp
 *
 * Implementation file for the TwoSensorIMUOdom class
 *
 * Copyright (c) 2023 Kevin Lou
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "TwoSensorIMUOdom.hpp"

namespace LouLib {
    namespace Odometry {

        TwoSensorIMUOdom::TwoSensorIMUOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                                           Units::Length trackWidth, OdomIMUSensor &imuSensor) :
                   leftSensor(leftSensor), rightSensor(rightSensor), trackWidth(trackWidth), imuSensor(imuSensor){
            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();
            lastTheta = imuSensor.getHeading();
        }

        void TwoSensorIMUOdom::setPose(Math::Pose2D newPose) {
            robotPose = newPose;
            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();
            lastTheta = imuSensor.getHeading();
        }

        void TwoSensorIMUOdom::update() {
            Units::Length deltaLeft = leftSensor.getPosition() - lastLeft;
            Units::Length deltaRight = rightSensor.getPosition() - lastRight;

            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();

            double deltaX = ((deltaLeft+deltaRight)/2.0).to(Units::INCH);
            double deltaY = 0;
            double deltaTheta = (imuSensor.getHeading() - lastTheta).to(Units::RADIAN);

            lastTheta = imuSensor.getHeading();

            Math::Vector deltaPoseVector({deltaX, deltaY, deltaTheta});

            Math::Matrix PEMatrix({{}});
            if(deltaTheta > Math::EPS){
                PEMatrix = Math::Matrix({{std::sin(deltaTheta)/deltaTheta, (std::cos(deltaTheta)-1)/deltaTheta, 0},
                                         {(1-std::cos(deltaTheta))/deltaTheta, std::sin(deltaTheta)/deltaTheta, 0},
                                         {0, 0, 1}});
            }else{
                PEMatrix = Math::Matrix({{1, 0, 0},
                                         {0, 1, 0},
                                         {0, 0, 1}});
            }

            double theta = robotPose.getTheta().to(Units::RADIAN);

            Math::Matrix rotMatrix({{std::cos(theta), -std::sin(theta), 0},
                                    {std::sin(theta), std::cos(theta), 0},
                                    {0, 0, 1}});

            Math::Vector realPoseChange = rotMatrix * (PEMatrix * deltaPoseVector);

            robotPose.setX(robotPose.getX() + realPoseChange[0] * Units::INCH);
            robotPose.setY(robotPose.getY() + realPoseChange[1] * Units::INCH);
            robotPose.setTheta(robotPose.getTheta() + realPoseChange[2] * Units::RADIAN);
            robotPose.setTheta(Math::constrainAngle(robotPose.getTheta().to(Units::DEGREE)) * Units::DEGREE);
        }

    } // LouLib
} // Odometry