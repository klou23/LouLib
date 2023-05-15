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

            PIDController(double _kp, double _ki, double _kd);

            void setTolerance(double _errorTolerance, double _derivativeTolerance = (1<<30));

            void setIntegratorRange(double _integratorRangeMin, double _integratorRangeMax);

            void setOutputRange(double _minOutput, double _maxOutput);

            void setDeltaTime(Units::Time _deltaTime);

            void setSetpoint(double _setpoint);

            bool atSetpoint();

            double getOutput();

            void update(double measurement);

        };

    } // LouLib
} // Controllers

#endif //LOULIB_PIDCONTROLLER_HPP
