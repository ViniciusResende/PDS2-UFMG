#include "celular.hpp"

int Celular::id = 0;

Celular::Celular(
  std::string modelo,
  std::string fabricante,
  int armazenamento,
  int memoria,
  double peso,
  std::string cor,
  int qtd,
  float valor) {
  this->modelo = modelo;
  this->fabricante = fabricante;
  this->armazenamento = armazenamento;
  this->memoria = memoria;
  this->peso = peso;
  this->cor = cor;
  this->qtd = qtd;
  this->valor = valor;

  this->id += 1;
  this->cod = this->id;
}

bool Celular::operator<(const Celular& other) {
  std::string trimmedThisFabricant = this->fabricante.substr(1, this->fabricante.length());
  std::string trimmedOtherFabricant = other.fabricante.substr(1, other.fabricante.length());

  if(trimmedThisFabricant < trimmedOtherFabricant)
    return true;
  
  std::string trimmedThisModel = this->modelo.substr(1, this->modelo.length());
  std::string trimmedOtherModel = other.modelo.substr(1, other.modelo.length());

  if((trimmedThisFabricant == trimmedOtherFabricant) && trimmedThisModel < trimmedOtherModel)
    return true;
  
  return false;
}

int Celular::getCellphoneId() {
  return this->cod;
}