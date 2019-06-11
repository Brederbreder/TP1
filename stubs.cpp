#include "stubs.h"

void StubControle::Construir(){

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

    ctrl_su = new StubUsuario();
    ctrl_sa = new StubAutenticacao();
    ctrl_se = new StubEvento();
    ctrl_sv = new StubVenda();

    ctrl_au->SetCtrlServicoUsuario(stub_u);
    ctrl_aa->SetCtrlServicoAutenticacao(stub_a);
    ctrl_ae->SetCtrlServicoEvento(stub_e);
    ctrl_av->SetCtrlServicoVenda(stub_v);

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
    delete stub_u;
    delete stub_a;
    delete stub_e;
    delete stub_v;
    delete ctrl_ac;
}
