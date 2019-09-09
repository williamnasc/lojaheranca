#ifndef CD_H
#define CD_H

#include <produto.h>

class CD: public Produto
{
private:
    unsigned num_faixas;
public:
    inline CD(): Produto(),num_faixas(0){}

    bool ler(istream &I);
    void salvar(ostream &O) const;
    void digitar();
    // Define a funcao imprimir como sendo salvar em cout
    inline void imprimir() const {salvar(cout);}
  };

  inline istream& operator>>(istream &I, CD &C) {C.digitar(); return I;}
  inline ostream& operator<<(ostream &O, const CD &C) {C.salvar(O); return O;}

#endif // CD_H
