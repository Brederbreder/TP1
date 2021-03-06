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

const string StubUsuario::trigger_erro_sistema_     = "000.000.000-00";
const string StubUsuario::trigger_cpf_invalido_     = "034.688.801-89";
const string StubUsuario::trigger_senha_invalida_   = "1Ee2Rr";
const string StubUsuario::trigger_numero_invalido_  = "4012001037141112";
const string StubUsuario::trigger_codigo_invalido_  = "201";
const string StubUsuario::trigger_data_invalida_    = "10/22";
const string StubUsuario::trigger_cpf_valido_       = "040.906.801-23";
const string StubUsuario::trigger_senha_valida_     = "1aA2bB";
const string StubUsuario::trigger_numero_valido_    = "5555666677778884";
const string StubUsuario::trigger_codigo_valido_    = "123";
const string StubUsuario::trigger_data_valida_      = "09/22";

const string StubVenda::trigger_erro_sistema_venda_  = "0000";
const string StubVenda::trigger_codigo_invalido_    = "4321";
const int StubVenda::trigger_quantidade_invalida_   = 20;
const string StubVenda::trigger_codigo_valido_      = "1234";
const int StubVenda::trigger_quantidade_valida_     = 10;

const string StubEvento::trigger_erro_sistema_codigo_           = "000";
const string StubEvento::trigger_erro_sistema_data_             = "19/08/20";
const string StubEvento::trigger_data_invalida_                 = "22/09/20";
const string StubEvento::trigger_horario_invalido_              = "10:00";
const string StubEvento::trigger_cidade_invalida_               = "jacarepagua";
const string StubEvento::trigger_estado_invalido_               = "MG";
const string StubEvento::trigger_data_valida_                   = "10/10/20";
const string StubEvento::trigger_horario_valido_                = "18:00";
const string StubEvento::trigger_cidade_valida_                 = "brazlandia";
const string StubEvento::trigger_estado_valido_                 = "DF";
const string StubEvento::trigger_codigo_evento_invalido_        = "321";
const string StubEvento::trigger_nome_invalido_                 = "show";
const string StubEvento::trigger_codigo_apresentacao_invalido_  = "4321";
const int StubEvento::trigger_preco_invalido_                   = 100;
const int StubEvento::trigger_numero_invalido_                  = 1;
const int StubEvento::trigger_classe_invalida_                  = 1;
const string StubEvento::trigger_faixa_invalida_                = "12";
const string StubEvento::trigger_codigo_evento_valido_          = "123";
const string StubEvento::trigger_nome_valido_                   = "festa";
const string StubEvento::trigger_codigo_apresentacao_valido_    = "1234";
const int StubEvento::trigger_preco_valido_                     = 200;
const int StubEvento::trigger_numero_valido_                    = 2;
const int StubEvento::trigger_classe_valida_                    = 2;
const string StubEvento::trigger_faixa_valida_                  = "16";

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

Resultado StubUsuario::CadastrarUsuario(Usuario &usuario, const Cpf &cpf, const Senha &senha,
                                        const NumeroCartaoDeCredito &numeroCartaoDeCredito,
                                        const CodigoDeSeguranca &codigoDeSeguranca,
                                        const DataDeValidade &dataDeValidade){
    Resultado resultado;
    cout << "\nCPF RECEBIDO NA STUB = " << cpf.GetCpf() << "\n";
    cout << "\nSENHA RECEBIDA NA STUB = " << senha.GetSenha() << "\n";
    cout << "\nNUMERO DE CARTAO DE CREDITO RECEBIDO NA STUB = " << numeroCartaoDeCredito.GetNumeroCartaoDeCredito() << "\n";
    cout << "\nCODIGO DE SEGURANCA RECEBIDO NA STUB = " << codigoDeSeguranca.GetCodigoDeSeguranca() << "\n";
    cout << "\nDATA DE VALIDADE RECEBIDA NA STUB = " << dataDeValidade.GetDataDeValidade() << "\n";

    if(cpf.GetCpf() == trigger_cpf_invalido_ || senha.GetSenha() == trigger_senha_invalida_ ||
       numeroCartaoDeCredito.GetNumeroCartaoDeCredito() == trigger_numero_invalido_ ||
       codigoDeSeguranca.GetCodigoDeSeguranca() == trigger_codigo_invalido_ ||
       dataDeValidade.GetDataDeValidade() == trigger_data_invalida_){
            resultado.SetResultado(ResultadoUsuario::falha);
       }else if(cpf.GetCpf() == trigger_erro_sistema_){
            resultado.SetResultado(ResultadoUsuario::falha);
            throw invalid_argument("Erro de Sistema!\n");
       }else{
            resultado.SetResultado(ResultadoUsuario::sucesso);
       }
    return resultado;
}

Resultado StubUsuario::DescadastrarUsuario(Usuario &usuario, const Cpf &cpf, const Senha &senha){
    Resultado resultado;
    cout << "\nCPF RECEBIDO NA STUB = " << cpf.GetCpf() << "\n";
    cout << "\nSENHA RECEBIDA NA STUB = " << senha.GetSenha() << "\n";

    if(cpf.GetCpf() == trigger_cpf_invalido_ || senha.GetSenha() == trigger_senha_invalida_){
        resultado.SetResultado(ResultadoUsuario::falha);
    }else if(cpf.GetCpf() == trigger_erro_sistema_){
        resultado.SetResultado(ResultadoUsuario::falha);
        throw invalid_argument("Erro de Sistema!\n");
    }else{
        resultado.SetResultado(ResultadoUsuario::sucesso);
    }
    return resultado;
}

Resultado StubVenda::Comprar(const CodigoDeApresentacao &codigo, const int quantidade){
    Resultado resultado;
    cout << "\nCODIGO DE APRESENTACAO RECEBIDO NA STUB = " << codigo.GetCodigoDeApresentacao() << "\n";
    cout << "\nQUANTIDADE RECEBIDA NA STUB = " << quantidade << "\n";

    if(codigo.GetCodigoDeApresentacao() == trigger_codigo_invalido_ || quantidade == trigger_quantidade_invalida_){
        resultado.SetResultado(ResultadoVenda::falha);
    }else if(codigo.GetCodigoDeApresentacao() == trigger_erro_sistema_venda_){
        resultado.SetResultado(ResultadoVenda::falha);
        throw invalid_argument("Erro de Sistema!\n");
    }else{
        resultado.SetResultado(ResultadoVenda::sucesso);
    }
    return resultado;
}

Resultado StubEvento::ProcurarEvento(const Data &data, const Horario &horario, const Cidade &cidade, const Estado &estado){
    Resultado resultado;
    cout << "\nDATA RECEBIDA NA STUB = " << data.GetData() << "\n";
    cout << "\nHORARIO RECEBIDO NA STUB = " << horario.GetHorario() << "\n";
    cout << "\nCIDADE RECEBIDA NA STUB = " << cidade.GetCidade() << "\n";
    cout << "\nESTADO RECEBIDO NA STUB = " << estado.GetEstado() << "\n";

    if(data.GetData() == trigger_data_invalida_ || horario.GetHorario() == trigger_horario_invalido_ ||
       cidade.GetCidade() == trigger_cidade_invalida_ || estado.GetEstado() == trigger_estado_invalido_){
        resultado.SetResultado(ResultadoEvento::falha);
    }else if(data.GetData() == trigger_erro_sistema_data_){
        resultado.SetResultado(ResultadoEvento::falha);
        throw invalid_argument("Erro de Sistema!\n");
    }else{
        resultado.SetResultado(ResultadoEvento::sucesso);
    }
    return resultado;
}

Resultado StubEvento::CadastrarEvento(const CodigoDeEvento &codigoDeEvento, const NomeDeEvento &nome,
                                      const CodigoDeApresentacao &codigoDeApresentacao, const Data &data,
                                      const Horario &horario, const Preco &preco, const NumeroDeSala &numero,
                                      const Cidade &cidade, const Estado &estado, const ClasseDeEvento &classe,
                                      const FaixaEtaria &faixa){
    Resultado resultado;

    cout << "\nCODIGO DE EVENTO RECEBIDO NA STUB = " << codigoDeEvento.GetCodigoDeEvento() << "\n";
    cout << "\nNOME RECEBIDO NA STUB = " << nome.GetNomeDeEvento() << "\n";
    cout << "\nCODIGO DE APRESENTACAO RECEBIDO NA STUB = " << codigoDeApresentacao.GetCodigoDeApresentacao() << "\n";
    cout << "\nDATA RECEBIDA NA STUB = " << data.GetData() << "\n";
    cout << "\nHORARIO RECEBIDO NA STUB = " << horario.GetHorario() << "\n";
    cout << "\nPRECO RECEBIDO NA STUB = " << preco.GetPreco() << "\n";
    cout << "\nNUMERO DE SALA RECEBIDO NA STUB = " << numero.GetNumeroDeSala() << "\n";
    cout << "\nCIDADE RECEBIDA NA STUB = " << cidade.GetCidade() << "\n";
    cout << "\nESTADO RECEBIDO NA STUB = " << estado.GetEstado() << "\n";
    cout << "\nCLASSE DE EVENTO RECEBIDA NA STUB = " << classe.GetClasseDeEvento() << "\n";
    cout << "\nFAIXA ETARIA RECEBIDA NA STUB = " << faixa.GetFaixaEtaria() << "\n";

    if(codigoDeEvento.GetCodigoDeEvento() == trigger_codigo_evento_invalido_ ||
       nome.GetNomeDeEvento() == trigger_nome_invalido_ ||
       codigoDeApresentacao.GetCodigoDeApresentacao() == trigger_codigo_apresentacao_invalido_ ||
       data.GetData() == trigger_data_invalida_ || horario.GetHorario() == trigger_horario_invalido_ ||
       preco.GetPreco() == trigger_preco_invalido_ || numero.GetNumeroDeSala() == trigger_numero_invalido_ ||
       cidade.GetCidade() == trigger_cidade_invalida_ || estado.GetEstado() == trigger_estado_invalido_ ||
       classe.GetClasseDeEvento() == trigger_classe_invalida_ || faixa.GetFaixaEtaria() == trigger_faixa_invalida_){
            resultado.SetResultado(ResultadoEvento::falha);
       }else if(codigoDeEvento.GetCodigoDeEvento() == trigger_erro_sistema_codigo_){
            resultado.SetResultado(ResultadoEvento::falha);
            throw invalid_argument("Erro de Sistema!\n");
       }else{
            resultado.SetResultado(ResultadoEvento::sucesso);
       }
       return resultado;
}

Resultado StubEvento::DescadastrarEvento(const CodigoDeEvento &codigoDeEvento){
    Resultado resultado;

    cout << "\nCODIGO DE EVENTO RECEBIDO NA STUB = " << codigoDeEvento.GetCodigoDeEvento() << "\n";

    if(codigoDeEvento.GetCodigoDeEvento() == trigger_codigo_evento_invalido_){
        resultado.SetResultado(ResultadoEvento::falha);
    }else if(codigoDeEvento.GetCodigoDeEvento() == trigger_erro_sistema_codigo_){
        resultado.SetResultado(ResultadoEvento::falha);
        throw invalid_argument("Erro de Sistema!\n");
    }else{
        resultado.SetResultado(ResultadoEvento::sucesso);
    }
    return resultado;
}

Resultado StubEvento::EditarEvento(const CodigoDeEvento &codigoDeEvento, const NomeDeEvento &nome,
                                   const Cidade &cidade, const Estado &estado, const ClasseDeEvento &classe,
                                   const FaixaEtaria &faixa){
    Resultado resultado;

    cout << "\nCODIGO DE EVENTO RECEBIDO NA STUB = " << codigoDeEvento.GetCodigoDeEvento() << "\n";
    cout << "\nNOME DE EVENTO RECEBIDO NA STUB = " << nome.GetNomeDeEvento() << "\n";
    cout << "\nCIDADE DO EVENTO RECEBIDO NA STUB = " << cidade.GetCidade() << "\n";
    cout << "\nESTADO DO EVENTO RECEBIDO NA STUB = " << estado.GetEstado() << "\n";
    cout << "\nCLASSE DE EVENTO RECEBIDA NA STUB = " << classe.GetClasseDeEvento() << "\n";
    cout << "\nFAIXA ETARIA RECEBIDA NA STUB = " << codigoDeEvento.GetCodigoDeEvento() << "\n";

    if(codigoDeEvento.GetCodigoDeEvento() == trigger_codigo_evento_invalido_ ||
       nome.GetNomeDeEvento() == trigger_nome_invalido_ || cidade.GetCidade() == trigger_cidade_invalida_ ||
       estado.GetEstado() == trigger_estado_invalido_ || classe.GetClasseDeEvento() == trigger_classe_invalida_ ||
       faixa.GetFaixaEtaria() == trigger_faixa_invalida_){
            resultado.SetResultado(ResultadoEvento::falha);
    }else if(codigoDeEvento.GetCodigoDeEvento() == trigger_erro_sistema_codigo_){
            resultado.SetResultado(ResultadoEvento::falha);
            throw invalid_argument("Erro de Sistema!\n");
    }else{
            resultado.SetResultado(ResultadoEvento::sucesso);
    }
    return resultado;
}
