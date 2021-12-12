/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include "util.hpp"

#include <iostream>
#include <sstream>

void readAddress(Pedido* pedido) {
  std::string endereco;

  std::getline(std::cin, endereco);
  pedido->setEndereco(endereco);
}

void readPizza(Pedido* pedido) {
  std::string sabor;
  int pedacos;
  bool borda_recheada;
  int qtd;
  float valor;

  std::string line, tmp;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, sabor, ',');

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> pedacos;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> borda_recheada;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> qtd;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> valor;

  Produto* produto = new Pizza(sabor, pedacos, borda_recheada, qtd, valor);
  pedido->adicionaProduto(produto);
}

void readJapaneseCuisine(Pedido* pedido) {
  std::string item;
  int temaki, hots, sushi;
  int qtd;
  float valor;

  std::string line, tmp;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, item, ',');

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> sushi;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> temaki;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> hots;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> qtd;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> valor;

  Produto* produto = new Japonesa(item, sushi, temaki, hots, qtd, valor);
  pedido->adicionaProduto(produto);
}

void readHamburguer(Pedido* pedido) {
  std::string tipo;
  bool artesanal;
  int qtd;
  float valor;

  std::string line, tmp;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, tipo, ',');

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> artesanal;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> qtd;

  std::getline(iss, tmp, ',');
  std::istringstream(tmp) >> valor;

  Produto* produto = new Hamburguer(tipo, artesanal, qtd, valor);
  pedido->adicionaProduto(produto);
}
