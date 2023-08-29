#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T>* anterior;
    Nodo<T>* proximo;
};

template<typename T>
struct ListaDuplamenteEncadeada{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

//template<typename T>
void leituraArquivo (string nomeArq){
    string palavra="";
    char ch;
    int coluna = 0;

    ifstream arqSeq(nomeArq.c_str());
    if(arqSeq.fail()){
        cout<<"Erro na abertura do arquivo '"<<nomeArq<<"'!";
        exit(0);
    }

    while (arqSeq.get(ch)){
        if(ch == ' ' or ch == '\n'){
            switch (coluna){
                case 0:
                    cout<<"\n\nnumero de voo : "<<palavra<<endl;
                    //aqui fica o insereNaLista1
                    break;
                case 1:
                    cout<<"local de origem: "<< palavra<<endl;
                    //aqui fica o insereNaLista2
                    break;
                case 2:
                    cout<<"local de destino: "<< palavra<<endl;
                    //aqui fica o insereNaLista3
                    break;
                case 3:
                    cout<<"numero de lugares disponiveis: "<< palavra<<endl;
                    //insereNaLista4
                    break;
                }
            coluna ++;
            if(coluna > 3)
                coluna = 0;
            palavra="";
        }else
        palavra = palavra + ch;
    }
    arqSeq.close();
}

template<typename T>
void criaLista (ListaDuplamenteEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}

#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
