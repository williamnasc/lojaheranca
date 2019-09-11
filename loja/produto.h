#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

class Produto
{
private:
  string nome;
  unsigned preco;
public:
  inline Produto(const string& N="", unsigned P=0): nome(N), preco(P) {}

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void digitar();
  // Define a funcao imprimir como sendo salvar em cout
  inline void imprimir() const {salvar(cout);}

  ///checa se o caractere é ou n o esperado
  inline bool check(char &C,char t){
      if(C != t){/*cerr << "Arquivo corrompido";*/return false;}
      return true;
  }
};

inline istream& operator>>(istream &I, Produto &P) {P.digitar(); return I;}
inline ostream& operator<<(ostream &O, const Produto &P) {P.salvar(O); return O;}

#endif // PRODUTO_H
