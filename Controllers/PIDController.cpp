/**
 * PIDController.cpp
 *
 * Implementation file for the PIDController class
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

#include "PIDController.hpp"
#include "../Math/MathFunctions.hpp"

using namespace LouLib::Units::literals;

namespace LouLib {
    namespace Controllers {

        PIDController::PIDController(double _kp, double _ki, double _kd) {
            kp = _kp;
            ki = _ki;
            kd = _kd;

            error = (1<<30);
            derivative = 0;
            integral = 0;

            setTolerance(0);

            setIntegratorRange(-(1<<30), (1<<30));

            setOutputRange(-(1<<30), (1<<30));

            setDeltaTime(10_ms);

            setSetpoint(0);
        }

        void PIDController::setTolerance(double _errorTolerance, double _derivativeTolerance) {
            errorTolerance = _errorTolerance;
            derivativeTolerance = _derivativeTolerance;
        }

        void PIDController::setIntegratorRange(double _integratorRangeMin, double _integratorRangeMax) {
            integratorMin = _integratorRangeMin;
            integratorMax = _integratorRangeMax;
        }

        void PIDController::setOutputRange(double _minOutput, double _maxOutput) {
            minOutput = _minOutput;
            maxOutput = _maxOutput;
        }

        void PIDController::setDeltaTime(Units::Time _deltaTime) {
            deltaTime = _deltaTime.to(Units::SECOND);
        }

        void PIDController::setSetpoint(double _setpoint) {
            setpoint = _setpoint;
        }

        bool PIDController::atSetpoint() {
            return (error < errorTolerance && derivative < derivativeTolerance);
        }

        double PIDController::getOutput() {
            return kp*error + ki*integral + kd*derivative;
        }

        void PIDController::update(double _error) {

            if(error == (1<<30)) derivative = 0;
            else derivative = (_error - error)/deltaTime;

            if(error >= integratorMin && error <= integratorMax){
                integral += error;
            }else{
                integral = 0;
            }

            if(Math::signum(error) != Math::signum(_error)){
                integral = 0;
            }

            error = _error;
        }

    } // LouLib
} // Controllers