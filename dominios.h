#ifndef __DOMINIOS_H__
#define __DOMINIOS_H__

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string.h>

using namespace std;

/**
 * @file dominios.h
 * @author Higor Santos
 * @author Matheus Breder
 * @date 28 de abril de 2019
 * @brief Classes de Dominio.
 * 
 * 
 * Classes com menor nível de abstração.
 * 
 */

/**
 * @brief Classe responsável pelo CodigoDeEvento
 * 
 *  Contem o formato XXX onde X é digito (0-9)
 * 
 */

class CodigoDeEvento{;
    private:
        string codigoDeEvento;
        const static int TAM_MAX_CODIGO = 3;
        const static int STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto codigo de evento da classe Codigo De Evento
         * 
         */

        void SetCodigoDeEvento(string);
        /**
         * @brief retorna o objeto CodigoDeEvento 
         *  
         * @return string Codigo valido.
         */

        string GetCodigoDeEvento() const{
            return codigoDeEvento;
        }
        /**
         * @brief Constroi o objeto CodigoDeEvento 
         * 
         * @param codigoDeEvento
         * 
         */

        explicit CodigoDeEvento(const string &codigoDeEvento) {
            SetCodigoDeEvento(codigoDeEvento);
        }
        /**
         * @brief Constroi um novo objeto CodigoDeEvento 
         * 
         */
        CodigoDeEvento() = default;

};


/**
 * @brief Classe responsavel pelo CodigoDeApresentacao
 * 
 * Contem o formato XXXX onde X é dígito (0-9)
 */
class CodigoDeApresentacao{
    private:
        string codigoDeApresentacao;
        const static int TAM_MAX_CODIGO = 4;
        const static int STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o codigo de apresentacao da classe Codigo De Apresentacao
         * 
         */
        void SetCodigoDeApresentacao(string);
        /**
         * @brief retorna o objeto codigo de apresentacao da classe Codigo De Apresentacao
         * 
         * @return string CodigoDeApresentacao
         */
        string GetCodigoDeApresentacao() const{
            return codigoDeApresentacao;
        }
        /**
         * @brief Constroi um novo objeto Codigo De Apresentacao
         *  
         * @param codigoDeApresentacao é o codigo responsavel
         */
        explicit CodigoDeApresentacao(const string &codigoDeApresentacao){
            SetCodigoDeApresentacao(codigoDeApresentacao);
        }
        CodigoDeApresentacao() = default;
};

/**
 * @brief Classe responsavel pelo CodigoDeIngresso
 * 
 * Contem o formato XXXXX onde X é digito (0-9)
 * 
 */
class CodigoDeIngresso{
    private:
        string codigoDeIngresso;
        const static int TAM_MAX_CODIGO = 5;
        const static int STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto codigo de ingresso da classe Codigo De Ingresso
         * 
         */
        void SetCodigoDeIngresso(string);
        /**
         * @brief retorna a string do Codigo De Ingresso 
         * 
         * @return string CodigoDeIngresso
         */
        string GetCodigoDeIngresso() const{
            return codigoDeIngresso;
        }
        /**
         * @brief Constroi um objeto novo Codigo De Ingresso
         * 
         * @param CodigoDeIngresso 
         */
        explicit CodigoDeIngresso(const string &codigoDeIngresso){
            SetCodigoDeIngresso(codigoDeIngresso);
        }
        CodigoDeIngresso() = default;
};

/**
 * @brief Classe responsavel pelo NomeDeEvento
 * 
 * Contem o formato XXXXXXXXXXXXXXXXXXXX onde cada X pode ser letra, digito ou espaço. Pelo menos um caracter e letra. Não podem existir espaços em sêquencia.
 * 
 */

class NomeDeEvento{
    private:
        string nomeDeEvento;
        const static int TAM_MAX_NOME = 20;
        const static int STRING_VAZIA = 0;
        void Validar(string);

    public:

        /**
         * @brief Seta o objeto nome de evento da classe Nome de Evento
         * 
         */
        void SetNomeDeEvento(string);
        /**
         * @brief Retorna o objeto nome do evento da classe Nome De Evento
         * 
         * @return string NomeDeEvento
         */
        string GetNomeDeEvento() const{
            return nomeDeEvento;
        }
        /**
         * @brief Constroi um novo objeto Nome De Evento
         * 
         * 
         * @param nomeDeEvento eh nome do evento
         */
        explicit NomeDeEvento(const string &nomeDeEvento){
            SetNomeDeEvento(nomeDeEvento);
        }
    
        NomeDeEvento() = default;
};

/**
 * @brief Classe responsavel pela Data
 * 
 * Contem o formato DD/MM/AA. DD eh numero de 1 a 31. MM eh numero de 1 a 12. AA eh numero de 00 a 99. O valor da data deve considerar a ocorrência de anos bissextos.
 */

class Data{
    private:
        string data;
        const static int DIA_MAX = 31, DIA_MIN = 1, MES_MAX = 12, MES_MIN = 1, ANO_MAX = 99, ANO_MIN = 0, DIA_MAX_FEVEREIRO = 28;
        const static int POS_BARRA_DIA = 2, POS_BARRA_MES = 5;
        const static int TAM_DATA_MAX = 8, STRING_VAZIA = 0;
        const static int JANEIRO = 1, FEVEREIRO = 2, MARCO = 3, ABRIL = 4, MAIO = 5, JUNHO = 6;
        const static int JULHO = 7, AGOSTO = 8, SETEMBRO = 9, OUTUBRO = 10, NOVEMBRO = 11, DEZEMBRO = 12;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto data da classe Data
         * 
         */
        void SetData(string);
        /**
         * @brief retorna a data do objeto da classe data
         * 
         * @return string data.
         */
        string GetData() const{
            return data;
        }
        /**
         * @brief Constroi um novo objeto Data
         * 
         * @param data Dia do evento
         */
        explicit Data(const string &data){
            SetData(data);
        }

        Data() = default;
};


/**
 * @brief Classe responsavel pelo Horario
 * 
 * Contem o formato HH:MM onde HH é o numero de 07 a 22, e MM eh 00, 15, 30 ou 45.
 * 
 */
class Horario{
    private:
        string horario;
        const static int HORA_MIN = 7, HORA_MAX = 22, MIN_0 = 0, MIN_15 = 15, MIN_30 = 30, MIN_45 = 45;
        const static int TAM_MAX = 5, STRING_VAZIA = 0;
        const static int POS_DOIS_PONTOS = 2;
        void Validar(string);

    public:
    /**
     * @brief Seta o objeto horario da classe Horario
     * 
     */
        void SetHorario(string);
        /**
         * @brief retorna o objeto horario da classe Horario
         * 
         * @return string horario.
         */
        string GetHorario() const{
            return horario;
        }
        /**
         * @brief Constroi um novo objeto horario
         * 
         * @param horario O horario do evento
         */
        explicit Horario(const string &horario){
            SetHorario(horario);
        }
        Horario() = default;
};

/**
 * @brief Classe responsavel pelo Preco
 * 
 * Contem o formato R$ 0,00 a R$ 1.000,00
 * 
 */
class Preco{
    private:
        float preco;
        constexpr static float PRECO_MAX = 1000;
        constexpr static float PRECO_MIN = 0;
        void Validar(float);

    public:
    /**
     * @brief Seta o objeto preco da classe Preco
     * 
     */
        void SetPreco(int);
        /**
         * @brief retorna o objeto preco da Classe Preco
         * 
         * @return float Dinheiro
         */
        float GetPreco() const{
            return preco;
        } 
        /**
         * @brief Constroi um novo objeto Preço
         * 
         * @param preco o valor do ingresso
         */
        explicit Preco(const float &preco){
            SetPreco(preco);
        }
        Preco() = default;
};

/**
 * @brief Classe responsavel pelo NumeroDeSala
 * 
 * Contem o formato X onde X é um valor de 1 a 10.
 * 
 */

class NumeroDeSala{
    private:
        int numeroDeSala;
        const static int NUM_MIN = 1, NUM_MAX = 10;
        void Validar(int);

    public:
        /**
         * @brief Seta o objeto numero de sala da classe Numero De Sala
         * 
         */
        void SetNumeroDeSala(int);
        /**
         * @brief retorna o objeto Numero De Sala da classe NumeroDeSala
         * 
         * @return int Sala
         */
        int GetNumeroDeSala() const{
            return numeroDeSala;
        }
        /**
         * @brief Constroi um novo objeto NumeroDeSala
         * 
         * @param numero o numero da sala
         */
        explicit NumeroDeSala(const int &numero){
            SetNumeroDeSala(numero);
        }
        NumeroDeSala() = default;
};
/**
 * @brief Classe responsavel pela Cidade
 *
 * Contem o formato XXXXXXXXXXXXXXX. Cada X pode ser letra, espaço ou ponto. Pelo menos um caracter eh letra. Nao ha espacos seguidos. Ponto eh precedido por letra.
 * 
 */

class Cidade{
    private:
        string cidade;
        const static int STRING_VAZIA = 0, TAM_MAX = 15;
        void Validar(string);

    public:
    /**
     * @brief Seta o objeto cidade da classe Cidade.
     * 
     */
        void SetCidade(string);
        /**
         * @brief retorna o objeto cidade da Classe Cidade
         * 
         * @return string O nome da cidade
         */
        string GetCidade() const{
            return cidade;
        }
        /**
         * @brief Constroi um novo objeto Cidade
         * 
         * @param cidade A cidade do evento
         */
        explicit Cidade(const string &cidade){
            SetCidade(cidade);
        }
        Cidade() = default;
};
/**
 * @brief Classe responsavel pelo Estado.
 * 
 * Tem como parametro as siglas correspondentes aos estados: AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE,
PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO
 * 
 * 
 * 
 */
class Estado{
    private:
        string estado;
        const static int TAM_MAX = 2, STRING_VAZIA = 0;
        string AC = "AC", AL = "AL", AP = "AP", AM = "AM", BA = "BA", CE = "CE", DF = "DF", ES = "ES";
        string GO = "GO", MA = "MA", MT = "MT", MS = "MS", MG = "MG", PA = "PA", PB = "PB", PR = "PR";
        string PE = "PE", PI = "PI", RJ = "RJ", RN = "RN", RS = "RS", RO = "RO", RR = "RR", SC = "SC";
        string SP = "SP", SE = "SE", TO = "TO";
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto estado da classe Estado
         * 
         */
        void SetEstado(string);
        
        /**
         * @brief retorna o objeto Estado da classe Estado
         * 
         * @return string Sigla do estado correspondente
         */

        string GetEstado() const{
            return estado;
        }

        /**
         * @brief Constroi um novo objeto Estado
         * 
         * @param estado A sigla do estado
         */

        explicit Estado(const string &estado){
            SetEstado(estado);
        }
        Estado() = default;
};

/**
 * @brief Classe responsavel pela disponibilidade
 * 
 * Trabalha com valores de 0 a 250. 
 *
 */
class Disponibilidade{
    private:
        int disponibilidade;
        const static int NUM_MAX = 250, NUM_MIN = 0;
        void Validar(int);

    public:
        /**
         * @brief Seta o objeto disponibilidade da classe Disponibilidade
         * 
         */
        void SetDisponibilidade(int);
        /**
         * @brief retorna o objeto disponibilidade da classe Disponibilidade
         * 
         * @return int a quantidade disponivel.
         */

        int GetDisponibilidade() const{
            return disponibilidade;
        }
        /**
         * @brief Constroi um novo objeto Disponibilidade
         * 
         * @param disponibilidade A quantidade disponivel
         */
        explicit Disponibilidade(const int &disponibilidade){
            SetDisponibilidade(disponibilidade);
        }
        Disponibilidade() = default;
};

/**
 * @brief Classe de Evento
 * 
 * Contem o formato X onde X é dígito de 1 a 4. O dígito 1 identifica TEATRO, 2 identifica ESPORTE, 3 identifica SHOW NACIONAL e 4 identifica SHOW
INTERNACIONAL.
 * 
 */
class ClasseDeEvento{
    private:
        int classeDeEvento;
        const static int NUM_MAX = 4, NUM_MIN = 1;
        void Validar(int);

    public:
        /**
         * @brief Seta o objeto classe de evento da Classe classe De Evento
         * 
         */
        void SetClasseDeEvento(int);
        /**
         * @brief retorna o objeto Classe De Evento
         * 
         * @return int Numero indicando a qual classe pertence o evento
         */
        int GetClasseDeEvento() const{
            return classeDeEvento;
        }
        /**
         * @brief Constroi um novo objeto da Classe De Evento 
         * 
         * @param classe Classe escolhida
         */
        explicit ClasseDeEvento(const int &classe){
            SetClasseDeEvento(classe);
        }
        ClasseDeEvento() = default;
};
 /**
  * @brief Classe responsavel pela Classificacao Indicativa baseado na faixa etaria.
  * 
  * Contem o formato L, 10, 12, 14, 16 ou 18
  * 
  */
class FaixaEtaria{
    private:
        string faixaEtaria;
        const static int TAM_MAX = 2, STRING_VAZIA = 0;
        string DEZ = "10", DOZE = "12", CATORZE = "14", DEZESSEIS = "16", DEZOITO = "18", LIVRE = "L";
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto faixa etaria da classe Faixa Etaria
         * 
         */
        void SetFaixaEtaria(string);
        /**
         * @brief retorna o objeto Faixa Etaria da classe FaixaEtaria
         * 
         * @return string Que indica a classificaçao indicativa
         */
        string GetFaixaEtaria() const{
            return faixaEtaria;
        }
        /**
         * @brief Constroi um novo objeto Faixa Etaria
         * 
         * @param idade Classificacao
         */
        explicit FaixaEtaria(const string &idade){
            SetFaixaEtaria(idade);
        }
        FaixaEtaria() = default;
};

/**
 * @brief Classe responsavel pelo CPF- Cadastro de Pessoas Fisicas
 * 
 * Contem o formato XXX.XXX.XXX-XX onde X é dígito (0 – 9). O número de CPF
deve incluir dígitos verificadores calculados por meio de algorítmo
apropriado.
 * 
 */
class Cpf{
    private:
        string cpf;
        const static int POS_PONTO_UM = 3, POS_PONTO_DOIS = 7, POS_TRACO = 11;
        const static int TAM_MAX = 14, STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto cpf da classe Cpf
         * 
         */
        void SetCpf(string);
        /**
         * @brief retorna o objeto Cpf da classe CPF
         * 
         * @return string Cpf validado
         */
        string GetCpf() const{
            return cpf;
        }
        /**
         * @brief Constroi um novo objeto Cpf
         * 
         * @param cpf o numero correspondente ao cpf do usuario
         */
        explicit Cpf(const string &cpf){
            SetCpf(cpf);
        }
        Cpf() = default;
};

/**
 * @brief Classe responsavel pela senha
 * 
 * Contem o formato XXXXXX onde X pode ser letra (A – Z a – z) ou dígito (0 a 9). Não
há caracters repetidos. Há pelo menos uma letra maiúscula, uma minúscula e
um dígito.
 * 
 */
class Senha{
    private:
        string senha;
        const static int TAM_MAX = 6, STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto senha da classe Senha
         * 
         */
        void SetSenha(string);
        /**
         * @brief retorna o objeto Senha da classe Senha
         * 
         * @return string senha correspondente ao cadastro
         */
        string GetSenha() const{
            return senha;
        }
        /**
         * @brief Constroi um novo objeto Senha
         * 
         * @param senha senha a ser cadastrada
         */
        explicit Senha(const string &senha){
            SetSenha(senha);
        }
        Senha() = default;
};
 /**
  * @brief Classe responsavel pelo codigo de seguranca do cartao de credito
  * 
  * Contem o formato XXX onde X é dígito (0 a 9).
  */
class CodigoDeSeguranca{
    private:
        string codigoDeSeguranca;
        const static int TAM_MAX = 3, STRING_VAZIA = 0;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto codigo de seguranca da classe Codigo De Seguranca
         * 
         */
        void SetCodigoDeSeguranca(string);
        /**
         * @brief retorna o objeto Codigo De Seguranca da classe CodigoDeSeguranca 
         * 
         * @return string codigo de seguranca
         */
        string GetCodigoDeSeguranca() const{
            return codigoDeSeguranca;
        } 
        /**
         * @brief Constroi um novo objeto Codigo De Seguranca
         * 
         * @param codigo codigo inserido
         */
        explicit CodigoDeSeguranca(const string &codigo){
            SetCodigoDeSeguranca(codigo);
        }
        CodigoDeSeguranca() = default;
};

/**
 * @brief Classe responsavel pela DataDeValidade 
 * 
 * Contem o formato XX/YY onde XX é número de 01 a 12 e YY é número de 00 a 99.
 * 
 */
class DataDeValidade{
    private:
        string dataDeValidade;
        const static int TAM_MAX = 5, STRING_VAZIA = 0, POS_BARRA = 2, MES_MIN = 0, MES_MAX = 12, ANO_MIN = 0, ANO_MAX = 99;
        void Validar(string);

    public:
        /**
         * @brief Seta o objeto data de validade da classe Data De Validade
         * 
         */
        void SetDataDeValidade(string);
        /**
         * @brief retorna o objeto Data De Validade da classe DataDeValidade
         * 
         * @return string que eh a data de validade
         */
        string GetDataDeValidade() const{
            return dataDeValidade;
        }
        /**
         * @brief Constroi um novo objeto Data De Validade 
         * 
         * @param data data limite
         */
        explicit DataDeValidade(const string &data){
            SetDataDeValidade(data);
        }
        DataDeValidade() = default;
};

/**
 * @brief Classe responsavel pelo Numero do Cartao de Credito
 * 
 * Contem o formato XXXXXXXXXXXXXXXX onde X é dígito (0 – 9). Número válido
segundo o algoritmo de Luhn.
 * 
 */
class NumeroCartaoDeCredito {
    private:
        string cartaoDeCredito;
        const static int TAM_MAX = 16, STRING_VAZIA = 0;
        void Validar(string);
    public:
        /**
         * @brief Seta o objeto cartao de credito da classe Numero Cartao De Credito
         * 
         */
        void SetNumeroCartaoDeCredito(string);
        /**
         * @brief retorna o objeto Numero Cartao De Credito da classe NumeroCartaoDeCredito
         * 
         * @return string numero validado do cartao
         */
        string GetNumeroCartaoDeCredito() const {
            return this->cartaoDeCredito;
        }
        /**
         * @brief Constroi um novo objeto Numero Cartao De Credito
         * 
         * @param numero numero do cartao
         */
        explicit NumeroCartaoDeCredito(const string &numero){
            SetNumeroCartaoDeCredito(numero);
        }
        NumeroCartaoDeCredito() = default;
};
#endif // __DOMINIOS_H__
