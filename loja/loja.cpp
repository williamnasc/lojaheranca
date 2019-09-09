#include "loja.h"


bool Loja::ler(const string& arq){
    ifstream arquivo(arq);
    if(!arquivo.is_open()){cerr << "diretorio invalido"; return false;}


    LL.ler(arquivo);
    LC.ler(arquivo);
    LD.ler(arquivo);

}
