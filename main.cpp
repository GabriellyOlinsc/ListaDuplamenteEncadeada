#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
    string nomeArq, palavra = "RJ";
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);

    ListaDuplamenteEncadeada<int>numeroVoo;
    ListaDuplamenteEncadeada<int> IDVoo;
    ListaDuplamenteEncadeada<string> localOrigem;
    ListaDuplamenteEncadeada<string> localDestino;

    criaLista(numeroVoo);
    criaLista(IDVoo);
    criaLista(localOrigem);
    criaLista(localDestino);

    //leituraArquivo(IDVoo,nomeArq);
    leituraArquivo(localOrigem, nomeArq);
    leituraArquivo(IDVoo, nomeArq);

    exibeLista(numeroVoo);
    exibeLista(IDVoo);
    exibeLista(localOrigem);
    exibeLista(localDestino);

    // cout << recuperaElemento(localOrigem, 1);

    try{
        recuperarPosicao(localOrigem, palavra);
    }catch(char const* msg){
        cout << msg;
    }

    destroiLista(numeroVoo);
    destroiLista(IDVoo);
    destroiLista(localOrigem);
    destroiLista(localDestino);

    return 0;
}
