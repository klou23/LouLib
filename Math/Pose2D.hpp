/**
 * Pose2D.hpp
 *
 * Header file for the Pose2D class
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

#ifndef LOULIB_POSE2D_HPP
#define LOULIB_POSE2D_HPP

#include "../Units/Units.hpp"

namespace LouLib {
    namespace Math {

        class Pose2D {
        private:
            Units::Length x;
            Units::Length y;
            Units::Angle theta;

        public:

            Pose2D(const Units::Length &x, const Units::Length &y, const Units::Angle &theta);

            const Units::Length &getX() const;

            void setX(const Units::Length &x);

            const Units::Length &getY() const;

            void setY(const Units::Length &y);

            const Units::Angle &getTheta() const;

            void setTheta(const Units::Angle &theta);

        };

    } // LouLib
} // Math

#endif //LOULIB_POSE2D_HPP
