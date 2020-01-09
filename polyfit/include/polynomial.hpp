#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <Eigen/Core>
#include <Eigen/QR>

using Eigen::VectorXd;
using Eigen::MatrixXd;

// Evaluate a polynomial.
double polyeval(const VectorXd & coeffs, double x);
// Fit a polynomial.
VectorXd polyfit(const VectorXd & xvals, const VectorXd & yvals, int order);

#endif
