#include <iostream>

using namespace std;

int main(){
    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int integerVariable = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *integerPointer = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int *pointerVector =  new int[10];
    for (int i = 0; i < 10; i++) {
      pointerVector[i] = 9 - i;
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1) 
    cout << &integerVariable << endl; //done

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << integerVariable << endl; //done

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &integerPointer << endl; //done
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << integerPointer << endl; //done

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &integerPointer << endl; //done

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &pointerVector[0] << endl; //done

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << pointerVector[0] << endl; //done

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    integerPointer = &integerVariable; 

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << integerPointer << endl; //done

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *integerPointer << endl; //done

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    cout << (&integerVariable == integerPointer) << endl; //done

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *integerPointer = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << integerVariable << endl; //done

    // 17) Atribua o ENDEREÇO da variável (3) à variável declarada em (2)
    integerPointer = &*pointerVector;

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << integerPointer << endl; //done

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *integerPointer << endl; //done

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    integerPointer = &pointerVector[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << integerPointer << endl; //done

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *integerPointer << endl; //done

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < 10; i++) {
      integerPointer = &pointerVector[i];
      *integerPointer *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < 10; i++) {
      cout << pointerVector[i]; //done
      if(i<9) {
        cout << " ";
      }
    }
    cout << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for (int i = 0; i < 10; i++) {
      cout << *(pointerVector + i); //done
      if(i<9) {
        cout << " ";
      }
    }
    cout << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    integerPointer = &*pointerVector;
    for (int i = 0; i < 10; i++) {
      cout << *(integerPointer + i); 
      if(i<9) {
        cout << " ";
      }
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    integerPointer = &pointerVector[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << integerPointer << endl; 

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *integerPointer << endl; 

    // 30) Imprima o VALOR guardado no ENDEREÇO do ponteiro (2) decrementado de 4
    cout << *(integerPointer - 4) << endl; 

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **doublePointer = &integerPointer;

    // 32) Imprima o VALOR da variável declarada em (31)
    cout << doublePointer << endl; 

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    cout << &doublePointer << endl; 

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    cout << *doublePointer << endl; 

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    cout << **doublePointer << endl; 
    
    delete pointerVector;
    return 0;
}