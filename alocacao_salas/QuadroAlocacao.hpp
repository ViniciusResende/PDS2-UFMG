#ifndef QUADROALOCACAO
#define QUADROALOCACAO

#include <iostream>
#include <map>
#include <vector>
#include "Disciplina.hpp"

struct compara_disciplina_f {
  bool operator() (const Disciplina& disciplina1, const Disciplina& disciplina2) {
    return disciplina1._codigo < disciplina2._codigo;
  }
};

struct QuadroAlocacao {
  //values  
  std::map<std::string, Disciplina*, compara_disciplina_f> todasAlocacoes;
  //methods
  void inserir_alocacao(
    std::string codigo, 
    std::string nome, 
    std::string dia, 
    std::string horario, 
    std::string sala
  );
  void remover_alocacao_disciplina(std::string codigo, std::string horario);
  std::vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
  void imprimir_alocacao_completa();
};

#endif