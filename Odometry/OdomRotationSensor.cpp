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
