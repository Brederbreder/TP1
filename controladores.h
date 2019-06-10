#ifndef __CONTROLADORES_H__
#define __CONTROLADORES_H__

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "servicos.h"

class CtrlApresentacaoControle : public InterfaceApresentacaoControle{
    private:
        InterfaceApresentacaoUsuario *ctrlAU;
        InterfaceApresentacaoAutenticacao *ctrlAA;
        InterfaceApresentacaoEvento *ctrlAE;
        InterfaceApresentacaoVenda *ctrlAV;

        enum Controle{
            nullc,
            pesquisarEvento,
            cadastrar,
            autenticar,
            sairc
        };

    public:
        void Inicializar();
        inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override {
            this->ctrlAU =iau;
        }
        inline void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
            this->ctrlAA = iaa;
        }
        inline void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *iae) override {
            this->ctrlAE = iae;
        }
        inline void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *iav) override {
            this->ctrlAV = iav;
        }
};

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao{
    private:
        InterfaceServicoAutenticacao *ctrlServicoAutenticacao;

    public:
        inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override {
            this->ctrlServicoAutenticacao = isa;
        }
};

class CtrlApresentacaoUsuario : public InterfaceApresentacaoUsuario{
    private:
        InterfaceServicoUsuario *ctrlServicoUsuario;

        enum{
            null,
            cadastrarUsuario,
            descadastrarUsuario,
            voltar
        };

    public:
        inline void SetCtrlServicoUsuario(InterfaceServicoUsuario *isu) override {
            this->ctrlServicoUsuario = isu;
        }
};

class CtrlApresentacaoEvento : public InterfaceApresentacaoEvento{
    private:
        InterfaceServicoEvento *ctrlServicoEvento;

        enum{
            null,
            cadastrarEvento,
            descadastrarEvento,
            voltar
        };

    public:
        inline void SetCtrlServicoEvento(InterfaceServicoEvento *ise) override {
            this->ctrlServicoEvento = ise;
        }
};

class CtrlApresentacaoVenda : public InterfaceApresentacaoVenda{
    private:
        InterfaceServicoVenda *ctrlServicoVenda;

        enum{
            null,
            comprar,
            voltar
        };

    public:
        inline void SetCtrlServicoVenda(InterfaceServicoVenda *isv) override {
            this->ctrlServicoVenda = isv;
        }
};

#endif
