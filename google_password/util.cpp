#include "util.hpp"

#include <iostream>
#include <sstream>

/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

void testaInsert(GooglePassword& passwords) {
  std::string url, login, password;

  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, url, ',');
  std::getline(iss, login, ',');
  std::getline(iss, password, ',');

  passwords.insert(url, login, password);
}

void testaRemove(GooglePassword& passwords) {
  std::string url;
  std::getline(std::cin, url);

  passwords.remove(url);
}

void testaUpdate(GooglePassword& passwords) {
  std::string url, login, old_password, password;

  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::getline(iss, url, ',');
  std::getline(iss, login, ',');
  std::getline(iss, old_password, ',');
  std::getline(iss, password, ',');

  passwords.update(url, login, old_password, password);
}