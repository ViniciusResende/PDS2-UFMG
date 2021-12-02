#ifndef GOOGLE_PASSWORD_H
#define GOOGLE_PASSWORD_H

#include "usuario.hpp"

#include <map>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das credenciais
 * salvas de um site.
 */
class GooglePassword {
 public:
  /**
   * @brief Adiciona uma nova credencial.
   * @param url Endereco do site.
   * @param login Login utilizado no cadastro.
   * @param password Password utilizado no cadastro.
   */
  void insert(const std::string& url,
              const std::string& login,
              const std::string& password);

  /**
   * @brief Remove as informacoes de um determinado site.
   * @param url Endereco do site.
   */
  void remove(const std::string& url);

  /**
   * @brief Atualiza as credenciais utilizadas em um site.
   * @param url Endereco do site.
   * @param login Novo login que deve ser atualizado.
   * @param old_password Password antigo.
   * @param new_password Novo password que deve ser atualizado.
   */
  void update(const std::string& url,
              const std::string& login,
              const std::string& old_password,
              const std::string& new_password);

  /**
   * @brief Imprime as informacoes salvas de todos os sites.
   */
  void printPasswords();

 private:
  /**
   * @brief Verifica se o password passa em todas as restricoes
   *
   * @param password Password que sera verificado
   * @return true Verdadeiro se passa em todas as condicoes
   * @return false Falso se nao passa em pelo menos uma das condicoes
   */
  bool checkPassword(const std::string& password) const;

 private:
  /**
   * @brief Container que armazena as informacoes salvas dos sites. Ele
   * utiliza a url do site como chave e as informacoes sao do tipo Usuario.
   * Logo, um site nao pode estar associado a mais de um usuario e senha.
   */
  std::map<std::string, Usuario> m_passwords;
};
#endif