#include <iostream>
#include "Processo.hpp"

Processo::Processo(int id, std::string  nome, int prioridade) {
  _id = id;
  _prioridade = prioridade;
  _nome = nome;
}

void Processo::imprimir_dados() {
  std::cout << this->_id;
  std::cout << " ";
  std::cout << this->_nome;
  std::cout << " ";
  std::cout << this->_prioridade;
  std::cout << std::endl;
}