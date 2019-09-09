#ifndef CD_H
#define CD_H

#include <produto.h>

class CD: public Produto
{
private:
    unsigned num_faixas;
public:
    CD();
};

#endif // CD_H
