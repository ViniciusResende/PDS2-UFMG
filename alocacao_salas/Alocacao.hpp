#ifndef ALOCACAO
#define ALOCACAO

#include <iostream>
struct Alocacao {
  //values  
  std::string _dia, _horario, _sala;
  //constructor
  Alocacao(std::string _dia = "", std::string _horario = "", std::string _sala = "");
  //methods
  void imprimir_dados();
};

#endif