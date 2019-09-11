#include "cd.h"

bool CD::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;            /// numero para checagem da integridade do stream

    I >> C;
    if (!check(C,'C'))return false;
    I >> C;
    if (!check(C,':'))return false;

    /// usar p ler da classe Produto para ler os valores de um produto
    if(!(Produto::ler(I))) return false;

    I >> num;
    if(num <= 0){/*cerr << "Arquivo corrompido";*/return false;}
    num_faixas = num;

/*
    I >> C;
    ///CHECA SE DEPOIS DO NUMERO HA UMA QUEBRA DE LINHA
    if(!check(C,0)) return false;
*/
    return true;
}

void CD::salvar(ostream &O) const{
    /// usa o salvar de Produto e add o numero de faixas
    O << "C: ";
    Produto::salvar(O);
    O <<  num_faixas << endl;
}

void CD::digitar(){
    int num =0;            /// numero para checagem da integridade do stream

    /// usa o de Produto e add o numero de faixas
    Produto::digitar();
    do{
        cout << "numero de faixas: ";
        cin >> num;
    }while(num<=0);
    num_faixas = num;

}
