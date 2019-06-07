#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "servicos.h"
#include <iostream>

void CtrlApresentacaoControle::Inicilizar(){

    int opt;

    do{
        cout << "Sistema de Venda de Ingressos\n\n";
        cout << "Escolha uma das opcoes abaixo.\n\n";
        cout << pesquisarEvento << ". Pesquisar evento\n";
        cout << cadastrar << ". Cadastrar\n";
        cout << autenticar << ". Autenticar\n";
        cout << sairc << ". Sair\n\topcao: ";
        cin >> opt;
    }while(opt != sairc);
}

void CtrlApresentacaoControle::ControleLogado(const Cpf &){
  int opt;

  do{
    cout << "\tBem-vindo!\n\n";
    cout << "Escolha uma das opcoes abaixo.\n\n";
    cout << comprar << ". Comprar ingresso\n";
    cout << cadastrarEvento << ". Cadastrar evento\n";
    cout << descadastrarEvento << ". Descadastrar evento\n";
    cout << descadastrarUsuario << ". Cadastrar usuario\n";
    cout << saircl << ". Sair\n\topcao: ";
    cin >> opt;
  }while(opt != saircl);
}

