#ifndef DVD_H
#define DVD_H

#include <produto.h>

class DVD: public Produto
{
private:
    unsigned duracao;
public:
    inline DVD():Produto(),duracao(0){}

    bool ler(istream &I);
    void salvar(ostream &O) const;
    void digitar();
    // Define a funcao imprimir como sendo salvar em cout
    inline void imprimir() const {salvar(cout);}
  };

  inline istream& operator>>(istream &I, DVD &D) {D.digitar(); return I;}
  inline ostream& operator<<(ostream &O, const DVD &D) {D.salvar(O); return O;}

#endif // DVD_H
