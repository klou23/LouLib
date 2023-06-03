/**
 * PIDController.hpp
 *
 * Header file for the PIDController class
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

#ifndef LOULIB_PIDCONTROLLER_HPP
#define LOULIB_PIDCONTROLLER_HPP

#include "../Units/Time.hpp"

namespace LouLib {
    namespace Controllers {

        /**
         * @class PIDController
         * Class used as a Proportional-Integral-Derivative controller
         */
        class PIDController {
        private:
            double kp;
            double ki;
            double kd;
            double errorTolerance;
            double derivativeTolerance;
            double integratorMin;
            double integratorMax;
            double maxOutput;
            double minOutput;
            double deltaTime;
            double setpoint;

            double error;
            double derivative;
            double integral;

        public:

            /**
             * Creates a new PID controller with the given gains
             * @param _kp proportional gain
             * @param _ki integral gain
             * @param _kd derivative gain
             */
            PIDController(double _kp, double _ki, double _kd);

            /**
             * Sets the maximum tolerance of the controller
             * @param _errorTolerance maximum error tolerance
             * @param _derivativeTolerance maximum derivative tolerance. Defaults
             * to infinity
             */
            void setTolerance(double _errorTolerance, double _derivativeTolerance = (1<<30));

            /**
             * Sets the error range in which the integral will accumulate
             * @param _integratorRangeMin lower bound of the range
             * @param _integratorRangeMax upper bound of the range
             */
            void setIntegratorRange(double _integratorRangeMin, double _integratorRangeMax);

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
             * Sets the target value of the controller
             */
            void setSetpoint(double _setpoint);

            /**
             * Returns whether or not the controller has reached the setpoint
             * based on the controller's tolerance
             */
            bool atSetpoint();

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

#endif //LOULIB_PIDCONTROLLER_HPP
