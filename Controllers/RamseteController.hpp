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

        class RamseteController {
        private:
            double b;
            double zeta;

            Units::Velocity v = 0_mps;
            Units::AngularVelocity omega = 0_radps;

        public:
            RamseteController(double b, double zeta);

            void computeControl(Paths::Trajectory& t, int idx, Math::Pose2D robotPose);

            const Units::Velocity &getV() const;

            const Units::AngularVelocity &getOmega() const;

        };

    } // LouLib
} // Controllers

#endif //LOULIB_RAMSETECONTROLLER_HPP
