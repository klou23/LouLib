#include "TwoSensorOdom.hpp"

namespace LouLib {
    namespace Odometry {

        TwoSensorOdom::TwoSensorOdom(AbstractOdomSensor &leftSensor, AbstractOdomSensor &rightSensor,
                                     Units::Length trackWidth) : leftSensor(
                leftSensor), rightSensor(rightSensor), trackWidth(trackWidth) {
            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();
        }

        void TwoSensorOdom::setPose(Math::Pose2D newPose) {
            robotPose = newPose;
            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();
        }

        void TwoSensorOdom::update() {
            Units::Length deltaLeft = leftSensor.getPosition() - lastLeft;
            Units::Length deltaRight = rightSensor.getPosition() - lastRight;

            lastLeft = leftSensor.getPosition();
            lastRight = rightSensor.getPosition();

            double deltaX = ((deltaLeft+deltaRight)/2.0).to(Units::INCH);
            double deltaY = 0;
            double deltaTheta = ((deltaRight-deltaLeft)/trackWidth).to(Units::number);

            std::cout << deltaX << " " << deltaY << " " << deltaTheta << std::endl;

            Math::Vector deltaPoseVector({deltaX, deltaY, deltaTheta});

            Math::Matrix PEMatrix({{}});
            if(deltaTheta > Math::EPS){
                PEMatrix = Math::Matrix({{std::sin(deltaTheta)/deltaTheta, (std::cos(deltaTheta)-1)/deltaTheta, 0},
                                         {(1-std::cos(deltaTheta))/deltaTheta, std::sin(deltaTheta)/deltaTheta, 0},
                                         {0, 0, 1}});
            }else{
                PEMatrix = Math::Matrix({{1, 0, 0},
                                         {0, 1, 0},
                                         {0, 0, 1}});
            }

            double theta = robotPose.getTheta().to(Units::RADIAN);

            Math::Matrix rotMatrix({{std::cos(theta), -std::sin(theta), 0},
                                    {std::sin(theta), std::cos(theta), 0},
                                    {0, 0, 1}});

            Math::Vector realPoseChange = rotMatrix * (PEMatrix * deltaPoseVector);

            robotPose.setX(robotPose.getX() + realPoseChange[0] * Units::INCH);
            robotPose.setY(robotPose.getY() + realPoseChange[1] * Units::INCH);
            robotPose.setTheta(robotPose.getTheta() + realPoseChange[2] * Units::RADIAN);
            robotPose.setTheta(Math::constrainAngle(robotPose.getTheta().to(Units::DEGREE)) * Units::DEGREE);
        }

    } // LouLib
} // Odometry