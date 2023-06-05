/**
 * @file Trajectory.cpp
 *
 * Implementation file for the Trajectory class
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

#ifndef LOULIB_TRAJECTORY_HPP
#define LOULIB_TRAJECTORY_HPP

#include "BezierCurve.hpp"

namespace LouLib {
    namespace Paths {

        /**
         * @class Trajectory
         * @brief Class used to compute differential drive trajectories
         */
        class Trajectory {
        private:
            std::vector<Units::Length> _x;
            std::vector<Units::Length> _y;
            std::vector<Units::Angle> _theta;
            std::vector<Units::Velocity> _v;
            std::vector<Units::AngularVelocity> _omega;

            std::vector<Units::Length> _distFromStart;
            std::vector<double> _curvature;


        public:
            /**
             * Constructor
             * @param waypoints
             * @param maxVel
             * @param maxAccel
             * @param maxFullSpeedTurnRadius
             * @param finalVel
             */
            Trajectory(std::vector<Math::Pose2D> waypoints, Units::Velocity maxVel, Units::Acceleration maxAccel,
                       Units::Length maxFullSpeedTurnRadius, Units::Velocity finalVel = 0_mps);

            /**
             * Returns the number of points in the computed path
             */
            int size();

            /**
             * Gets the computed x-position at the given index
             */
            Units::Length getX(int i);

            /**
             * Gets the computed y-position at the given index
             */
            Units::Length getY(int i);

            /**
             * Gets the computed heading at the given index
             */
            Units::Angle getTheta(int i);

            /**
             * Gets the computed velocity at the given index
             */
            Units::Velocity getVelocity(int i);

            /**
             * Gets the computed angular velocity at the given index
             */
            Units::AngularVelocity getAngularVelocity(int i);

            /**
             * Gets the arc length from the start of the path to the point
             * at the given index
             */
            Units::Length getDistFromStart(int i);

        };

    } // LouLib
} // Paths

#endif //LOULIB_TRAJECTORY_HPP
