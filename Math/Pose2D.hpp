#ifndef LOULIB_POSE2D_HPP
#define LOULIB_POSE2D_HPP

namespace LouLib {
    namespace Math {

        class Pose2D {
        private:
            double x;
            double y;
            double theta;

        public:

            Pose2D(double x, double y, double theta);

            double getX() const;

            void setX(double x);

            double getY() const;

            void setY(double y);

            double getTheta() const;

            void setTheta(double theta);

        };

    } // LouLib
} // Math

#endif //LOULIB_POSE2D_HPP
