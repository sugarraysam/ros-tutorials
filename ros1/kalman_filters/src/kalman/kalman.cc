#include "kalman.h"

void Kalman::measurement_update(const Gaussian &measurement) {
  _state = combine(_state, measurement);
}

void Kalman::state_prediction(const Gaussian &motion) {
  _state = add(_state, motion);
}

Gaussian Kalman::get_state() { return _state; }

std::ostream &operator<<(std::ostream &os, const Kalman &k) {
  os << "Kalman(" << k._state << ")";
  return os;
}
