#ifndef __STUBS_H__
#define __STUBS_H__

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "auxiliar.h"

class StubControle : public InterfaceServicoControle{
    public:
        void Construir() override;
};

class StubUsuario : public InterfaceServicoUsuario{
    public:
        const static string trigger_erro_sistema_;
        const static string trigger_cpf_invalido_;
        const static string trigger_senha_invalida_;
        const static string trigger_numero_invalido_;
        const static string trigger_codigo_invalido_;
        const static string trigger_data_invalida_;
        const static string trigger_cpf_valido_;
        const static string trigger_senha_valida_;
        const static string trigger_numero_valido_;
        const static string trigger_codigo_valido_;
        const static string trigger_data_valida_;
        virtual Resultado CadastrarUsuario(Usuario &usuario, const Cpf &cpf, const Senha &senha,
                                            const NumeroCartaoDeCredito &numeroCartaoDeCredito,
                                            const CodigoDeSeguranca &codigoDeSeguranca,
                                            const DataDeValidade &dataDeValidade);
        virtual Resultado DescadastrarUsuario(Usuario &usuario, const Cpf &cpf, const Senha &senha);
};

class StubAutenticacao : public InterfaceServicoAutenticacao{
    public:
        const static string trigger_erro_sistema_;
        const static string trigger_cpf_valido_;
        const static string trigger_cpf_invalido_;
        const static string trigger_senha_valida_;
        const static string trigger_senha_invalida_;
        Resultado Autenticar(const Cpf &cpf, const Senha &senha);
};

class StubEvento : public InterfaceServicoEvento{
    public:
        const static string trigger_erro_sistema_data;
        const static string trigger_data_invalida_;
        const static string trigger_horario_invalido_;
        const static string trigger_cidade_invalida_;
        const static string trigger_estado_invalido_;
        const static string trigger_data_valida_;
        const static string trigger_horario_valido_;
        const static string trigger_cidade_valida_;
        const static string trigger_estado_valido_;
        Resultado ProcurarEvento(const Data &data, const Horario &horario, const Cidade &cidade, const Estado &estado);
};

class StubVenda : public InterfaceServicoVenda{
    public:
        const static string trigger_erro_sistema_venda;
        const static string trigger_codigo_invalido_;
        const static int trigger_quantidade_invalida_;
        const static string trigger_codigo_valido_;
        const static int trigger_quantidade_valida_;
        Resultado Comprar(const CodigoDeApresentacao &codigo, const int quantidade);
};

#endif
