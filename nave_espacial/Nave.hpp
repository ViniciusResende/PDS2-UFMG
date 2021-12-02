#ifndef NAVE
#define NAVE
#include "Ponto2D.hpp"
struct Nave {
  // values
  Ponto2D _posicao;
  double _forca;
  double _energia = 100;
  // constructor
  Nave(Ponto2D _posicao, double _forca = 1);
  // methods
  void mover(double dx, double dy);
  double calcular_distancia(Nave* nave);
  Nave* determinar_nave_mais_proxima(Nave** naves, int n);
  void atacar(Nave** naves, int n);
  void imprimir_status();
};
#endif