#include "OdomIMUSensor.hpp"

#include "../Math/Math.hpp"

namespace LouLib {
    namespace Odometry {

        OdomIMUSensor::OdomIMUSensor(int port) : imuSensor(port){
            imuSensor.reset();
        }

        Units::Angle OdomIMUSensor::getHeading() {
            double raw = imuSensor.get_heading();
            double bounded = Math::constrainAngle(raw);
            return bounded * Units::DEGREE;
        }

    } // LouLib
} // Odometry