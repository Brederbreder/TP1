#ifndef __INTERFACES_H__
#define __INTERFACES_H__

#include "auxiliar.h"

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
        virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;
        virtual void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;
        virtual void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *) = 0;
        virtual void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *) = 0;
        virtual ~InterfaceApresentacaoControle() = default;
};

class InterfaceServicoAutenticacao{
    public:
        virtual Resultado Autenticar(const Cpf &, const Senha &) = 0;
        virtual ~InterfaceServicoAutenticacao() = default;
};

class InterfaceApresentacaoAutenticacao{
    public:
        virtual ResultadoAutenticar Autenticar() = 0;
        virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;
        virtual ~InterfaceApresentacaoAutenticacao() = default;
};

class InterfaceServicoUsuario{
    public:
        virtual Resultado CadastrarUsuario(Usuario &usuario, const Cpf &, const Senha &, const NumeroCartaoDeCredito &,
                                           const CodigoDeSeguranca &, const DataDeValidade &) = 0;
        virtual Resultado DescadastrarUsuario(Usuario &usuario, const Cpf &, const Senha &) = 0;
        virtual ~InterfaceServicoUsuario() = default;
};

class InterfaceApresentacaoUsuario{
    public:
        virtual ResultadoUsuario Cadastrar() = 0;
        virtual ResultadoUsuario Descadastrar() = 0;
        virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;
        virtual ~InterfaceApresentacaoUsuario() = default;
};

class InterfaceServicoEvento{
    public:
        virtual Resultado ProcurarEvento(const Data &data, const Horario &horario, const Cidade &cidade, const Estado &estado) = 0;
        virtual ~InterfaceServicoEvento() = default;
};

class InterfaceApresentacaoEvento{
    public:
        virtual ResultadoEvento Procurar() = 0;
        virtual void SetCtrlServicoEvento(InterfaceServicoEvento *) = 0;
        virtual ~InterfaceApresentacaoEvento() = default;
};

class InterfaceServicoVenda{
    public:
        virtual Resultado Comprar(const CodigoDeApresentacao &codigo, const int quantidade) = 0;
        virtual ~InterfaceServicoVenda() = default;
};

class InterfaceApresentacaoVenda{
    public:
        virtual ResultadoVenda ComprarIngresso() = 0;
        virtual void SetCtrlServicoVenda(InterfaceServicoVenda *) = 0;
        virtual ~InterfaceApresentacaoVenda() = default;
};

#endif // __INTEFACES_H__
