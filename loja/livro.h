#ifndef LIVRO_H
#define LIVRO_H

#include <produto.h>

class Livro: public Produto
{
private:
    string autor;
public:
    Livro();
};

#endif // LIVRO_H
