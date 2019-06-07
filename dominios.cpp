#include "dominios.h"
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <array>

using namespace std;

void CodigoDeEvento::Validar(string codigoDeEvento){
    int tamanhoVetor = codigoDeEvento.size();

    if(tamanhoVetor > TAM_MAX_CODIGO){
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanhoVetor > STRING_VAZIA && tamanhoVetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXX(0<X<9).");
    }
    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(codigoDeEvento[i] < '0' || codigoDeEvento[i] > '9'){
            throw invalid_argument("Formato errado, somente digitos sao permitidos.\n");
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeEvento::SetCodigoDeEvento(string codigoDeEvento){
    Validar(codigoDeEvento);
    this->codigoDeEvento = codigoDeEvento;
}

/*------------------------------------------------------------------------------------------*/

void CodigoDeApresentacao::Validar(string codigoDeApresentacao){
    int tamanhoVetor = codigoDeApresentacao.size();

    if(tamanhoVetor > TAM_MAX_CODIGO){
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanhoVetor > STRING_VAZIA && tamanhoVetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXXX(0<X<9).\n");
    }
    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(codigoDeApresentacao[i] < '0' || codigoDeApresentacao[i] > '9'){
            throw invalid_argument("Somente digitos sao permitidos.\n");
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeApresentacao::SetCodigoDeApresentacao(string codigoDeApresentacao){
    Validar(codigoDeApresentacao);
    this->codigoDeApresentacao = codigoDeApresentacao;
}

/*--------------------------------------------------------------------------------------------------------*/

void CodigoDeIngresso::Validar(string codigoDeIngresso){
    int tamanhoVetor = codigoDeIngresso.size();

    if(tamanhoVetor > TAM_MAX_CODIGO){
        throw invalid_argument("Codigo maior que o possivel.\n");
    }
    if(tamanhoVetor > STRING_VAZIA && tamanhoVetor < TAM_MAX_CODIGO){
        throw invalid_argument("Formato errado, o formato correto e XXXXX(0<X<9).\n");
    }
    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(codigoDeIngresso[i] < '0' || codigoDeIngresso[i] > '9'){
            throw invalid_argument("Somente digitos sao permitidos.\n");
        }
    }//testa cada um dos caracteres, se nao for um numero de 1 a 9, retorna um erro
}

void CodigoDeIngresso::SetCodigoDeIngresso(string codigoDeIngresso){
    Validar(codigoDeIngresso);
    this->codigoDeIngresso = codigoDeIngresso;
}

/*--------------------------------------------------------------------------------------------*/

void NomeDeEvento::Validar(string nomeDeEvento){
    int tamanhoVetor = nomeDeEvento.size();
    int possuiLetra = 0;

    if(tamanhoVetor > TAM_MAX_NOME){
        throw invalid_argument("Nome muito extenso, o maximo de caracteres sao 20.\n");
    }
    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }
    for(int i=0; i<tamanhoVetor; i++){
        if(nomeDeEvento[i] < '0' && nomeDeEvento[i] > '9' && nomeDeEvento[i] < 'a' && nomeDeEvento[i] > 'z' &&
           nomeDeEvento[i] < 'A' && nomeDeEvento[i] > 'Z' && nomeDeEvento[i] != ' '){
            throw invalid_argument("Somento sao permitidos letras, digitos ou espaco.\n");
        }
        if((nomeDeEvento[i] > 'a' && nomeDeEvento[i] < 'z') || (nomeDeEvento[i] > 'A' && nomeDeEvento[i] < 'Z')){
            possuiLetra++;
        }
        if(nomeDeEvento[i] == ' ' && nomeDeEvento[i-1] == ' ' && i>0){
            throw invalid_argument("Nao sao permitidos espacos em sequencia.\n");
        }
    }//testa cada caractere, se for algo diferente de letra, numetro ou espaco, retorna erro
    //retorna erro se tiverem dois espacos seguidos

    if(possuiLetra == 0){
        throw invalid_argument("Nao possui nenhuma letra.\n");
    }//retorna erro caro nao tenha ao menos uma letra no nome;
}

void NomeDeEvento::SetNomeDeEvento(string nomeDeEvento){
    Validar(nomeDeEvento);
    this->nomeDeEvento = nomeDeEvento;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Data::Validar(string data){
    int tamanhoVetor = data.size();
    int anoBissexto = 0;
    string::size_type sz;

    if(tamanhoVetor < STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    if(tamanhoVetor > TAM_DATA_MAX){
        throw invalid_argument("Data muito extensa.\n");
    }

    if(data[POS_BARRA_DIA] != '/'){
        throw invalid_argument("Data no formato errado.\n");
    }

    if(data[POS_BARRA_MES] != '/'){
        throw invalid_argument("Data no formato errado.\n");
    }

    int diaInt = stoi(data, &sz);
    int mesInt = stoi(data.substr(sz+1), &sz);
    int anoInt = stoi(data.substr(sz + sz + 2));

    if(anoInt % 400 == 0 || (anoInt % 4 == 0 && anoInt % 100 != 0)){
        anoBissexto = 1;
    }

    if((anoBissexto == 0 && diaInt > DIA_MAX_FEVEREIRO && mesInt == FEVEREIRO) || diaInt > DIA_MAX ||
        diaInt < DIA_MIN || mesInt > MES_MAX || mesInt < MES_MIN || anoInt > ANO_MAX || anoInt < ANO_MIN){
            throw invalid_argument("Data invalida.\n");
        }

    if(diaInt > 30 && (mesInt == ABRIL || mesInt == JUNHO || mesInt == SETEMBRO || mesInt == NOVEMBRO)){
        throw invalid_argument("Dia invalido.\n");
    }
}

void Data::SetData(string data){
    Validar(data);
    this->data = data;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Horario::Validar(string horario){
    int tamanhoVetor = horario.size();
    int horaInt, minutoInt;
    string::size_type sz;

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Horario muito extenso.\n");
    }

    horaInt = stoi(horario, &sz);
    minutoInt = stoi(horario.substr(sz+1));

    if(horaInt < HORA_MIN && horaInt > HORA_MAX){
        throw invalid_argument("Hora invalida.\n");
    }

    if(minutoInt != MIN_0 && minutoInt != MIN_15 && minutoInt != MIN_30 && minutoInt != MIN_45){
        throw invalid_argument("Minuto invalido.\n");
    }
}

void Horario::SetHorario(string horario){
    Validar(horario);
    this->horario = horario;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void Preco::Validar(float preco){
    if(preco <= PRECO_MIN){
        throw invalid_argument("Preco menor ou igual a 0.\n");
    }
    if(preco > PRECO_MAX){
        throw invalid_argument("Preco maior que 1000.\n");
    }
}

void Preco::SetPreco(int preco){
    Validar(preco);
    this->preco = preco;
}

/*--------------------------------------------------------------------------------------------------------------------*/

void NumeroDeSala::Validar(int numeroDeSala){
    if(numeroDeSala < NUM_MIN){
        throw invalid_argument("Numero de sala menor que 1.\n");
    }

    if(numeroDeSala > NUM_MAX){
        throw invalid_argument("Numero de sala maior que 10.\n");
    }
}

void NumeroDeSala::SetNumeroDeSala(int numeroDeSala){
    Validar(numeroDeSala);
    this->numeroDeSala = numeroDeSala;
}

/*---------------------------------------------------------------------------------------------------------------------*/

void Cidade::Validar(string cidade){
    int tamanhoVetor = cidade.size();
    int numLetras = 0;

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Nome de cidade muito extenso.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(cidade[i] < 'a' && cidade[i] > 'z' && cidade[i] != ' ' && cidade[i] != '.'){
            throw invalid_argument("Somente sao permitidos letras, espacos e pontos");
        }
        if(cidade[i] > 'a' && cidade[i] < 'z'){
            numLetras++;
        }

        if(cidade[i] == ' ' && cidade[i-1] == ' '){
            throw invalid_argument("Nao podem existir espacos seguidos.\n");
        }

        if(cidade[i] == '.' && cidade[i-1] < 'a' && cidade[i] > 'z'){
            throw invalid_argument("Ponto deve ser precedido de letra.\n");
        }
    }

    if(numLetras == 0){
        throw invalid_argument("Pelo menos um caracter deve ser uma letra.\n");
    }
}

void Cidade::SetCidade(string cidade){
    Validar(cidade);
    this->cidade = cidade;
}

/*----------------------------------------------------------------------------------------------------*/

void Estado::Validar(string estado){
    int tamanhoVetor = estado.size();

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Nome do estado muito extenso.\n");
    }

    if(estado != AC && estado != AL && estado != AP && estado != AM && estado != BA && estado != CE && estado != DF &&
       estado != ES && estado != GO && estado != MA && estado != MT && estado != MS && estado != MG && estado != PA &&
       estado != PB && estado != PR && estado != PE && estado != PI && estado != RJ && estado != RN && estado != RS &&
       estado != RO && estado != RR && estado != SC && estado != SP && estado != SE && estado != TO){
        throw invalid_argument("Estado invalido.\n");
       }
}

void Estado::SetEstado(string estado){
    Validar(estado);
    this->estado = estado;
}

/*-----------------------------------------------------------------------------------------------------------------------*/

void Disponibilidade::Validar(int disponibilidade){
    if(disponibilidade < NUM_MIN){
        throw invalid_argument("Disponibilidade menor que 0.\n");
    }

    if(disponibilidade > NUM_MAX){
        throw invalid_argument("Disponibilidade maior que 250.\n");
    }
}

void Disponibilidade::SetDisponibilidade(int disponibilidade){
    Validar(disponibilidade);
    this->disponibilidade = disponibilidade;
}

/*------------------------------------------------------------------------------------------------------------------------*/

void ClasseDeEvento::Validar(int classeDeEvento){
    if(classeDeEvento > NUM_MAX){
        throw invalid_argument("Numero invalido.\n");
    }

    if(classeDeEvento < NUM_MIN){
        throw invalid_argument("Numero invalido.\n");
    }
}

void ClasseDeEvento::SetClasseDeEvento(int classeDeEvento){
    Validar(classeDeEvento);
    this->classeDeEvento = classeDeEvento;
}

/*---------------------------------------------------------------------------------------------------------------------*/

void FaixaEtaria::Validar(string faixaEtaria){
    int tamanhoVetor = faixaEtaria.size();

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Faixa etaria muito extensa.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    if(faixaEtaria != DEZ && faixaEtaria != DOZE && faixaEtaria != CATORZE && faixaEtaria != DEZESSEIS &&
       faixaEtaria != DEZOITO && faixaEtaria != LIVRE){
        throw invalid_argument("Faixa etaria invalida.\n");
       }
}

void FaixaEtaria::SetFaixaEtaria(string faixaEtaria){
    Validar(faixaEtaria);
    this->faixaEtaria = faixaEtaria;
}

/*----------------------------------------------------------------------------------------------------------*/

void Cpf::Validar(string cpf){
    int tamanhoVetor = cpf.size();
    int pesoCpf = 10;
    int somatorio = 0, numCpf;
    int digito1, digito2;
    int resto;

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("CPF muito extenso.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    if(cpf[POS_PONTO_UM] != '.'){
        throw invalid_argument("CPF com formato invalido.\n");
    }

    if(cpf[POS_PONTO_DOIS] != '.'){
        throw invalid_argument("CPF com formato invalido.\n");
    }

    if(cpf[POS_TRACO] != '-'){
        throw invalid_argument("CPF com formato invalido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(i == POS_PONTO_UM || i == POS_PONTO_DOIS || i == POS_TRACO){
            continue;
        }
        if(cpf[i] < '0' && cpf[i] > '9'){
            throw invalid_argument("CPF so aceita digitos.\n");
        }
    }

    for(int i=0; i<(tamanhoVetor-3); i++){
        if(i == POS_PONTO_UM || i == POS_PONTO_DOIS || i == POS_TRACO){
            continue;
        }
        numCpf = cpf[i] - 48; //TABELA ASCII
        somatorio += numCpf*(pesoCpf--);
    }

    resto = somatorio % 11;

    if(resto < 2){
        digito1 = 0;
    }else{
        digito1 = 11 - resto;
    }

    pesoCpf = 11;
    somatorio = 0;

    for(int i=0; i<(tamanhoVetor-3); i++){
        if(i == POS_PONTO_UM || i == POS_PONTO_DOIS || i == POS_TRACO){
            continue;
        }
        numCpf = cpf[i] - 48; //TABELA ASCII
        somatorio += numCpf*(pesoCpf--);
    }

    somatorio += digito1*2;

    resto = somatorio % 11;

    if(resto < 2){
        digito2 = 0;
    }else{
        digito2 = 11 - resto;
    }

    if((cpf[POS_TRACO+1]-48) != digito1){
        throw invalid_argument("Primeiro digito verificador invalido\n");
    }

    if((cpf[POS_TRACO+2]-48) != digito2){
        throw invalid_argument("Segundo digito verificador invalido\n");
    }
}

void Cpf::SetCpf(string cpf){
    Validar(cpf);
    this->cpf = cpf;
}

/*-------------------------------------------------------------------------------------*/

void Senha::Validar(string senha){
    int tamanhoVetor = senha.size();
    int numMinuscula = 0, numMaiuscula = 0, numDigito = 0;

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Senha muito extensa.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum caracter foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(senha[i] > 'a' && senha[i] < 'z'){
            numMinuscula++;
        }
        if(senha[i] > 'A' && senha[i] < 'Z'){
            numMaiuscula++;
        }
        if(senha[i] > '0' && senha[i] < '9'){
            numDigito++;
        }
        if(i == 0){
            continue;
        }
        if(senha[i] == senha[i-1]){
            throw invalid_argument("Nao pode existir caracteres iguais na senha.\n");
        }
    }

    if(numDigito == 0 || numMaiuscula == 0 || numMinuscula == 0){
        throw invalid_argument("A senha deve haver no minimo uma letra minuscula, uma maiuscula e um digito.\n");
    }
}

void Senha::SetSenha(string senha){
    Validar(senha);
    this->senha = senha;
}

/*------------------------------------------------------------------------------------------------------*/

void CodigoDeSeguranca::Validar(string codigoDeSeguranca){
    int tamanhoVetor = codigoDeSeguranca.size();

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Codigo de seguranaca muito extenso.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digitos foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(codigoDeSeguranca[i] > '9' && codigoDeSeguranca[i] < '0'){
            throw invalid_argument("Codigo de seguranca aceita somente digitos.\n");
        }
    }
}

void CodigoDeSeguranca::SetCodigoDeSeguranca(string codigoDeSeguranca){
    Validar(codigoDeSeguranca);
    this->codigoDeSeguranca = codigoDeSeguranca;
}

/*----------------------------------------------------------------------------------------------------*/

void DataDeValidade::Validar(string dataDeValidade){
    int tamanhoVetor = dataDeValidade.size();
    int mesInt, anoInt;
    string::size_type sz;

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Data de validade muito extensa.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    if(dataDeValidade[POS_BARRA] != '/'){
        throw invalid_argument("Data de validade no formato errado.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(i == POS_BARRA){
            continue;
        }
        if(dataDeValidade[i] < '0' && dataDeValidade[i] > '9'){
            throw invalid_argument("A data aceita somente digitos.\n");
        }
    }

    mesInt = stoi(dataDeValidade, &sz);
    anoInt = stoi(dataDeValidade.substr(sz+1));

    if(mesInt > MES_MAX || mesInt < MES_MIN){
        throw invalid_argument("Mes invalido.\n");
    }

    if(anoInt > ANO_MAX || anoInt < MES_MIN){
        throw invalid_argument("Ano invalido.\n");
    }

}

void DataDeValidade::SetDataDeValidade(string dataDeValidade){
    Validar(dataDeValidade);
    this->dataDeValidade = dataDeValidade;
}

/*----------------------------------------------------------------------------------------------------*/

void NumeroCartaoDeCredito::Validar(string cartaoDeCredito){
    int tamanhoVetor = cartaoDeCredito.size();
    int digitoVerificador, valor, somatorio = 0;

    if(tamanhoVetor > TAM_MAX){
        throw invalid_argument("Numero de cartao de credito muito extensa.\n");
    }

    if(tamanhoVetor == STRING_VAZIA){
        throw invalid_argument("Nenhum digito foi inserido.\n");
    }

    for(int i=0; i<tamanhoVetor; i++){
        if(cartaoDeCredito[i] < '0' && cartaoDeCredito[i] > '9'){
            throw invalid_argument("O numero de cartao de credito aceita somente digitos.\n");
        }
    }

    for(int i=(tamanhoVetor-1); i>=0; i--){
        if(i % 2 == 0){
            valor = cartaoDeCredito[i] - 48;//TABELA ASCII
            valor *= 2;
            if(valor > 9){
                cartaoDeCredito[i] = valor - 9 + 48;//TABELA ASCII
            }else{
                cartaoDeCredito[i] = valor + 48;//TABELA ASCII
            }
        }
    }

    for(int i=0; i<(tamanhoVetor-1); i++){
        valor = cartaoDeCredito[i] - 48;//TABELA ASCII
        somatorio += valor;
    }

    valor = somatorio % 10;

    digitoVerificador = 10 - valor;

    if((cartaoDeCredito[tamanhoVetor-1]-48) != digitoVerificador){
        throw invalid_argument("Numero de cartao de credito invalido.\n");
    }
}

void NumeroCartaoDeCredito::SetNumeroCartaoDeCredito(string cartaoDeCredito){
    Validar(cartaoDeCredito);
    this->cartaoDeCredito = cartaoDeCredito;
}

/*--------------------------------------------------------------------------------------------*/
