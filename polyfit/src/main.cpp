// In this quiz you'll fit a polynomial to waypoints.

#include <iostream>
#include <polynomial.hpp>

int main() {
  VectorXd xvals(6);
  VectorXd yvals(6);
  // x waypoint coordinates
  xvals << 9.261977, -2.06803, -19.6663, -36.868, -51.6263, -66.3482;
  // y waypoint coordinates
  yvals << 5.17, -2.25, -15.306, -29.46, -42.85, -57.6116;

  /**
   * Use `polyfit` to fit a third order polynomial to the (x, y)
   *   coordinates.
   * Hint: call Eigen::VectorXd polyfit() and pass xvals, yvals, and the
   *   polynomial degree/order
   */
  // Pass the x and y waypoint coordinates along the order of the polynomial.
  //   In this case, 3.
  VectorXd coeffs = polyfit(xvals, yvals, 3);

  // NOTE: use STL iterators, when Eigen 3.3.9 becomes stable
  for (double x = 0.0; x <= 20.0; ++x) {
    // We can evaluate the polynomial at a x coordinate by calling `polyeval`.
    //   The first argument being the coefficients, `coeffs`.
    //   The second being the x coordinate, `x`.
    std::cout << polyeval(coeffs, x) << std::endl;
  }

  // Expected output
  // -0.905562
  // -0.226606
  // 0.447594
  // 1.11706
  // 1.7818
  // 2.44185
  // 3.09723
  // 3.74794
  // 4.39402
  // 5.03548
  // 5.67235
  // 6.30463
  // 6.93236
  // 7.55555
  // 8.17423
  // 8.7884
  // 9.3981
  // 10.0033
  // 10.6041
  // 11.2005
  // 11.7925
}

