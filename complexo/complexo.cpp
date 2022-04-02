// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
  // mod_ = sqrt(a * a + b * b);
  // arg_ = atan2(b, a);

  this->real_ = a;
  this->imaginary_ = b;
}

double Complexo::real() const {
  return this->real_;
}

double Complexo::imag() const {
  return this->imaginary_;
}

bool Complexo::operator==(Complexo x) const {
  // // Precisão numérica utilizda.    
  // static const double epsilon = 1E-6;

  // // Quando o módulo é zero, não importa o valor do argumento.
  // if (mod_ < epsilon) {   
  //   return fabs(x.mod_ - mod_) < epsilon;
  // } else {
  //   return fabs(x.mod_ - mod_) < epsilon &&
  //          fabs(sin(x.arg_) - sin(arg_)) < epsilon &&
  //          fabs(cos(x.arg_) - cos(arg_)) < epsilon;
  // }

  return (this->real_ == x.real()) && (this->imaginary_ == x.imag());
}

void Complexo::operator=(Complexo x) {
  // mod_ = x.mod_;
  // arg_ = x.arg_;

  this->real_ = x.real();
  this->imaginary_ = x.imag();
} 

double Complexo::modulo() const {
  // return mod_
  return sqrt(this->real_ * this->real_ + this->imaginary_ * this->imaginary_);
}

Complexo Complexo::conjugado() const {
  Complexo c;
  // c.mod_ = mod_;
  // c.arg_ = -arg_;

  c.real_ = this->real_;
  c.imaginary_ = -(this->imaginary_);
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  // c.mod_ = mod_;
  // c.arg_ = arg_ + M_PI;

  c.real_ = -(this->real_);
  c.imaginary_ = -(this->imaginary_);
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  // i.mod_ = 1.0 / mod_;
  // i.arg_ = -arg_;

  double divisor = (this->real_ * this->real_ + this->imaginary_ * this->imaginary_);
  i.real_ = this->real_/divisor;
  i.imaginary_ = -(this->imaginary_)/divisor;

  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  // p.mod_ = mod_ * y.mod_;
  // p.arg_ = arg_ + y.arg_;

  p.real_ = (this->real_ * y.real()) - (this->imaginary_ * y.imag());
  p.imaginary_ = (this->imaginary_ * y.real()) + (this->real_ * y.imag());
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
