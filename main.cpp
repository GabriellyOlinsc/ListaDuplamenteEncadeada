#include <iostream>
#include "ListaDuplamenteEncadeada.h"

using namespace std;
int main() {
    string nomeArq;

    cout<<"Informe o nome do arquivo (.txt): ";
    getline(cin,nomeArq);

    leituraArquivo(nomeArq);


    return 0;
}
