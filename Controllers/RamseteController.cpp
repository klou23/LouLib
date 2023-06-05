/**
 * @file RamseteController.cpp
 *
 * Implementation file for the RamseteController class
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

#include "RamseteController.hpp"

namespace LouLib {
    namespace Controllers {

        RamseteController::RamseteController(double b, double zeta) : b(b), zeta(zeta) {}

        void RamseteController::computeControl(Paths::Trajectory& t, int idx, Math::Pose2D robotPose) {
            double targX = t.getX(idx).to(Units::METER);
            double targY = t.getY(idx).to(Units::METER);
            double targTheta = t.getTheta(idx).to(Units::RADIAN);
            double targV = t.getVelocity(idx).to(Units::METER_PER_SECOND);
            double targOmega = t.getAngularVelocity(idx).to(Units::RADIAN_PER_SECOND);

            double robotX = robotPose.getX().to(Units::METER);
            double robotY = robotPose.getY().to(Units::METER);
            double robotTheta = robotPose.getTheta().to(Units::RADIAN);

            double targTheta_deg = t.getTheta(idx).to(Units::DEGREE);
            double robotTheta_deg = robotPose.getTheta().to(Units::DEGREE);

            double deltaX = targX - robotX;
            double deltaY = targY - robotY;
            double deltaTheta = (Math::angleDifference(targTheta_deg, robotTheta_deg)*Units::DEGREE).to(Units::RADIAN);

            if(std::abs(deltaTheta) < Math::EPS) deltaTheta += 0.0001;

            double ex = std::cos(robotTheta)*deltaX + std::sin(robotTheta)*deltaY;
            double ey = -std::sin(robotTheta)*deltaX + std::cos(robotTheta)*deltaY;
            double et = deltaTheta;

            double k = 2*zeta*std::sqrt(targOmega*targOmega + b*targV*targV);

            v = (targV*std::cos(et) + k*ex) * Units::METER_PER_SECOND;
            omega = (targOmega + k*et + b*targV*std::sin(et)*ey/et) * Units::RADIAN_PER_SECOND;
        }

        const Units::Velocity &RamseteController::getV() const {
            return v;
        }

        const Units::AngularVelocity &RamseteController::getOmega() const {
            return omega;
        }


    } // LouLib
} // Controllers