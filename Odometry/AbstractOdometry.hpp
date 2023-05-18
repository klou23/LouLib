#ifndef LOULIB_ABSTRACTODOMETRY_HPP
#define LOULIB_ABSTRACTODOMETRY_HPP

#include "../Units/Units.hpp"
#include "../../../include/api.h"
#include "../Math/Math.hpp"

namespace LouLib {
    namespace Odometry {

        class AbstractOdometry {
        private:

            double deltaTimeMs;
            pros::Task odomTask;
            Math::Pose2D robotPose;

        public:

            void setDeltaTime(Units::Time _deltaTime);

            virtual void setPose(Math::Pose2D) = 0;

            virtual void start() = 0;

            virtual void stop() = 0;

            Math::Pose2D getPose();
        };

    } // LouLib
} // Odometry

#endif //LOULIB_ABSTRACTODOMETRY_HPP
