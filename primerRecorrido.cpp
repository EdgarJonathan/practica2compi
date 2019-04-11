#include "primerrecorrido.h"


enum Choice
{
    INT =1 ,
    STRING = 2,
    BOOL = 3,
    CHAR = 4,
    DOUBLE = 5,
    SUMA = 6,
    RESTA = 7,
    MULTI = 8,
    DIV = 9,
    POTENCIA = 10,
    OPERACION = 11,
    LOPERACION = 12,
};

/*

    if(this->tipo=="int"){return 1;}
    if(this->tipo=="string"){return 2;}
    if(this->tipo=="bool"){return 3;}
    if(this->tipo=="char"){return 4;}
    if(this->tipo=="double"){return 5;}
    if(this->tipo=="suma"){return 6;}
    if(this->tipo=="resta"){return 7;}
    if(this->tipo=="multi"){return 8;}
    if(this->tipo=="div"){return 9;}
    if(this->tipo=="potencia"){return 10;}
    if(this->tipo=="operacion"){return 11;}
*/

primerRecorrido::primerRecorrido()
{
    resultado = "";
}

Resultado primerRecorrido:: recorrer( NodoAST *raiz)
{

    resultado = accion::init(raiz).valor;

    return r;
}


