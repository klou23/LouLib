#ifndef LOULIB_TWOSENSORIMUODOM_HPP
#define LOULIB_TWOSENSORIMUODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"
#include "OdomIMUSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class TwoSensorIMUOdom : public AbstractOdometry{
        private:

            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;
            OdomIMUSensor &imuSensor;

            Units::Length trackWidth;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;
            Units::Angle lastTheta = 0_deg;

        public:

            TwoSensorIMUOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                             Units::Length trackWidth, OdomIMUSensor &imuSensor);

            void setPose(Math::Pose2D newPose) override;

            void update() override;

        };

    } // LouLib
} // Odometry

#endif //LOULIB_TWOSENSORIMUODOM_HPP
