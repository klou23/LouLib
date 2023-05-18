#include "AbstractOdometry.hpp"

namespace LouLib{
    namespace Odometry{

        void AbstractOdometry::setDeltaTime(Units::Time _deltaTime) {
            deltaTimeMs = _deltaTime.to(Units::MILLISECOND);
        }

        Math::Pose2D AbstractOdometry::getPose() {
            return robotPose;
        }
    }
}