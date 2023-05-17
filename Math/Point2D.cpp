#include "Point2D.hpp"

namespace LouLib {
    namespace Math {
        Point2D::Point2D(double x, double y) : x(x), y(y) {}

        double Point2D::getX() const {
            return x;
        }

        void Point2D::setX(double x) {
            Point2D::x = x;
        }

        double Point2D::getY() const {
            return y;
        }

        void Point2D::setY(double y) {
            Point2D::y = y;
        }
    } // LouLib
} // Math