#ifndef __CONTROLADORES_H__
#define __CONTROLADORES_H__

#include "interfaces.h"

class CtrlApresentacaoControle : public InterfaceApresentacaoControle{
    private:
        InterfaceApresentacaoUsuario *ctrl_au;
        InterfaceApresentacaoAutenticacao *ctrl_aa;
        InterfaceApresentacaoEvento *ctrl_ae;
        InterfaceApresentacaoVenda *ctrl_av;

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
            this->ctrl_au =iau;
        }
        inline void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override {
            this->ctrl_aa = iaa;
        }
        inline void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *iae) override {
            this->ctrl_ae = iae;
        }
        inline void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *iav) override {
            this->ctrl_av = iav;
        }
};

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao{
    private:
        InterfaceServicoAutenticacao *ctrlServicoAutenticacao;

    public:
        ResultadoAutenticar Autenticar() override;
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
