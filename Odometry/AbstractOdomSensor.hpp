#ifndef LOULIB_ABSTRACTODOMSENSOR_HPP
#define LOULIB_ABSTRACTODOMSENSOR_HPP

#include "../Units/Units.hpp"

namespace LouLib{
    namespace Odometry{
        class AbstractOdomSensor {
        public:
            virtual void setGearRatio(int wheelSide, int sensorSide) = 0;

            virtual Units::Length getPosition() = 0;
        };
    }
}


#endif //LOULIB_ABSTRACTODOMSENSOR_HPP
