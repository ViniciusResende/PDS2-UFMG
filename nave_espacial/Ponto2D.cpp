#include "Ponto2D.hpp"
#include <cmath>

Ponto2D::Ponto2D(double x, double y) {
  _x = x;
  _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto) {
  float dx = ponto->_x - this->_x;
  float dy = ponto->_y - this->_y;

  return sqrt(pow(dx, 2) + pow(dy, 2));
}