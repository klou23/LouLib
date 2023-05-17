#include "Pose2D.hpp"

namespace LouLib {
    namespace Math {
        Pose2D::Pose2D(double x, double y, double theta) : x(x), y(y), theta(theta) {}

        double Pose2D::getX() const {
            return x;
        }

        void Pose2D::setX(double x) {
            Pose2D::x = x;
        }

        double Pose2D::getY() const {
            return y;
        }

        void Pose2D::setY(double y) {
            Pose2D::y = y;
        }

        double Pose2D::getTheta() const {
            return theta;
        }

        void Pose2D::setTheta(double theta) {
            Pose2D::theta = theta;
        }
    } // LouLib
} // Math