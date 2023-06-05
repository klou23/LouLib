/**
 * ThreeSensorOdom.hpp
 *
 * Header file for the ThreeSensorOdom class
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

#ifndef LOULIB_THREESENSORODOM_HPP
#define LOULIB_THREESENSORODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class ThreeSensorOdom : public AbstractOdometry{
        private:

            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;

            Units::Length trackWidth;

            AbstractOdomSensor &backSensor;

            Units::Length backDist;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;
            Units::Length lastBack = 0_in;

        public:

            /**
             * Constructor
             * @param leftSensor
             * @param rightSensor
             * @param trackWidth
             * @param backSensor
             * @param backDist
             */
            ThreeSensorOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                            const Units::Length &trackWidth, AbstractOdomSensor &backSensor,
                            const Units::Length &backDist);

            /**
             * Sets the current pose of the robot
             */
            void setPose(Math::Pose2D newPose) override;

            /**
             * Computes the new position of the robot
             */
            void update() override;

        };

    } // LouLib
} // Odometry

#endif //LOULIB_THREESENSORODOM_HPP
