#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED
#include <iostream>
#include <fstream>
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
void leituraArquivoString (ListaDuplamenteEncadeada<T> &lista, string nomeArq, int ordemLista){
    string palavra;
    char ch;
    int coluna;
    ifstream arqSeq(nomeArq.c_str());
    if(arqSeq.fail()){
        cout<<"Erro na abertura do arquivo '"<<nomeArq<<"'!";
        exit(0);}

    while (arqSeq.get(ch)){
        if(ch == ' ' or ch == '\n'){
            if(coluna == ordemLista){
                insereNaLista(lista,palavra,numeroDeElementos(lista)+1);
            }
           coluna++;
           if(coluna > 3) coluna = 0;
           palavra = "";
        }else
            palavra = palavra + ch;
    }
    arqSeq.close();
}

template< typename T>
void leituraArquivoInt (ListaDuplamenteEncadeada<T> &lista, string nomeArq, int ordemLista){
    string palavra;
    char ch;
    int coluna;
    T elemento;

    ifstream arqSeq(nomeArq.c_str());
    if(arqSeq.fail()){
        cout<<"Erro na abertura do arquivo '"<<nomeArq<<"'!";
        exit(0);}

    while (arqSeq.get(ch)){
        if(ch == ' ' or ch == '\n'){
            if(coluna == ordemLista){
                elemento = atoi (palavra.c_str());
                insereNaLista(lista,elemento,numeroDeElementos(lista)+1);
            }
           coluna++;
           if(coluna > 3) coluna = 0;
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

template<typename T>
int numeroDeElementos(ListaDuplamenteEncadeada<T> lista){
    return lista.cardinalidade;
}

template<typename T>
bool ehVazia(ListaDuplamenteEncadeada<T> lista){
    return lista.cardinalidade == 0;
}

template<typename T>
void insereNaLista(ListaDuplamenteEncadeada<T>& lista, T elemento, int posicao) {
   int contPosicao;
   if(posicao < 1 || posicao > lista.cardinalidade + 1)
        throw "POSICAO INVALIDA";

    Nodo<T>* ptr = new Nodo<T>;
    ptr->elemento = elemento;
    ptr->proximo = NULL;
    ptr->anterior = NULL;

    if (lista.inicio == NULL){ //se for vazia
        lista.inicio = ptr;
        lista.fim = ptr;
    }else{
        Nodo<T>* p = lista.inicio;
        if (posicao == 1){
            ptr->proximo = lista.inicio;
            p->anterior = ptr;
            lista.inicio = ptr;
        }else{
            contPosicao = 1;
            while (posicao - 1 != contPosicao){ //pois vamos inserir antes do nodo da posicao
                p = p->proximo;
                contPosicao++;
            }
            ptr->proximo = p->proximo;
            p->proximo = ptr;
            ptr->anterior = p;
            if (ptr->proximo != NULL){
                p = ptr->proximo;
                p->anterior = ptr;
            }
            else
                lista.fim = ptr;
        }
    }
    lista.cardinalidade++;
}

//FALTA O RETIRA ELEMENTO

template<typename T>
T recuperaElemento(ListaDuplamenteEncadeada<T> &lista, int posicao) {
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
int recuperarPosicao(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio, * q = lista.fim;
    int index = 1, indexFim = lista.cardinalidade;

    if(!existeElemento(lista,elemento)){
        throw "Elemento nao existe!";
    }
    while(p != NULL || q!=NULL){
        if(p->elemento == elemento)
            return index;
        if(p->elemento == elemento)
            return indexFim;
        q = q->anterior;
        p = p->proximo;
        index++;
        indexFim--;
    }
}

/*
template<typename T>
int recuperarPosicao(ListaDuplamenteEncadeada<T> lista, T e){
    Nodo<T> *p = lista.inicio;
    int index = 1;
    while(p != nullptr && p->elemento != e){
        p=p->proximo;
        index++;
    }
    if(p == nullptr)
        throw "Elemento nao existe.";

    return index;
}
*/

template<typename T>
void exibeLista(ListaDuplamenteEncadeada<T> lista)
{
    for (Nodo<T>* p = lista.inicio; p != nullptr; p = p->proximo)
        cout << p->elemento << "\t";
    cout<<endl;
}

template<typename T>
void destroiLista(ListaDuplamenteEncadeada<T> &lista){
    Nodo<T> *p;
    while (lista.inicio != NULL){
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}


#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
