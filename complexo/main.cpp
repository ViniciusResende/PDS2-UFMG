// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "complexo.h"

std::ostream& operator<< (std::ostream& os, const Complexo& c) {
  if (c.imag() >= 0.0) {
  os << c.real() << " + " << c.imag() << "i";
  } else {
  os << c.real() << " - " << -c.imag() << "i";
  }
  return os;
}

TEST_CASE("Complexo::Complexo()") {
  Complexo zero;
  CHECK(zero.real() == doctest::Approx(0.0));
  CHECK(zero.imag() == doctest::Approx(0.0));
}

TEST_CASE("Complexo::Complexo(double)") {
  Complexo a(2);
  CHECK(a.real() == doctest::Approx(2.0));
  CHECK(a.imag() == doctest::Approx(0.0));
}

TEST_CASE("Complexo::Complexo(double, double)") {
  Complexo a(-2.0, -3.0);
  CHECK(a.real() == doctest::Approx(-2.0));
  CHECK(a.imag() == doctest::Approx(-3.0));
}

TEST_CASE("Complexo::real()") {
  Complexo a(2.0, 3.0);
  CHECK(a.real() == doctest::Approx(2.0));

  Complexo b(-2.0, 3.0);
  CHECK(b.real() == doctest::Approx(-2.0));
}

TEST_CASE("Complexo::imag()") {
  Complexo a(2.0, 3.0);
  CHECK(a.imag() == doctest::Approx(3.0));

  Complexo b(2.0, -3.0);
  CHECK(b.imag() == doctest::Approx(-3.0));
}

TEST_CASE("Complexo::operator==(Complexo)"){
  Complexo zero;
  Complexo a(2, 3);
  Complexo b(2, -3);
  CHECK(zero == Complexo(0, 0));
  CHECK(a == a);
  CHECK_FALSE(b == a);
}

TEST_CASE("Complexo::operator=(Complexo)"){
  Complexo a(2, 3);
  Complexo b(4, 5);
  CHECK_FALSE(b == Complexo(2, 3));
  b = a;
  CHECK(b == Complexo(2, 3));
}

TEST_CASE("Complexo::modulo()") {
  Complexo a(3.0, 4.0);
  CHECK(a.modulo() == doctest::Approx(5.0));
  
  Complexo b(1.0, 1.0);
  CHECK(b.modulo() == doctest::Approx(1.414213));
}

TEST_CASE("Complexo::conjugado()") {
  Complexo zero;
  Complexo a(2, 3);
  Complexo b(2, -3);
  CHECK((zero.conjugado() == Complexo(0, 0)));
  CHECK((a.conjugado().conjugado() == a));
  CHECK((a.conjugado() == Complexo(2.0, -3.0)));
  CHECK((b.conjugado() == Complexo(2.0, 3.0)));
}

TEST_CASE("Complexo::operador-()") {
  Complexo zero;
  CHECK(-zero == Complexo(0, 0));

  Complexo a(2, 0);
  CHECK(-a == Complexo(-2, 0));

  Complexo b(-2, 0);
  CHECK(-b == Complexo(2, 0));

  Complexo c(0, 2);
  CHECK(-c == Complexo(0, -2));

  Complexo d(4, 2);
  CHECK((-d == Complexo(-4, -2)));
}

TEST_CASE("Complexo::inverso()") {
  Complexo a(0, 2);
  CHECK(a.inverso() ==  Complexo(0, -1.0 / 2));

  Complexo b(2.0, 0.0);
  CHECK(b.inverso() == Complexo(1.0 / 2, 0));
}

TEST_CASE("Complexo::operator+(Complexo)") {
  Complexo zero;
  Complexo a(2, 3);
  Complexo b(-2, -3);
  CHECK(zero + zero == Complexo(0, 0));
  CHECK(zero + a ==  Complexo(2, 3));
  CHECK(b + zero ==  Complexo(-2, -3));
  CHECK(a + b == Complexo(0, 0));
}

TEST_CASE("Complexo::operator-(Complexo)") {
  Complexo zero;
  Complexo a(2, 3);
  Complexo b(-2, -3);
  CHECK(zero - zero == Complexo(0, 0));
  CHECK(zero - a ==  Complexo(-2, -3));
  CHECK(b - zero ==  Complexo(-2, -3));
  CHECK(a - b == Complexo(4, 6));
  CHECK(b - a == Complexo(-4, -6));
}

TEST_CASE("Complexo::operator*(Complexo)") {
  Complexo zero;
  Complexo b(2, 3);
  Complexo c(-2, -3);
  Complexo d(0, 1);
  CHECK(zero * zero == Complexo(0, 0));
  CHECK(zero * b ==  Complexo(0, 0));
  CHECK(c * zero ==  Complexo(0, 0));
  CHECK(b * c == Complexo(5, -12));
  CHECK(b * c == c * b);
  CHECK(d * d == Complexo(-1, 0));
}

TEST_CASE("Complexo::operator/(Complexo)") {
  Complexo zero;
  Complexo a(2, 3);
  Complexo b(-2, -3);
  Complexo c(0, 1);
  CHECK(a / a ==  Complexo(1, 0));
  CHECK(zero / a ==  Complexo(0, 0));
  CHECK(a / b == Complexo(-1, 0));
  CHECK(b / a == Complexo(-1, 0));
  CHECK(c / c == Complexo(1, 0));
}

