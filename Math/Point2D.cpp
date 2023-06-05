/**
 * @file Point2D.cpp
 *
 * Implementation file for the Point2D class
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

#include "Point2D.hpp"

namespace LouLib {
    namespace Math {

        Point2D::Point2D(const Units::Length &x, const Units::Length &y) : x(x), y(y) {}

        const Units::Length &Point2D::getX() const {
            return x;
        }

        void Point2D::setX(const Units::Length &x) {
            Point2D::x = x;
        }

        const Units::Length &Point2D::getY() const {
            return y;
        }

        void Point2D::setY(const Units::Length &y) {
            Point2D::y = y;
        }

        double Point2D::findCurvature(Point2D a, Point2D b) {
            double x1 = a.getX().to(Units::METER);
            double y1 = a.getY().to(Units::METER);
            double x2 = getX().to(Units::METER);
            double y2 = getY().to(Units::METER);
            double x3 = b.getX().to(Units::METER);
            double y3 = b.getY().to(Units::METER);

            double A = x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2;
            double B = (x1*x1+y1*y1)*(y3-y2)+(x2*x2+y2*y2)*(y1-y3)+
                       (x3*x3+y3*y3)*(y2-y1);
            double C = (x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+
                       (x3*x3+y3*y3)*(x1-x2);
            double D = (x1*x1+y1*y1)*(x3*y2-x2*y3)+(x2*x2+y2*y2)*(x1*y3-x3*y1)+
                       (x3*x3+y3*y3)*(x2*y1-x1*y2);

            if(A < 0.0001) return 0;
            double r = std::sqrt((B*B+C*C-4*A*D)/(4*A*A));
            return 1.0/r;
        }

        Units::Length Point2D::distTo(Point2D a) {
            double dx = (getX() - a.getX()).to(Units::METER);
            double dy = (getY() - a.getY()).to(Units::METER);
            return sqrt(dx*dx + dy*dy) * Units::METER;
        }


    } // LouLib
} // Math