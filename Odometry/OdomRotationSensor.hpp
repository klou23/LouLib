#ifndef LOULIB_ODOMROTATIONSENSOR_HPP
#define LOULIB_ODOMROTATIONSENSOR_HPP

#include "../../../include/api.h"
#include "../Units/Units.hpp"
#include "AbstractOdomSensor.hpp"

namespace LouLib {
    namespace Odometry{

        class OdomRotationSensor : public AbstractOdomSensor{
        private:
            pros::Rotation rotationSensor;
            Units::Length wheelDiam;
            double gearRatio;

        public:
            OdomRotationSensor(int port, bool reversed, const Units::Length &wheelDiam);

            void setGearRatio(int wheelSide, int sensorSide) override;

            Units::Length getPosition() override;
        };

    }
}


#endif //LOULIB_ODOMROTATIONSENSOR_HPP
