#ifndef __AUXILIAR_H__
#define __AUXILIAR_H__

#include "dominios.h"
#include "entidades.h"

class Resultado{
    private:
        int valor_;
    public:
        const static int sucesso = 1;
        const static int falha = 0;
        inline void SetResultado(int valor){
            this->valor_ = valor;
        }
        inline int GetResultado() const {
            return valor_;
        }
};

class ResultadoAutenticar : public Resultado{
    private:
        inline void SetCpfResultado(const Cpf &cpf){
            this->cpf_ = cpf;
        }
        inline void SetSenhaResultado(const Senha &senha){
            this->senha_ = senha;
        }
        Cpf GetCpfResultado() const {
            return cpf_;
        }
        Senha GetSenhaResultado() const {
            return senha_;
        }
    public:
        Cpf cpf_;
        Senha senha_;
};

#endif
