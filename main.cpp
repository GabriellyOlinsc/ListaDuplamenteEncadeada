#include <iostream>
#include "ListaDuplamenteEncadeada.h"
#include "Operacoes.h"
using namespace std;
int main()
{
    string nomeArq;
    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);;

    ListaDuplamenteEncadeada<int>numeroVoo;
    ListaDuplamenteEncadeada<string> localOrigem;
    ListaDuplamenteEncadeada<string> localDestino;
    ListaDuplamenteEncadeada<int> assentos;

    criaLista(numeroVoo);
    criaLista(assentos);
    criaLista(localOrigem);
    criaLista(localDestino);

    leituraArquivoInt(numeroVoo,nomeArq,0);
    leituraArquivoString(localOrigem,nomeArq,1);
    leituraArquivoString(localDestino,nomeArq,2);
    leituraArquivoInt(assentos,nomeArq,3);

    system("cls");

    bool finalizar = false;
    int opcao, posVoo, numAssentos;
    string nome, origem, destino;
    char marcador;

    do{
        cout<<"======== SISTEMA COMPANHIA AEREA ========\n"<<endl;
        cout<<"1) Marcar ou desmarcar passagem\n2) Exibir voos disponiveis\n3) Sair\n\nSelecione a opcao: ";
        cin>>opcao;
        cin.ignore();
        system("cls");
        switch(opcao){
            case 1:
                cout<<"Marcar (+) ou Desmarcar(-) passagem: ";
                cin.get(marcador);
                cin.ignore();
                cout<<"Insira os dados:\nNome: ";
                getline(cin,nome);
                cout<<"Local de Origem: ";
                getline(cin,origem);
                cout<<"Local de Destino: ";
                getline(cin,destino);

                nome = transformaString(nome);
                origem  = transformaString(origem);
                destino = transformaString(destino);
                if(existeElemento(localOrigem,origem) && existeElemento(localDestino,destino)){
                    posVoo = recuperaPosicaoVooValido(localOrigem,localDestino,origem,destino);
                    if(posVoo > 0){
                        numAssentos = recuperaElemento(assentos,posVoo);
                        if(numAssentos > 0){
                            marcador == '+' ? numAssentos--: numAssentos++;
                            try{
                                //retiraElemento(assentos,posVoo);    AQUI FICA O RETIRA PARA CONTROLARMOS O NUMERO DE ASSENTOS!!
                                insereNaLista(assentos,numAssentos,posVoo);
                            }catch (const char* msg){
                                cerr<<msg<<endl;
                            }
                            if(marcador == '-')
                                 cout<<"\n** CONFIRMADO ** "<<nome<<" ** VOO DESMARCADO";
                            else
                                 cout<<"\n** CONFIRMADO ** "<<nome<<" ** "<<recuperaElemento(numeroVoo,posVoo);
                        }else
                            cout<<"\n** NAO CONFIRMADO ** "<<nome<<" ** VOO LOTADO";
                    }
                    else
                        cout<<"\n** NAO CONFIRMADO ** "<<nome<<" ** VOO INEXISTENTE";
                }
                else
                    cout<<"\n** NAO CONFIRMADO ** "<<nome<<" ** VOO INEXISTENTE";
                cout<<endl;

            break;
            case 2:
                //EXIBE LISTA - VINICIUS
                break;
            case 3:

                finalizar = true;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
   } while (!finalizar);


    destroiLista(numeroVoo);
    destroiLista(assentos);
    destroiLista(localOrigem);
    destroiLista(localDestino);

    return 0;
}
