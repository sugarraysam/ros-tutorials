#include <eigen3/Eigen/LU>
#include <eigen3/Eigen/src/Core/EigenBase.h>
#include <tuple>
#include <vector>

using namespace Eigen;

class Kalman2D {
private:
  MatrixXf _x{2, 1}; // initial state (location + velocity)
  MatrixXf _P{2, 2}; // initial uncertainty
  MatrixXf _u{2, 1}; // external motion
  MatrixXf _F{2, 2}; // next state function
  MatrixXf _H{1, 2}; // measurement function
  MatrixXf _R{1, 1}; // measurement uncertainty
  MatrixXf _I{2, 2}; // identity matrix

public:
  Kalman2D(MatrixXf x, MatrixXf P);
  std::tuple<MatrixXf, MatrixXf> transition(std::vector<float> measurements);
};
