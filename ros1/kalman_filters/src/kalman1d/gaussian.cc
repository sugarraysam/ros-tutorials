#include "gaussian.h"

double Gaussian::operator()(double x) {
  return 1.0 / std::sqrt(2 * M_PI * _sigma2) *
         std::exp(-0.5 * std::pow((x - _mu), 2.0) / _sigma2);
}

std::ostream &operator<<(std::ostream &os, const Gaussian &g) {
  os << "Gaussian(mu: " << g._mu << ", sigma2: " << g._sigma2 << ")";
  return os;
}

Gaussian combine(Gaussian a, Gaussian b) {
  double mu = (b._sigma2 * a._mu + a._sigma2 * b._mu) / (a._sigma2 + b._sigma2);
  double sigma2 = 1 / (1 / a._sigma2 + 1 / b._sigma2);
  return Gaussian(mu, sigma2);
}

Gaussian add(Gaussian a, Gaussian b) {
  return Gaussian(a._mu + b._mu, a._sigma2 + b._sigma2);
}
