/**
 * @file BezierCurve.hpp
 *
 * Header file for the BezierCurve class
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

#ifndef LOULIB_BEZIERCURVE_HPP
#define LOULIB_BEZIERCURVE_HPP

#include "../Math/Math.hpp"

namespace LouLib {
    namespace Paths {

        /**
         * @class BezierCurve
         * @brief Class representing a cubic bezier spline curve
         */
        class BezierCurve {
        private:
            Math::Point2D P0;
            Math::Point2D P1;
            Math::Point2D P2;
            Math::Point2D P3;

        public:

            /**
             * Constructor
             * @param p0 control point
             * @param p1 control point
             * @param p2 control point
             * @param p3 control point
             */
            BezierCurve(const Math::Point2D &p0, const Math::Point2D &p1, const Math::Point2D &p2,
                        const Math::Point2D &p3);

            /**
             * Returns the value of the bezier
             */
            Math::Point2D evaluate(double t);

            /**
             * Decomposes the bezier curve into n points
             */
            std::vector<Math::Point2D> decompose(int n);

        };

    } // LouLib
} // Paths

#endif //LOULIB_BEZIERCURVE_HPP
