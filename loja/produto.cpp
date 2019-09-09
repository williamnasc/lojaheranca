#include "produto.h"

bool Produto::ler(istream &I){

    char C = 0;         /// char para chegarem da integridade do stream
    double precod=0;    /// double para ler o preço e converter para int depois

    /// ignora os characteres até achar uma aspa dupla
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I, nome, '"');      /// ler nome do produto

    I >> C;                     /// ler o proximo caractere para testar integridade
    if(C != ';'){cerr << "Arquivo corrompido";return false;}

    I >> C;                     /// ler o proximo caractere para testar integridade
    if(C != '$'){cerr << "Arquivo corrompido";return false;}

    /// ler o preco como double e "converte" para int
    I >> precod;
    preco = precod*100;

    I >> C;                     /// ler o proximo caractere para testar integridade
    if(C != ';'){cerr << "Arquivo corrompido";return false;}

    return true;
}

void Produto::salvar(ostream &O) const{
    double precod = preco;      /// variavel que converte o preço para double
    precod = precod/100;
    /// escreve produto na stream
    O << '"' << nome << '"' << ';' << '$' << precod << ';';
}

void Produto::digitar(){
    double precod=0;    /// double para ler o preço e converter para int depois

    cout << "nome: ";
    getline(cin, nome, '\n');

    /// ler o preco como double e "converte" para int
    cout << "preco: ";
    cin >> precod;
    preco = precod*100;

}
