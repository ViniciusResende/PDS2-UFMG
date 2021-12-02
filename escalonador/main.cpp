#include <iostream>
#include <iomanip>
#include "avaliacao_basica_escalonador.hpp"
#include "ListaProcessos.hpp"
#include "Processo.hpp"

using namespace std;

int main() {
  ListaProcessos lista;
  Processo proc;
  int id, prioridade;   
  string nome = "";

  // cout << fixed << showpoint; 
  // cout << setprecision(2);

  char data;
  while (cin >> data) {
    switch (data) {
      case 'a':  
        cin >> id >> nome >> prioridade;

        proc._id = id;
        proc._nome = nome;
        proc._prioridade = prioridade;

        lista.adicionar_processo(&proc);
        break;
      case 'm': 
        lista.remover_processo_maior_prioridade();
        break;
      case 'n':                  
        lista.remover_processo_menor_prioridade();        
        break;           
      case 'r':   
        int id;               
        cin >> id;

        lista.remover_processo_por_id(id);
        break;            
      case 'p':                  
        avaliacao_basica();
        
        break;                                              
    }
  }
    
  return 0;
}