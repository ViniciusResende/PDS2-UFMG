#ifndef VENDA_H
#define VENDA_H

#include "celular.hpp"

#include <list>
#include <string>

/**
 * @brief Classe responsavel pelo gerenciamento de estoque e vendas de
 * celulares.
 */
class Venda {
 public:
  /**
   * @brief Adiciona um novo lote de celulares ao estoque.
   *
   * @param celular Instancia do objeto Celular que sera adicionado a lista
   */
  void adicionaCelular(const Celular& celular);

  /**
   * @brief Adiciona um novo lote de celulares ao estoque atual de um
   * determinado modelo.
   * @param cod Codigo do celular.
   * @param qtd Quantidade de celulares do lote que esta sendo adicionado.
   */
  void recarregaEstoque(int cod, int qtd);

  /**
   * @brief Processa a venda de um determinado modelo. A quantidade de
   * celulares vendidos deve ser subtraida do estoque atual.
   * @param cod Codigo do celular.
   * @param qtd Quantidade de celulares vendido.
   */
  void efetuaVenda(int cod, int qtd);

  /**
   * @brief Aplica um desconto em todos os celulares de um fabricante.
   * Ex: Desconto de 10% em todos os celulares Samsung.
   * @param fabricante Fabricante do celular.
   * @param desconto Desconto em % que deve ser subtraido dos modelos.
   */
  void aplicaDesconto(const std::string& fabricante, float desconto);

  /**
   * @brief Remove um modelo de celular do estoque.
   * @param cod Codigo do celular.
   */
  void removeModelo(int cod);

  /**
   * @brief Imprime a lista de modelos de celulares que possuem
   * pelo menos uma unidade em estoque.
   */
  void imprimeEstoque() const;

  /**
   * @brief Ordena a lista de modelos de celulares
   *
   */
  void ordena();

 private:
  /**
   * @brief Lista de modelos de celulares em estoque.
   */
  std::list<Celular> m_celulares;
};

#endif