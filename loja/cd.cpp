#include "cd.h"

bool CD::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;            /// numero para checagem da integridade do stream

    /// usar p ler da classe Produto para ler os valores de um produto
    Produto::ler(I);

    I >> num;
    if(num <= 0){cerr << "Arquivo corrompido";return false;}
    num_faixas = num;
    cout << num_faixas << endl;

    I >> C;
    ///CHECA SE DEPOIS DO NUMERO HA UMA QUEBRA DE LINHA
    if(!check(C,0)) return false;

    return true;
}

void CD::salvar(ostream &O) const{
    /// usa o salvar de Produto e add o numero de faixas + quebra de linha
    Produto::salvar(O);
    O <<  num_faixas << "\n" << endl;
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
