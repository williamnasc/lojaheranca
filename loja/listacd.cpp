#include "listacd.h"

void ListaCD::limpar()
{
  delete[] x;
  x = NULL;
  N = 0;
}

void ListaCD::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new CD[N] : NULL );
}

void ListaCD::copiar(const ListaCD &LC)
{
  criar(LC.N);
  for (unsigned i=0; i<N; i++) x[i] = LC.x[i];
}

ListaCD::ListaCD(unsigned n):N(n)
{
    criar(n);
}

ListaCD::ListaCD(ListaCD &LC)
{
    copiar(LC);
}

ListaCD::~ListaCD()
{
    limpar();
}

void ListaCD::operator=(const ListaCD &LC){
    if (this != &LC)
      {
        if (this->N == LC.N)
        {
          for (unsigned i=0; i<N; i++) x[i] = LC.x[i];
        }
        else
        {
          limpar();
          copiar(LC);
        }
      }
}

void ListaCD::incluir(const CD &C){
    CD *prov = new CD[N+1];
    for (unsigned i=0;i<N;i++) {
        prov[i] = x[i];
    }
    prov[N] = C;
    delete [] x;
    x = prov;
    N++;
}

bool ListaCD::excluir(unsigned id){
    if(id<N){
        CD *prov = new CD[N-1];
        for (unsigned i=0;i<N;i++) {
            if(i<id)
                prov[i] = x[i];
            if(i>id)
                prov[i-1] = x[i];
        }
        delete[] x;
        x = prov;
        N--;

        return true;
    }else {
        cerr << "indice invalido" << endl;
        return false;
    }
}

bool ListaCD::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;         /// numero para checagem da integridade do stream
    string S;           /// string para checagem da integridade do stream
    I >> ws;
    /// confere se a lista a seguir é lista de livros
    getline(I,S,' ');
    if(S != "LISTACD"){cerr << "Arquivo corrompido";return false;}
    ///testa se o numero de itens é valido
    I >> num;
    if(num <= 0){cerr << "Arquivo corrompido";return false;}

    criar(num);

    for (unsigned i=0;i<N;i++){
        x[i].ler(I);
        //x[i].imprimir();
    }

    return true;
}

void ListaCD::salvar(ostream &O) const{
    O << "LISTACD "<< N << endl;

    for (unsigned i=0;i<N;i++){
        //x[i].ler(I);
        x[i].salvar(O);
    }
    O << endl;
}

void ListaCD::imprimir() const{
    cout << ">> CDs: " << endl;

    for (unsigned i=0;i<N;i++){
        cout << i << ") ";
        x[i].imprimir();
    }
    cout << endl;
}
