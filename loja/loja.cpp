#include "loja.h"


bool Loja::ler(const string& arq){
    ifstream arquivo(arq);
    if(!arquivo.is_open()){cerr << "diretorio invalido"; return false;}

    bool a,b,c;
    a = LL.ler(arquivo);
    b = LC.ler(arquivo);
    c = LD.ler(arquivo);

    if( a && b && c )
        return true;
    else{
        cerr << "Arquivo corrompido\n";
        return false;
    }


}

bool Loja::salvar(const string& arq) const{
    ofstream arquivo(arq);
    if(!arquivo.is_open()){cerr << "diretorio invalido"; return false;}

    LL.salvar(arquivo);
    LC.salvar(arquivo);
    LD.salvar(arquivo);

    return true;

}

void Loja::imprimir() const{
    LL.imprimir();
    LC.imprimir();
    LD.imprimir();
}
