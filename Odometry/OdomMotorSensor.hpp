#ifndef LOULIB_ODOMMOTORSENSOR_HPP
#define LOULIB_ODOMMOTORSENSOR_HPP

#include "../../../include/api.h"
#include "../Units/Units.hpp"
#include "AbstractOdomSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class OdomMotorSensor : public AbstractOdomSensor{
        private:
            pros::Motor motor;
            Units::Length wheelDiam;
            double gearRatio;

        public:
            OdomMotorSensor(int motorPort, pros::motor_gearset_e_t gearset, bool motorReversed,
                            const Units::Length &wheelDiam);

            void setGearRatio(int wheelSide, int sensorSide) override;

            Units::Length getPosition() override;
        };

    } // LouLib
} // Odometry

#endif //LOULIB_ODOMMOTORSENSOR_HPP
