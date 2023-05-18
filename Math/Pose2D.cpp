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