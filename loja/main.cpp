#include <iostream>
#include <fstream>
#include <loja.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    CD p;
    ifstream entrada("entrada.txt");
    p.ler(entrada);
    /*ofstream saida("saida.txt");
    p.salvar(saida);
    */return 0;
}
