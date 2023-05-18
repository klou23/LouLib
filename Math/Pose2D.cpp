/**
 * Pose2D.cpp
 *
 * Implementation file for the Pose2D class
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

#include "Pose2D.hpp"

namespace LouLib {
    namespace Math {


        Pose2D::Pose2D(const Units::Length &x, const Units::Length &y, const Units::Angle &theta) : x(x), y(y),
                                                                                                    theta(theta) {}

        const Units::Length &Pose2D::getX() const {
            return x;
        }

        void Pose2D::setX(const Units::Length &x) {
            Pose2D::x = x;
        }

        const Units::Length &Pose2D::getY() const {
            return y;
        }

        void Pose2D::setY(const Units::Length &y) {
            Pose2D::y = y;
        }

        const Units::Angle &Pose2D::getTheta() const {
            return theta;
        }

        void Pose2D::setTheta(const Units::Angle &theta) {
            Pose2D::theta = theta;
        }
    } // LouLib
} // Math