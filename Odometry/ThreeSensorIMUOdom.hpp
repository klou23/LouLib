#ifndef LOULIB_THREESENSORIMUODOM_HPP
#define LOULIB_THREESENSORIMUODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"
#include "OdomIMUSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class ThreeSensorIMUOdom : public AbstractOdometry{
        private:

            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;

            Units::Length trackWidth;

            AbstractOdomSensor &backSensor;

            Units::Length backDist;

            OdomIMUSensor &imuSensor;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;
            Units::Length lastBack = 0_in;
            Units::Angle lastTheta = 0_deg;

        public:

            ThreeSensorIMUOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                               const Units::Length &trackWidth, AbstractOdomSensor &backSensor,
                               const Units::Length &backDist, OdomIMUSensor &imuSensor);

            void setPose(Math::Pose2D newPose) override;

            void update() override;
        };

    } // LouLib
} // Odometry

#endif //LOULIB_THREESENSORIMUODOM_HPP
