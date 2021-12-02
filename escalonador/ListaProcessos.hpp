#ifndef LISTAPROCESSOS
#define LISTAPROCESSOS

#include <iostream>
#include "Processo.hpp"

struct ListaProcessos {
  //values
  Processo* head = nullptr;
  Processo* tail = nullptr;
  //methods
  void adicionar_processo(Processo* proc);
  Processo* remover_processo_maior_prioridade();
  Processo* remover_processo_menor_prioridade();
  Processo* remover_processo_por_id(int id);
  void imprimir_lista();
};
#endif