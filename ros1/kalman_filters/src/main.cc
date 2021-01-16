#include "kalman2d/kalman.h"
#include <iostream>
#include <tuple>

int main(int argc, char **argv) {
  std::vector<float> measurements = {1, 2, 3};
  MatrixXf x{2, 1};
  x << 0, 0;
  MatrixXf P{2, 2};
  P << 100, 0, 0, 100;

  Kalman2D kalman{x, P};
  std::tie(x, P) = kalman.transition(measurements);
  std::cout << "x= " << x << "\n";
  std::cout << "P= " << P << "\n";
  return 0;
}
