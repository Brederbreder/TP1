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
};

class StubVenda : public InterfaceServicoVenda{
    public:
};

#endif
