#ifndef LOULIB_THREESENSORODOM_HPP
#define LOULIB_THREESENSORODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class ThreeSensorOdom : public AbstractOdometry{
        private:

            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;


            Units::Length trackWidth;

            AbstractOdomSensor &backSensor;

            Units::Length backDist;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;
            Units::Length lastBack = 0_in;

        public:
            ThreeSensorOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                            const Units::Length &trackWidth, AbstractOdomSensor &backSensor,
                            const Units::Length &backDist);

            void setPose(Math::Pose2D newPose) override;

            void update() override;

        };

    } // LouLib
} // Odometry

#endif //LOULIB_THREESENSORODOM_HPP
