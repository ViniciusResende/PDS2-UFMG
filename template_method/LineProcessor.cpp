#include <regex>
#include <math.h>
#include <string>
#include <list>
#include <sstream>

#include "LineProcessor.hpp"

// LineProcessor::~LineProcessor() {
//   delete[] _in;
// }

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  std::regex naturalNumber("(\\s*(?:\\d\\s*)*)");
  
  return std::regex_match(str, naturalNumber);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  int lineSum = 0;

  std::stringstream ss(str);

  int currentNumber;
  while (ss >> currentNumber) {
    lineSum += currentNumber;
  }
  

  std::cout << lineSum << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  std::regex regularExpr("\\s*[A-Za-z]+\\s+\\d+\\s+[A-Za-z]+\\s+\\d+");

  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  std::stringstream ss(str);

  std::string time1, time2;
  unsigned gols1, gols2;

  ss >> time1 >> gols1 >> time2 >> gols2;

  if(gols1 != gols2) {
    std::string winner = gols1 > gols2 ? time1 : time2;
    std::cout << "Vencedor: " << winner << std::endl;
    
    return;
  }

  std::cout << "Empate" << std::endl;
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int totalOfWords = 0;

  std::stringstream ss(str);

  std::string currentWord;
  while (ss >> currentWord) {
    totalOfWords ++;
  }
  
  std::cout << totalOfWords << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  std::regex stringValue("^[ \t\na-zA-Z]+$");
  
  return std::regex_match(str, stringValue);
}

void InversorDeFrases::processaLinha(const std::string &str) {
  std::list<std::string> listOfWords;

  std::stringstream ss(str);

  std::string currentWord;
  while (ss >> currentWord) {
    listOfWords.push_front(currentWord);
  }

  std::list<std::string>::iterator it;
  for(auto const &item : listOfWords) {
    std::cout << item;
    std::cout << " ";
  }

  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";

  return std::regex_match(str, std::regex(dateFormat));
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".

  std::stringstream ss(str);

  std::string date;
  ss >> date;

  std::string delimiter = "/";

  size_t pos = 0;
  std::string day, month;
  while((pos = date.find(delimiter)) != std::string::npos) {
    if(day.length()) 
      day = date.substr(0, pos);
    else 
      month = date.substr(0, pos);
    date.erase(0, pos + delimiter.length());
  }

  std::string year = date;
  switch (stoi(month)) {
    case 1:
      std::cout << "Jan" << std::endl;
      break;
    case 2:
      std::cout << "Fev" << std::endl;
      break;
    case 3:
      std::cout << "Mar" << std::endl;
      break;
    case 4:
      std::cout << "Abr" << std::endl;
      break;
    case 5:
      std::cout << "Mai" << std::endl;
      break;
    case 6:
      std::cout << "Jun" << std::endl;
      break;
    case 7:
      std::cout << "Jul" << std::endl;
      break;
    case 8:
      std::cout << "Ago" << std::endl;
      break;
    case 9:
      std::cout << "Set" << std::endl;
      break;
    case 10:
      std::cout << "Out" << std::endl;
      break;
    case 11:
      std::cout << "Nov" << std::endl;
      break;
    case 12:
      std::cout << "Dez" << std::endl;
      break;
  
    default:
      break;
  }
}