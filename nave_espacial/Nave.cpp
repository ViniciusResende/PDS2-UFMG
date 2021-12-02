#include <iostream>
#include "Nave.hpp"

Nave::Nave(Ponto2D posicao, double forca) {
  _posicao = posicao;
  _forca = forca ? forca : 1.0;
}

void Nave::mover(double dx, double dy) {
  this->_posicao._x += dx;
  this->_posicao._y += dy;
}

double Nave::calcular_distancia(Nave* nave) {
  Ponto2D *spaceShipPointer = &nave->_posicao;

  return this->_posicao.calcular_distancia(spaceShipPointer);
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n) {
  int lowerIndex = -1;
  double lowerDistance = -1;

  auto setupValues = [&lowerIndex, &lowerDistance](int idx, double value) {
    lowerIndex = idx;
    lowerDistance = value;
  };

  for (int i = 0; i < n; i++) {
    double distance = this->calcular_distancia(naves[i]);

    if(naves[i] != this) {
      if(lowerDistance != -1) {
        if(distance < lowerDistance) {
          setupValues(i, distance);
        }
      } else {
        setupValues(i, distance);
      }
    }
  }

  return naves[lowerIndex];
}

double measureDamage(double distance, double forca) {
  double damage = (100/distance)*forca;
  return (damage < 30) ? damage : 30;
}

void Nave::atacar(Nave** naves, int n) {
  Nave *closestSpaceship = this->determinar_nave_mais_proxima(naves, n);
  
  double distance = this->calcular_distancia(closestSpaceship);
  double damage = measureDamage(distance, this->_forca);

  closestSpaceship->_energia -= damage;

  if(closestSpaceship->_energia <= 50) {
    std::cout << "Energia baixa!";
  }
}

void Nave::imprimir_status() {
  std::cout << this->_posicao._x;
  std::cout << " "; 
  std::cout << this->_posicao._y;
  std::cout << " "; 
  std::cout << this->_energia << std::endl;
}