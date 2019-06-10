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
        virtual void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *) = 0;
        virtual void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *) = 0;
        virtual void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *) = 0;
        virtual void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *) = 0;
        virtual ~InterfaceApresentacaoControle() = default;
};

class InterfaceServicoAutenticacao{
    public:
        virtual ~InterfaceServicoAutenticacao() = default;
};

class InterfaceApresentacaoAutenticacao{
    public:
        virtual void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *) = 0;
        virtual ~InterfaceApresentacaoAutenticacao() = default;
};

class InterfaceServicoUsuario{
    public:
        virtual ~InterfaceServicoUsuario() = default;
};

class InterfaceApresentacaoUsuario{
    public:
        virtual void SetCtrlServicoUsuario(InterfaceServicoUsuario *) = 0;
        virtual ~InterfaceApresentacaoUsuario() = default;
};

class InterfaceServicoEvento{
    public:
        virtual ~InterfaceServicoEvento() = default;
};

class InterfaceApresentacaoEvento{
    public:
        virtual void SetCtrlServicoEvento(InterfaceServicoEvento *) = 0;
        virtual ~InterfaceApresentacaoEvento() = default;
};

class InterfaceServicoVenda{
    public:
        virtual ~InterfaceServicoVenda() = default;
};

class InterfaceApresentacaoVenda{
    public:
        virtual void SetCtrlServicoVenda(InterfaceServicoVenda *) = 0;
        virtual ~InterfaceApresentacaoVenda() = default;
};

#endif // __INTEFACES_H__
