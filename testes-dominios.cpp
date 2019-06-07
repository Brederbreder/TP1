#include "testes-dominios.h"
#include "dominios.h"
#include <iostream>
#include <stdbool.h>
#include <exception>
#include <stdexcept>

using namespace std;

void TUCodigoDeEvento::CasoFalha(){
    try{
        codigo->SetCodigoDeEvento(CODIGO_INVALIDO_1);
        estado = false;
        codigo->SetCodigoDeEvento(CODIGO_INVALIDO_2);
        estado = false;
        codigo->SetCodigoDeEvento(CODIGO_INVALIDO_3);
        estado = false;
        codigo->SetCodigoDeEvento(CODIGO_INVALIDO_4);
        estado = false;
    }
    catch(exception &e){
        return;
    }
}

void TUCodigoDeEvento::CasoSucesso(){
    try{
        codigo->SetCodigoDeEvento(CODIGO_VALIDO);
        if(codigo->GetCodigoDeEvento() != CODIGO_VALIDO){
            estado = false;
        }
    }
    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUCodigoDeApresentacao::CasoFalha(){
    try{
        codigo->SetCodigoDeApresentacao(CODIGO_INVALIDO_1);
        estado = false;
        codigo->SetCodigoDeApresentacao(CODIGO_INVALIDO_2);
        estado = false;
        codigo->SetCodigoDeApresentacao(CODIGO_INVALIDO_3);
        estado = false;
        codigo->SetCodigoDeApresentacao(CODIGO_INVALIDO_4);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUCodigoDeApresentacao::CasoSucesso(){
    try{
        codigo->SetCodigoDeApresentacao(CODIGO_VALIDO);
        if(codigo->GetCodigoDeApresentacao() != CODIGO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUCodigoDeIngresso::CasoFalha(){
    try{
        codigo->SetCodigoDeIngresso(CODIGO_INVALIDO_1);
        estado = false;
        codigo->SetCodigoDeIngresso(CODIGO_INVALIDO_2);
        estado = false;
        codigo->SetCodigoDeIngresso(CODIGO_INVALIDO_3);
        estado = false;
        codigo->SetCodigoDeIngresso(CODIGO_INVALIDO_4);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUCodigoDeIngresso::CasoSucesso(){
    try{
        codigo->SetCodigoDeIngresso(CODIGO_VALIDO);
        if(codigo->GetCodigoDeIngresso() != CODIGO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUNomeDeEvento::CasoFalha(){
    try{
        nome->SetNomeDeEvento(NOME_INVALIDO_1);
        estado = false;
        nome->SetNomeDeEvento(NOME_INVALIDO_2);
        estado = false;
        nome->SetNomeDeEvento(NOME_INVALIDO_3);
        estado = false;
        nome->SetNomeDeEvento(NOME_INVALIDO_4);
        estado = false;
        nome->SetNomeDeEvento(NOME_INVALIDO_5);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUNomeDeEvento::CasoSucesso(){
    try{
        nome->SetNomeDeEvento(NOME_VALIDO);
        if(nome->GetNomeDeEvento() != NOME_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUData::CasoFalha(){
    try{
        data->SetData(DATA_INVALIDA_1);
        estado = false;
        data->SetData(DATA_INVALIDA_2);
        estado = false;
        data->SetData(DATA_INVALIDA_3);
        estado = false;
        data->SetData(DATA_INVALIDA_4);
        estado = false;
        data->SetData(DATA_INVALIDA_5);
        estado = false;
        data->SetData(DATA_INVALIDA_6);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUData::CasoSucesso(){
    try{
        data->SetData(DATA_VALIDA);
        if(data->GetData() != DATA_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUHorario::CasoFalha(){
    try{
        horario->SetHorario(HORARIO_INVALIDO_1);
        estado = false;
        horario->SetHorario(HORARIO_INVALIDO_2);
        estado = false;
        horario->SetHorario(HORARIO_INVALIDO_3);
        estado = false;
        horario->SetHorario(HORARIO_INVALIDO_4);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUHorario::CasoSucesso(){
    try{
        horario->SetHorario(HORARIO_VALIDO);
        if(horario->GetHorario() != HORARIO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUPreco::CasoFalha(){
    try{
        preco->SetPreco(PRECO_INVALIDO_1);
        estado = false;
        preco->SetPreco(PRECO_INVALIDO_2);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUPreco::CasoSucesso(){
    try{
        preco->SetPreco(PRECO_VALIDO);
        if(preco->GetPreco() != PRECO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUNumeroDeSala::CasoFalha(){
    try{
        numero->SetNumeroDeSala(NUMERO_INVALIDO_1);
        estado = false;
        numero->SetNumeroDeSala(NUMERO_INVALIDO_2);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUNumeroDeSala::CasoSucesso(){
    try{
        numero->SetNumeroDeSala(NUMERO_VALIDO);
        if(numero->GetNumeroDeSala() != NUMERO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUCidade::CasoFalha(){
    try{
        cidade->SetCidade(CIDADE_INVALIDA_1);
        estado = false;
        cidade->SetCidade(CIDADE_INVALIDA_2);
        estado = false;
        cidade->SetCidade(CIDADE_INVALIDA_3);
        estado = false;
        cidade->SetCidade(CIDADE_INVALIDA_4);
        estado = false;
        cidade->SetCidade(CIDADE_INVALIDA_5);
        estado = false;
        cidade->SetCidade(CIDADE_INVALIDA_6);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUCidade::CasoSucesso(){
    try{
        cidade->SetCidade(CIDADE_VALIDA);
        if(cidade->GetCidade() != CIDADE_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUEstado::CasoFalha(){
    try{
        estado_->SetEstado(ESTADO_INVALIDO_1);
        estado = false;
        estado_->SetEstado(ESTADO_INVALIDO_2);
        estado = false;
        estado_->SetEstado(ESTADO_INVALIDO_3);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUEstado::CasoSucesso(){
    try{
        estado_->SetEstado(ESTADO_VALIDO);
        if(estado_->GetEstado() != ESTADO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUDisponibilidade::CasoFalha(){
    try{
        disponibilidade->SetDisponibilidade(DISPONIBILIDADE_INVALIDA_1);
        estado = false;
        disponibilidade->SetDisponibilidade(DISPONIBILIDADE_INVALIDA_2);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUDisponibilidade::CasoSucesso(){
    try{
        disponibilidade->SetDisponibilidade(DISPONIBILIDADE_VALIDA);
        if(disponibilidade->GetDisponibilidade() != DISPONIBILIDADE_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUClasseDeEvento::CasoFalha(){
    try{
        classe->SetClasseDeEvento(CLASSE_INVALIDA_1);
        estado = false;
        classe->SetClasseDeEvento(CLASSE_INVALIDA_2);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUClasseDeEvento::CasoSucesso(){
    try{
        classe->SetClasseDeEvento(CLASSE_VALIDA);
        if(classe->GetClasseDeEvento() != CLASSE_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUFaixaEtaria::CasoFalha(){
    try{
        idade->SetFaixaEtaria(IDADE_INVALIDA_1);
        estado = false;
        idade->SetFaixaEtaria(IDADE_INVALIDA_2);
        estado = false;
        idade->SetFaixaEtaria(IDADE_INVALIDA_3);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUFaixaEtaria::CasoSucesso(){
    try{
        idade->SetFaixaEtaria(IDADE_VALIDA);
        if(idade->GetFaixaEtaria() != IDADE_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUCpf::CasoFalha(){
    try{
        cpf->SetCpf(CPF_INVALIDO_1);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_2);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_3);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_4);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_5);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_6);
        estado = false;
        cpf->SetCpf(CPF_INVALIDO_7);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUCpf::CasoSucesso(){
    try{
        cpf->SetCpf(CPF_VALIDO);
        if(cpf->GetCpf() != CPF_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUSenha::CasoFalha(){
    try{
        senha->SetSenha(SENHA_INVALIDA_1);
        estado = false;
        senha->SetSenha(SENHA_INVALIDA_2);
        estado = false;
        senha->SetSenha(SENHA_INVALIDA_3);
        estado = false;
        senha->SetSenha(SENHA_INVALIDA_4);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUSenha::CasoSucesso(){
    try{
        senha->SetSenha(SENHA_VALIDA);
        if(senha->GetSenha() != SENHA_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUCodigoDeSeguranca::CasoFalha(){
    try{
        codigo->SetCodigoDeSeguranca(CODIGO_INVALIDO_1);
        estado = false;
        codigo->SetCodigoDeSeguranca(CODIGO_INVALIDO_2);
        estado = false;
        codigo->SetCodigoDeSeguranca(CODIGO_INVALIDO_3);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUCodigoDeSeguranca::CasoSucesso(){
    try{
        codigo->SetCodigoDeSeguranca(CODIGO_VALIDO);
        if(codigo->GetCodigoDeSeguranca() != CODIGO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUDataDeValidade::CasoFalha(){
    try{
        data->SetDataDeValidade(DATA_INVALIDA_1);
        estado = false;
        data->SetDataDeValidade(DATA_INVALIDA_2);
        estado = false;
        data->SetDataDeValidade(DATA_INVALIDA_3);
        estado = false;
        data->SetDataDeValidade(DATA_INVALIDA_4);
        estado = false;
        data->SetDataDeValidade(DATA_INVALIDA_5);
        estado = false;
        data->SetDataDeValidade(DATA_INVALIDA_6);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUDataDeValidade::CasoSucesso(){
    try{
        data->SetDataDeValidade(DATA_VALIDA);
        if(data->GetDataDeValidade() != DATA_VALIDA){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

/*-----------------------------------------------------------------------------------------*/

void TUNumeroCartaoDeCredito::CasoFalha(){
    try{
        cartao->SetNumeroCartaoDeCredito(CARTAO_INVALIDO_1);
        estado = false;
        cartao->SetNumeroCartaoDeCredito(CARTAO_INVALIDO_2);
        estado = false;
        cartao->SetNumeroCartaoDeCredito(CARTAO_INVALIDO_3);
        estado = false;
        cartao->SetNumeroCartaoDeCredito(CARTAO_INVALIDO_4);
        estado = false;
    }

    catch(exception &e){
        return;
    }
}

void TUNumeroCartaoDeCredito::CasoSucesso(){
    try{
        cartao->SetNumeroCartaoDeCredito(CARTAO_VALIDO);
        if(cartao->GetNumeroCartaoDeCredito() != CARTAO_VALIDO){
            estado = false;
        }
    }

    catch(exception &e){
        cout << "\n\t" << e.what() << "\n";
        estado = false;
    }
}

void TUDominios::RunDominios(){
    cout << "\tTestes de unidade dos Dominios em execucao\n\n";
    SetUpDominios();

    switch(testeUnidadeCodigoDeEvento->Run()){
        case true:{
            cout << "Teste de unidade do Codigo de Evento realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Codigo de Evento realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCodigoDeApresentacao->Run()){
        case true:{
            cout << "Teste de unidade do Codigo de Apresentacao realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Codigo de Apresentacao realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCodigoDeIngresso->Run()){
        case true:{
            cout << "Teste de unidade do Codigo de Ingresso realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Codigo de Ingresso realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeNomeDeEvento->Run()){
        case true:{
            cout << "Teste de unidade do Nome de Evento realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Nome de Evento realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeData->Run()){
        case true:{
            cout << "Teste de unidade da Data realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Data realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeHorario->Run()){
        case true:{
            cout << "Teste de unidade do Horario realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Horario realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadePreco->Run()){
        case true:{
            cout << "Teste de unidade do Preco realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Preco realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeNumeroDeSala->Run()){
        case true:{
            cout << "Teste de unidade do Numero de Sala realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Numero de Sala realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCidade->Run()){
        case true:{
            cout << "Teste de unidade da Cidade realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Cidade realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeEstado->Run()){
        case true:{
            cout << "Teste de unidade do Estado realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Estado realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeDisponibilidade->Run()){
        case true:{
            cout << "Teste de unidade da Disponibilidade realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Disponibilidade realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeClasseDeEvento->Run()){
        case true:{
            cout << "Teste de unidade da Classe de Evento realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Classe de Evento realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeFaixaEtaria->Run()){
        case true:{
            cout << "Teste de unidade da Faixa Etaria realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Faixa Etaria realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCpf->Run()){
        case true:{
            cout << "Teste de unidade do Cpf realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Cpf realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeSenha->Run()){
        case true:{
            cout << "Teste de unidade da Senha realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade da Senha realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeNumeroCartaoDeCredito->Run()){
        case true:{
            cout << "Teste de unidade do Numero de Cartao de Credito realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Numero de Cartao de Credito realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeCodigoDeSeguranca->Run()){
        case true:{
            cout << "Teste de unidade do Codigo de Seguranca realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Codigo De Seguranca realizado com falha\n";
            break;
        }
        default:break;
    }

    switch(testeUnidadeDataDeValidade->Run()){
        case true:{
            cout << "Teste de unidade da Data de Validade realizado com sucesso\n";
            break;
        }
        case false:{
            cout << "Teste de unidade do Data de Validade realizado com falha\n";
            break;
        }
        default:break;
    }
    DestroyDominios();
}
