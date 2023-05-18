#ifndef LOULIB_ODOMIMUSENSOR_HPP
#define LOULIB_ODOMIMUSENSOR_HPP

#include "../../../include/api.h"
#include "../Units/Units.hpp"

namespace LouLib {
    namespace Odometry {

        class OdomIMUSensor {
        private:
            pros::IMU imuSensor;

        public:
            explicit OdomIMUSensor(int port);

            Units::Angle getHeading();
        };

    } // LouLib
} // Odometry

#endif //LOULIB_ODOMIMUSENSOR_HPP
