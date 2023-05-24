#ifndef LOULIB_TRAJECTORY_HPP
#define LOULIB_TRAJECTORY_HPP

#include "BezierCurve.hpp"

namespace LouLib {
    namespace Paths {

        class Trajectory {
        private:
            std::vector<Units::Length> _x;
            std::vector<Units::Length> _y;
            std::vector<Units::Angle> _theta;
            std::vector<Units::Velocity> _v;
            std::vector<Units::AngularVelocity> _omega;

            std::vector<Units::Length> _distFromStart;
            std::vector<double> _curvature;


        public:
            Trajectory(std::vector<Math::Pose2D> waypoints, Units::Velocity maxVel, Units::Acceleration maxAccel,
                       Units::Length maxFullSpeedTurnRadius, Units::Velocity finalVel = 0_mps);

            int size();

            Units::Length getX(int i);

            Units::Length getY(int i);

            Units::Angle getTheta(int i);

            Units::Velocity getVelocity(int i);

            Units::AngularVelocity getAngularVelocity(int i);

            Units::Length getDistFromStart(int i);

        };

    } // LouLib
} // Paths

#endif //LOULIB_TRAJECTORY_HPP
