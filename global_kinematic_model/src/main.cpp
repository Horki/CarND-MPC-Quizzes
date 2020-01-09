// In this quiz you'll implement the global kinematic model.
#include <iostream>
#include <Eigen/Core>
#include <kinematic.hpp>
#include <iomanip>

int main() {
  using Eigen::VectorXd;
  // [x, y, psi, v]
  VectorXd state(4);
  // [delta, v]
  VectorXd actuators(2);

  state << 0, 0, deg2rad(45), 1;
  actuators << deg2rad(5), 1;

  // should be [0.212132, 0.212132, 0.798488, 1.3]
  VectorXd next_state = globalKinematic(state, actuators, 0.3);

  std::cout << next_state << std::endl;
}
