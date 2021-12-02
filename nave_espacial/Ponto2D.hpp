#ifndef PONTO2D
#define PONTO2D
struct Ponto2D {
  //values
  double _x, _y;
  //constructor
  Ponto2D(double _x = 0.0, double _y = 0.0);
  //methods
  double calcular_distancia(Ponto2D* ponto);
};
#endif