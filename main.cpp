#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
    string nomeArq, palavra = "FLN";
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);

    ListaDuplamenteEncadeada<string> IDVoo;
    criaLista(IDVoo);
    leituraArquivo(IDVoo,nomeArq,2);
    exibeLista(IDVoo);
    cout<<"Numero de elementos: " <<numeroDeElementos(IDVoo)<<endl;
    cout<<"EH vazia: "<<ehVazia(IDVoo)<<endl;
    cout<<"Recupera Elemenrto: "<<recuperaElemento(IDVoo,2)<<endl;
    cout<<"Existe elemento: "<<existeElemento(IDVoo,palavra)<<endl;
   // cout<<"Recupera posicao: "<<recuperarPosicao(IDVoo,palavra)<<endl;

    destroi(IDVoo);
    cout<<"EH vazia apos destruicao: "<<ehVazia(IDVoo)<<endl;


    return 0;
}
