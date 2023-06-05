/**
 * @file OdomRotationSensor.cpp
 *
 * Implementation file for the OdomRotationSensor class
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

#include "OdomRotationSensor.hpp"


LouLib::Odometry::OdomRotationSensor::OdomRotationSensor(int port, bool reversed,
        const LouLib::Units::Length &wheelDiam) : rotationSensor(port, reversed), wheelDiam(wheelDiam){
    gearRatio = 1;
    rotationSensor.reset_position();
}

void LouLib::Odometry::OdomRotationSensor::setGearRatio(int wheelSide, int sensorSide) {
    gearRatio = (double)wheelSide/(double)sensorSide;
}

LouLib::Units::Length LouLib::Odometry::OdomRotationSensor::getPosition() {
    Units::Angle drivingRotation = rotationSensor.get_position() * Units::CENTIDEGREE;
    Units::Angle drivenRotation = drivingRotation / gearRatio;
    return drivenRotation.to(Units::RADIAN) * (wheelDiam/2.0);
}
