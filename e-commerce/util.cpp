/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include "util.hpp"

#include <iostream>
#include <sstream>
#include <string>

void testaInsert(Venda& venda) {
  std::string modelo, fabricante, cor, tmp;
  int armazenamento, memoria, qtd;
  double peso, valor;

  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, modelo, ',');
  std::getline(iss, fabricante, ',');
  std::getline(iss, cor, ',');

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> armazenamento;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> memoria;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> peso;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> qtd;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> valor;

  venda.adicionaCelular(Celular(modelo, fabricante, armazenamento, memoria,
                                peso, cor, qtd, valor));
}

void testaSell(Venda& venda) {
  int cod, qtd;
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  iss >> cod >> qtd;
  venda.efetuaVenda(cod, qtd);
}

void testaAdd(Venda& venda) {
  int cod, qtd;
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  iss >> cod >> qtd;
  venda.recarregaEstoque(cod, qtd);
}

void testaDel(Venda& venda) {
  int cod;
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  iss >> cod;
  venda.removeModelo(cod);
}

void testaDiscount(Venda& venda) {
  double desconto;
  std::string fabricante;
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  iss >> fabricante >> desconto;
  venda.aplicaDesconto(fabricante, desconto);
}