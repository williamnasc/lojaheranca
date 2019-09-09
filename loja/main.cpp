#include <iostream>
#include <fstream>
#include <loja.h>
using namespace std;

int main()
{
    /// /home/williammcn/Documentos/dados.txt
    string s;
    cout << "Hello World!" << endl;
    Loja p;
    //cin >> s;
    p.ler("/home/williammcn/Documentos/dados.txt");
    return 0;
}
