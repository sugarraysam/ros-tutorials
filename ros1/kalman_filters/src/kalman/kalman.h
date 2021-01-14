#include "gaussian.h"
#include <ostream>

class Kalman {
private:
  Gaussian _state;

public:
  Kalman(Gaussian g) : _state(g) {}
  void measurement_update(Gaussian const &measurement);
  void state_prediction(Gaussian const &motion);
  Gaussian get_state();

  friend std::ostream &operator<<(std::ostream &os, const Kalman &k);
};
