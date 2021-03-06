#include <vector>
#include <Eigen/QR>
#include <helpers.hpp>
#include <matplotlibcpp.hpp>
#include <MPC.hpp>
#include <iomanip>

namespace plt = matplotlibcpp;

using Eigen::VectorXd;

int main() {
  MPC mpc;
  size_t iters = 50;

  VectorXd ptsx(2);
  VectorXd ptsy(2);
  ptsx << -100, 100;
  ptsy << -1, -1;
  /**
   * Polynomial is fitted to a straight line, so a polynomial with
   *   order 1 is sufficient.
   */
  VectorXd coeffs = polyfit(ptsx, ptsy, 1);
  // NOTE: free feel to play around with these
  double x   = -1;
  double y   = 10;
  double psi = 0;
  double v   = 10;
  // The cross track error is calculated by evaluating at polynomial at x, f(x)
  // and subtracting y.
  double cte = polyeval(coeffs, x) - y;
  // Due to the sign starting at 0, the orientation error is -f'(x).
  // derivative of coeffs[0] + coeffs[1] * x -> coeffs[1]
  double epsi = psi - atan(coeffs[1]);
  VectorXd state(6);
  state << x, y, psi, v, cte, epsi;
  std::vector<double> x_vals     = {state[0]};
  std::vector<double> y_vals     = {state[1]};
  std::vector<double> psi_vals   = {state[2]};
  std::vector<double> v_vals     = {state[3]};
  std::vector<double> cte_vals   = {state[4]};
  std::vector<double> epsi_vals  = {state[5]};
  std::vector<double> delta_vals = {};
  std::vector<double> a_vals     = {};

  for (size_t i = 0; i < iters; ++i) {
    std::cout << "Iteration " << i << std::endl;
    std::vector<double> vars = mpc.Solve(state, coeffs);
    x_vals.push_back(vars[0]);
    y_vals.push_back(vars[1]);
    psi_vals.push_back(vars[2]);
    v_vals.push_back(vars[3]);
    cte_vals.push_back(vars[4]);
    epsi_vals.push_back(vars[5]);
    delta_vals.push_back(vars[6]);
    a_vals.push_back(vars[7]);

    state << vars[0], vars[1], vars[2], vars[3], vars[4], vars[5];
    std::cout << std::setprecision(333);
    std::cout << "x = "     << vars[0] << std::endl;
    std::cout << "y = "     << vars[1] << std::endl;
    std::cout << "psi = "   << vars[2] << std::endl;
    std::cout << "v = "     << vars[3] << std::endl;
    std::cout << "cte = "   << vars[4] << std::endl;
    std::cout << "epsi = "  << vars[5] << std::endl;
    std::cout << "delta = " << vars[6] << std::endl;
    std::cout << "a = "     << vars[7] << std::endl;
    std::cout << std::endl;
  }

  // Plot values
  // NOTE: feel free to play around with this.
  // It's useful for debugging!
  plt::subplot(3, 1, 1);
  plt::title("CTE");
  plt::plot(cte_vals);
  plt::subplot(3, 1, 2);
  plt::title("Delta (Radians)");
  plt::plot(delta_vals);
  plt::subplot(3, 1, 3);
  plt::title("Velocity");
  plt::plot(v_vals);

  plt::show(); // NOTE: Why is show not working
  plt::save("result.png");
  std::cout << "saved to result.png\n";
}
