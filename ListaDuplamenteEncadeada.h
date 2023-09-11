#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED
#include <iostream>
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

//retira elemento

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
    exit(0);
}

template<typename T>
int recuperarPosicao(ListaDuplamenteEncadeada<T> lista, T elemento){
    Nodo<T> *p = lista.inicio, * q = lista.fim;
    int index = 1, indexFim = lista.cardinalidade, posicao;

    if(!existeElemento(lista,elemento)){
        throw "Elemento nao existe!";
    }
    while(p != NULL || q!=NULL){
        if(p->elemento == elemento){
            posicao = index; break;
        }
        if(q->elemento == elemento){
            posicao = indexFim; break;
        }
        q = q->anterior;
        p = p->proximo;
        index++;
        indexFim--;
    }
    return posicao;
}

template<typename T>
void exibeLista(ListaDuplamenteEncadeada<T> lista){
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
