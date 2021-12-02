#ifndef PROCESSO
#define PROCESSO

#include <iostream>
struct Processo {
  //values
  int _id, _prioridade;
  std::string _nome;
  Processo* next = nullptr;
  //constructor
  Processo(int id = -1, std::string  nome = "", int prioridade = 0);
  //methods
  void imprimir_dados();
};
#endif