#ifndef LISTALIVRO_H
#define LISTALIVRO_H

#include <livro.h>

class ListaLivro
{
private:
  Livro *x;
  unsigned N;

  void limpar();
  void criar(unsigned Num);
  void copiar(const ListaLivro &LL);
public:
  /// CONSTRUTORES
  inline ListaLivro():x(NULL),N(0){}
  explicit ListaLivro(unsigned n);
  ListaLivro(ListaLivro &LL);

  /// DESTRUTOR
  ~ListaLivro();

  ///METODOS
  void operator=(const ListaLivro &LL);

  void incluir(const Livro &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};


#endif // LISTALIVRO_H
