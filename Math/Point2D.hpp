#ifndef LOULIB_POINT2D_HPP
#define LOULIB_POINT2D_HPP

namespace LouLib {
    namespace Math {

        class Point2D {
        private:
            double x;
            double y;

        public:
            Point2D(double x, double y);

            double getX() const;

            void setX(double x);

            double getY() const;

            void setY(double y);

        };

    } // LouLib
} // Math

#endif //LOULIB_POINT2D_HPP
