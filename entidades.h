#ifndef __ENTIDADES_H__
#define __ENTIDADES_H__

#include "dominios.h"

using namespace std;

/**
 * @file entidades.h
 * @author Matheus Breder Branquinho Nogueira
 * @author Higor Gabriel
 * @date 29 de Abril de 2019
 *
 * @brief Descrição de todas as classes de Entidades.
 *
 * Neste arquivo estão listadas as classes de Entidade, ou seja, as classes que armazenarão os dados dos usuários, dos eventos e dos ingressos.
 * */

/**
 * @brief classe responsável por armazenar o CPF e a senha de um usuario.
 */

class Usuario{
    private:
        Cpf cpf;
        Senha senha;

    public:

        /**
         * @brief Constrói um novo objeto da classe Usuario.
         *
         * @param cpf é o cpf do usuário.
         * @param senha é a senha do usuário.
         */        

        Usuario(Cpf &cpf, Senha &senha){
            SetCpf(cpf);
            SetSenha(senha);
        }

        Usuario() = default;

        /**
         * @brief Seta o objeto Cpf do Usuario.
         *
         * @param cpf é o cpf do usuário.
         */

        void SetCpf(const Cpf &cpf){
            this->cpf = cpf;
        }

        /**
         * @brief Seta o objeto Senha do Usuario.
         *
         * @param senha é a senha do usuário.
         */

        void SetSenha(const Senha &senha){
            this->senha = senha;
        }

        /**
         *@brief Retorna o Cpf do objeto da classe Usuario.
         * 
         *@return cpf retorna um objeto da classe.
         */

        Cpf GetCpf() const{
            return cpf;
        }

        /**
         *@brief Retorna a Senha do objeto da classe Usuario.
         * 
         *@return senha retorna um objeto da classe.
         */

        Senha GetSenha() const{
            return senha;
        }
};

/**
 * @brief classe responsável por armazenar os dados de um evento, ou seja, o código de evento, nome de evento, cidade, estado, classe de evento e a faixa etária.
 */

class Evento{
    private:
        CodigoDeEvento codigoDeEvento;
        NomeDeEvento nomeDeEvento;
        Cidade cidade;
        Estado estado;
        ClasseDeEvento classeDeEvento;
        FaixaEtaria faixaEtaria;

    public:

        /**
         * @brief Constrói um novo objeto da classe Evento.
         *
         * @param codigo é o código de evento.
         * @param nome é o nome de evento.
         * @param cidade é a cidade onde será realizado o evento.
         * @param estado é o estado onde será realizado o evento.
         * @param classe é a classe do evento, ou seja, o tipo de evento.
         * @param idade é a faixa etária do evento.
         */   

        Evento(CodigoDeEvento &codigo, NomeDeEvento &nome, Cidade &cidade, Estado &estado, ClasseDeEvento &classe, FaixaEtaria &idade){
            SetCodigoDeEvento(codigo);
            SetNomeDeEvento(nome);
            SetCidade(cidade);
            SetEstado(estado);
            SetClasseDeEvento(classe);
            SetFaixaEtaria(idade);
        }

        Evento() = default;

        /**
        * @brief Seta o objeto CodigoDeEvento do Evento.
        *
        * @param codigoDeEvento é o codigo relacionado ao evento.
        */

        void SetCodigoDeEvento(const CodigoDeEvento &codigoDeEvento){
            this->codigoDeEvento = codigoDeEvento;
        }

        /**
        * @brief Seta o objeto Nome de Evento do Evento.
        *
        * @param nomeDeEvento é o nome do evento.
        */

        void SetNomeDeEvento(const NomeDeEvento &nomeDeEvento){
            this->nomeDeEvento = nomeDeEvento;
        }

        /**
        * @brief Seta o objeto Cidade do Evento.
        *
        * @param cidade é a cidade onde o evento será realizado.
        */

        void SetCidade(const Cidade &cidade){
            this->cidade = cidade;
        }

        /**
        * @brief Seta o objeto Estado do Evento.
        *
        * @param estado é o estado onde o evento será realizado.
        */

        void SetEstado(const Estado &estado){
            this->estado = estado;
        }

        /**
        * @brief Seta o objeto ClasseDeEvento do Evento.
        *
        * @param classeDeEvento é a classe do evento.
        */

        void SetClasseDeEvento(const ClasseDeEvento &classeDeEvento){
            this->classeDeEvento = classeDeEvento;
        }

        /**
        * @brief Seta o objeto FaixaEtaria do Evento.
        *
        * @param faixaEtaria é a faixa etária do evento.
        */

        void SetFaixaEtaria(const FaixaEtaria &faixaEtaria){
            this->faixaEtaria = faixaEtaria;
        }

        /**
         *@brief Retorna o CodigoDeEvento do objeto da classe Evento
         * 
         *@return codigoDeEvento retorna um objeto da classe.
         */        

        CodigoDeEvento GetCodigoDeEvento() const{
            return codigoDeEvento;
        }

        /**
         *@brief Retorna o NomeDeEvento do objeto da classe Evento.
         * 
         *@return codigoDeEvento retorna um objeto da classe.
         */

        NomeDeEvento GetNomeDeEvento() const{
            return nomeDeEvento;
        }

        /**
         *@brief Retorna a Cidade do objeto da classe Evento.
         * 
         *@return cidade retorna um objeto da classe.
         */

        Cidade GetCidade() const{
            return cidade;
        }

        /**
         *@brief Retorna o Estado do objeto da classe Evento.
         * 
         *@return estado retorna um objeto da classe.
         */

        Estado GetEstado() const{
            return estado;
        }

        /**
         *@brief Retorna a ClasseDeEvento do objeto da classe Evento.
         * 
         *@return classeDeEvento retorna um objeto da classe.
         */

        ClasseDeEvento GetClasseDeEvento() const{
            return classeDeEvento;
        }

        /**
         *@brief Retorna a FaixaEtaria do objeto da classe Evento.
         * 
         *@return faixaEtaria retorna um objeto da classe.
         */

        FaixaEtaria GetFaixaEtaria() const{
            return faixaEtaria;
        }
};

/**
 * @brief classe responsável por armazenar os dados de uma Apresentação, ou seja, seu código de apresentação, data, horário, preço, número de sala e disponibilidade.
 */

class Apresentacao{
    private:
        CodigoDeApresentacao codigoDeApresentacao;
        Data data;
        Horario horario;
        Preco preco;
        NumeroDeSala numeroDeSala;
        Disponibilidade disponibilidade;

    public:

        /**
         * @brief Constrói um novo objeto da classe Apresentacao.
         *
         * @param codigo é o código de apresentação.
         * @param data é a data da apresentação.
         * @param horario é o horário da apresentação.
         * @param preco é preço do ingresso da apresentação.
         * @param numero é o número da sala onde será realizada a apresentação.
         * @param disponibilidade é disponibilidade da apresentação.
         */ 

        Apresentacao(CodigoDeApresentacao &codigo, Data &data, Horario &horario, Preco &preco, NumeroDeSala &numero, Disponibilidade &disponibilidade){
            SetCodigoDeApresentacao(codigo);
            SetData(data);
            SetHorario(horario);
            SetPreco(preco);
            SetNumeroDeSala(numero);
            SetDisponibilidade(disponibilidade);
        }

        Apresentacao() = default;

        /**
        * @brief Seta o objeto CodigoDeApresentacao da Apresentacao.
        *
        * @param codigoDeApresentacao é o código de apresentação da apresentação.
        */

        void SetCodigoDeApresentacao(const CodigoDeApresentacao &codigoDeApresentacao){
            this->codigoDeApresentacao = codigoDeApresentacao;
        }

        /**
        * @brief Seta o objeto Data da Apresentacao.
        *
        * @param data é a data da apresentação.
        */

        void SetData(const Data &data){
            this->data = data;
        }

        /**
        * @brief Seta o objeto Horario da Apresentacao.
        *
        * @param horario é o horario da apresentação.
        */

        void SetHorario(const Horario &horario){
            this->horario = horario;
        }

        /**
        * @brief Seta o objeto Preco da Apresentacao.
        *
        * @param preco é o preço do ingresso da apresentação.
        */

        void SetPreco(const Preco &preco){
            this->preco = preco;
        }

        /**
        * @brief Seta o objeto NumeroDeSala da Apresentação.
        *
        * @param numeroDeSala é o número da sala onde será realizada a apresentação.
        */

        void SetNumeroDeSala(const NumeroDeSala &numeroDeSala){
            this->numeroDeSala = numeroDeSala;
        }

        /**
        * @brief Seta o objeto Disponibilidade do Apresentação.
        *
        * @param disponibilidade é a disponibilidade da apresentação.
        */

        void SetDisponibilidade(const Disponibilidade &disponibilidade){
            this->disponibilidade = disponibilidade;
        }

        /**
         *@brief Retorna o CodigoDeApresentacao do objeto da classe Apresentacao.
         * 
         *@return codigoDeApresentacao retorna um objeto da classe.
         */

        CodigoDeApresentacao GetCodigoDeApresentacao() const{
            return codigoDeApresentacao;
        }

        /**
         *@brief Retorna a Data do objeto da classe Apresentacao.
         * 
         *@return data retorna um objeto da classe.
         */

        Data GetData() const{
            return data;
        }

        /**
         *@brief Retorna o Horario do objeto da classe Apresentacao.
         * 
         *@return horario retorna um objeto da classe.
         */

        Horario GetHorario() const{
            return horario;
        }

        /**
         *@brief Retorna o Preco do objeto da classe Apresentacao.
         * 
         *@return preco retorna um objeto da classe.
         */

        Preco GetPreco() const{
            return preco;
        }

        /**
         *@brief Retorna o NumeroDeSala do objeto da classe Apresentacao.
         * 
         *@return numeroDeSala retorna um objeto da classe.
         */

        NumeroDeSala GetNumeroDeSala() const{
            return numeroDeSala;
        }

        /**
         *@brief Retorna a Disponibilidade do objeto da classe Apresentacao.
         * 
         *@return disponibilidade retorna um objeto da classe.
         */

        Disponibilidade GetDisponibilidade() const{
            return disponibilidade;
        }
};

/**
 * @brief classe responsável por armazenar os dados do Ingresso, que é apenas o código de ingresso.
 */

class Ingresso{
    private:
        CodigoDeIngresso codigoDeIngresso;

    public:

        /**
         * @brief Constrói um novo objeto da classe Ingresso
         *
         * @param codigo é o código de ingresso.
         */

        Ingresso(CodigoDeIngresso &codigo){
            SetCodigoDeIngresso(codigo);
        }

        Ingresso() = default;

        /**
        * @brief Seta o objeto CodigoDeIngresso do Ingresso.
        *
        * @param codigoDeIngresso é o código de ingresso do ingresso.
        */

        void SetCodigoDeIngresso(const CodigoDeIngresso &codigoDeIngresso){
            this->codigoDeIngresso = codigoDeIngresso;
        }

        /**
         *@brief Retorna o CodigoDeIngresso do objeto da classe Ingresso.
         * 
         *@return codigoDeIngresso retorna um objeto da classe.
         */

        CodigoDeIngresso GetCodigoDeIngresso() const{
            return codigoDeIngresso;
        }
};

class CartaoDeCredito{
    private:
        NumeroCartaoDeCredito cartaoDeCredito;
        CodigoDeSeguranca codigoDeSeguranca;
        DataDeValidade dataDeValidade;

    public:

        /**
         * @brief Constrói um novo objeto da classe CartaoDeCredito.
         *
         * @param cartaoDeCredito é o número do cartão de crédito.
         * @param codigoDeSeguranca é o código de segurança do cartão de cŕedito.
         * @param dataDeValidade é a data de validade do cartão de cŕedito.
         */
        
        CartaoDeCredito(NumeroCartaoDeCredito &cartaoDeCredito, CodigoDeSeguranca &codigoDeSeguranca, DataDeValidade &dataDeValidade){
            SetNumeroCartaoDeCredito(cartaoDeCredito);
            SetCodigoDeSeguranca(codigoDeSeguranca);
            SetDataDeValidade(dataDeValidade);
        }

        CartaoDeCredito() = default;

        /**
        * @brief Seta o objeto NumeroCartaoDeCredito do CartaoDeCredito.
        *
        * @param cartaoDeCredito é o número do cartão de cŕedito.
        */

        void SetNumeroCartaoDeCredito(const NumeroCartaoDeCredito &cartaoDeCredito){
            this->cartaoDeCredito = cartaoDeCredito;
        }

        /**
        * @brief Seta o objeto CodigoDeSeguranca do CartaoDeCredito.
        *
        * @param codigoDeSeguranca é o codigo de segurança do cartão de cŕedito.
        */

        void SetCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca){
            this->codigoDeSeguranca = codigoDeSeguranca;
        }

        /**
        * @brief Seta o objeto DataDeValidade do CartaoDeCredito.
        *
        * @param dataDeValidade é a data de validade do cartão de cŕedito.
        */

        void SetDataDeValidade(const DataDeValidade &dataDeValidade){
            this->dataDeValidade = dataDeValidade;
        }

        /**
         *@brief Retorna o NumeroCartaoDeCredito do objeto da classe CartaoDeCredito.
         * 
         *@return cartaoDeCredito retorna um objeto da classe.
         */

        NumeroCartaoDeCredito GetNumeroCartaoDeCredito() const{
            return cartaoDeCredito;
        }

        /**
         *@brief Retorna o CodigoDeSeguranca do objeto da classe CartaoDeCredito.
         * 
         *@return cartaoDeCredito retorna um objeto da classe.
         */

        CodigoDeSeguranca GetCodigoDeSeguranca() const{
            return codigoDeSeguranca;
        }

        /**
         *@brief Retorna a DataDeValidade do objeto da classe CartaoDeCredito.
         * 
         *@return dataDeValidade retorna um objeto da classe.
         */

        DataDeValidade GetDataDeValidade() const{
            return dataDeValidade;
        }
};

#endif // __ENTIDADES_H__
