#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
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
template<typename T>
void leituraArquivo (ListaDuplamenteEncadeada<T> &lista, string nomeArq){
    string palavra;
    int valor = 0;
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
                    //cout<<"\n\nnumero de voo : "<<palavra<<endl;
                   // insereNaLista(lista, palavra);
                    // insere lista1
                    break;
                case 1:
                    //cout<<"local de origem: "<< palavra<<endl;
                    //insereNaLista(lista, palavra);
                    // insere lista2
                    break;
                case 2:
                    //cout<<"local de destino: "<< palavra<<endl;
                    insereNaLista(lista, palavra);
                    // insere lista3
                    break;
                case 3:
                    //cout<<"numero de lugares disponiveis: "<< palavra<<endl;
                  //  insereNaLista(lista, palavra);
                    // insere lista4
                    break;
                }
            coluna ++;
            if(coluna > 3)
                coluna = 0;
            palavra = "";

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

template<typename T>
int numeroDeElementos(ListaDuplamenteEncadeada<T> lista){
    return lista.cardinalidade;
}

template<typename T>
bool ehVazia(ListaDuplamenteEncadeada<T> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T>
bool existeElemento(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio, *q = lista.fim;
    while(p != NULL)
    {
        if(p->elemento == elemento || q->elemento == elemento)
            return true;
        p = p->proximo;
        q = q->anterior;
    }
    return false;
}
//ARRUMAR E COLOCAR INSERE NA POSICAO
template<typename T>
void insereNaLista(ListaDuplamenteEncadeada<T>& lista, T elemento) {
    Nodo<T>* novoNodo = new Nodo<T>;
    novoNodo->elemento = elemento;
    novoNodo->proximo = nullptr;

    if (lista.inicio == nullptr) {
        novoNodo->anterior = nullptr;
        lista.inicio = novoNodo;
        lista.fim = novoNodo;
    } else {
        novoNodo->anterior = lista.fim;
        lista.fim->proximo = novoNodo;
        lista.fim = novoNodo;
    }
    lista.cardinalidade++;
}

//FALTA O RECUPERA POSICAO
//FALTA O RETIRA ELEMENTO

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> lista, int posicao) {
    Nodo<T> *p = lista.inicio, *q = lista.fim;
    int cont = 1, contFim = lista.cardinalidade;

    if(posicao < 1 || posicao >lista.cardinalidade)
        throw "POSICAO INVALIDA";

    while(p != NULL || q != NULL){
        if(cont == posicao)
            return p->elemento;
        if(contFim == posicao)
            return q->elemento;
        p = p->proximo;
        q = q->anterior;
        cont++;
        contFim--;
    }
}

template<typename T>
void exibeLista(ListaDuplamenteEncadeada<T> lista)
{
    for (Nodo<T>* p = lista.inicio; p != NULL; p = p->proximo)
        cout << p->elemento << "\t";
    cout << endl;
}

template<typename T>
void destroi(ListaDuplamenteEncadeada<T> &lista)
{
    Nodo<T> *p;
    while (lista.inicio != NULL)
    {
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}


#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
