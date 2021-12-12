#include <sstream>
#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */

  std::ostringstream stream;
  stream << std::to_string(this->getQtd()) << "X ";
  stream << "Comida Japonesa - ";
  stream << this->combinado << ", ";
  stream << std::to_string(this->sushis) << " sushis, ";
  stream << std::to_string(this->temakis) << " temakis e ";
  stream << std::to_string(this->hots) << " hots.";

  std::string description = stream.str();
   
  return description;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  this->combinado = combinado;
  this->sushis = sushis;
  this->temakis = temakis;
  this->hots = hots;

  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}