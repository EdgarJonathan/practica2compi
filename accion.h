#ifndef ACCION_H
#define ACCION_H
#include <NodoAST.h>
#include <resultado.h>
#include <QString>
#include <iostream>
#include <QHash>
#include <QTextStream>
#include <QChar>
#include <QtMath>
#include <variables.h>

enum Choice
{
    //para verifcar si las variables no han sindo declaradas
    ERROR =-1,

    //--inicio
    INICIO =1 ,

    //--listas principales
    LISTA_CUERPO = 2,
    LISTA_REPETIR=3,
    LISTA_FOR=4,
    LISTA_MOSTRAR=5,
    LISTA_IMPRIMIR=6,
    LISTA_ASIGNACION=7,
    LISTA_DECLARACION=8,
    LISTA_IF=9,

    //Declaracion var
    DECLARACIONVAR1=10,
    DECLARACIONVAR2=11,
    DECLARACIONARRAY1=12,
    DECLARACIONARRAY2=13,
    DECLARACIONARRAY3=14,

    //--tipo de dato
    STRING =15,
    BOOL =16,
    INT = 17,
    DOUBLE =18,
    CHAR =19,

    //valores de operaciones y condiciones
    IDENTIFICADOR =20,
    CADENA =21,
    ENTERO=22,
    DECIMAL = 23,
    BOOLEANO=24,
    CARACTER=25,
    ARREGLO=26,

    //--cont valor
    AND =27,
    OR =28,
    MAYORQUE=29,
    MENORQUE=30,
    MAYORIGUAL=31,
    MENORIGUAL=32,
    IGUALACION=33,
    DIFERENCIACION=34,


    //--operacion
    SUMA = 35,
    RESTA = 36,
    POR = 37,
    DIV = 38,
    POTENCIA = 39,
    MENOS =40,
    AUMENTO =41,
    DECREMENTO =42,




};




class accion
{
public:

    QString  resultado;
    QHash<QString,Variable*>listaVariables;
    QHash<QString,array1*>listaarray;

    accion();

    //-----inicio del documento
    void init(NodoAST *raiz);
    void ListaCuerpo(NodoAST*raiz);


    //-------------------Acciones y sentencias
    void declaracion(NodoAST* raiz);
    void asignacion(NodoAST* raiz);
    void imprimir(NodoAST* raiz);
    void sentenciaMostrar(NodoAST* raiz);
    void sentenciaIf(NodoAST* raiz);
    void sentenciaFor(NodoAST* raiz);
    void sentendiaRepetir(NodoAST* raiz);

    //--para la declaracion
    Resultado tipoDato(NodoAST* raiz);
    void  listaId(NodoAST* raiz, int tipo,int tipo_valor, QString valor );
    Resultado contValor(NodoAST* raiz);
    Resultado OPERACION(NodoAST* raiz);
    Resultado VALOR(NodoAST* raiz);
    //para almacenar las variables




    //----acciones que se repiten xd
    void Msgerror(Resultado r, QString Msg);
    bool condBool(QString valor);
    bool divCero(QString valor);

    void Dimensiones(NodoAST *raiz, NodoAST* dimension,Resultado tk_valor);

    void  declaraArray1(int tipo, NodoAST* fila, int tamanio, NodoAST* listaid );

    bool esEntero(Resultado r);

    bool validaArray(NodoAST*raiz,Resultado r);
    bool validaPos(QString valor, int i,Resultado r);


};




#endif // ACCION_H
