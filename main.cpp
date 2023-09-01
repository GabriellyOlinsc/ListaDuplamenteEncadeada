#include <iostream>
#include "ListaDuplamenteEncadeada.h"


using namespace std;
int main() {
    string nomeArq;
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);
    ListaDuplamenteEncadeada<int> numVoo;
    criaLista(numVoo);

    ListaDuplamenteEncadeada<string> localOrigem;
    criaLista(localOrigem);

    ListaDuplamenteEncadeada<string> localDestino;
    criaLista(localDestino);

    ListaDuplamenteEncadeada<int> assentos;
    criaLista(assentos);


    return 0;
}
