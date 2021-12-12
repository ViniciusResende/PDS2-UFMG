#include <sstream>
#include "pedido.hpp"

Pedido::~Pedido() {
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */

  while(!this->m_produtos.empty()) delete this->m_produtos.front(), this->m_produtos.pop_front();
}

void Pedido::setEndereco(const std::string& endereco) {
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float total = 0.0;
  std::list<Produto*>::const_iterator it;
  for (it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it) {
    float itemPrice = (*it)->getQtd() * (*it)->getValor();
    total += itemPrice;
  }
  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  this->m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  std::list<Produto*>::const_iterator it;
  std::ostringstream stream;
  for (it = this->m_produtos.begin(); it != this->m_produtos.end(); ++it) {
    stream << (*it)->descricao() << std::endl;
  }
  stream << "Endereco: " << this->m_endereco << std::endl;
  std::string description = stream.str();

  return description;
}