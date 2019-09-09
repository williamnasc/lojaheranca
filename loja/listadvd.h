#ifndef LISTADVD_H
#define LISTADVD_H

#include <dvd.h>

class ListaDVD
{
private:
  DVD *x;
  unsigned N;


  void limpar();
  void criar(unsigned Num);
  void copiar(const ListaDVD &LD);
public:
  /// CONSTRUTORES
  inline ListaDVD():x(NULL),N(0){}
  explicit ListaDVD(unsigned n);
  ListaDVD(ListaDVD &LD);

  /// DESTRUTOR
  ~ListaDVD();

  ///METODOS
  void operator=(const ListaDVD &LD);

  void incluir(const DVD &D);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};
#endif // LISTADVD_H
