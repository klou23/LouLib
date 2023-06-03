/**
 * RamseteController.hpp
 *
 * Header file for the RamseteController class
 *
 * Copyright (c) 2023 Kevin Lou
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef LOULIB_RAMSETECONTROLLER_HPP
#define LOULIB_RAMSETECONTROLLER_HPP

#include "../Paths/Trajectory.hpp"

namespace LouLib {
    namespace Controllers {

        /**
         * @class RamseteController
         * Class used as a RAMSETE non-linear, time-varying uncycle controller
         */
        class RamseteController {
        private:
            double b;
            double zeta;

            Units::Velocity v = 0_mps;
            Units::AngularVelocity omega = 0_radps;

        public:
            /**
             * Creates a new RAMSETE controller with the given gains
             */
            RamseteController(double b, double zeta);

            /**
             * Computes the optimal trajectory following control
             * @param t The trajectory the robot is following
             * @param idx The current index along the trajectory
             * @param robotPose The current pose of the robot
             */
            void computeControl(Paths::Trajectory& t, int idx, Math::Pose2D robotPose);

            /**
             * Returns the computed velocity value
             */
            const Units::Velocity &getV() const;

            /**
             * Returns the computed angular velocity value
             */
            const Units::AngularVelocity &getOmega() const;

        };

    } // LouLib
} // Controllers

#endif //LOULIB_RAMSETECONTROLLER_HPP
