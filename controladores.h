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

        enum ControleLogado{
            nullcl,
            comprar,
            cadastrarEvento,
            descadastrarEvento,
            descadastrarUsuario,
            saircl
        };

    public:
        void Inicilizar();
        void ControleLogado(const Cpf &) override;
        inline void SetCtrlApresentacaoUsuario(InterfaceApresentacaoUsuario *iau) override{
            this->ctrlAU = iau;
        }
        inline void SetCtrlApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao *iaa) override{
            this->ctrlAA = iaa;
        }
        inline void SetCtrlApresentacaoEvento(InterfaceApresentacaoEvento *iae) override{
            this->ctrlAE = iae;
        }
        inline void SetCtrlApresentacaoVenda(InterfaceApresentacaoVenda *iav) override{
            this->ctrlAV = iav;
        }
};

class CtrlApresentacaoAutenticacao : public InterfaceApresentacaoAutenticacao{
    private:
        InterfaceServicoAutenticacao *ctrlServicoAutenticacao;

    public:
        bool Autenticar() override;
        inline void SetCtrlServicoAutenticacao(InterfaceServicoAutenticacao *isa) override{
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
        bool Cadastrar(const string cpf, const string senha, const string numeroCartaoDeCredito,
                       const string codigoDeSeguranca, const string dataDeValidade);
        bool Descadastrar(const string cpf, const string senha );
        inline void SetCtrlServicoUsuario(InterfaceServicoUsuario *isu){
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
        bool ProcurarEvento(const string horarioInicio, const string horarioTermino, const string cidade,
                            const string estado);
        bool CadastrarEvento(const CodigoDeEvento &, const NomeDeEvento &, const CodigoDeApresentacao &,
                             const Data &, const Horario &, const Preco &, const NumeroDeSala &,
                             const Cidade &, const Estado &, const ClasseDeEvento &, const FaixaEtaria &);
        bool DescadastrarEvento(const CodigoDeEvento &);
        void Executar(const Cpf &);
        inline void SetCtrlServicoEvento(InterfaceServicoEvento *ise) override{
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
        void Executar(const Cpf &);
        inline void SetCtrlServicoVenda(InterfaceServicoVenda *isv){
            this->ctrlServicoVenda = isv;
        }
};

#endif
