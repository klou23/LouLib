/**
 * @file AbstractOdomSensor.hpp
 *
 * Header file for the AbstractOdomSensor class
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

#ifndef LOULIB_ABSTRACTODOMSENSOR_HPP
#define LOULIB_ABSTRACTODOMSENSOR_HPP

#include "../Units/Units.hpp"

namespace LouLib{
    namespace Odometry{

        /**
         * @class AbstractOdomSensor
         * @brief Abstract class representing an odometry tracking sensor
         */
        class AbstractOdomSensor {
        public:
            /**
             * Sets the gear ratio of the sensor
             */
            virtual void setGearRatio(int wheelSide, int sensorSide) = 0;

            /**
             * Returns the position of the sensor
             */
            virtual Units::Length getPosition() = 0;
        };
    }
}


#endif //LOULIB_ABSTRACTODOMSENSOR_HPP
