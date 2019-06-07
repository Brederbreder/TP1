#ifndef __AUXILIAR_H__
#define __AUXILIAR_H__

#include "controladores.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include <iostream>
#include <stdbool>

class Resultado{
    private:
        int valor;
    public:
        const static int sucesso = 1;
        const static int falha = 0;
        inline void SetResultado(int valor){
            this->valor = valor;
        }
        inline int GetResultado() const{
            return valor;
        }
};

class ResultadoAutenticar :: public Resultado{
    private:
        Cpf cpf;
        Senha senha;

    public:
        inline void SetCpfResultado(const Cpf &cpf){
            this->cpf = cpf;
        }
        inline void SetSenhaResultado(const Senha &senha){
            this->senha = senha;
        }
        Senha GetSenhaResultado(){
            return senha;
        }
        Cpf GetCpfResultado(){
            return cpf;
        }
}

#endif