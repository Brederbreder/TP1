#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "servicos.h"
#include "auxiliar.h"
#include <iostream>

void CtrlApresentacaoControle::Inicializar(){

    ResultadoAutenticar resultado;
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

        switch(opt){

            case Controle::pesquisarEvento:
                cout << "TESTE PESQUISAR EVENTO\n\n";
                break;

            case Controle::autenticar:

                try{
                    resultado = ctrl_aa->Autenticar();
                    if (resultado.GetResultado() == ResultadoAutenticar::sucesso) {
                        cout << "Sucesso na autenticacao!\n\n";
                    }
                }catch (exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
                break;

            case Controle::cadastrar:
                cout << "TESTE CADASTRAR\n\n";
                break;
        }

    }while(opt != sairc);
}

ResultadoAutenticar CtrlApresentacaoAutenticacao::Autenticar(){

    cout << "\nTESTE\n";

}



