#include <gtest/gtest.h>
#include <MPC.hpp>
#include <Eigen/Core>

TEST(DISABLED_HelpersTest, test_polyeval) {
  ASSERT_TRUE(false) << "Done in polyfit test";
}

TEST(DISABLED_HelpersTest, test_polyfit_and_polyeval) {
  ASSERT_TRUE(false) << "Done in polyfit test";
}

TEST(DISABLED_HelpersTest, test_polyfit) {
  ASSERT_TRUE(false) << "Done in polyfit test";
}

TEST(MPC_Test, test_solve) {
  using Eigen::VectorXd;
  std::vector<double> should_be {
    -0.5,                                                       // x
    10,                                                         // y
    -0.0817101142314461681426251971060992218554019927978515625, // psi
    10.05000000049938790880332817323505878448486328125,         // v
    -11,                                                        // cte
    -0.0817101142314461681426251971060992218554019927978515625, // episi
    -0.436331999999999997630339976240065880119800567626953125,  // delta
    1,                                                          // a
  };
  VectorXd coeffs(2); // polyfit([-100, 100], [-1, -1], 1)
  coeffs <<
    -0.99999999999999988897769753748434595763683319091796875,
    0;
  double x    = -1;
  double y    = 10;
  double psi  = 0;
  double v    = 10;
  double cte  = -11;  // polyeval(coeffs, x) - y;
  double epsi = psi - atan(coeffs[1]);
  VectorXd state(6);
  state << x, y, psi, v, cte, epsi;

  MPC mpc;
  std::vector<double> result = mpc.Solve(state, coeffs);
  ASSERT_EQ(result.size(), should_be.size()) << "Vectors are not the same size";
  ASSERT_EQ(result, should_be) << "Values are not matching";
  ASSERT_TRUE(std::equal(result.begin(), result.end(),
                       should_be.begin())) << "Values are not matching";
  for (size_t i = 0; i < should_be.size(); ++i) {
    ASSERT_DOUBLE_EQ(result[i], should_be[i]) << "Result[" << i << "] not equal";
  }
}

