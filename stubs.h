#ifndef __STUBS_H__
#define __STUBS_H__

#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include <iostream>
#include <string.h>

class StubControle :: public InterfaceApresentacaoControle{
    public:
        void Contruir() override;
};

class StubAutenticacao :: public InterfaceApresentacaoAutenticacao{
    public:
        const static string triggerFalha;
        const static string triggerSucesso;
        const static string triggerErro;
}

#endif