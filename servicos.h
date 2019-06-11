#ifndef __SERVICOS_H__
#define __SERVICOS_H__

#include "interfaces.h"

class CtrlServicoControle : public InterfaceServicoControle{
    public:
        void Construir();
};

class CtrlServicoAutenticacao : public InterfaceServicoAutenticacao{
    public:
        Resultado Autenticar(const Cpf &, const Senha &) override;
};

class CtrlServicoUsuario : public InterfaceServicoUsuario{
    public:
};

class CtrlServicoEvento : public InterfaceServicoEvento{
    public:
};

class CtrlServicoVenda : public InterfaceServicoVenda{
    public:
};


#endif // __SERVICOS_H__
