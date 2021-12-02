#include <iostream>
#include <stdlib.h>

using namespace std;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  int countA = 0, countE = 0 , countI = 0, countO = 0, countU = 0;
  string s1;
  cin >> s1; 
  
  for (size_t i = 0; i < s1.length(); i++) {
    switch (s1[i]) {
    case 'a':
        countA += 1;
      break;
    case 'e':
        countE += 1;
      break;
    case 'i':
        countI += 1;
      break;
    case 'o':
        countO += 1;
      break;
    case 'u':
        countU += 1;
      break;
    
    default:
      break;
    }
  }

  if(countA) {
     cout << "a " << countA << endl;
    }
    if(countE) {
     cout << "e " << countE << endl;
    }
    if(countI) {
     cout << "i " << countI << endl;
    }
    if(countO) {
     cout << "o " << countO << endl;
    }
    if(countU) {
     cout << "u " << countU << endl;
    }
 
  return 0;
}