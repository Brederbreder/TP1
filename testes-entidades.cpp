#include "testes-entidades.h"
#include "dominios.h"
#include "entidades.h"

using namespace std;

void TUUsuario::CasoSucesso(){
    try{
        if(usuarioValido->GetCpf().GetCpf() != CPF_VALIDO.GetCpf()){
            estado = false;
        }
        if(usuarioValido->GetSenha().GetSenha() != SENHA_VALIDA.GetSenha()){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUEvento::CasoSucesso(){
    try{
        if(eventoValido->GetCodigoDeEvento().GetCodigoDeEvento() != CODIGO_DE_EVENTO_VALIDO.GetCodigoDeEvento()){
            estado = false;
        }
        if(eventoValido->GetNomeDeEvento().GetNomeDeEvento() != NOME_DE_EVENTO_VALIDO.GetNomeDeEvento()){
            estado = false;
        }
        if(eventoValido->GetCidade().GetCidade() != CIDADE_VALIDA.GetCidade()){
            estado = false;
        }
        if(eventoValido->GetEstado().GetEstado() != ESTADO_VALIDO.GetEstado()){
            estado = false;
        }
        if(eventoValido->GetClasseDeEvento().GetClasseDeEvento() != CLASSE_DE_EVENTO_VALIDA.GetClasseDeEvento()){
            estado = false;
        }
        if(eventoValido->GetFaixaEtaria().GetFaixaEtaria() != FAIXA_ETARIA_VALIDA.GetFaixaEtaria()){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUApresentacao::CasoSucesso(){
    try{
        if(apresentacaoValida->GetCodigoDeApresentacao().GetCodigoDeApresentacao() != CODIGO_DE_APRESENTACAO_VALIDO.GetCodigoDeApresentacao()){
            estado = false;
        }
        if(apresentacaoValida->GetData().GetData() != DATA_VALIDA.GetData()){
            estado = false;
        }
        if(apresentacaoValida->GetHorario().GetHorario() != HORARIO_VALIDO.GetHorario()){
            estado = false;
        }
        if(apresentacaoValida->GetPreco().GetPreco() != PRECO_VALIDO.GetPreco()){
            estado = false;
        }
        if(apresentacaoValida->GetNumeroDeSala().GetNumeroDeSala() != NUMERO_DE_SALA_VALIDO.GetNumeroDeSala()){
            estado = false;
        }
        if(apresentacaoValida->GetDisponibilidade().GetDisponibilidade() != DISPONIBILIDADE_VALIDA.GetDisponibilidade()){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUIngresso::CasoSucesso(){
    try{
        if(ingressoValido->GetCodigoDeIngresso().GetCodigoDeIngresso() != CODIGO_DE_INGRESSO_VALIDO.GetCodigoDeIngresso()){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUCartaoDeCredito::CasoSucesso(){
    try{
        if(cartaoValido->GetCodigoDeSeguranca().GetCodigoDeSeguranca() != CODIGO_DE_SEGURANCA_VALIDO.GetCodigoDeSeguranca()){
            estado = false;
        }
        if(cartaoValido->GetDataDeValidade().GetDataDeValidade() != DATA_DE_VALIDADE_VALIDA.GetDataDeValidade()){
            estado = false;
        }
        if(cartaoValido->GetNumeroCartaoDeCredito().GetNumeroCartaoDeCredito() != NUMERO_CARTAO_DE_CREDITO_VALIDO.GetNumeroCartaoDeCredito()){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUEntidades::RunEntidades(){
    cout << "\n\tTestes de unidade das Entidades em execucao\n\n";
    SetUpEntidades();

    switch(testeUnidadeUsuario->run()){
        case true:{
            cout << "Teste de unidade do Usuario realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Usuario realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeEvento->run()){
        case true:{
            cout << "Teste de unidade do Evento realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Evento realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeApresentacao->run()){
        case true:{
            cout << "Teste de unidade da Apresentacao realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Apresentacao realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeIngresso->run()){
        case true:{
            cout << "Teste de unidade do Ingresso realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Ingresso realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCartaoDeCredito->run()){
        case true:{
            cout << "Teste de unidade do Cartao de Credito realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Cartao de Credito com falha\n";
            break;
        }
        default:break;
    }
    DestroyEntidades();
}
