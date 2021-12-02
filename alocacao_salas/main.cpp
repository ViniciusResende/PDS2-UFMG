// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_alocacao.hpp"
#include "QuadroAlocacao.hpp"

int main() {
    QuadroAlocacao quadroAlocacao;

    vector<Disciplina> vector;
    string codigo, nome, dia, horario, sala;

   
    char input;
    while (cin >> input){
      switch (input){
        case 'a':
          cin >> codigo;
          cin >> nome;
          cin >> dia;
          cin >> horario;
          cin >> sala;
          quadroAlocacao.inserir_alocacao(codigo, nome, dia, horario, sala);
          break;

        case 'm':
          vector = quadroAlocacao.recuperar_disciplinas_mais_ofertadas();
          for(Disciplina d : vector){
              d.imprimir_alocacao();
          }

          break;

        case 'r':
          cin >> codigo;
          cin >> horario;
          quadroAlocacao.remover_alocacao_disciplina(codigo, horario);

          break;

        case 'p':
          quadroAlocacao.imprimir_alocacao_completa();

          break;

        case 'b':
          avaliacao_basica();

          break;
        default:
          break;
      }
    }
    return 0;
}