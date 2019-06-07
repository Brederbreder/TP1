#ifndef __TESTES_DOMINIOS_H__
#define __TESTES_DOMINIOS_H__

#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "dominios.h"

using namespace std;

class TUBaseDominios{
    private:
        virtual void SetUp() = 0;
        virtual void CasoSucesso() = 0;
        virtual void CasoFalha() = 0;
        virtual void Destroy() = 0;

    protected:
        int estado;

    public:
        int Run(){
            SetUp();
            CasoSucesso();
            CasoFalha();
            Destroy();
            return estado;
        }

        virtual ~TUBaseDominios() = default;
};

class TUCodigoDeEvento : public TUBaseDominios{
    private:
        const string CODIGO_INVALIDO_1 = "1234";
        const string CODIGO_INVALIDO_2 = "12";
        const string CODIGO_INVALIDO_3 = "";
        const string CODIGO_INVALIDO_4 = "12a";
        const string CODIGO_VALIDO     = "123";

        CodigoDeEvento *codigo;

        void SetUp(){
            codigo = new CodigoDeEvento();
            estado = true;
        }

        void Destroy(){
            delete codigo;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUCodigoDeApresentacao : public TUBaseDominios{
    private:
        const string CODIGO_INVALIDO_1 = "12345";
        const string CODIGO_INVALIDO_2 = "12";
        const string CODIGO_INVALIDO_3 = "";
        const string CODIGO_INVALIDO_4 = "123a";
        const string CODIGO_VALIDO     = "1234";

        CodigoDeApresentacao *codigo;

        void SetUp(){
            codigo = new CodigoDeApresentacao();
            estado = true;
        }

        void Destroy(){
            delete codigo;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUCodigoDeIngresso : public TUBaseDominios{
    private:
        const string CODIGO_INVALIDO_1 = "123456";
        const string CODIGO_INVALIDO_2 = "12";
        const string CODIGO_INVALIDO_3 = "";
        const string CODIGO_INVALIDO_4 = "1234a";
        const string CODIGO_VALIDO     = "12345";

        CodigoDeIngresso *codigo;

        void SetUp(){
            codigo = new CodigoDeIngresso();
            estado = true;
        }

        void Destroy(){
            delete codigo;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUNomeDeEvento : public TUBaseDominios{
    private:
        const string NOME_INVALIDO_1 = "asdfghjklkjhgfdsasdfghjkl";
        const string NOME_INVALIDO_2 = "";
        const string NOME_INVALIDO_3 = "nome-errado";
        const string NOME_INVALIDO_4 = "espaco  espaco";
        const string NOME_INVALIDO_5 = "1234567890";
        const string NOME_VALIDO     = "Apresentacao";

        NomeDeEvento *nome;

        void SetUp(){
            nome = new NomeDeEvento();
            estado = true;
        }

        void Destroy(){
            delete nome;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUData : public TUBaseDominios{
    private:
        const string DATA_INVALIDA_1 = "";
        const string DATA_INVALIDA_2 = "19/08/2010";
        const string DATA_INVALIDA_3 = "50/10/20";
        const string DATA_INVALIDA_4 = "1/20/20";
        const string DATA_INVALIDA_5 = "29/2/20";
        const string DATA_INVALIDA_6 = "31/04/19";
        const string DATA_VALIDA     = "10/10/19";

        Data *data;

        void SetUp(){
            data = new Data();
            estado = true;
        }

        void Destroy(){
            delete data;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUHorario : public TUBaseDominios{
    private:
        const string HORARIO_INVALIDO_1 = "";
        const string HORARIO_INVALIDO_2 = "12:120";
        const string HORARIO_INVALIDO_3 = "23:59";
        const string HORARIO_INVALIDO_4 = "10:25";
        const string HORARIO_VALIDO     = "18:00";

        Horario *horario;

        void SetUp(){
            horario = new Horario();
            estado = true;
        }

        void Destroy(){
            delete horario;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUPreco : public TUBaseDominios{
    private:
        const float PRECO_INVALIDO_1 = 0;
        const float PRECO_INVALIDO_2 = 1001;
        const float PRECO_VALIDO     = 500;

        Preco *preco;

        void SetUp(){
            preco = new Preco();
            estado = true;
        }

        void Destroy(){
            delete preco;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUNumeroDeSala : public TUBaseDominios{
    private:
        const int NUMERO_INVALIDO_1 = 0;
        const int NUMERO_INVALIDO_2 = 12;
        const int NUMERO_VALIDO     = 5;

        NumeroDeSala *numero;

        void SetUp(){
            numero = new NumeroDeSala();
            estado = true;
        }

        void Destroy(){
            delete numero;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUCidade : public TUBaseDominios{
    private:
        const string CIDADE_INVALIDA_1 = "";
        const string CIDADE_INVALIDA_2 = "nomemaiorquequinze";
        const string CIDADE_INVALIDA_3 = "nomecomnumero5";
        const string CIDADE_INVALIDA_4 = "espaco  espaco";
        const string CIDADE_INVALIDA_5 = "ponto.";
        const string CIDADE_INVALIDA_6 = "...";
        const string CIDADE_VALIDA     = "nome de cidade.";

        Cidade *cidade;

        void SetUp(){
            cidade = new Cidade();
            estado = true;
        }

        void Destroy(){
            delete cidade;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUEstado : public TUBaseDominios{
    private:
        const string ESTADO_INVALIDO_1 = "";
        const string ESTADO_INVALIDO_2 = "ABC";
        const string ESTADO_INVALIDO_3 = "AA";
        const string ESTADO_VALIDO     = "DF";


        Estado *estado_;

        void SetUp(){
            estado_ = new Estado();
            estado = true;
        }

        void Destroy(){
            delete estado_;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUDisponibilidade : public TUBaseDominios{
    private:
        const int DISPONIBILIDADE_INVALIDA_1 = -1;
        const int DISPONIBILIDADE_INVALIDA_2 = 10000;
        const int DISPONIBILIDADE_VALIDA     = 100;

        Disponibilidade *disponibilidade;

        void SetUp(){
            disponibilidade = new Disponibilidade();
            estado = true;
        }

        void Destroy(){
            delete disponibilidade;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUClasseDeEvento : public TUBaseDominios{
    private:
        const int CLASSE_INVALIDA_1 = 10;
        const int CLASSE_INVALIDA_2 = 0;
        const int CLASSE_VALIDA     = 2;

        ClasseDeEvento *classe;

        void SetUp(){
            classe = new ClasseDeEvento();
            estado = true;
        }

        void Destroy(){
            delete classe;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUFaixaEtaria : public TUBaseDominios{
    private:
        const string IDADE_INVALIDA_1 = "120";
        const string IDADE_INVALIDA_2 = "";
        const string IDADE_INVALIDA_3 = "22";
        const string IDADE_VALIDA     = "L";

        FaixaEtaria *idade;

        void SetUp(){
            idade = new FaixaEtaria();
            estado = true;
        }

        void Destroy(){
            delete idade;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUCpf : public TUBaseDominios{
    private:
        const string CPF_INVALIDO_1 = "040.906.801.100";
        const string CPF_INVALIDO_2 = "";
        const string CPF_INVALIDO_3 = "04.0906.801-00";
        const string CPF_INVALIDO_4 = "040.9068.01-00";
        const string CPF_INVALIDO_5 = "040.906.801.00";
        const string CPF_INVALIDO_6 = "040.9a6.801-00";
        const string CPF_INVALIDO_7 = "123.456.789-10"; //DIGITOS VERIFICADORES ERRADOS
        const string CPF_VALIDO     = "123.456.789-09";

        Cpf *cpf;

        void SetUp(){
            cpf = new Cpf();
            estado = true;
        }

        void Destroy(){
            delete cpf;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUSenha : public TUBaseDominios{
    private:
        const string SENHA_INVALIDA_1 = "a1b2c3d4";
        const string SENHA_INVALIDA_2 = "";
        const string SENHA_INVALIDA_3 = "aabbcc";
        const string SENHA_INVALIDA_4 = "abc123";
        const string SENHA_VALIDA     = "Aa1Bb2";

        Senha *senha;

        void SetUp(){
            senha = new Senha();
            estado = true;
        }

        void Destroy(){
            delete senha;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUCodigoDeSeguranca : public TUBaseDominios{
    private:
        const string CODIGO_INVALIDO_1 = "1234";
        const string CODIGO_INVALIDO_2 = "";
        const string CODIGO_INVALIDO_3 = "1a2";
        const string CODIGO_VALIDO     = "201";

        CodigoDeSeguranca *codigo;

        void SetUp(){
            codigo = new CodigoDeSeguranca();
            estado = true;
        }

        void Destroy(){
            delete codigo;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUDataDeValidade : public TUBaseDominios{
    private:
        const string DATA_INVALIDA_1 = "10/999";
        const string DATA_INVALIDA_2 = "";
        const string DATA_INVALIDA_3 = "2/222";
        const string DATA_INVALIDA_4 = "2a/2b";
        const string DATA_INVALIDA_5 = "13/22";
        const string DATA_INVALIDA_6 = "1/100";
        const string DATA_VALIDA     = "10/22";

        DataDeValidade *data;

        void SetUp(){
            data = new DataDeValidade();
            estado = true;
        }

        void Destroy(){
            delete data;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUNumeroCartaoDeCredito : public TUBaseDominios{
    private:
        const string CARTAO_INVALIDO_1 = "1234567890987654321";
        const string CARTAO_INVALIDO_2 = "";
        const string CARTAO_INVALIDO_3 = "123456abc0123456";
        const string CARTAO_INVALIDO_4 = "0000000000000000";
        const string CARTAO_VALIDO     = "5555666677778884";

        NumeroCartaoDeCredito *cartao;

        void SetUp(){
            cartao = new NumeroCartaoDeCredito();
            estado = true;
        }

        void Destroy(){
            delete cartao;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUDominios{
    private:
        TUCodigoDeEvento *testeUnidadeCodigoDeEvento;
        TUCodigoDeApresentacao *testeUnidadeCodigoDeApresentacao;
        TUCodigoDeIngresso *testeUnidadeCodigoDeIngresso;
        TUNomeDeEvento *testeUnidadeNomeDeEvento;
        TUData *testeUnidadeData;
        TUHorario *testeUnidadeHorario;
        TUPreco *testeUnidadePreco;
        TUNumeroDeSala *testeUnidadeNumeroDeSala;
        TUCidade *testeUnidadeCidade;
        TUEstado *testeUnidadeEstado;
        TUDisponibilidade *testeUnidadeDisponibilidade;
        TUClasseDeEvento *testeUnidadeClasseDeEvento;
        TUFaixaEtaria *testeUnidadeFaixaEtaria;
        TUCpf *testeUnidadeCpf;
        TUSenha *testeUnidadeSenha;
        TUNumeroCartaoDeCredito *testeUnidadeNumeroCartaoDeCredito;
        TUCodigoDeSeguranca *testeUnidadeCodigoDeSeguranca;
        TUDataDeValidade *testeUnidadeDataDeValidade;

        void SetUpDominios(){
            testeUnidadeCidade = new TUCidade();
            testeUnidadeClasseDeEvento = new TUClasseDeEvento();
            testeUnidadeCodigoDeApresentacao = new TUCodigoDeApresentacao();
            testeUnidadeCodigoDeEvento = new TUCodigoDeEvento();
            testeUnidadeCodigoDeIngresso = new TUCodigoDeIngresso();
            testeUnidadeCodigoDeSeguranca = new TUCodigoDeSeguranca();
            testeUnidadeCpf = new TUCpf();
            testeUnidadeData = new TUData();
            testeUnidadeDataDeValidade = new TUDataDeValidade();
            testeUnidadeDisponibilidade = new TUDisponibilidade();
            testeUnidadeEstado = new TUEstado();
            testeUnidadeFaixaEtaria = new TUFaixaEtaria();
            testeUnidadeHorario = new TUHorario();
            testeUnidadeNomeDeEvento = new TUNomeDeEvento();
            testeUnidadeNumeroCartaoDeCredito = new TUNumeroCartaoDeCredito();
            testeUnidadeNumeroDeSala = new TUNumeroDeSala();
            testeUnidadePreco = new TUPreco();
            testeUnidadeSenha = new TUSenha();
        }

        void DestroyDominios(){
            delete testeUnidadeCidade;
            delete testeUnidadeClasseDeEvento;
            delete testeUnidadeCodigoDeApresentacao;
            delete testeUnidadeCodigoDeEvento;
            delete testeUnidadeCodigoDeIngresso;
            delete testeUnidadeCodigoDeSeguranca;
            delete testeUnidadeCpf;
            delete testeUnidadeData;
            delete testeUnidadeDataDeValidade;
            delete testeUnidadeDisponibilidade;
            delete testeUnidadeEstado;
            delete testeUnidadeFaixaEtaria;
            delete testeUnidadeHorario;
            delete testeUnidadeNomeDeEvento;
            delete testeUnidadeNumeroCartaoDeCredito;
            delete testeUnidadeNumeroDeSala;
            delete testeUnidadePreco;
            delete testeUnidadeSenha;
        }

    public:
        void RunDominios();
};
#endif // __TESTES_DOMINIOS__
