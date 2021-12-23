#ifndef _ALGORTIMOS_H
#define _ALGORTIMOS_H

/**
 * \details   Este arquivo eh parte de um VPL de PDS II.
 * \author    Fernando Magno Quintao Pereira
 * \version   1.0
 * \date      Oct 21st 2021
 */

/**
 * \brief Leh uma sequencia de valores do tipo T da entrada, e armazena esses
 * valores no vetor vec.
 *
 * \tparam T o tipo dos elementos que serao lidos. Esse tipo deve reconhecer
 * a operacao de streaming, isso eh: <<. Mas nao se preocupe com isso: todos os
 * testes usam somente valores que podem ser lidos via o operador de streaming.
 *
 * \param vec O vetor que irah conter os valores lidos da entrada.
 */
template <class T> void read_input(std::vector<T>& vec);

/**
 * \brief Imprime o conteudo do vector vec na saida padrao.
 *
 * \details
 * Essa funcao imprime os elementos armazenados em vec na saida padrao. Deve
 * haver uma virgula entre cada par de elementos, mas nao deve haver uma virgula
 * apos o ultimo elemento. Apos o ultimo elemento deve haver uma quebra de
 * linha. Por exemplo, se vec contem os elementos 1, 2 e 3,
 * entao a saida deve ser:
 *
 * 1, 2, 3
 *
 * Este string eh equivalent a "1, 2, 3\n"
 *
 * \tparam T o tipo dos elementos que serao lidos. Esse tipo deve reconhecer
 * a operacao de streaming de saida, isso eh: >>. Mas, novamente, nao se
 * preocupe com isso: todos os testes usam somente valores que podem ser
 * escritos na saida padrao via o operador de streaming.
 *
 * \param vec O vetor com os elementos que devem ser impressos.
 */
template <class T> void print_input(std::vector<T>& vec);

/**
 * \brief Obtem o maior elemento armazenado em vec.
 *
 * \tparam T o tipo dos elementos que serao comparados. Esse tipo deve
 * reconhecer a operacao de comparacao, isto eh, "o maior que". Mas, de novo,
 * todos os testes usam somente tipos validos, entao nao se preocupe com isso.
 *
 * \param vec O vetor que contem os elementos que serao comparados.
 */
template <class T> T get_max(std::vector<T>& vec);

/**
 * \brief Conta quantas vezes diferentes elementos aparecem repetidos no
 * vector.
 *
 * \details
 * Essa funcao conta elementos repeticoes de elementos. Por exemplo, se o
 * vetor possui os seguintes elementos:
 *
 * 1, 2, 3, 2, 1, 2, 4
 *
 * Entao a saida da funcao deve ser o valor tres, pois o elemento 1 aparece
 * repetido uma vez, e o elemento 2 aparece repetido duas vezes. Outro exemplo:
 *
 * 1, 2, 1, 2, 1, 2, 1 => 5
 *
 * \tparam T o tipo dos elementos que serao comparados. Esse tipo deve
 * reconhecer a operacao de igualdade, isto eh, "==". Mas, de novo,
 * todos os testes usam somente tipos validos, entao nao se preocupe com isso.
 *
 * \param vec O vetor que contem os elements a serem inspecionados.
 */
template <class T> unsigned int count_duplicates(std::vector<T>& vec);

#endif