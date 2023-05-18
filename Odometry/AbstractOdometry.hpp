#ifndef LOULIB_ABSTRACTODOMETRY_HPP
#define LOULIB_ABSTRACTODOMETRY_HPP

#include "../Units/Units.hpp"
#include "../../../include/api.h"
#include "../Math/Math.hpp"

namespace LouLib {
    namespace Odometry {

        class AbstractOdometry {
        protected:

            Math::Pose2D robotPose;

        public:

            AbstractOdometry();

            virtual void setPose(Math::Pose2D newPose) = 0;

            virtual void update() = 0;

            Math::Pose2D getPose();
        };

    } // LouLib
} // Odometry

#endif //LOULIB_ABSTRACTODOMETRY_HPP
