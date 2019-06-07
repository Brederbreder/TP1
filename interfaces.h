#ifndef __INTERFACES_H__
#define __INTERFACES_H__

#include "dominios.h"
#include "entidades.h"
#include <stdbool.h>

class InterfaceApresentacaoControle;
class InterfaceApresentacaoUsuario;
class InterfaceApresentacaoAutenticacao;
class InterfaceApresentacaoEvento;
class InterfaceApresentacaoVenda;
class InterfaceServicoControle;
class InterfaceServicoUsuario;
class InterfaceServicoAutenticacao;
class InterfaceServicoEvento;
class InterfaceServicoVenda;

class InterfaceServicoControle{
    public:
        virtual void Construir() = 0;
        virtual ~InterfaceServicoControle() = default;
};

class InterfaceApresentacaoControle{
    public:
        virtual void Inicializar() = 0;
        virtual void ControleLogado(const Cpf &) = 0;
        virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;
        virtual void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;
        virtual void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *) = 0;
        virtual void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *) = 0;

        virtual ~InterfaceApresentacaoControle() = default;
};

class InterfaceServicoAutenticacao{
    public:
        virtual bool Autenticar(const Cpf &, const Senha &) = 0;
        virtual ~InterfaceServicoAutenticacao() = default;
};

class InterfaceApresentacaoAutenticacao{
    public:
        virtual bool Autenticar() = 0;
        virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;
        virtual ~InterfaceApresentacaoAutenticacao() = default;
};

class InterfaceServicoUsuario{
    public:
        virtual bool CadastrarUsuario(const string cpf, const string senha, const string numeroCartaoDeCredito,
                                      const string codigoDeSeguranca, const string dataDeValidade) = 0;
        virtual bool DescadastrarUsuario(const string cpf, const string senha ) = 0;
        virtual ~InterfaceServicoUsuario() = default;
};

class InterfaceApresentacaoUsuario{
    public:
        virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;
        virtual ~InterfaceApresentacaoUsuario() = default;
};

class InterfaceServicoEvento{
    public:
        virtual bool ProcurarEventos(const string horarioInicio, const string horarioTermino, const string cidade,
                                     const string estado) = 0;
        virtual bool CadastrarEvento(const CodigoDeEvento &, const NomeDeEvento &, const CodigoDeApresentacao &,
                                     const Data &, const Horario &, const Preco &, const NumeroDeSala &,
                                     const Cidade &, const Estado &, const ClasseDeEvento &, const FaixaEtaria &) = 0;
        virtual bool DescadastrarEvento(const CodigoDeEvento &);
        virtual ~InterfaceServicoEvento() = default;
};

class InterfaceApresentacaoEvento{
    public:
        virtual void Executar(const Cpf &) = 0;
        virtual void SetCtrlServicoEvento(InterfaceServicoEvento *) = 0;
        virtual ~InterfaceApresentacaoEvento() = default;
};

class InterfaceServicoVenda{
    public:
        virtual bool Comprar(const CodigoDeApresentacao &, int quantidade) = 0;
        virtual ~InterfaceServicoVenda() = default;
};

class InterfaceApresentacaoVenda{
    public:
        virtual void Executar(const Cpf &) = 0;
        virtual void SetCtrlServicoVenda(InterfaceServicoVenda *) = 0;
        virtual ~InterfaceApresentacaoVenda() = default;
};

#endif // __INTEFACES_H__
