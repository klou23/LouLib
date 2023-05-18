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
