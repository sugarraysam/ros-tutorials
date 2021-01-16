#include "kalman.h"

Kalman2D::Kalman2D(MatrixXf x, MatrixXf P) {
  _x << x;
  _P << P;
  _u << 0, 0;
  _F << 1, 1, 0, 1;
  _H << 1, 0;
  _R << 1;
  _I << 1, 0, 0, 1;
}

std::tuple<MatrixXf, MatrixXf>
Kalman2D::transition(std::vector<float> measurements) {
  for (size_t i = 0; i < measurements.size(); ++i) {
    // Measurement update
    MatrixXf Z{1, 1};
    Z << measurements[i];

    MatrixXf y{1, 1};
    y << Z - (_H * _x);

    MatrixXf S{1, 1};
    S << _H * _P * _H.transpose() + _R;

    MatrixXf K{2, 1};
    K << _P * _H.transpose() * S.inverse();

    _x << _x + (K * y);
    _P << (_I - (K * _H)) * _P;

    // Prediction
    _x << (_F * _x) + _u;
    _P << _F * _P * _F.transpose();
  }
  return std::make_tuple(_x, _P);
}
