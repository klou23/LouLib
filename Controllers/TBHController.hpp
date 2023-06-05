/**
 * TBHController.hpp
 *
 * Header file for the TBHController class
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

#ifndef LOULIB_TBHCONTROLLER_HPP
#define LOULIB_TBHCONTROLLER_HPP

#include "../Units/Time.hpp"

namespace LouLib {
    namespace Controllers {

        /**
         * @class TBHController
         * @brief Class used as a Take-Back Half controller
         */
        class TBHController {
        private:
            double k;
            double setpoint;
            double maxOutput;
            double minOutput;
            double deltaTime;
            double output;
            double tbh;
            double prevError;

        public:
            /**
             * Creates a new TBH controller with the given gain
             */
            explicit TBHController(double _k);

            /**
             * Sets the target value of the controller
             */
            void setSetpoint(double _setpoint);

            /**
             * Sets the range of possible output values
             * @param _minOutput lower bound for output values
             * @param _maxOutput upper bound for output values
             */
            void setOutputRange(double _minOutput, double _maxOutput);

            /**
             * Sets the amount of time between each controller loop
             */
            void setDeltaTime(Units::Time _deltaTime);

            /**
             * Returns the computed control input
             */
            double getOutput();

            /**
             * Update the PID controller with the new measured value
             */
            void update(double measurement);

        };

    } // LouLib
} // Controllers

#endif //LOULIB_TBHCONTROLLER_HPP
