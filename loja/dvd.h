#ifndef DVD_H
#define DVD_H

#include <produto.h>

class DVD: public Produto
{
private:
    unsigned duracao;
public:
    DVD();
};

#endif // DVD_H
