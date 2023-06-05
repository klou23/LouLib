/**
 * @file OdomMotorSensor.cpp
 *
 * Implementation file for the OdomMotorSensor class
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

#include "OdomMotorSensor.hpp"

namespace LouLib {
    namespace Odometry {

        OdomMotorSensor::OdomMotorSensor(int motorPort, pros::motor_gearset_e_t gearset, bool motorReversed,
                        const Units::Length &wheelDiam) : motor(motorPort, gearset, motorReversed,
                                pros::E_MOTOR_ENCODER_DEGREES), wheelDiam(wheelDiam){
            gearRatio = 1;
        }

        void OdomMotorSensor::setGearRatio(int wheelSide, int sensorSide) {
            gearRatio = (double)wheelSide/(double)sensorSide;
        }

        Units::Length OdomMotorSensor::getPosition() {
            Units::Angle drivingRotation = motor.get_position() * Units::DEGREE;
            Units::Angle drivenRotation = drivingRotation / gearRatio;
            return drivenRotation.to(Units::RADIAN) * (wheelDiam/2.0);
        }
    } // LouLib
} // Odometry