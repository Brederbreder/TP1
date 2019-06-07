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
        bool Autenticar(const Cpf &, const Senha &);
};

class CtrlServicoUsuario : public InterfaceServicoUsuario{
    public:
        bool CadastrarUsuario(const string cpf, const string senha, const string numeroCartaoDeCredito,
                              const string codigoDeSeguranca, const string dataDeValidade);
        bool DescadastrarUsuario(const string cpf, const string senha);
};

class CtrlServicoEvento : public InterfaceServicoEvento{
    public:
        bool ProcurarEventos(const string horarioInicio, const string horarioTermino, const string cidade,
                             const string estado);
        bool CadastrarEvento(const CodigoDeEvento &, const NomeDeEvento &, const CodigoDeApresentacao &,
                             const Data &, const Horario &, const Preco &, const NumeroDeSala &,
                             const Cidade &, const Estado &, const ClasseDeEvento &, const FaixaEtaria &);
        bool DescadastrarEvento(const CodigoDeEvento &);

};

class CtrlServicoVenda : public InterfaceServicoVenda{
    public:
        bool Comprar(const CodigoDeApresentacao &, const int quantidade);
};


#endif // __SERVICOS_H__
