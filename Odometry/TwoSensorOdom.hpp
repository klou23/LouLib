/**
 * TwoSensorOdom.hpp
 *
 * Header file for the TwoSensorOdom class
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

#ifndef LOULIB_TWOSENSORODOM_HPP
#define LOULIB_TWOSENSORODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class TwoSensorOdom : public AbstractOdometry{
        private:

            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;

            Units::Length trackWidth;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;

        public:

            TwoSensorOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                          Units::Length trackWidth);

            void setPose(Math::Pose2D newPose) override;

            void update() override;

        };

    } // LouLib
} // Odometry

#endif //LOULIB_TWOSENSORODOM_HPP
