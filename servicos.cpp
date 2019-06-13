/*

#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "controladores.h"
#include "servicos.h"

void CtrlServicoControle::Construir(){

    InterfaceApresentacaoUsuario *ctrl_au;
    InterfaceApresentacaoAutenticacao *ctrl_aa;
    InterfaceApresentacaoEvento *ctrl_ae;
    InterfaceApresentacaoVenda *ctrl_av;

    ctrl_au = new CtrlApresentacaoUsuario();
    ctrl_aa = new CtrlApresentacaoAutenticacao();
    ctrl_ae = new CtrlApresentacaoEvento();
    ctrl_av = new CtrlApresentacaoVenda();

    InterfaceServicoUsuario *ctrl_su;
    InterfaceServicoAutenticacao *ctrl_sa;
    InterfaceServicoEvento *ctrl_se;
    InterfaceServicoVenda *ctrl_sv;

    ctrl_su = new CtrlServicoUsuario();
    ctrl_sa = new CtrlServicoAutenticacao();
    ctrl_se = new CtrlServicoEvento();
    ctrl_sv = new CtrlServicoVenda();

    ctrl_au->SetCtrlServicoUsuario(ctrl_su);
    ctrl_aa->SetCtrlServicoAutenticacao(ctrl_sa);
    ctrl_ae->SetCtrlServicoEvento(ctrl_se);
    ctrl_av->SetCtrlServicoVenda(ctrl_sv);

    InterfaceApresentacaoControle *ctrl_ac;

    ctrl_ac = new CtrlApresentacaoControle();

    ctrl_ac->SetCtrlApresentacaoUsuario(ctrl_au);
    ctrl_ac->SetCtrlApresentacaoAutenticacao(ctrl_aa);
    ctrl_ac->SetCtrlApresentacaoEvento(ctrl_ae);
    ctrl_ac->SetCtrlApresentacaoVenda(ctrl_av);

    ctrl_ac->Inicializar();

    delete ctrl_au;
    delete ctrl_aa;
    delete ctrl_ae;
    delete ctrl_av;
    delete ctrl_su;
    delete ctrl_sa;
    delete ctrl_se;
    delete ctrl_sv;
    delete ctrl_ac;
}

Resultado CtrlServicoAutenticacao::Autenticar(const Cpf &cpf, const Senha &senha){
    cout << "\nTESTE\n";
}
