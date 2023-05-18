#include "AbstractOdometry.hpp"

namespace LouLib{
    namespace Odometry{

        Math::Pose2D AbstractOdometry::getPose() {
            return robotPose;
        }

        AbstractOdometry::AbstractOdometry() : robotPose(0_in, 0_in, 0_deg){

        }

    }
}