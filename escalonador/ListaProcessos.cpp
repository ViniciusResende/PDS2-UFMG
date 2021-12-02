#include "ListaProcessos.hpp"
#include "Processo.hpp"

void ListaProcessos::adicionar_processo(Processo* proc) {
  Processo *current = this->head;
  Processo *previous = nullptr;

  if(this->head == nullptr) {
    head = proc;
    tail = proc;
  } else {
    while (current != nullptr) {
      if(head->_prioridade < proc->_prioridade) {
        proc->next = this->head;
        head = proc;
        return;
      }

      if(tail->_prioridade >= proc->_prioridade) {
        tail->next = proc;
        tail = proc;
        return;
      }

      if (current->_prioridade < proc->_prioridade) {
        proc->next = previous->next;
        previous->next = proc;
        return;
      }

      
      previous = current;
      current = current->next;
    }
  }
}

Processo* ListaProcessos::remover_processo_maior_prioridade() {
  Processo* aux = this->head;

  this->head = head->next;

  return aux;
}

Processo* ListaProcessos::remover_processo_menor_prioridade() {
  Processo *current = this->head;
  Processo *previous = nullptr;

  while (current != nullptr) {
    if (current->next == nullptr) {
      this->tail = previous;
      previous->next = nullptr;
      return current;
    }

    previous = current;
    current = current->next;
  }
  return current;
}

Processo* ListaProcessos::remover_processo_por_id(int id) {
  Processo *current = this->head;
  Processo *previous = nullptr;

  while (current != nullptr) {
    if (current->_id == id) {
      if(current == this->tail) {
        previous->next = nullptr;
        this->tail = previous;

        return current;
      }

      if(current == this->head) {
        this->head = current->next;
        return current;
      }

      previous->next = current->next;
      return current;
    }

    previous = current;
    current = current->next;
  }
  return current;
}

void ListaProcessos::imprimir_lista() {
  Processo *current = this->head;

  while (current != nullptr) {
    current->imprimir_dados();
    current = current->next;
  }
}