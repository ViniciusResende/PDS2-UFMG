#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include "QuadroAlocacao.hpp"

using namespace std;

void avaliacao_basica() {
    
    QuadroAlocacao quadro_alocacao;

    quadro_alocacao.inserir_alocacao("XYZ", "DISC2", "Seg-Qua", "14:55-16:35", "2003");
    quadro_alocacao.inserir_alocacao("XYZ", "DISC2", "Seg-Qua", "19:00-20:40", "2003");

    quadro_alocacao.inserir_alocacao("ABC", "DISC1", "Ter-Qui", "14:55-16:35", "3015");
    quadro_alocacao.inserir_alocacao("ABC", "DISC1", "Ter-Qui", "07:30-09:10", "3015");

    quadro_alocacao.imprimir_alocacao_completa();
    cout << "----------" << endl;

    quadro_alocacao.remover_alocacao_disciplina("ABC", "07:30-09:10");

    quadro_alocacao.imprimir_alocacao_completa();
    cout << "----------" << endl;

    vector<Disciplina> mais_ofertadas = quadro_alocacao.recuperar_disciplinas_mais_ofertadas();
    for (Disciplina &disciplina : mais_ofertadas)
        disciplina.imprimir_alocacao();    
    
}

#endif