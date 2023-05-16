/**
 * TBHController.cpp
 *
 * Implementation file for the TBHController class
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

#include "TBHController.hpp"
#include "../Math/MathFunctions.hpp"

namespace LouLib {
    namespace Controllers {
        TBHController::TBHController(double _k) {
            k = _k;
            setpoint = 0;
            maxOutput = 0;
            minOutput = 0;
            deltaTime = 0;
            output = 0;
            tbh = 0;
            prevError = 0;
        }

        void TBHController::setSetpoint(double _setpoint) {
            setpoint = _setpoint;
        }

        void TBHController::setOutputRange(double _minOutput, double _maxOutput) {
            minOutput = _minOutput;
            maxOutput = _maxOutput;
        }

        void TBHController::setDeltaTime(Units::Time _deltaTime) {
            deltaTime = _deltaTime.to(Units::SECOND);
        }

        double TBHController::getOutput() {
            return output;
        }

        void TBHController::update(double measurement) {
            double error = setpoint - measurement;

            output += error * deltaTime * k;

            output = Math::clamp(output, minOutput, maxOutput);

            if(Math::signum(error) != Math::signum(prevError)){
                output = 0.5 * (output + tbh);
                tbh = output;
                prevError = error;
            }
        }
    } // LouLib
} // Controllers