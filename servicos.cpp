#include "interfaces.h"
#include "dominios.h"
#include "entidades.h"
#include "controladores.h"
#include "servicos.h"

void CtrlServicoControle::Construir(){

    InterfaceApresentacaoAutenticacao *ctrl_aa;
    InterfaceApresentacaoUsuario *ctrl_au;
    InterfaceApresentacaoEvento *ctrl_ae;
    InterfaceApresentacaoVenda *ctrl_av;

    ctrl_aa = new CtrlApresentacaoAutenticacao();
    ctrl_au = new CtrlApresentacaoUsuario();
    ctrl_ae = new CtrlApresentacaoEvento();
    ctrl_av = new CtrlApresentacaoVenda();

    InterfaceServicoAutenticacao *ctrl_sa;
    InterfaceServicoUsuario *ctrl_su;
    InterfaceServicoEvento *ctrl_se;
    InterfaceServicoVenda *ctrl_sv;

    ctrl_sa = new CtrlServicoAutenticacao();
    ctrl_su = new CtrlServicoUsuario();
    ctrl_se = new CtrlServicoEvento();
    ctrl_sv = new CtrlServicoVenda();

    InterfaceApresentacaoControle *ctrl_ac;

    ctrl_ac = new CtrlApresentacaoControle();

    ctrl_ac->SetCtrlApresentacaoAutenticacao(ctrl_aa);
    ctrl_ac->SetCtrlApresentacaoEvento(ctrl_ae);
    ctrl_ac->SetCtrlApresentacaoUsuario(ctrl_au);
    ctrl_ac->SetCtrlApresentacaoVenda(ctrl_av);

    ctrl_ac->Inicializar();

    delete ctrl_aa;
    delete ctrl_au;
    delete ctrl_ae;
    delete ctrl_av;
    delete ctrl_sa;
    delete ctrl_su;
    delete ctrl_se;
    delete ctrl_sv;
    delete ctrl_ac;
}
