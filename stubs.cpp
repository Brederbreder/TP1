#include "stubs.h"
#include "auxiliar.h"
#include "dominios.h"
#include "entidades.h"
#include "controladores.h"
#include "servicos.h"

const string StubAutenticacao::trigger_erro_sistema_    = "000.000.000-00";
const string StubAutenticacao::trigger_cpf_invalido_    = "034.688.801-89";
const string StubAutenticacao::trigger_senha_invalida_  = "1Ee2Rr";
const string StubAutenticacao::trigger_cpf_valido_      = "040.906.801-23";
const string StubAutenticacao::trigger_senha_valida_    = "1aA2bB";

void StubControle::Construir(){

    InterfaceApresentacaoUsuario *ctrl_au;
    InterfaceApresentacaoAutenticacao *ctrl_aa;
    InterfaceApresentacaoEvento *ctrl_ae;
    InterfaceApresentacaoVenda *ctrl_av;

    ctrl_au = new CtrlApresentacaoUsuario();
    ctrl_aa = new CtrlApresentacaoAutenticacao();
    ctrl_ae = new CtrlApresentacaoEvento();
    ctrl_av = new CtrlApresentacaoVenda();

    InterfaceServicoUsuario *stub_u;
    InterfaceServicoAutenticacao *stub_a;
    InterfaceServicoEvento *stub_e;
    InterfaceServicoVenda *stub_v;

    stub_u = new StubUsuario();
    stub_a = new StubAutenticacao();
    stub_e = new StubEvento();
    stub_v = new StubVenda();

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

Resultado StubAutenticacao::Autenticar(const Cpf &cpf, const Senha &senha){
    ResultadoAutenticar resultado;

    cout << "\nCPF RECEBIDO NA STUB = " << cpf.GetCpf() << "\n";
    cout << "SENHA RECEBIDA NA STUB = " << senha.GetSenha() << "\n";

    if(cpf.GetCpf() == trigger_cpf_invalido_ || senha.GetSenha() == trigger_senha_invalida_){
        resultado.SetResultado(ResultadoAutenticar::falha);
    }else if(cpf.GetCpf() == trigger_erro_sistema_){
        resultado.SetResultado(ResultadoAutenticar::falha);
        throw invalid_argument("Erro de Sistema!\n");
    }else{
        resultado.SetResultado(ResultadoAutenticar::sucesso);
    }
    return resultado;
}
