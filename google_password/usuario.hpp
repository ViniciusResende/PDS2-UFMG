#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @brief Classe que armazena e gerencia as informacoes do usuario.
 *
 */
class Usuario {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis privadas da
   * classe.
   *
   * @param login Login do usuario
   * @param password Password do usuario
   */
  Usuario(const std::string& login, const std::string& password);

  /**
   * @brief Retorna o login do usuario
   *
   * @return std::string Login do usuario
   */
  std::string getLogin() const;

  /**
   * @brief Retorna o password do usuario
   *
   * @return std::string Password do usuario
   */
  std::string getPassword() const;

  /**
   * @brief Atualiza o login do usuario
   *
   * @param login Novo login do usuario
   */
  void setLogin(const std::string& login);

  /**
   * @brief Atualiza o password do usuario
   *
   * @param login Novo password do usuario
   */
  void setPassword(const std::string& password);

 private:
  /**
   * @brief Login do usuario
   *
   */
  std::string login;

  /**
   * @brief Password do usuario
   *
   */
  std::string password;
};

#endif