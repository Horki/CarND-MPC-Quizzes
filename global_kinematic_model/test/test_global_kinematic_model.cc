#include <gtest/gtest.h>
#include <kinematic.hpp>
#include <Eigen/Core>

TEST(KinematicTest, test_pi) {
  // using Eigen::VectorXd;
  // EXPECT_TRUE(true);
  EXPECT_EQ(pi(), M_PI) << "Pi is wrong";
}

TEST(KinematicTest, test_deg2rad) {
  double deg = 45.;
  double rad = deg2rad(deg);
  double should_be = 0.78539816339744827899949086713604629039764404296875;
  EXPECT_EQ(rad, should_be) << "deg2rad FAIL";
}

TEST(KinematicTest, test_rad2deg) {
  double rad = 0.78539816339744827899949086713604629039764404296875;
  double deg = rad2deg(rad);
  double should_be = 45.;
  EXPECT_EQ(deg, should_be) << "rad2deg FAIL";
}

TEST(KinematicTest, test_globalKinematic) {
  using Eigen::VectorXd;
  VectorXd state(4);
  VectorXd actuators(2);
  VectorXd should_be(4);
  should_be <<
    0.2121320343559642551678479094334761612117290496826171875,
    0.212132034355964227412272293804562650620937347412109375,
    0.79848813278740571330871489408309571444988250732421875,
    1.3000000000000000444089209850062616169452667236328125;
  state << 0, 0, deg2rad(45), 1;
  actuators << deg2rad(5), 1;

  VectorXd next_state = globalKinematic(state, actuators, 0.3);

  EXPECT_EQ(next_state, should_be) << "Next state FAIL";
}
