#include <iostream>
#include <math.h>
#include <ostream>

class Gaussian {
private:
  double _mu{0};
  double _sigma2{1};

public:
  Gaussian(double mu, double sigma2) : _mu{mu}, _sigma2{sigma2} {}
  double operator()(double x);

  friend std::ostream &operator<<(std::ostream &os, const Gaussian &g);
  friend Gaussian combine(Gaussian a, Gaussian b);
  friend Gaussian add(Gaussian a, Gaussian b);
};
