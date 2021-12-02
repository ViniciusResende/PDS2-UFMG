#ifndef UTIL_H
#define UTIL_H

/**
 * Este arquivo contem testes para o VPL. Ele nao deve ser modificado em
 * hipotese alguma. Voce pode usa-lo para testar seu VPL localmente.
 */

#include "google_password.hpp"

void testaInsert(GooglePassword& passwords);
void testaRemove(GooglePassword& passwords);
void testaUpdate(GooglePassword& passwords);

#endif