#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
    string nomeArq, palavra = "RJ";
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);

    ListaDuplamenteEncadeada<int>numeroVoo;
    ListaDuplamenteEncadeada<string> localOrigem;
    ListaDuplamenteEncadeada<string> localDestino;
    ListaDuplamenteEncadeada<int> assentos;

    criaLista(numeroVoo);
    criaLista(assentos);
    criaLista(localOrigem);
    criaLista(localDestino);

    leituraArquivoInt(numeroVoo,nomeArq,0);
    leituraArquivoString(localOrigem, nomeArq,1);
    leituraArquivoString(localDestino, nomeArq,2);
    leituraArquivoInt(assentos, nomeArq,3);

    exibeLista(numeroVoo);
    exibeLista(localOrigem);
    exibeLista(localDestino);
    exibeLista(assentos);

    try{
        cout<<"Posicao: "<<recuperarPosicao(localOrigem, palavra);
    }catch(char const* msg){
        cout << msg;
    }

    destroiLista(numeroVoo);
    destroiLista(assentos);
    destroiLista(localOrigem);
    destroiLista(localDestino);


    destroiLista(numeroVoo);
    destroiLista(assentos);
    destroiLista(localOrigem);
    destroiLista(localDestino);

    return 0;
}
