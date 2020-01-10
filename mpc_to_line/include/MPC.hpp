#ifndef MPC_H
#define MPC_H

#include <vector>
#include <Eigen/Core>

struct MPC {
  MPC();
  virtual ~MPC();

  // Solve the model given an initial state.
  // Return the next state and actuations as a vector.
  std::vector<double> Solve(const Eigen::VectorXd & x0, 
                            const Eigen::VectorXd & coeffs);
};

#endif  // MPC_H
