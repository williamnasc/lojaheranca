#ifndef LISTACD_H
#define LISTACD_H

#include <cd.h>

class ListaCD
{
private:
  CD *x;
  unsigned N;

  void limpar();
  void criar(unsigned Num);
  void copiar(const ListaCD &LC);
public:
  /// CONSTRUTORES
  inline ListaCD():x(NULL),N(0){}
  explicit ListaCD(unsigned n);
  ListaCD(ListaCD &LC);

  /// DESTRUTOR
  ~ListaCD();

  ///METODOS
  void operator=(const ListaCD &LC);

  void incluir(const CD &C);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

#endif // LISTACD_H
