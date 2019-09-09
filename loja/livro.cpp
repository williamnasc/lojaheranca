#include "livro.h"

bool Livro::ler(istream &I){
    char C = 0;         /// char para chegarem da integridade do stream

    /// usar p ler da classe Produto para ler os valores de um produto
    Produto::ler(I);

    I >> C;
    if(!check(C,'"')) return false;

    getline(I,autor,'"');

    return true;
}

void Livro::salvar(ostream &O) const{
    /// usa o salvar de Produto e add o nome do autor + quebra de linha
    Produto::salvar(O);
    O << '"' << autor << "\"\n" << endl;
}

void Livro::digitar(){
    /// usa o de Produto e add o nome do autor;
    Produto::digitar();

    cout << "autor: ";
    getline(cin,autor,'\n');
}
