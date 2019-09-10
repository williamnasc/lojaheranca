#include "livro.h"

bool Livro::ler(istream &I){
    char C = 0;         /// char para chegarem da integridade do stream

    I >> C;
    if (!check(C,'L'))return false;
    I >> C;
    if (!check(C,':'))return false;

    /// usar p ler da classe Produto para ler os valores de um produto
    Produto::ler(I);

    I >> C;
    if(!check(C,'"')) return false;

    getline(I,autor,'"');

    return true;
}

void Livro::salvar(ostream &O) const{
    /// usa o salvar de Produto e add o nome do autor
    O << "L: ";
    Produto::salvar(O);
    O << '"' << autor << "\"" << endl;
}

void Livro::digitar(){
    /// usa o de Produto e add o nome do autor;
    Produto::digitar();

    cout << "autor: ";
    cin >> ws;
    getline(cin,autor,'\n');
}
