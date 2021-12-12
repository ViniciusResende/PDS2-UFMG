/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include <iostream>

#include "util.hpp"
#include "venda.hpp"

int main() {
  Venda vendas;
  std::string command;
  std::getline(std::cin, command);
  while (command == "pedido") {
    Pedido* pedido = new Pedido();
    while (std::getline(std::cin, command) && !command.empty()) {
      if (command == "pizza") {
        readPizza(pedido);
      } else if (command == "hamburguer") {
        readHamburguer(pedido);
      } else if (command == "japonesa") {
        readJapaneseCuisine(pedido);
      } else if (command == "endereco") {
        readAddress(pedido);
      } else {
        break;
      }
    }
    vendas.adicionaPedido(pedido);
  }
  vendas.imprimeRelatorio();
  return 0;
}