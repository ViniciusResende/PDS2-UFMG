#include <sstream>
#include "pizza.hpp"

std::string Pizza::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
   
  std::ostringstream stream;
  stream << std::to_string(this->getQtd()) << "X ";
  stream << "Pizza " << this->sabor << ", " ;
  stream << std::to_string(this->pedacos) << " pedacos ";
  stream << (this->borda_recheada ? "e borda recheada." : "e sem borda recheada");
  // std::string pizzaBorder = this->borda_recheada ? "e borda recheada" : "sem borda recheada";
  // std::string description = std::to_string(this->getQtd()) + "X " + "Pizza " + this->sabor + ", " + std::to_string(this->pedacos) + " pedacos " + pizzaBorder;

  std::string description = stream.str();
  return description;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;

  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}