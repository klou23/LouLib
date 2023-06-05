#ifndef LOULIB_TRAJECTORY_HPP
#define LOULIB_TRAJECTORY_HPP

#include "BezierCurve.hpp"

namespace LouLib {
    namespace Paths {

        /**
         * @class Trajectory
         * @brief Class used to compute differential drive trajectories
         */
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
            /**
             * Constructor
             * @param waypoints
             * @param maxVel
             * @param maxAccel
             * @param maxFullSpeedTurnRadius
             * @param finalVel
             */
            Trajectory(std::vector<Math::Pose2D> waypoints, Units::Velocity maxVel, Units::Acceleration maxAccel,
                       Units::Length maxFullSpeedTurnRadius, Units::Velocity finalVel = 0_mps);

            /**
             * Returns the number of points in the computed path
             */
            int size();

            /**
             * Gets the computed x-position at the given index
             */
            Units::Length getX(int i);

            /**
             * Gets the computed y-position at the given index
             */
            Units::Length getY(int i);

            /**
             * Gets the computed heading at the given index
             */
            Units::Angle getTheta(int i);

            /**
             * Gets the computed velocity at the given index
             */
            Units::Velocity getVelocity(int i);

            /**
             * Gets the computed angular velocity at the given index
             */
            Units::AngularVelocity getAngularVelocity(int i);

            /**
             * Gets the arc length from the start of the path to the point
             * at the given index
             */
            Units::Length getDistFromStart(int i);

        };

    } // LouLib
} // Paths

#endif //LOULIB_TRAJECTORY_HPP
