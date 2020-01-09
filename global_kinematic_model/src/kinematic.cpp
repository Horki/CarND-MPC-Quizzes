#include <kinematic.hpp>

VectorXd globalKinematic(const VectorXd & state,
                         const VectorXd & actuators, double dt) {
  // Create a new vector for the next state.
  VectorXd next_state(state.size());

  /**
   * Implement the global kinematic model,
   *   to return the next state from the inputs.
   */
  // NOTE: state is [x, y, psi, v]
  double x   = state(0);
  double y   = state(1);
  double psi = state(2);
  double v   = state(3);

  // NOTE: actuators is [delta, a]
  double delta = actuators(0);
  double a     = actuators(1);

  // Recall the equations for the model:
  // x_[t+1] = x[t] + v[t] * cos(psi[t]) * dt
  // y_[t+1] = y[t] + v[t] * sin(psi[t]) * dt
  // psi_[t+1] = psi[t] + v[t] / Lf * delta[t] * dt
  // v_[t+1] = v[t] + a[t] * dt
  next_state(0) = x + (v * cos(psi) * dt);
  next_state(1) = y + (v * sin(psi) * dt);
  next_state(2) = psi + (v / Lf * delta * dt);
  next_state(3) = v + (a * dt);

  return next_state;
}

