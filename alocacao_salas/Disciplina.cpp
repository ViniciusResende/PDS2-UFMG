#include <iostream>
#include "Disciplina.hpp"

Disciplina::Disciplina(std::string codigo, std::string nome) {
  this->_codigo = codigo;
  this->_nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala) {
  Alocacao aula;
  aula._dia = dia;
  aula._horario = horario;
  aula._sala = sala;
  this->alocacao.insert({ aula });
}

void Disciplina::remover_alocacao(std::string horario) {
  std::set<Alocacao>::iterator it;
  for (it = this->alocacao.begin(); it != this->alocacao.end(); ++it) {
    if(it->_horario == horario) {
      this->alocacao.erase(it);
      return;
    }
  }
}

void Disciplina::imprimir_alocacao() {
  for(Alocacao a : this->alocacao) {
    std::cout << this->_codigo << " ";
    std::cout << this->_nome << " ";
    a.imprimir_dados();
  }
}