#ifndef LIVRO_H
#define LIVRO_H

#include <produto.h>

class Livro: public Produto
{
private:
    string autor;
public:
    inline Livro():Produto(),autor(""){}

    bool ler(istream &I);
    void salvar(ostream &O) const;
    void digitar();
    // Define a funcao imprimir como sendo salvar em cout
    inline void imprimir() const {salvar(cout);}
  };

  inline istream& operator>>(istream &I, Livro &L) {L.digitar(); return I;}
  inline ostream& operator<<(ostream &O, const Livro &L) {L.salvar(O); return O;}

#endif // LIVRO_H
