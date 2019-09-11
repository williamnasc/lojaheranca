#include "loja.h"


bool Loja::ler(const string& arq){

    ifstream arquivo(arq);
    if(!arquivo.is_open()){cerr << "Diretorio invalido\n"; return false;}

    bool a,b,c;
    a = LL.ler(arquivo);
    b = LC.ler(arquivo);
    c = LD.ler(arquivo);

    if( a && b && c )
        return true;
    else{
        /// Zera as listas caso tenham sido preenchidas com algum dado
        ListaLivro z1(0);
        LL = z1;
        ListaCD z2(0);
        LC = z2;
        ListaDVD z3(0);
        LD = z3;
        cerr << "Arquivo corrompido\n";
        return false;
    }


}

bool Loja::salvar(const string& arq) const{
    ofstream arquivo(arq);
    if(!arquivo.is_open()){cerr << "Diretorio invalido\n"; return false;}

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
