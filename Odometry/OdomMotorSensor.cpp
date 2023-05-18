#include "OdomMotorSensor.hpp"

namespace LouLib {
    namespace Odometry {

        OdomMotorSensor::OdomMotorSensor(int motorPort, pros::motor_gearset_e_t gearset, bool motorReversed,
                        const Units::Length &wheelDiam) : motor(motorPort, gearset, motorReversed,
                                pros::E_MOTOR_ENCODER_DEGREES), wheelDiam(wheelDiam){
            gearRatio = 1;
        }

        void OdomMotorSensor::setGearRatio(int driven, int driving) {
            gearRatio = (double)driven/(double)driving;
        }

        Units::Length OdomMotorSensor::getPosition() {
            Units::Angle drivingRotation = motor.get_position() * Units::DEGREE;
            Units::Angle drivenRotation = drivingRotation / gearRatio;
            return drivenRotation.to(Units::RADIAN) * wheelDiam;
        }
    } // LouLib
} // Odometry