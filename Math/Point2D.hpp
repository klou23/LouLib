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

            Point2D(const Units::Length &x, const Units::Length &y);

            const Units::Length &getX() const;

            void setX(const Units::Length &x);

            const Units::Length &getY() const;

            void setY(const Units::Length &y);

        };

    } // LouLib
} // Math

#endif //LOULIB_POINT2D_HPP
