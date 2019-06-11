#ifndef __STUBS_H__
#define __STUBS_H__

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "servicos.h"
#include "controladores.h"

class StubControle : public InterfaceServicoControle{
    public:
        void Construir() override;
};

class StubUsuario : public InterfaceServicoUsuario{
    public:
};

class StubAutenticacao : public InterfaceServicoAutenticacao{
    public:
};

class StubEvento : public InterfaceServicoEvento{
    public:
};

class StubVenda : public InterfaceServicoVenda{
    public:
};

#endif
