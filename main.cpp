#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
<<<<<<< HEAD
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
=======
    string nomeArq, OLGA="OLA";

    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);

    ListaDuplamenteEncadeada<int> IDVOO;
    criaLista(IDVOO);
    ListaDuplamenteEncadeada<string> localOrigem;
    criaLista(localOrigem);
    ListaDuplamenteEncadeada<string> localDestino;
    criaLista(localDestino);
    ListaDuplamenteEncadeada<int> assentos;
    criaLista(assentos);

    leituraArquivo(localDestino,nomeArq);
    exibeLista(localDestino);

    cout<<numeroDeElementos(localDestino)<<endl;
    try{
        cout<<recuperaElemento(localDestino,4);
    }catch(const char* msg){
        cerr<<msg<<endl;
    }

    destroi(IDVOO);
    destroi(localOrigem);
    destroi(localDestino);
    destroi(assentos);
>>>>>>> df8b83d24d65c12d597561a20b9554a144529481

    return 0;
}
