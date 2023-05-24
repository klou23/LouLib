#include <iostream>
#include "Trajectory.hpp"

namespace LouLib {
    namespace Paths {
        Trajectory::Trajectory(std::vector<Math::Pose2D> waypoints, Units::Velocity maxVel,
                               Units::Acceleration maxAccel, Units::Length maxFullSpeedTurnRadius,
                               Units::Velocity finalVel) {

            //generate points
            std::vector<BezierCurve> bezierCurves;
            for(int i = 0; i < waypoints.size()-1; i++){
                double x0 = waypoints[i].getX().to(Units::METER);
                double y0 = waypoints[i].getY().to(Units::METER);
                double x3 = waypoints[i+1].getX().to(Units::METER);
                double y3 = waypoints[i+1].getY().to(Units::METER);

                double halfDist = std::sqrt(std::pow(x3-x0,2) + std::pow(x3-x0,2))*0.5;
                double x1 = x0 + std::cos(waypoints[i].getTheta().to(Units::RADIAN)) * halfDist;
                double y1 = y0 + std::sin(waypoints[i].getTheta().to(Units::RADIAN)) * halfDist;
                double x2 = x3 - std::cos(waypoints[i+1].getTheta().to(Units::RADIAN)) * halfDist;
                double y2 = y3 - std::sin(waypoints[i+1].getTheta().to(Units::RADIAN)) * halfDist;

                Math::Point2D P0(x0 * Units::METER, y0 * Units::METER);
                Math::Point2D P1(x1 * Units::METER, y1 * Units::METER);
                Math::Point2D P2(x2 * Units::METER, y2 * Units::METER);
                Math::Point2D P3(x3 * Units::METER, y3 * Units::METER);

                std::cout << P0.getX().to(Units::INCH) << " " << P0.getY().to(Units::INCH) << std::endl;
                std::cout << P1.getX().to(Units::INCH) << " " << P1.getY().to(Units::INCH) << std::endl;
                std::cout << P2.getX().to(Units::INCH) << " " << P2.getY().to(Units::INCH) << std::endl;
                std::cout << P3.getX().to(Units::INCH) << " " << P3.getY().to(Units::INCH) << std::endl;
                std::cout << "------" << std::endl;

                bezierCurves.emplace_back(P0, P1, P2, P3);
            }

            std::vector<Math::Point2D> points = bezierCurves[0].decompose(1000);

            for(int i = 1; i < bezierCurves.size(); i++){
                std::vector<Math::Point2D> currPoints = bezierCurves[i].decompose(1000);
                points.insert(points.end(), currPoints.begin()+1, currPoints.end());
            }

            //calculate distances
            std::vector<Units::Length> distance(points.size(), 0_m);
            distance[0] = 0_m;
            for(int i = 1; i < points.size(); i++){
                distance[i] = distance[i - 1] + points[i - 1].distTo(points[i]);
            }

            //calculate curvatures
            std::vector<double> curvature(points.size(), 0);
            for(int i = 1; i < points.size()-1; i++){
                curvature[i] = points[i].findCurvature(points[i-1], points[i+1]);
            }

            std::vector<Units::Velocity> velocities(points.size(), 0_mps);

            //limit velocities using curvature
            double turnSpeedConstant = 1.0/maxFullSpeedTurnRadius.to(Units::METER);
            for(int i = 0; i < points.size(); i++){
                if(curvature[i] < Math::EPS) velocities[i] = maxVel;
                else velocities[i] = std::min(maxVel, maxVel * turnSpeedConstant/curvature[i]);
            }

            //limit velocity based on acceleration
            velocities[0] = 0_mps;
            for(int i = 1; i < points.size(); i++){
                double dist_m = (distance[i] - distance[i-1]).to(Units::METER);
                double v0_mps = velocities[i-1].to(Units::METER_PER_SECOND);
                double a_mps2 = maxAccel.to(Units::METER_PER_SECOND_SQUARED);
                double possibleVel_mps = std::sqrt(v0_mps * v0_mps + 2*a_mps2*dist_m);
                velocities[i] = std::min(velocities[i], possibleVel_mps * Units::METER_PER_SECOND);
            }

            //limit velocity based on braking
            velocities[points.size()-1] = finalVel;
            for(int i = (int)points.size()-2; i >= 0; i--){
                double dist_m = (distance[i+1] - distance[i]).to(Units::METER);
                double v0_mps = velocities[i+1].to(Units::METER_PER_SECOND);
                double a_mps2 = maxAccel.to(Units::METER_PER_SECOND_SQUARED);
                double possibleVel_mps = std::sqrt(v0_mps * v0_mps + 2*a_mps2*dist_m);
                velocities[i] = std::min(velocities[i], possibleVel_mps * Units::METER_PER_SECOND);
            }

            //select points
            _x.push_back(points[0].getX());
            _y.push_back(points[0].getY());
            _v.push_back(velocities[0]);
            _distFromStart.push_back(distance[0]);
            _curvature.push_back(curvature[0]);

            Units::Time timeElapsed = 0_s;
            for(int i = 1; i < points.size(); i++){
                Units::Length dist = distance[i]-distance[i-1];
                Units::Velocity avgVel = (velocities[i-1] + velocities[i])/2.0;
                Units::Time dt = dist/avgVel;
                timeElapsed += dt;
                if(timeElapsed >= 10_ms){
                    _x.push_back(points[i].getX());
                    _y.push_back(points[i].getY());
                    _v.push_back(velocities[i]);
                    _distFromStart.push_back(distance[i]);
                    _curvature.push_back(curvature[i]);
                    timeElapsed -= 10_ms;
                }
            }
            if(points[points.size()-1].getX() != _x[_x.size()-1] ||
               points[points.size()-1].getY() != _y[_y.size()-1]){
                _x.push_back(points[points.size()-1].getX());
                _y.push_back(points[points.size()-1].getY());
                _v.push_back(velocities[points.size()-1]);
                _distFromStart.push_back(distance[points.size()-1]);
                _curvature.push_back(curvature[points.size()-1]);
            }

            //calculate theta values
            _theta.resize(_x.size(), 0_rad);
            for(int i = 1; i < _x.size()-1; i++){
                //TODO: Use smarter angle calculation
//                double x0 = _x[i-1].to(Units::METER);
//                double y0 = _y[i-1].to(Units::METER);
//                double x1 = _x[i].to(Units::METER);
//                double y1 = _y[i].to(Units::METER);
//                double x2 = _x[i+1].to(Units::METER);
//                double y2 = _y[i+1].to(Units::METER);
//                Units::Angle t0 = std::atan2(y1-y0, x1-x0) * Units::RADIAN;
//                double theta0 = (Math::constrainAngle(t0.to(Units::DEGREE)) * Units::DEGREE).to(Units::RADIAN);
//                Units::Angle t1 = std::atan2(y2-y1, x2-x1) * Units::RADIAN;
//                double theta1 = (Math::constrainAngle(t1.to(Units::DEGREE)) * Units::DEGREE).to(Units::RADIAN);
//                Units::Angle avgAngle = 0.5 * (theta0 + theta1) * Units::RADIAN;
//                Units::Angle perp = Math::constrainAngle((avgAngle + 90_deg).to(Units::DEGREE)) * Units::DEGREE;
//                _theta[i] = perp;

                double x1 = _x[i].to(Units::METER);
                double y1 = _y[i].to(Units::METER);
                double x2 = _x[i+1].to(Units::METER);
                double y2 = _y[i+1].to(Units::METER);
                Units::Angle theta = std::atan2(y2-y1, x2-x1) * Units::RADIAN;
                _theta[i] = theta;
            }

            _theta[0] = waypoints[0].getTheta();
            _theta[_theta.size()-1] = waypoints[waypoints.size()-1].getTheta();

            //calculate angular velocities
            _omega.resize(_theta.size(), 0_radps);
            for(int i = 1; i < _theta.size()-1; i++){
                double theta0 = _theta[i-1].to(Units::DEGREE);
                double theta1 = _theta[i+1].to(Units::DEGREE);
                _omega[i] = (Math::angleDifference(theta1,theta0)/0.02) * Units::DEGREE_PER_SECOND;
            }
            _omega[0] = 0_radps;
            _omega[_omega.size()-1] = 0_radps;

        }

        int Trajectory::size() {
            return (int) _x.size();
        }

        Units::Length Trajectory::getX(int i) {
            return _x[i];
        }

        Units::Length Trajectory::getY(int i) {
            return _y[i];
        }

        Units::Angle Trajectory::getTheta(int i) {
            return _theta[i];
        }

        Units::Velocity Trajectory::getVelocity(int i) {
            return _v[i];
        }

        Units::AngularVelocity Trajectory::getAngularVelocity(int i) {
            return _omega[i];
        }

        Units::Length Trajectory::getDistFromStart(int i) {
            return _distFromStart[i];
        }

    } // LouLib
} // Paths