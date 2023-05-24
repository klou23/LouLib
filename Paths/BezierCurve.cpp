/**
 * BezierCurve.cpp
 *
 * Implementation file for the BezierCurve class
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

#include "BezierCurve.hpp"

namespace LouLib {
    namespace Paths {
        BezierCurve::BezierCurve(const Math::Point2D &p0, const Math::Point2D &p1, const Math::Point2D &p2,
                                 const Math::Point2D &p3) : P0(p0), P1(p1), P2(p2), P3(p3) {}

        Math::Point2D BezierCurve::evaluate(double t) {
            Units::Length x = 0_m;
            Units::Length y = 0_m;

            x += std::pow(1-t, 3) * P0.getX();
            x += 3 * std::pow(1-t,2) * t * P1.getX();
            x += 3 * (1-t) * std::pow(t, 2) * P2.getX();
            x += std::pow(t, 3) * P3.getX();

            y += std::pow(1-t, 3) * P0.getY();
            y += 3 * std::pow(1-t,2) * t * P1.getY();
            y += 3 * (1-t) * std::pow(t, 2) * P2.getY();
            y += std::pow(t, 3) * P3.getY();

            return Math::Point2D{x, y};
        }

        std::vector<Math::Point2D> BezierCurve::decompose(int n) {
            std::vector<Math::Point2D> sol;
            for(int i = 0; i < n; i++){
                double t = (double)(i)/(double)(n-1);
                sol.push_back(evaluate(t));
            }
            return sol;
        }

    } // LouLib
} // Paths