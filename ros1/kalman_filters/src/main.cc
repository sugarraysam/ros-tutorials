#include "kalman/kalman.h"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  std::vector<Gaussian> measurements = {
      Gaussian(5, 4), Gaussian(6, 4),  Gaussian(7, 4),
      Gaussian(9, 4), Gaussian(10, 4),
  };
  std::vector<Gaussian> motions = {
      Gaussian(1, 2), Gaussian(1, 2), Gaussian(2, 1),
      Gaussian(1, 2), Gaussian(1, 2),
  };

  Kalman k{Gaussian(0, 1000)};

  for (size_t i = 0; i < std::min(motions.size(), measurements.size()); ++i) {
    k.measurement_update(measurements[i]);
    std::cout << "update: " << k << "\n";
    k.state_prediction(motions[i]);
    std::cout << "predict: " << k << "\n";
  }
  return 0;
}
