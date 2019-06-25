#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "servicos.h"
#include "auxiliar.h"
#include <iostream>

void CtrlApresentacaoControle::Inicializar(){

    ResultadoAutenticar resultado_a;
    ResultadoUsuario resultado_c;
    ResultadoUsuario resultado_d;
    ResultadoVenda resultado_ci;
    ResultadoEvento resultado_pe;
    int opt;

    do{
        cout << "/\\/\\/\\/\\/\\ Sistema de Venda de Ingressos /\\/\\/\\/\\/\\ \n\n";
        cout << "Escolha uma das opcoes abaixo.\n\n";
        cout << pesquisarEvento << ". Pesquisar evento\n";
        cout << cadastrar << ". Cadastrar\n";
        cout << descadastrar << ". Descadastrar\n";
        cout << autenticar << ". Autenticar\n";
        cout << cadastrarEvento << ". Cadastrar Evento\n";
        cout << descadastrarEvento << ". Descadastrar Evento\n";
        cout << comprar << ". Comprar\n";
        cout << sairc << ". Sair\n\topcao: ";
        cin >> opt;
        cout << "\n";

        switch(opt){
            case Controle::autenticar:
                try{
                    resultado_a = ctrl_aa->Autenticar();
                    if (resultado_a.GetResultado() == ResultadoAutenticar::sucesso) {
                        cout << "\nSucesso de autenticacao!\n\n";
                    }
                }catch (exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
                break;

            case Controle::cadastrar:
                try{
                    resultado_c = ctrl_au->Cadastrar();
                    if (resultado_c.GetResultado() == ResultadoUsuario::sucesso) {
                        cout << "\nSucesso de cadastramento!\n\n";
                    }
                }catch(exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
                break;

            case Controle::descadastrar:
                try{
                    resultado_d = ctrl_au->Descadastrar();
                    if(resultado_d.GetResultado() == ResultadoUsuario::sucesso){
                        cout << "\nSucesso de descadastramento!\n\n";
                    }
                }catch(exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
                break;

            case Controle::comprar:
                try{
                    resultado_ci = ctrl_av->ComprarIngresso();
                    if(resultado_ci.GetResultado() == ResultadoUsuario::sucesso){
                        cout << "\nSucesso na compra!\n\n";
                    }
                }catch(exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
                break;

            case Controle::pesquisarEvento:
                try{
                    resultado_pe = ctrl_ae->Procurar();
                    if(resultado_pe.GetResultado() == ResultadoUsuario::sucesso){
                        cout << "\nSucesso na pesquisa!\n\n";
                    }
                }catch(exception &e){
                    cout << "\n\t" << e.what() << "\n";
                    opt = sairc;
                }
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

        cout << "\nDigite a senha (trigger de sucesso = 1aA2bB,\ntrigger de erro = 1Ee2Rr):\n";
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

ResultadoUsuario CtrlApresentacaoUsuario::Cadastrar(){
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

    cout << "Deseja retornar?\n\n1-Sim\n2-Nao\n";
    cout << "Opcao: ";
    cin >> opt;
    cout << "\n";

    switch(opt){
        case 1:
            break;

        case 2:
            try{
                cout << "\nDigite o cpf (trigger de sucesso = 040.906.801-23,\ntrigger de falha = 034.688.801-89): \n";
                cin >> cpf;
                cpf_ = Cpf(cpf);

                cout << "\nDigite a senha (trigger de sucesso = 1aA2bB,\ntrigger de falha = 1Ee2Rr): \n";
                cin >> senha;
                senha_ = Senha(senha);

                cout << "\nDigite o numero do cartao de credito (trigger de sucesso = 5555666677778884,\ntrigger de falha = 4012001037141112): \n";
                cin >> numero;
                numero_ = NumeroCartaoDeCredito(numero);

                cout << "\nDigite o codigo de seguranca do cartao de credito (trigger de sucesso = 123,\ntrigger de falha = 201): \n";
                cin >> codigo;
                codigo_ = CodigoDeSeguranca(codigo);

                cout << "\nDigite a data de validade do cartao de credito (trigger de sucesso = 09/22,\ntrigger de falha = 10/22): \n";
                cin >> data;
                data_ = DataDeValidade(data);
            }catch(exception &e){
                cout << "Formato incorreto!\n" << e.what() << "\n";
            }

            usuario_ = Usuario(cpf_, senha_);

            try{
                verificado = ctrlServicoUsuario->CadastrarUsuario(usuario_, cpf_, senha_, numero_, codigo_, data_);
            }catch(exception &e){
                cout << "\n" << e.what() << "\n";
            }

            if(verificado.GetResultado() == ResultadoUsuario::falha){
                cout << "\nFalha de cadastramento!\n\n";
            }else{
                resultado.SetUsuarioResultado(usuario_);
            }

            resultado.SetResultado(verificado.GetResultado());
            return resultado;
    }
}

ResultadoUsuario CtrlApresentacaoUsuario::Descadastrar(){
    ResultadoUsuario resultado;
    Resultado verificado;
    Usuario usuario_;
    Cpf cpf_;
    Senha senha_;
    string cpf, senha;
    int opt;

    cout << "Deseja retornar?\n\n1-Sim\n2-Nao\n";
    cout << "Opcao: ";
    cin >> opt;
    cout << "\n";

    switch(opt){
        case 1:
            break;

        case 2:
            try{
                cout << "\nDigite o cpf (trigger de sucesso = 040.906.801-23,\ntrigger de falha = 034.688.801-89): \n";
                cin >> cpf;
                cpf_ = Cpf(cpf);

                cout << "\nDigite a senha (trigger de sucesso = 1aA2bB,\ntrigger de falha = 1Ee2Rr): \n";
                cin >> senha;
                senha_ = Senha(senha);
            }catch(exception &e){
                cout << "Formato incorreto!\n" << e.what() << "\n";
            }
            usuario_ = Usuario(cpf_, senha_);

            try{
                verificado = ctrlServicoUsuario->DescadastrarUsuario(usuario_, cpf_, senha_);
            }catch(exception &e){
                cout << "\n" << e.what() << "\n";
            }

            if(verificado.GetResultado() == ResultadoUsuario::falha){
                cout << "\nFalha de descadastramento!\n\n";
            }else{
                resultado.SetUsuarioResultado(usuario_);
            }

            resultado.SetResultado(verificado.GetResultado());
            return resultado;
        }
}

ResultadoVenda CtrlApresentacaoVenda::ComprarIngresso(){
    ResultadoVenda resultado;
    Resultado verificado;
    CodigoDeApresentacao codigo_;
    string codigo;
    int quantidade;
    int opt;

    cout << "Deseja retornar?\n\n1-Sim\n2-Nao\n";
    cout << "Opcao: ";
    cin >> opt;
    cout << "\n";

    switch(opt){
        case 1:
            break;

        case 2:
            try{
                cout << "\nDigite o codigo de apresentacao (trigger de sucesso = 1234,\ntrigger de falha = 4321): \n";
                cin >> codigo;
                codigo_ = CodigoDeApresentacao(codigo);

                cout << "\nDigite a quantidade de ingressos (trigger de sucesso = 10,\ntrigger de falha = 20): \n";
                cin >> quantidade;
            }catch(exception &e){
                cout << "Formato incorreto!\n" << e.what() << "\n";
            }

            try{
                verificado = ctrlServicoVenda->Comprar(codigo_, quantidade);
            }catch(exception &e){
                cout << "\n" << e.what() << "\n";
            }

            if(verificado.GetResultado() == ResultadoVenda::falha){
                cout << "\nFalha de compra!\n\n";
            }

            resultado.SetResultado(verificado.GetResultado());
            return resultado;
        }
}

ResultadoEvento CtrlApresentacaoEvento::Procurar(){
    ResultadoEvento resultado;
    Resultado verificado;
    Data data_;
    Horario horario_;
    Cidade cidade_;
    Estado estado_;
    string data, horario, cidade, estado;
    int opt;

    cout << "Deseja retornar?\n\n1-Sim\n2-Nao\n";
    cout << "Opcao: ";
    cin >> opt;
    cout << "\n";

    switch(opt){
        case 1:
            break;

        case 2:
            try{
                cout << "\nDigite a Data do evento (trigger de sucesso = 10/10/20,\ntrigger de falha = 22/09/20): \n";
                cin >> data;
                data_ = Data(data);

                cout << "\nDigite o horario do evento (trigger de sucesso = 18:00,\ntrigger de falha = 10:00): \n";
                cin >> horario;
                horario_ = Horario(horario);

                cout << "\nDigite a cidade do evento (trigger de sucesso = brazlandia,\ntrigger de falha = jacarepagua): \n";
                cin >> cidade;
                cidade_ = Cidade(cidade);

                cout << "\nDigite o Estado do evento (trigger de sucesso = DF,\ntrigger de falha = MG): \n";
                cin >> estado;
                estado_ = Estado(estado);
            }catch(exception &e){
                cout << "Formato incorreto!\n" << e.what() << "\n";
            }

            try{
                verificado = ctrlServicoEvento->ProcurarEvento(data_, horario_, cidade_, estado_);
            }catch(exception &e){
                cout << "\n" << e.what() << "\n";
            }

            if(verificado.GetResultado() == ResultadoEvento::falha){
                cout << "\nFalha de procura!\n\n";
            }

            resultado.SetResultado(verificado.GetResultado());
            return resultado;
        }
}



