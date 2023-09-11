#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED
#include "ListaDuplamenteEncadeada.h"
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
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
int recuperaPosicaoVooValido(ListaDuplamenteEncadeada<T> listaOrigem, ListaDuplamenteEncadeada<T> listaDestino, string origem, string destino){
    int auxOrig, auxDest;
    string validaOrigem, validaDestino;

    auxOrig = recuperarPosicao(listaOrigem, origem);
    auxDest = recuperarPosicao(listaDestino, destino);

    if(auxOrig != auxDest){
        validaOrigem = recuperaElemento(listaOrigem,auxDest);
        if(validaOrigem == origem)
            return auxDest;
        validaDestino = recuperaElemento(listaDestino, auxOrig);
        if(validaDestino == destino)
            return auxOrig;
    }
    return auxDest;
}

string transformaString(string elemento){
    string resultado = "";
    for(unsigned int i=0; i<elemento.length(); i++){
        resultado += toupper(elemento.at(i));
    }
    return resultado;
}


#endif // OPERACOES_H_INCLUDED
