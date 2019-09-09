#include "listalivro.h"

void ListaLivro::limpar()
{
  delete[] x;
  x = NULL;
  N = 0;
}

void ListaLivro::criar(unsigned Num)
{
  N = Num;
  x = ( N>0 ? new Livro[N] : NULL );
}

void ListaLivro::copiar(const ListaLivro &LL)
{
  criar(LL.N);
  for (unsigned i=0; i<N; i++) x[i] = LL.x[i];
}

ListaLivro::ListaLivro(unsigned n):N(n)
{
    criar(n);
}

ListaLivro::ListaLivro(ListaLivro &LL)
{
    copiar(LL);
}

ListaLivro::~ListaLivro()
{
    limpar();
}

void ListaLivro::operator=(const ListaLivro &LL){
    if (this != &LL)
      {
        if (this->N == LL.N)
        {
          for (unsigned i=0; i<N; i++) x[i] = LL.x[i];
        }
        else
        {
          limpar();
          copiar(LL);
        }
      }
}

void ListaLivro::incluir(const Livro &L){
    Livro *prov = new Livro[N+1];
    for (unsigned i=0;i<N;i++) {
        prov[i] = x[i];
    }
    prov[N] = L;
    delete [] x;
    x = prov;
    N++;
}

bool ListaLivro::excluir(unsigned id){
    if(id<N){
        Livro *prov = new Livro[N-1];
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

bool ListaLivro::ler(istream &I){
    char C = 0;         /// char para checagem da integridade do stream
    int num =0;         /// numero para checagem da integridade do stream
    string S;           /// string para checagem da integridade do stream

    /// confere se a lista a seguir é lista de livros
    getline(I,S,' ');

    if(S != "LISTALIVRO"){cerr << "Arquivo corrompido";return false;}

    ///testa se o numero de itens é valido
    I >> num;
    if(num <= 0){cerr << "Arquivo corrompido";return false;}
    criar(num);

    for (unsigned i=0;i<N;i++){
        x[i].ler(I);
        //cout << i <<endl;
        //x[i].imprimir();
    }

    return true;
}

void ListaLivro::salvar(ostream &O) const{
    O << "LISTALIVRO "<< N << endl;

    for (unsigned i=0;i<N;i++){
        //x[i].ler(I);
        x[i].salvar(O);
    }
    O << endl;
}

void ListaLivro::imprimir() const{
    cout << ">> LIVROS: " << endl;

    for (unsigned i=0;i<N;i++){
        cout << i << ") ";
        x[i].imprimir();
    }
    cout << endl;
}
