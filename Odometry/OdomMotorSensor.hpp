#ifndef LOULIB_ODOMMOTORSENSOR_HPP
#define LOULIB_ODOMMOTORSENSOR_HPP

#include "../../../include/api.h"
#include "../Units/Units.hpp"

namespace LouLib {
    namespace Odometry {

        class OdomMotorSensor {
        private:
            pros::Motor motor;
            Units::Length wheelDiam;
            double gearRatio;

        public:
            OdomMotorSensor(int motorPort, pros::motor_gearset_e_t gearset, bool motorReversed,
                            const Units::Length &wheelDiam);

            void setGearRatio(int driven, int driving);

            Units::Length getPosition();
        };

    } // LouLib
} // Odometry

#endif //LOULIB_ODOMMOTORSENSOR_HPP
