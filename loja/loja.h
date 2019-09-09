#ifndef LOJA_H
#define LOJA_H

#include <produto.h>
#include <livro.h>
#include <dvd.h>
#include <cd.h>

class ListaLivro
{
private:
  Livro *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  void incluir(const Livro &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class ListaCD
{
private:
  CD *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  void incluir(const CD &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class ListaDVD
{
private:
  DVD *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  void incluir(const DVD &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class Loja
{
private:
  ListaLivro LL;
  ListaCD LC;
  ListaDVD LD;
public:
  inline Loja(): LL(), LC(), LD() {}

  inline void incluirLivro(const Livro &X) {LL.incluir(X);}
  inline bool excluirLivro(unsigned id) {return LL.excluir(id);}
  inline void incluirDVD(const DVD &X) {LD.incluir(X);}
  inline bool excluirDVD(unsigned id) {return LD.excluir(id);}
  inline void incluirCD(const CD &X) {LC.incluir(X);}
  inline bool excluirCD(unsigned id) {return LC.excluir(id);}

  bool ler(const string& arq);
  bool salvar(const string& arq) const;
  void imprimir() const;
};

#endif // LOJA_H
