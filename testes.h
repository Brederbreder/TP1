#ifndef __TESTES_H__
#define __TESTES_H__

#include "dominios.h"
#include "entidades.h"
#include "testes-dominios.h"
#include "testes-entidades.h"

using namespace std;

class Teste{
    private:
        TUDominios *testeUnidadeDominios;
        TUEntidades *testeUnidadeEntidades;

        void SetUpTestes(){
            testeUnidadeDominios = new TUDominios();
            testeUnidadeEntidades = new TUEntidades();
        }

        void RunTestes(){
            testeUnidadeDominios->RunDominios();
            testeUnidadeEntidades->RunEntidades();
        }

        void DestroyTestes(){
            delete testeUnidadeDominios;
            delete testeUnidadeEntidades;
        }

    public:
        void Execute(){
            SetUpTestes();
            RunTestes();
            DestroyTestes();
        }
};

#endif // __TESTES_H__
