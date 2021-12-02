#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular& celular) {
  this->m_celulares.push_front(celular);
}

void swapCellphones(Celular* a, Celular* b) {
  Celular temporary = *a;
  *a = *b;
  *b = temporary;
}

Celular getCellphoneByIndex(std::list<Celular> _list, int _idx) {
  std::list<Celular>::iterator it = _list.begin();

  for (int i = 0; i < _idx; i ++)
    ++it;

  return *it;
}

int partitionList(std::list<Celular> cellphoneArr, int low, int high) {
  Celular pivot = getCellphoneByIndex(cellphoneArr, high);    // pivot
  int i = (low - 1);  // Index of smaller element

  for (int j = low; j <= high - 1; j++)  {
    // If current element is smaller than or
    // equal to pivot
    Celular currentCellphone = getCellphoneByIndex(cellphoneArr, j);
    if (!(pivot.operator<(currentCellphone))) {
      i++;    // increment index of smaller element
      Celular smallerElement = getCellphoneByIndex(cellphoneArr, i);
      swapCellphones(&smallerElement, &currentCellphone);
    }
  }
  
  Celular swapWithPivotCellphone = getCellphoneByIndex(cellphoneArr, i + 1);
  swapCellphones(&swapWithPivotCellphone, &pivot);
  return (i + 1);
}

void quickSort(std::list<Celular> cellphoneArr, int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
        at right place */
    int pi = partitionList(cellphoneArr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(cellphoneArr, low, pi - 1);
    quickSort(cellphoneArr, pi + 1, high);
  }
}

bool compareItens(Celular first, Celular second) {
  std::string trimmedFirstFabricant = first.fabricante.substr(1, first.fabricante.length());
  std::string trimmedSecondFabricant = second.fabricante.substr(1, second.fabricante.length());

  std::string trimmedFirstModel = first.modelo.substr(1, first.modelo.length());
  std::string trimmedSecondModel = second.modelo.substr(1, second.modelo.length());

  if(first.fabricante != second.fabricante)
    return first.fabricante < second.fabricante;
  else if(first.modelo != second.modelo)
    return first.modelo < second.modelo;
}

void Venda::ordena() {
  // int n = this->m_celulares.size();
  // quickSort(this->m_celulares, 0, n-1);

  this->m_celulares.sort(compareItens);
}

void Venda::recarregaEstoque(int cod, int qtd) {
  std::list<Celular>::iterator it;
  for (it = this->m_celulares.begin(); it != this->m_celulares.end(); ++it) {
    if(it->getCellphoneId() == cod) {
      it->qtd += qtd;
      return;
    }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {
  std::list<Celular>::iterator it;
  for (it = this->m_celulares.begin(); it != this->m_celulares.end(); ++it) {
    if(it->getCellphoneId() == cod) {
      if(it->qtd >= qtd)
        it->qtd -= qtd;
      if(it->qtd == 0)
        Venda::removeModelo(cod);
      return;
    }
  }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  std::list<Celular>::iterator it;
  for (it = this->m_celulares.begin(); it != this->m_celulares.end(); ++it) {
    if(it->fabricante == fabricante)
      it->valor -= it->valor*(desconto/100);
  }
}

void Venda::removeModelo(int cod) {
  std::list<Celular>::iterator it;
  for (it = this->m_celulares.begin(); it != this->m_celulares.end(); ++it) {
    if(it->getCellphoneId() == cod) {
      this->m_celulares.erase(it);
      return;
    }
  } 
}

void Venda::imprimeEstoque() const {
  for(const auto& celular : this->m_celulares) {
    std::cout << celular.fabricante; 
    std::cout << " ";

    std::cout << celular.modelo; 
    std::cout << ", ";

    std::cout << celular.armazenamento; 
    std::cout << "GB, ";

    std::cout << celular.memoria; 
    std::cout << "GB RAM, ";

    std::cout << (int)(celular.peso*1000); 
    std::cout << " gramas, ";

    std::string teste = "";
    teste += std::toupper(celular.cor[0]);
    teste += celular.cor.substr(1, celular.cor.size());

    std::cout << teste; 
    std::cout << ", ";

    std::cout << celular.qtd; 
    if(celular.qtd == 1)
      std::cout << " restante, ";
    else
      std::cout << " restantes, ";

    std::cout << "R$ ";
    std::cout << std::fixed << std::setprecision(2) << celular.valor;

    std::cout << std::endl;
  }
}