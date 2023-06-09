/**
 * @file OdomRotationSensor.hpp
 *
 * Header file for the OdomRotationSensor class
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

#ifndef LOULIB_ODOMROTATIONSENSOR_HPP
#define LOULIB_ODOMROTATIONSENSOR_HPP

#include "../../../include/api.h"
#include "../Units/Units.hpp"
#include "AbstractOdomSensor.hpp"

namespace LouLib {
    namespace Odometry{

        /**
         * @class OdomRotationSensor
         * @brief Class representing a rotation sensor being used as an odometry tracking sensor
         */
        class OdomRotationSensor : public AbstractOdomSensor{
        private:
            pros::Rotation rotationSensor;
            Units::Length wheelDiam;
            double gearRatio;

        public:
            /**
             * Constructor
             * @param port
             * @param reversed
             * @param wheelDiam
             */
            OdomRotationSensor(int port, bool reversed, const Units::Length &wheelDiam);

            /**
             * Sets the gear ratio of the sensor
             */
            void setGearRatio(int wheelSide, int sensorSide) override;

            /**
             * Returns the position of the sensor
             */
            Units::Length getPosition() override;
        };

    }
}


#endif //LOULIB_ODOMROTATIONSENSOR_HPP
