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
        cout << "/\\/\\/\\/\\/\\ Sistema de Venda de Ingressos /\\/\\/\\/\\/\\ \n\n";
        cout << "Escolha uma das opcoes abaixo.\n\n";
        cout << pesquisarEvento << ". Pesquisar evento\n";
        cout << cadastrar << ". Cadastrar/Descadastrar\n";
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
                        cout << "\nSucesso de autenticacao!\n\n";
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
    ResultadoAutenticar resultado;
    Resultado verificado;
    string cpf, senha;
    Cpf cpf_;
    Senha senha_;
    int opt;

    cout << "Deseja retornar?\n\n1-Sim\n2-Nao\n";
    cout << "Opcao: ";
    cin >> opt;
    cout << "\n";

    switch(opt){
        case 1:
            resultado.SetResultado(Resultado::falha);
            return resultado;
            break;
        case 2:
            default:break;
    }

    try{
        cout << "\nDigite o cpf (trigger de sucesso = 040.906.801-23,\ntrigger de falha = 034.688.801-89):\n";
        cin >> cpf;
        cpf_ = Cpf(cpf);

        cout << "Digite a senha (trigger de sucesso = 1aA2bB,\ntrigger de erro = 1Ee2Rr):\n";
        cin >> senha;
        senha_ = Senha(senha);
    }catch(exception &e){
        cout << "Formato incorreto!\n" << e.what() << "\n";
    }

    try{
        verificado = ctrlServicoAutenticacao->Autenticar(cpf_, senha_);
    }catch(exception &e){
        cout << "\n" << e.what() << "\n";
    }

    if(verificado.GetResultado() == ResultadoAutenticar::falha){
        cout << "Falha de autenticacao!\n\n";
    }else{
        resultado.SetCpfResultado(cpf_);
        resultado.SetSenhaResultado(senha_);
    }
    resultado.SetResultado(verificado.GetResultado());

    return resultado;

}

void CtrlApresentacaoUsuario::Cadastrar(){
    ResultadoUsuario resultado;
    Resultado verificado;
    Usuario usuario_;
    Cpf cpf_;
    Senha senha_;
    NumeroCartaoDeCredito numero_;
    CodigoDeSeguranca codigo_;
    DataDeValidade data_;
    string cpf, senha, numero, codigo, data;
    int opt;

    do{
        cout << "\nDeseja retornar?\n\n1-Sim\n2-Nao\n";
        cout << "Opcao: ";
        cin >> opt;
        cout << "\n";

        cout << "\nDigite o cpf (trigger de sucesso = , trigger de falha) \n;";
        cin >> cpf;
        cpf_ = Cpf(cpf);

        cout << "\nDigite a senha (trigger de sucesso = , trigger de falha) \n";
        cin >> senha;
        senha_ = Senha(senha);

        cout << "\nDigite o numero do cartao de credito (trigger de sucesso = , trigger de falha = )";
        cin >> numero;
        numero_ = NumeroCartaoDeCredito(numero);

        cout << "\nDigite o codigo de seguranca do cartao de credito (trigger de sucesso = , trigger de falha = )";
        cin >> codigo;
        codigo_ = CodigoDeSeguranca(codigo);

        cout << "\nDigite a data de validade do cartao de credito (trigger de sucesso = , trigger de falha = )";
        cin >> data;
        data_ = DataDeValidade(data);

        Resultado res = ctrlServicoUsuario->CadastrarUsuario(usuario_, cpf_, senha_, numero_, codigo_, data_);

        cout << "\n\nIMPLEMENTAR O CADASTRO!!!\n\n";

    }while(opt != voltar);
}



