#include "NodoAST.h"
#include <qdebug.h> // Para imprimir en consola.
NodoAST::NodoAST()
{
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;
    hijos =  QList<NodoAST>();
}

NodoAST:: NodoAST(int l, int c, QString t, QString v)
{
    linea = l;
    columna = c;
    tipo = t;
    valor = v;
    tipo_ = getTipo();
    hijos = QList<NodoAST>();
}

void NodoAST::add(NodoAST nd)
{
    this->hijos.append(nd);
}

int NodoAST::getTipo()
{


    if(this->tipo=="INICIO"){return 1;}
    if(this->tipo=="LISTA_CUERPO"){return 2;}

    //--Listas Principales
    if(this->tipo=="LISTA_REPETIR"){return 3;}
    if(this->tipo=="LISTA_FOR"){return 4;}
    if(this->tipo=="LISTA_MOSTRAR"){return 5;}
    if(this->tipo=="LISTA_IMPRIMIR"){return 6;}
    if(this->tipo=="LISTA_ASIGNACION"){return 7;}
    if(this->tipo=="LISTA_DECLARACION"){return 8;}
    if(this->tipo=="LISTA_IF"){return 9;}

    //--Declaracion var
    if(this->tipo=="DECLARACIONVAR1"){return 10;}
    if(this->tipo=="DECLARACIONVAR2"){return 11;}
    if(this->tipo=="DECLARACIONARRAY1"){return 12;}
    if(this->tipo=="DECLARACIONARRAY2"){return 13;}
    if(this->tipo=="DECLARACIONARRAY3"){return 14;}


    //--Tipo de dato
    if(this->tipo=="tk_string"){return 15;}
    if(this->tipo=="tk_bool"){return 16;}
    if(this->tipo=="tk_int"){return 17;}
    if(this->tipo=="tk_double"){return 18;}
    if(this->tipo=="tk_char"){return 19;}

    //--valores
    if(this->tipo=="iden"){return 20;}
    if(this->tipo=="cadena"){return 21;}
    if(this->tipo=="entero"){return 22;}
    if(this->tipo=="decimal"){return 23;}
    if(this->tipo=="boleano"){return 24;}
    if(this->tipo=="char"){return 25;}
    if(this->tipo=="idenD"){return 26;}

    //--CONT_VALOR
    if(this->tipo=="and"){return 27;}
    if(this->tipo=="or"){return 28;}
    if(this->tipo=="mayorque"){return 29;}
    if(this->tipo=="menorque"){return 30;}
    if(this->tipo=="mayorigual"){return 31;}
    if(this->tipo=="menorigual"){return 32;}
    if(this->tipo=="igualacion"){return 33;}
    if(this->tipo=="diferenciacion"){return 34;}

    //--OPERACION
    if(this->tipo=="suma"){return 35;}
    if(this->tipo=="resta"){return 36;}
    if(this->tipo=="por"){return 37;}
    if(this->tipo=="div"){return 38;}
    if(this->tipo=="potencia"){return 39;}
    if(this->tipo=="menos"){return 40;}
    if(this->tipo=="aumento"){return 41;}
    if(this->tipo=="decremento"){return 42;}


    //-- saltar dos numeros para validar posicion y array























    return 0;
}
