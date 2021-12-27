#ifndef _DATA_EXTRACTOR_H
#define _DATA_EXTRACTOR_H

#include <vector>

/**
 * \class Mapeador
 *
 * \brief Esta classe eh um "Transformador de dados".
 *
 * \details
 * Um mapeador de dados, em outras palavras, implementa um algoritmo
 * que recebe um valor (um dado de entrada) e produz um outro valor (um dado de
 * saida).
 *
 * Exemplos de transformadores de dados:
 *
 * 1. Transformar um numero inteiro em um float que eh sua raiz quadrada.
 *
 * 2. Transformar um numero inteiro em outro inteiro que eh sua quantidade de
 * divisores.
 *
 * 3. Transforma uma string em um inteiro que denota a quantidade de caracteres
 * naquela string.
 *
 * \tparam O Tipo dos dados de entrada.
 * \tparam D Tipo dos dados de saida. Note que os dados de entrada nao precisam
 * ter o mesmo tipo dos dados de saida.
 */
template <class O, class D> class Mapeador {
  public:
    /**
     * \brief Destrutor virtual. Note que esta classe somente pode ser usada
     * via heranca, entao ela precisa ter um destrutor virtual.
     */
    virtual ~Mapeador() {};

    /**
     * \brief Transforma um dado de entrada em um dado de saida.
     *
     * \param d O valor do dado de entrada.
     *
     * \return Um valor do tipo D, que nao eh necessariamente o mesmo tipo que
     * o tipo dos dados de entrada.
     */
    virtual D transformaDado(O &d) const = 0;
};

/**
 * \class Filtro
 *
 * \brief Esta classe implementa um filtro generico de dados.
 *
 * \details
 * Um filtro eh um algoritmo que recebe um dado, isto eh, um valor, e retorna
 * um booleano indicando se o valor eh valido ou nao. Seguem alguns exemplos
 * de filtros:
 *
 * 1. Determina se um inteiro eh primo ou composto.
 *
 * 2. Determina se uma string representa um numero ou nao.
 *
 * 3. Determina se um numero de ponto flutuante possui uma raiz quadrada exata
 * ou nao.
 *
 * \tparam T o tipo dos dados que eh avaliado por este filtro.
 */
template <class T> class Filtro {
  public:
    /**
     * \brief Destrutor virtual. Note que esta classe somente pode ser usada
     * via heranca, entao ela precisa ter um destrutor virtual.
     */
    virtual ~Filtro() {};

    /**
     * \brief Predicado que informa se o dado de entrada eh valido ou nao.
     *
     * \param d O dado que serah avaliado.
     *
     * \return true se o dado for valido, e false caso contrario.
     */
    virtual bool dadoValido(T& d) const = 0;
};

/**
 * \class ExtratorDeDados
 *
 * \brief Esta classe eh parte de uma implementacao do padrao de projetos
 * "Strategy" que usaremos para combinar filtros e transformadores de dados.
 *
 * \details
 * Esta classe define o esqueleto de um algoritmo. Esse algoritmo recebe uma
 * sequencia de dados, filtra dados de interesse, e transforma os dados validos
 * em novos dados. Ele entao salva a sequencia com os dados transformados,
 * para que estes possam ser lidos no futuro.
 *
 * Exemplos de processamentos de dados que podemos fazer:
 *
 * 1. Separar as strings que sao numeros e transforma-las em inteiros:
 * input: "oi", "1", "ai", "2"; output: 1, 2
 *
 * 2. Separar o maior fator primo de cada numero que nao for primo:
 * input: 2, 4, 5, 6; output: 2, 3
 *
 * Note que esta classe nao eh abstrata e nao deve ser herdada. Ela nao possui
 * metodos virtuais ou metodos sem corpo definido.
 *
 * \tparam O Tipo dos dados de entrada.
 * \tparam D Tipo dos dados de saida. Note que os dados de entrada nao precisam
 * ter o mesmo tipo dos dados de saida.
 */
template <class O, class D> class ExtratorDeDados {
  public:

    /**
     * \brief Construtor da classe.
     *
     * \param input_data A sequencia de dados que serah processada.
     * \param filtro O algoritmo que determina quais sao os dados validos.
     * \param mapeador O algoritmo que transforma um dado valido em um outro
     * dado.
     */
    ExtratorDeDados(
        std::vector<O>& input_data,
        Filtro<O>& filtro,
        Mapeador<O, D>& mapeador
    ): _input_data(input_data), _filtro(filtro), _mapeador(mapeador) {}

    /**
     * \brief Preenche um vetor com os dados validos transformados.
     *
     * \details
     * Este eh o metodo chave desta classe. Ele vai passar sobre a sequencia de
     * dados validos, que estah armazenada no atributo _input, e para cada um
     * desses dados, vai determinar se ele eh um dado valido ou nao. Para cada
     * dado valido, o metodo getData aplica o transformador sobre aquele dado,
     * e insere o resultado no vetor "output".
     *
     * \return O numero de dados validos encontrados na sequencia de entrada.
     *
     * \param output O vetor que serah preenchido com os dados validos.
     */
    unsigned int getData(std::vector<D>& output) {
      unsigned total = 0;
      for (O& data: _input_data) {
        if (_filtro.dadoValido(data)) {
          output.push_back(_mapeador.transformaDado(data));
          total++;
        }
      }
      return total;
    }

  private:

    std::vector<O>& _input_data; ///< A sequencia de dados de entrada.

    Filtro<O>& _filtro; ///< O algoritmo que filtra os dados.

    Mapeador<O, D>& _mapeador; /// O algoritmo que transforma os dados.
};

#endif