#include "listadvd.h"

void ListaDVD::limpar()
{
  delete[] x;
  x = NULL;
  N = 0;
}

void ListaDVD::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new DVD[N] : NULL );
}

void ListaDVD::copiar(const ListaDVD &LC)
{
  criar(LC.N);
  for (unsigned i=0; i<N; i++) x[i] = LC.x[i];
}

ListaDVD::ListaDVD(unsigned n):N(n)
{
    criar(n);
}

ListaDVD::ListaDVD(ListaDVD &LD)
{
    copiar(LD);
}

ListaDVD::~ListaDVD()
{
    limpar();
}

void ListaDVD::operator=(const ListaDVD &LD){
    if (this != &LD)
      {
        if (this->N == LD.N)
        {
          for (unsigned i=0; i<N; i++) x[i] = LD.x[i];
        }
        else
        {
          limpar();
          copiar(LD);
        }
      }
}

void ListaDVD::incluir(const DVD &D){
    DVD *prov = new DVD[N+1];
    for (unsigned i=0;i<N;i++) {
        prov[i] = x[i];
    }
    prov[N] = D;
    delete [] x;
    x = prov;
    N++;
}

bool ListaDVD::excluir(unsigned id){
    if(id<N){
        DVD *prov = new DVD[N-1];
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

bool ListaDVD::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;         /// numero para checagem da integridade do stream
    string S;           /// string para checagem da integridade do stream
    I >> ws;
    /// confere se a lista a seguir é lista de livros
    getline(I,S,' ');
    if(S != "LISTADVD"){/*cerr << "Arquivo corrompido";*/return false;}

    ///testa se o numero de itens é valido
    I >> num;
    if(num <= 0){/*cerr << "Arquivo corrompido";*/return false;}

    criar(num);

    for (unsigned i=0;i<N;i++){
        x[i].ler(I);
        //x[i].imprimir();
    }

    return true;
}

void ListaDVD::salvar(ostream &O) const{
    O << "LISTADVD "<< N << endl;

    for (unsigned i=0;i<N;i++){
        //x[i].ler(I);
        x[i].salvar(O);
    }
    //O << endl;
}

void ListaDVD::imprimir() const{
    cout << ">> DVDs: " << endl;

    for (unsigned i=0;i<N;i++){
        cout << i << ") ";
        x[i].imprimir();
    }
    cout << endl;
}
