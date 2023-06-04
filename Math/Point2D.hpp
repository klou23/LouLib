/**
 * Point2D.hpp
 *
 * Header file for the Point2D class
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

#ifndef LOULIB_POINT2D_HPP
#define LOULIB_POINT2D_HPP

#include "../Units/Units.hpp"

namespace LouLib {
    namespace Math {

        class Point2D {
        private:
            Units::Length x;
            Units::Length y;

        public:

            /**
             * Constructor
             */
            Point2D(const Units::Length &x, const Units::Length &y);

            /**
             * Getter for x
             */
            const Units::Length &getX() const;

            /**
             * Setter for x
             */
            void setX(const Units::Length &x);

            /**
             * Getter for y
             */
            const Units::Length &getY() const;

            /**
             * Setter for y
             */
            void setY(const Units::Length &y);

            /**
             * Calculates the curvature at this point given two other points
             * @param a point before
             * @param b point after
             * @return curvature at this point
             */
            double findCurvature(Point2D a, Point2D b);

            /**
             * Returns the distance to another point
             */
            Units::Length distTo(Point2D a);

        };

    } // LouLib
} // Math

#endif //LOULIB_POINT2D_HPP
