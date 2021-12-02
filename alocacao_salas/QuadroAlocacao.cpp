#include <iostream>
#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao(
  std::string codigo, 
  std::string nome, 
  std::string dia, 
  std::string horario, 
  std::string sala
) {
  Disciplina* disciplina = new Disciplina;
  disciplina->_codigo = codigo;
  disciplina->_nome = nome;

  std::map<std::string, Disciplina*>::iterator it;
  for(it = this->todasAlocacoes.begin(); it != this->todasAlocacoes.end(); it++) {
    if(it->first == codigo) {
      this->todasAlocacoes[codigo]->inserir_alocacao(dia, horario, sala);
      return;
    }
  }  
  this->todasAlocacoes.insert(std::pair<std::string, Disciplina*>(codigo, disciplina));
  this->todasAlocacoes[codigo]->inserir_alocacao(dia, horario, sala);

  this->imprimir_alocacao_completa();
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario) {
  this->todasAlocacoes[codigo]->remover_alocacao(horario);
}

int findGreaterValue(std::map<std::string, Disciplina*, compara_disciplina_f> todasAlocacoes) {
  int greater = -1;
  std::map<std::string, Disciplina*>::iterator it;
  for (it = todasAlocacoes.begin(); it != todasAlocacoes.end(); it++) {
    int currentElementAlocationSize = int(it->second->alocacao.size());
    if( currentElementAlocationSize > greater)
      greater = currentElementAlocationSize;
  }

  return greater;
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas() {
  std::vector<Disciplina> vector;
  int greater = findGreaterValue(this->todasAlocacoes);

  std::map<std::string, Disciplina*>::iterator it;
  for (it = todasAlocacoes.begin(); it != todasAlocacoes.end(); it++) {
    if(int(it->second->alocacao.size()) == greater)
      vector.push_back(*(it->second));
  }

  return vector;
}

void QuadroAlocacao::imprimir_alocacao_completa() {
  std::map<std::string, Disciplina*>::iterator it;
  for (it = this->todasAlocacoes.begin(); it != this->todasAlocacoes.end(); it++) {
    it->second->imprimir_alocacao();
  }
}