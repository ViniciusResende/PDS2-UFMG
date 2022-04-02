#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fila.h"

TEST_CASE("Testa Fila::Inserir()") {
  Fila fila;
  // Insere um único elemento.
  fila.Inserir(-11);
  REQUIRE(fila.tamanho() == 1);
  CHECK(fila.primeiro() == -11);
  CHECK(fila.ultimo() == -11);
  // Insere um segundo elemento.
  fila.Inserir(-22);
  REQUIRE(fila.tamanho() == 2);
  CHECK(fila.primeiro() == -11);
  CHECK(fila.ultimo() == -22);
  // Insere um terceiro elemento.
  fila.Inserir(-33);
  REQUIRE(fila.tamanho() == 3);
  CHECK(fila.primeiro() == -11);
  CHECK(fila.ultimo() == -33);
}

TEST_CASE("Testa Fila::RemoverPrimeiro()") {
  // Cria uma vila com 3 elementos. 
  Fila fila;
  fila.Inserir(-11);
  fila.Inserir(-22);
  fila.Inserir(-33);

  // Apaga o primeiro elemento.
  fila.RemoverPrimeiro();
  REQUIRE(fila.tamanho() == 2);
  CHECK(fila.primeiro() == -22);
  CHECK(fila.ultimo() == -33);

  // Apaga o segundo elemento.
  fila.RemoverPrimeiro();
  REQUIRE(fila.tamanho() == 1);
  CHECK(fila.primeiro() == -33);
  CHECK(fila.ultimo() == -33);

  // Apaga o último elemento.
  fila.RemoverPrimeiro();
  REQUIRE(fila.tamanho() == 0);
}

TEST_CASE("Testa Fila::tamanho()") {
  Fila fila;
  CHECK(fila.tamanho() == 0);
  fila.Inserir(-11);
  CHECK(fila.tamanho() == 1);
  fila.Inserir(-22);
  CHECK(fila.tamanho() == 2);
  fila.Inserir(-33);
  CHECK(fila.tamanho() == 3);
  fila.RemoverPrimeiro();
  CHECK(fila.tamanho() == 2);
  fila.RemoverPrimeiro();
  CHECK(fila.tamanho() == 1);
  fila.RemoverPrimeiro();
  CHECK(fila.tamanho() == 0);
}

TEST_CASE("Testa se front/back/pop lançam um exceção EmptyException") {
  Fila fila;
  CHECK_THROWS_AS(fila.primeiro(), const Fila::ExcecaoFilaVazia&);
  CHECK_THROWS_AS(fila.ultimo(), const Fila::ExcecaoFilaVazia&);
  CHECK_THROWS_AS(fila.RemoverPrimeiro(), const Fila::ExcecaoFilaVazia&);
}