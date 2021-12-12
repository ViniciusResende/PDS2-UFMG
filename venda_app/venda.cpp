#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  while(!this->m_pedidos.empty()) delete this->m_pedidos.front(), this->m_pedidos.pop_front();
}

void Venda::adicionaPedido(Pedido* p) {
  this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  int numOfOrder = 0;
  float totalOfOrder = 0.0;
  std::list<Pedido*>::const_iterator it;
  for (it = this->m_pedidos.begin(); it != this->m_pedidos.end(); ++it) {
    numOfOrder++;
    std::cout << "Pedido " << numOfOrder << std::endl;
    std::cout << (*it)->resumo();
    totalOfOrder += (*it)->calculaTotal();
  }
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ ";
  std::cout << std::fixed << std::setprecision(2) << totalOfOrder << std::endl;

  std::cout << "Total de pedidos: " << numOfOrder;
}