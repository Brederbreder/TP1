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
        const static string trigger_erro_sistema_codigo_;
        const static string trigger_erro_sistema_data_;
        const static string trigger_data_invalida_;
        const static string trigger_horario_invalido_;
        const static string trigger_cidade_invalida_;
        const static string trigger_estado_invalido_;
        const static string trigger_codigo_evento_invalido_;
        const static string trigger_nome_invalido_;
        const static string trigger_codigo_apresentacao_invalido_;
        const static int trigger_preco_invalido_;
        const static int trigger_numero_invalido_;
        const static int trigger_classe_invalida_;
        const static string trigger_faixa_invalida_;
        const static string trigger_data_valida_;
        const static string trigger_horario_valido_;
        const static string trigger_cidade_valida_;
        const static string trigger_estado_valido_;
        const static string trigger_codigo_evento_valido_;
        const static string trigger_nome_valido_;
        const static string trigger_codigo_apresentacao_valido_;
        const static int trigger_preco_valido_;
        const static int trigger_numero_valido_;
        const static int trigger_classe_valida_;
        const static string trigger_faixa_valida_;
        Resultado ProcurarEvento(const Data &data, const Horario &horario, const Cidade &cidade, const Estado &estado);
        Resultado CadastrarEvento(const CodigoDeEvento &codigoDeEvento, const NomeDeEvento &nome,
                                  const CodigoDeApresentacao &codigoDeApresentacao, const Data &data,
                                  const Horario &horario, const Preco &preco, const NumeroDeSala &numero,
                                  const Cidade &cidade, const Estado &estado, const ClasseDeEvento &classe,
                                  const FaixaEtaria &faixa);
        Resultado EditarEvento(const CodigoDeEvento &codigoDeEvento, const NomeDeEvento &nome,
                               const Cidade &cidade, const Estado &estado, const ClasseDeEvento &classe,
                               const FaixaEtaria &faixa);
        Resultado DescadastrarEvento(const CodigoDeEvento &codigoDeEvento);
};

class StubVenda : public InterfaceServicoVenda{
    public:
        const static string trigger_erro_sistema_venda_;
        const static string trigger_codigo_invalido_;
        const static int trigger_quantidade_invalida_;
        const static string trigger_codigo_valido_;
        const static int trigger_quantidade_valida_;
        Resultado Comprar(const CodigoDeApresentacao &codigo, const int quantidade);
};

#endif
