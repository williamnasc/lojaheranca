#include "dvd.h"

bool DVD::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;            /// numero para checagem da integridade do stream

    I >> C;
    if (!check(C,'D'))return false;
    I >> C;
    if (!check(C,':'))return false;

    /// usar p ler da classe Produto para ler os valores de um produto
    Produto::ler(I);

    /// ler o numero, caso ele seja valido add a duracao
    I >> num;
    if(num <= 0){cerr << "Arquivo corrompido";return false;}
    duracao = num;

    return true;
}


void DVD::salvar(ostream &O) const{
    /// usa o salvar de Produto e add a duracao
    O << "D: ";
    Produto::salvar(O);
    O <<  duracao <<  endl;
}


void DVD::digitar(){
    int num =0;            /// numero para checagem da integridade do stream

    /// usa o de Produto e add a duracao
    Produto::digitar();
    do{
        cout << "numero de faixas: ";
        cin >> num;
    }while(num<=0);
    duracao = num;

}

