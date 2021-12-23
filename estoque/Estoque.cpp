#include <string>
#include <iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  std::map<std::string, unsigned int>::iterator it = this->m_mercadorias.find(mercadoria);
  if(it == m_mercadorias.end()) 
    this->m_mercadorias.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));
  else
    it->second += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  std::map<std::string, unsigned int>::iterator it = this->m_mercadorias.find(mercadoria);
  if(it == m_mercadorias.end()) {
    std::cout << "Mercadoria não existe." << std::endl;
    return;
  }

  if(it->second < qtd) {
    std::cout << "Quantidade excede o estoque." << std::endl;
    return;
  }

  it->second -= qtd;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  std::map<const std::string, unsigned int>::const_iterator it = this->m_mercadorias.find(mercadoria);
  if(it == m_mercadorias.end()) {
    std::cout << "Mercadoria não existe." << std::endl;
    return 0;
  }

  return it->second;
}

void Estoque::imprime_estoque() const {
  std::map<std::string, unsigned int>::const_iterator it;
  for (it = this->m_mercadorias.begin(); it != this->m_mercadorias.end(); it++) {
    std::cout << it->first << ", " << it->second << std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  std::map<std::string, unsigned int>::const_iterator externalIterator;
  for (externalIterator = rhs.m_mercadorias.begin(); externalIterator != rhs.m_mercadorias.end(); externalIterator++) {
    std::map<std::string, unsigned int>::iterator internalIterator = this->m_mercadorias.find(externalIterator->first);

    if(internalIterator == this->m_mercadorias.end()) 
      this->m_mercadorias.insert(std::pair<std::string, unsigned int>(externalIterator->first, externalIterator->second));
    else
      internalIterator->second += externalIterator->second;
  }
  
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  std::map<std::string, unsigned int>::const_iterator externalIterator;
  for (externalIterator = rhs.m_mercadorias.begin(); externalIterator != rhs.m_mercadorias.end(); externalIterator++) {
    std::map<std::string, unsigned int>::iterator internalIterator = this->m_mercadorias.find(externalIterator->first);

    if(internalIterator != this->m_mercadorias.end()) 
      internalIterator->second -= externalIterator->second;      
  }
  
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  std::map<std::string, unsigned int>::const_iterator externalIterator;
  for (externalIterator = lhs.m_mercadorias.begin(); externalIterator != lhs.m_mercadorias.end(); externalIterator++) {
    std::map<std::string, unsigned int>::iterator internalIterator = rhs.m_mercadorias.find(externalIterator->first);

    if(internalIterator == rhs.m_mercadorias.end()) 
      return false;

    if(externalIterator->second >= internalIterator->second)
      return false;
  }

  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  std::map<std::string, unsigned int>::const_iterator externalIterator;
  for (externalIterator = rhs.m_mercadorias.begin(); externalIterator != rhs.m_mercadorias.end(); externalIterator++) {
    std::map<std::string, unsigned int>::iterator internalIterator = lhs.m_mercadorias.find(externalIterator->first);

    if(internalIterator == lhs.m_mercadorias.end()) 
      return false;

    if(internalIterator->second <= externalIterator->second)
      return false;
  }

  return true;
}