#include <iostream>
#include "Alocacao.hpp"

Alocacao::Alocacao(std::string dia, std::string horario, std::string sala) {
  this->_dia = dia;
  this->_horario = horario;
  this->_sala = sala;
}

void Alocacao::imprimir_dados() {
  std::cout << this->_dia;
  std::cout << " ";
  std::cout << this->_horario;
  std::cout << " ";
  std::cout << this->_sala;
  std::cout << std::endl;
}