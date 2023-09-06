#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
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

    return 0;
}
