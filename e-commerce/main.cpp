/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include <iostream>

#include "util.hpp"
#include "venda.hpp"

int main() {
  Venda venda;
  std::string command;
  while (getline(std::cin, command) && !command.empty()) {
    if (command == "insert") {
      testaInsert(venda);
    } else if (command == "sell") {
      testaSell(venda);
    } else if (command == "add") {
      testaAdd(venda);
    } else if (command == "del") {
      testaDel(venda);
    } else if (command == "discount") {
      testaDiscount(venda);
    }
    command = "";
  }
  venda.ordena();
  venda.imprimeEstoque();
  return 0;
}