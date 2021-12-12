#include "produto.hpp"

int Produto::getQtd() const {
  return this->m_qtd;
}

float Produto::getValor() const {
  return this->m_valor_unitario;
}