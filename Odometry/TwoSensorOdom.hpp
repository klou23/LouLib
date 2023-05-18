#ifndef LOULIB_TWOSENSORODOM_HPP
#define LOULIB_TWOSENSORODOM_HPP

#include "AbstractOdometry.hpp"
#include "OdomMotorSensor.hpp"
#include "OdomRotationSensor.hpp"

namespace LouLib {
    namespace Odometry {

        class TwoSensorOdom : public AbstractOdometry{
        private:

            pros::Task *odomTask = nullptr;
            AbstractOdomSensor &leftSensor;
            AbstractOdomSensor &rightSensor;

            Units::Length trackWidth;

            Units::Length lastLeft = 0_in;
            Units::Length lastRight = 0_in;

        public:

            TwoSensorOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                          Units::Length trackWidth);

            void setPose(Math::Pose2D newPose) override;

            void update() override;

        };

    } // LouLib
} // Odometry

#endif //LOULIB_TWOSENSORODOM_HPP
