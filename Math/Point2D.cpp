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


    } // LouLib
} // Math