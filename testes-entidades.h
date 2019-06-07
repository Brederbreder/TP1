#ifndef __TESTES_ENTIDADES_H__
#define __TESTES_ENTIDADES_H__

#include "entidades.h"
#include "dominios.h"

class TUBaseEntidades{
    private:
        virtual void SetUp() = 0;
        virtual void Destroy() = 0;
        virtual void CasoSucesso() = 0;

    protected:
        int estado;

    public:
        int run(){
            SetUp();
            CasoSucesso();
            Destroy();
            return estado;
        }

        virtual ~TUBaseEntidades() = default;
};

class TUUsuario : public TUBaseEntidades{
    private:
        Usuario *usuarioValido;
        Cpf CPF_VALIDO = Cpf("123.456.789-09");
        Senha SENHA_VALIDA = Senha("1Aa2Bb");

        void SetUp(){
            usuarioValido = new Usuario(CPF_VALIDO, SENHA_VALIDA);
            estado = 1;
        }

        void Destroy(){
            delete usuarioValido;
        }

        void CasoSucesso();
};

class TUEvento : public TUBaseEntidades{
    private:
        Evento *eventoValido;
        CodigoDeEvento CODIGO_DE_EVENTO_VALIDO  = CodigoDeEvento("123");
        NomeDeEvento NOME_DE_EVENTO_VALIDO      = NomeDeEvento("apresentacao");
        Cidade CIDADE_VALIDA                    = Cidade("cidade");
        Estado ESTADO_VALIDO                    = Estado("DF");
        ClasseDeEvento CLASSE_DE_EVENTO_VALIDA  = ClasseDeEvento(1);
        FaixaEtaria FAIXA_ETARIA_VALIDA         = FaixaEtaria("L");

        void SetUp(){
            eventoValido = new Evento(CODIGO_DE_EVENTO_VALIDO, NOME_DE_EVENTO_VALIDO, CIDADE_VALIDA, ESTADO_VALIDO,
                                      CLASSE_DE_EVENTO_VALIDA, FAIXA_ETARIA_VALIDA);
            estado = 1;
        }

        void Destroy(){
            delete eventoValido;
        }

        void CasoSucesso();
};

class TUApresentacao : public TUBaseEntidades{
    private:
        Apresentacao *apresentacaoValida;
        CodigoDeApresentacao CODIGO_DE_APRESENTACAO_VALIDO    = CodigoDeApresentacao("1234");
        Data DATA_VALIDA                                      = Data("10/05/19");
        Horario HORARIO_VALIDO                                = Horario("16:00");
        Preco PRECO_VALIDO                                    = Preco(500);
        NumeroDeSala NUMERO_DE_SALA_VALIDO                    = NumeroDeSala(5);
        Disponibilidade DISPONIBILIDADE_VALIDA                = Disponibilidade(100);

        void SetUp(){
            apresentacaoValida = new Apresentacao(CODIGO_DE_APRESENTACAO_VALIDO, DATA_VALIDA, HORARIO_VALIDO,
                                                  PRECO_VALIDO, NUMERO_DE_SALA_VALIDO, DISPONIBILIDADE_VALIDA);
            estado = 1;
        }

        void Destroy(){
            delete apresentacaoValida;
        }

        void CasoFalha();
        void CasoSucesso();
};

class TUIngresso : public TUBaseEntidades{
    private:
        Ingresso *ingressoValido;
        CodigoDeIngresso CODIGO_DE_INGRESSO_VALIDO    = CodigoDeIngresso("12345");

        void SetUp(){
            ingressoValido = new Ingresso(CODIGO_DE_INGRESSO_VALIDO);
            estado = 1;
        }

        void Destroy(){
            delete ingressoValido;
        }

        void CasoSucesso();
};

class TUCartaoDeCredito : public TUBaseEntidades{
    CartaoDeCredito *cartaoValido;
    NumeroCartaoDeCredito NUMERO_CARTAO_DE_CREDITO_VALIDO      = NumeroCartaoDeCredito("5555666677778884");
    CodigoDeSeguranca CODIGO_DE_SEGURANCA_VALIDO               = CodigoDeSeguranca("201");
    DataDeValidade DATA_DE_VALIDADE_VALIDA                     = DataDeValidade("10/22");

    void SetUp(){
        cartaoValido = new CartaoDeCredito(NUMERO_CARTAO_DE_CREDITO_VALIDO, CODIGO_DE_SEGURANCA_VALIDO,
                                           DATA_DE_VALIDADE_VALIDA);
        estado = 1;
    }

    void Destroy(){
        delete cartaoValido;
    }

    void CasoSucesso();
};

class TUEntidades{
    private:
        TUUsuario *testeUnidadeUsuario;
        TUEvento *testeUnidadeEvento;
        TUApresentacao *testeUnidadeApresentacao;
        TUIngresso *testeUnidadeIngresso;
        TUCartaoDeCredito *testeUnidadeCartaoDeCredito;

        void SetUpEntidades(){
            testeUnidadeUsuario = new TUUsuario();
            testeUnidadeEvento = new TUEvento();
            testeUnidadeApresentacao = new TUApresentacao();
            testeUnidadeIngresso = new TUIngresso();
            testeUnidadeCartaoDeCredito = new TUCartaoDeCredito();
        }

        void DestroyEntidades(){
            delete testeUnidadeUsuario;
            delete testeUnidadeEvento;
            delete testeUnidadeApresentacao;
            delete testeUnidadeIngresso;
            delete testeUnidadeCartaoDeCredito;
        }

    public:
        void RunEntidades();
};

#endif // __TESTES_ENTIDADES_H__




