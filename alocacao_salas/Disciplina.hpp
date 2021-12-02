#ifndef DISCIPLINA
#define DISCIPLINA

#include <iostream>
#include <set>
#include "Alocacao.hpp"

struct compara_alocacao_f {
  bool operator() (const Alocacao& alocacao1, const Alocacao& alocacao2) {
    return alocacao1._horario < alocacao2._horario;
  }
};


struct Disciplina {
  //values  
  std::string _codigo, _nome;
  std::set<Alocacao, compara_alocacao_f> alocacao;
  //constructor
  Disciplina(std::string _codigo = "", std::string _nome = "");
  //methods
  void inserir_alocacao(std::string dia, std::string horario, std::string sala);
  void remover_alocacao(std::string horario);
  void imprimir_alocacao();
};

#endif