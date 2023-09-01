#include <iostream>
#include "ListaDuplamenteEncadeada.h"


using namespace std;
int main() {
    string nomeArq;
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);
    ListaDuplamenteEncadeada<int> l1;
    ListaDuplamenteEncadeada<string> l2;
    ListaDuplamenteEncadeada<string> l3;
    ListaDuplamenteEncadeada<int> l4;

    insereNaLista(l1, 1111);
    insereNaLista(l2, string("FLN"));
    insereNaLista(l3, string("SP"));
    insereNaLista(l4, 3);
    leituraArquivo(l1, nomeArq);
    return 0;
}
