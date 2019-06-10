#ifndef __SERVICOS_H__
#define __SERVICOS_H__

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "controladores.h"

class CtrlServicoControle : public InterfaceServicoControle{
    public:
        void Construir();
};

class CtrlServicoAutenticacao : public InterfaceServicoAutenticacao{
    public:
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
