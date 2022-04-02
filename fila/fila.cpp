#include "fila.h"

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
  this->primeiro_ = new No;
  this->ultimo_ = this->primeiro_;
  this->primeiro_->proximo = this->ultimo_;

  this->isEmpty = true;
}

void Fila::Inserir(int k) {
  if(this->isEmpty) {
    this->primeiro_->chave = k;
    this->ultimo_->chave = k;
    this->primeiro_->proximo = this->ultimo_;
    this->isEmpty = false;

    return;
  }

  No* current = this->primeiro_;

  while (current->proximo != this->ultimo_) {
    current = current->proximo;
  }
  
  No* newItem = new No;
  newItem->chave = k;

  current->proximo->proximo = newItem;

  this->ultimo_ = newItem;
}

void Fila::RemoverPrimeiro() {
  if(this->isEmpty) throw ExcecaoFilaVazia{};

  if(this->primeiro_ == this->ultimo_)
    this->isEmpty = true;

  No* aux = this->primeiro_->proximo;

  delete this->primeiro_;

  this->primeiro_ = aux;
}

int Fila::primeiro() const {
  if(this->isEmpty) throw ExcecaoFilaVazia{};

  return this->primeiro_->chave;
}

int Fila::ultimo() const {
  if(this->isEmpty) throw ExcecaoFilaVazia{};

  return this->ultimo_->chave;
}

int Fila::tamanho() const {
  if(this->isEmpty) return 0;

  No *current = this->primeiro_;
  int counter = 1;

  if(this->primeiro_ == this->ultimo_)
    return counter;

  while (current->proximo != this->ultimo_) {
    current = current->proximo;
    counter++;
  }

  // mais um pois desconsidera o this->ultimo_
  return counter + 1;
}