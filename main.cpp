#include <iostream>
#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "testes-dominios.h"
#include "testes-entidades.h"
#include "testes.h"
#include "interfaces.h"
#include "controladores.h"

using namespace std;

int main()
{
    InterfaceServicoControle *isc;
    isc = new CtrlServicoControle();
    isc->Construir();

    delete isc;

    return 0;
}
