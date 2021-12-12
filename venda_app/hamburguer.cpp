#include <sstream>
#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  std::ostringstream stream;
  stream << std::to_string(this->getQtd()) << "X ";
  stream << "Hamburguer " << this->tipo;
  stream << (this->artesanal ? " artesanal" : " simples");

  std::string description = stream.str();
   
  return description;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  this->tipo = tipo;
  this->artesanal = artesanal;

  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}