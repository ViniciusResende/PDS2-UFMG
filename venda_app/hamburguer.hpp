#ifndef HAMBURGUER_H
#define HAMBURGUER_H

#include "produto.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um produto do tipo Hamburguer.
 *
 */
class Hamburguer : public Produto {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   *
   * @param tipo Tipo do hamburguer. Ex: X-salada.
   * @param artesanal Informa se o hamburguer e artesanal ou nao
   * @param qtd Quantidade de hamburgueres
   * @param valor_unitario Valor unitario do hamburguer
   */
  Hamburguer(const std::string& tipo,
             bool artesanal,
             int qtd,
             float valor_unitario);

  /**
   * @brief Retorna uma descricao detalhada do hamburguer.
   *
   * @return std::string Descricao detalhada do hamburguer
   */
  std::string descricao() const override;

 private:
  std::string tipo{""};
  bool artesanal{false};
};
#endif