#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "servicos.h"
#include <iostream>

void CtrlApresentacaoControle::Inicializar(){

    int opt;

    do{
        cout << "Sistema de Venda de Ingressos\n\n";
        cout << "Escolha uma das opcoes abaixo.\n\n";
        cout << pesquisarEvento << ". Pesquisar evento\n";
        cout << cadastrar << ". Cadastrar\n";
        cout << autenticar << ". Autenticar\n";
        cout << sairc << ". Sair\n\topcao: ";
        cin >> opt;
        cout << "\n";
    }while(opt != sairc);
}



