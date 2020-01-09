#ifndef KINEMATIC_H_
#define KINEMATIC_H_

#include <Eigen/Core>
#include <cmath>

using Eigen::VectorXd;

constexpr double Lf = 2;

//
// Helper functions
//
constexpr double pi()    { return M_PI;             }
double deg2rad(double x) { return x * pi() / 180.0; }
double rad2deg(double x) { return x * 180.0 / pi(); }

// Return the next state.
VectorXd globalKinematic(const VectorXd & state,
                         const VectorXd & actuators, double dt);

#endif
