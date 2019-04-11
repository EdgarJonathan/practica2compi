#include "accion.h"

//******************************************************************************
//*************************** Constructor **************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
accion::accion(){ resultado="";}
//******************************************************************************
//***************************Iniciar ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::init(NodoAST *raiz)
{
    if(raiz->hijos.at(0).tipo_ == LISTA_CUERPO)
    {

        for (int x= 0; x<  raiz->hijos.at(0).hijos.size(); x++)
        {

            NodoAST lista = raiz->hijos.at(0).hijos.at(x);
            ListaCuerpo(&lista);

        }



    }

}
//******************************************************************************
//*************************** LIsta_CUerpo ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::ListaCuerpo(NodoAST*raiz)
{

    switch (raiz->tipo_)
    {

    case LISTA_DECLARACION:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            declaracion(&nodo);
        }
    }
        break;

    case LISTA_ASIGNACION:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            asignacion(&nodo);
            //  QTextStream(stdout) << "Asig-> "+QString::number(x)+"valor-> "+raiz->hijos.at(x).valor << endl;
        }


    }
        break;

    case LISTA_IMPRIMIR:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            imprimir(&nodo);
        }

    }
        break;

    case LISTA_MOSTRAR:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            sentenciaMostrar(&nodo);
        }
    }
        break;

    case LISTA_IF:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            sentenciaIf(&nodo);
        }

    }
        break;

    case LISTA_FOR:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            sentenciaFor(&nodo);
        }

    }
        break;

    case LISTA_REPETIR:
    {
        for (int x= 0; x< raiz->hijos.size(); x++)
        {
            NodoAST nodo = raiz->hijos.at(x);
            sentendiaRepetir(&nodo);
        }

    }
        break;

    }

}
//******************************************************************************
//*************************** Declaracion ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::declaracion(NodoAST* raiz)
{

    switch (raiz->tipo_) {

    case DECLARACIONVAR1:
    {
        NodoAST tk_tipo = raiz->hijos.at(0);
        NodoAST listId = raiz->hijos.at(1);
        NodoAST tk_valor = raiz->hijos.at(2);

        int tipo_= tipoDato(&tk_tipo).tipo;

        Resultado r1 =contValor(&tk_valor);
        QString valor = r1.valor;
        int tipo_valor = r1.tipo;

        QTextStream(stdout) << "Valor: ["+valor+"]" << endl;

        listaId(&listId,tipo_,tipo_valor,valor);

    }
        break;
    case DECLARACIONVAR2:
    {
        NodoAST tk_tipo = raiz->hijos.at(0);
        NodoAST listId = raiz->hijos.at(1);

        int tipo_= tipoDato(&tk_tipo).tipo;
        QString valor = "null";
        listaId(&listId,tipo_,tipo_,valor);

    }
        break;
    case DECLARACIONARRAY1:
    {
        QTextStream(stdout) << "estamos en arr1" << endl;
    }
        break;
    case DECLARACIONARRAY2:
    {

        QTextStream(stdout) << "estamos en arr2" << endl;

    }
        break;
    case DECLARACIONARRAY3:
    {

        NodoAST tk_tipo = raiz->hijos.at(0);
        int tipo_= tipoDato(&tk_tipo).tipo;
        NodoAST listId = raiz->hijos.at(1);
        NodoAST fila = raiz->hijos.at(3);
        NodoAST tam = raiz->hijos.at(2).hijos.at(0);
        Resultado tama = OPERACION(&tam);

        if(esEntero(tama)){
            int tamanio = tama.valor.toInt();
            declaraArray1(tipo_,&fila,tamanio,&listId);
        }


        /* array1* arr = new array1(INT,5);

       bool estado = arr->anadir(0,"valor cambiado1");
        bool estado1 = arr->anadir(6,"valor cambiado1");

       if(estado){

        QTextStream(stdout) << "se agrego con exito" << endl;
       }else{

            QTextStream(stdout) << "no se pudo agregar" << endl;
       }

       if(estado1){

        QTextStream(stdout) << "se agrego con exito" << endl;
       }else{

            QTextStream(stdout) << "no se pudo agregar" << endl;
       }
       listaarray.insert("id1",arr);


        array1* lol = listaarray.value("id1");

        if(lol){
                QTextStream(stdout) << "cuarlquier otro valor "+lol->obtener(4)<< endl;
                QTextStream(stdout) << "valorRecuperado "+lol->obtener(7)<< endl;
        }

        QTextStream(stdout) << "estamos en arr3" << endl;*/




    }
        break;

    }


}
//******************************************************************************
//*************************** Asignacion ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::asignacion(NodoAST* raiz){

    NodoAST aux = raiz->hijos.at(raiz->hijos.size()-1);
    Resultado tk_valor = contValor(&aux);
    Variable* var = new Variable(tk_valor.tipo,tk_valor.valor);


    for (int x= 0; x<  raiz->hijos.size()-1; x++)
    {
        NodoAST actual =  raiz->hijos.at(x);
        if(actual.hijos.size()>0){
            NodoAST dimen = actual.hijos.first();
            Dimensiones(&actual , &dimen,tk_valor);
        }else{

            Variable* VariableDeclarada = listaVariables.value(actual.valor);

            if(VariableDeclarada!= nullptr){

                if(VariableDeclarada->tipo_ == tk_valor.tipo){

                    listaVariables.insert(actual.valor,var);
                    QTextStream(stdout) << "Variable ["+actual.valor+"] asignada con exito"<< endl;

                }else{

                    Resultado r = Resultado();
                    r.linea = actual.linea;
                    r.columna = actual.columna;
                    Msgerror(r,"El tipo declarado en  \""+actual.valor+"\" no coincide con el tipo asignado");
                }

            }else{

                Resultado r = Resultado();
                r.linea = actual.linea;
                r.columna = actual.columna;
                Msgerror(r,"No existe una declaracion de \""+actual.valor+"\"");

            }

        }

    }

}
//******************************************************************************
//*************************** Imprimir ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::imprimir(NodoAST* raiz){


}
//******************************************************************************
//*************************** Mostrar ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::sentenciaMostrar(NodoAST* raiz){

}
//******************************************************************************
//*************************** if ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::sentenciaIf(NodoAST* raiz){


}
//******************************************************************************
//*************************** for ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::sentenciaFor(NodoAST* raiz){


}
//******************************************************************************
//*************************** repetir ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::sentendiaRepetir(NodoAST* raiz){


}
//******************************************************************************
//*************************** tipo Dato ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
Resultado accion::tipoDato(NodoAST* raiz){

    Resultado r = Resultado();
    r.linea = raiz->linea;
    r.columna = raiz->columna;

    switch (raiz->tipo_) {

    case STRING:
        r.tipo =STRING ;
        r.valor = raiz->valor;
        break;
    case BOOL:
        r.tipo =BOOL ;
        r.valor = raiz->valor;
        break;
    case INT:
        r.tipo =INT ;
        r.valor = raiz->valor;
        break;
    case DOUBLE:
        r.tipo =DOUBLE ;
        r.valor = raiz->valor;
        break;
    case CHAR:
        r.tipo =CHAR ;
        r.valor = raiz->valor;
        break;
    }



    return r;
}
//******************************************************************************
//*************************** listaid ************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void accion::listaId(NodoAST *raiz, int tipo, int tipo_valor, QString valor){

    for (int x= 0; x< raiz->hijos.size(); x++)
    {
        if(tipo!=ERROR){
            if(tipo==tipo_valor){

                NodoAST nodo = raiz->hijos.at(x);
                listaVariables.insert(nodo.valor,new Variable(tipo,valor));
                QTextStream(stdout) << "Declaracion Exitosa" << endl;

            }else{

                resultado+="No se puede declarar  el tipo de dato no coincide con el valor";
            }


        }else{

            resultado+="Existe en un error en el valor de la declaracion";
        }

    }

}
//******************************************************************************
//*************************** contValor ***************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
Resultado accion::contValor(NodoAST* raiz){


    Resultado r = Resultado();
    r.linea = raiz->linea;
    r.columna = raiz->columna;

    switch (raiz->tipo_) {

    case AND :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {
        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor) && condBool(op2.valor))
                {
                    r.valor ="true";

                }else{

                    r.valor="false";

                }

                break;
            }
            default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se pueden comparar los tipos");
            break;
        }
        }

        break;
    }
    case OR :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor)||condBool(op2.valor))
                {
                    r.valor ="true";

                }else{

                    r.valor="false";

                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se pueden comparar los tipos");
            break;
        }

        }

        break;
    }
    case MAYORQUE :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()> op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }

                break;
            }
            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble()> op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }


                break;
            }
            case CHAR:{

                r.tipo =BOOL;
                if(op1.valor.toInt() > op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case STRING:{
                r.tipo =BOOL;
                if(op1.valor > op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()> op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()> op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{

                r.tipo = BOOL;

                if(op1.valor.toDouble() > op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() > op2.valor.toInt())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() > op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() > op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"No se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor)> condBool(op2.valor))
                {

                    r.valor="true";
                }else {
                    r.valor="false";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede comparar los tipos");
            break;
        }

        }

        break;
    }
    case MENORQUE :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()< op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }

                break;
            }
            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble()< op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }


                break;
            }
            case CHAR:{

                r.tipo =BOOL;
                if(op1.valor.toInt() < op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case STRING:{
                r.tipo =BOOL;
                if(op1.valor < op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()< op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()< op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{

                r.tipo = BOOL;

                if(op1.valor.toDouble() < op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() < op2.valor.toInt())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() < op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() < op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"No se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor)< condBool(op2.valor))
                {

                    r.valor="true";
                }else {
                    r.valor="false";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se pueden comparar los tipos");
            break;
        }

        }

        break;
    }
    case MAYORIGUAL :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()>= op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }

                break;
            }
            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble()>= op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }


                break;
            }
            case CHAR:{

                r.tipo =BOOL;
                if(op1.valor.toInt() >= op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case STRING:{
                r.tipo =BOOL;
                if(op1.valor >= op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()>= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()>= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{

                r.tipo = BOOL;

                if(op1.valor.toDouble() >= op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() >= op2.valor.toInt())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() >= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() >= op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"No se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor)>= condBool(op2.valor))
                {

                    r.valor="true";
                }else {
                    r.valor="false";
                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        default:{


            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"error en la comparacion");
            break;
        }

        }

        break;

    }
    case MENORIGUAL :
    { NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()<= op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }

                break;
            }
            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble()<= op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }


                break;
            }
            case CHAR:{

                r.tipo =BOOL;
                if(op1.valor.toInt() <= op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="false";
                }
                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case STRING:{
                r.tipo =BOOL;
                if(op1.valor <= op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()<= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.toDouble()<= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{

                r.tipo = BOOL;

                if(op1.valor.toDouble() <= op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() <= op2.valor.toInt())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }
            case DOUBLE:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() <= op2.valor.toDouble())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }

                break;
            }
            case CHAR:{
                r.tipo = BOOL;

                if(op1.valor.at(0).toLatin1() <= op2.valor.at(0).toLatin1())
                {
                    r.valor="true";

                }else{
                    r.valor="false";

                }
                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"No se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case BOOL:{
                r.tipo = BOOL;
                if(condBool(op1.valor)<= condBool(op2.valor))
                {

                    r.valor="true";
                }else {
                    r.valor="false";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"error en comparacion");
            break;
        }

        }

        break;
    }
    case IGUALACION :
    { NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()==op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }
            case CHAR:{

                r.tipo =BOOL;
                if(op1.valor.at(0).toLatin1() ==op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden diferenciar los tipos" );

                break;
            }

            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {


            case STRING:{
                r.tipo =BOOL;
                if(op1.valor ==op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {


            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble() == op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:
            case CHAR:
                r.tipo =BOOL;
                if(op1.valor.at(0).toLatin1() ==op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden comparar los tipos");
                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {


            case BOOL:{
                r.tipo =BOOL;
                if(condBool(op1.valor) ==condBool(op2.valor))
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden diferenciar los tipos");
                break;
            }

            }

            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"error en la igualaciona" );
            break;
        }


        }

        break;
    }
    case DIFERENCIACION :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = contValor(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = contValor(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =BOOL;
                if(op1.valor.toInt()!=op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }

            case CHAR:{
                r.tipo =BOOL;
                if(op1.valor.at(0).toLatin1()!=op2.valor.at(0).toLatin1())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }
            default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden diferenciar los tipos");
                break;
            }


            }

            break;
        }
        case STRING:{

            switch (op2.tipo) {


            case STRING:{

                r.tipo =BOOL;
                if(op1.valor!=op2.valor)
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"No se pueden diferenciar los tipo");
                break;
            }

            }

            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case DOUBLE:{
                r.tipo =BOOL;
                if(op1.valor.toDouble()!=op2.valor.toDouble())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }

                break;
            }default:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r, "error de tipos");

                break;
            }

            }

            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{

                r.tipo =BOOL;
                if(op1.valor.at(0).toLatin1() !=op2.valor.toInt())
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }
            case CHAR:{
                r.tipo =BOOL;
                if(op1.valor.at(0).toLatin1() !=op2.valor.at(0).toLatin1() )
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }


                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden diferenciar los tipos ");

                break;
            }

            }

            break;
        }
        case BOOL:{

            switch (op2.tipo) {


            case BOOL:{
                r.tipo =BOOL;
                if(condBool(op1.valor)!=condBool(op2.valor))
                {
                    r.valor ="true";

                }else{
                    r.valor="falso";
                }



                break;
            }default:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se pueden diferenciar los tipos");
                break;
            }

            }

            break;
        }
        default:{


            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"error en le difereciacion");
        }

        }

        break;
    }
    default:{
        Resultado r1 =OPERACION(raiz);
        r.tipo = r1.tipo;
        r.valor = r1.valor;

        break;
    }


    }

    return r;
}
//******************************************************************************
//*************************** contValor ***************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
Resultado accion::OPERACION(NodoAST* raiz){

    Resultado r = Resultado();
    r.linea = raiz->linea;
    r.columna = raiz->columna;

    switch (raiz->tipo_) {
    case SUMA :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = OPERACION(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{

                r.tipo = INT;
                int result = op1.valor.toInt() +op2.valor.toInt();
                r.valor = QString::number(result);
                break;
            }
            case STRING:{

                r.tipo = STRING;
                r.valor = op1.valor + op2.valor;

                break;
            }
            case BOOL:{

                r.tipo = INT;
                QString valor = op2.valor;

                if( ( valor.toLower().compare("true") ==0) ||  (valor.toLower().compare("verdadero")==0) ){

                    int result = op1.valor.toInt() +1;
                    r.valor = QString::number(result);

                }else{
                    r.valor = op1.valor;

                }

                break;
            }
            case DOUBLE:{

                r.tipo = DOUBLE;
                double result = op1.valor.toDouble() + op2.valor.toDouble();
                r.valor = QString::number(result);
                break;
            }
            case CHAR:{
                r.tipo = INT;
                char  aux = op2.valor.at(0).toLatin1();
                int result = op1.valor.toInt()+ aux;
                r.valor = QString::number(result);
                break;
            }
            default:{

                r.tipo = ERROR;
                r.valor ="null";

                QTextStream(stdout) << "Error Semantico" << endl;
            }

            }

            break;
        }

        case STRING:{

            switch (op2.tipo) {

            case INT:{

                r.tipo = STRING;
                r.valor = op1.valor + op2.valor;
                break;
            }
            case STRING:{
                r.tipo = STRING;
                r.valor = op1.valor + op2.valor;
                break;
            }
            case DOUBLE:{
                r.tipo = STRING;
                r.valor = op1.valor + op2.valor;
                break;
            }
            case CHAR:{
                r.tipo = STRING;
                r.valor = op1.valor + op2.valor;
                break;
            }
            case BOOL:{

                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+"  no se puede sumar string y bool \n";
                QTextStream(stdout) << "Error Semantico" << endl;
                break;
            }
            default:{


                r.tipo = ERROR;
                r.valor ="null";
                QTextStream(stdout) << "Error Semantico" << endl;
            }

            }

            break;
        }

        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = DOUBLE;
                double result = op1.valor.toDouble() + op2.valor.toDouble();
                r.valor = QString::number(result);
                break;
            }
            case STRING:{
                r.tipo = STRING;
                r.valor = op1.valor+op2.valor;
                break;
            }
            case DOUBLE:{
                r.tipo = DOUBLE;
                double result = op1.valor.toDouble() + op2.valor.toDouble();
                r.valor = QString::number(result);
                break;
            }
            case CHAR:{
                r.tipo = DOUBLE;
                char  aux = op2.valor.at(0).toLatin1();
                int result = op1.valor.toInt()+ aux;
                r.valor = QString::number(result);
                break;
            }
            case BOOL:{
                r.tipo = DOUBLE;
                QString valor = op2.valor;

                if( ( valor.toLower().compare("true") ==0)||  (valor.toLower().compare("verdadero")==0) ){

                    int result = op1.valor.toInt() +1;
                    r.valor = QString::number(result);

                }else{
                    r.valor = op1.valor;
                }

                break;

            } default:

                r.tipo = ERROR;
                r.valor ="null";
                QTextStream(stdout) << "Error Semantico" << endl;
                break;
            }

            break;
        }

        case CHAR:{

            switch (op2.tipo) {

            case INT:{

                r.tipo = INT;
                char  aux = op1.valor.at(0).toLatin1();
                int result = op2.valor.toInt()+ aux;
                r.valor = QString::number(result);

                break;
            }
            case STRING:{
                r.tipo = STRING;
                r.valor = op1.valor+op2.valor;
                break;
            }
            case DOUBLE:{
                r.tipo = DOUBLE;
                char  aux = op1.valor.at(0).toLatin1();
                double result = op2.valor.toDouble()+ aux;
                r.valor = QString::number(result);
                break;
            }
            case CHAR:{
                r.tipo = INT;
                char  aux1 = op1.valor.at(0).toLatin1();
                char aux2 = op2.valor.at(0).toLatin1();
                int result = aux1+aux2;
                r.valor =QString::number(result);
                break;
            }
            case BOOL:{

                r.tipo = INT;
                QString valor = op2.valor;

                if( ( valor.toLower().compare("true") ==0) ||  (valor.toLower().compare("verdadero")==0) ){

                    char  aux1 = op1.valor.at(0).toLatin1();
                    int result =1+ aux1;
                    r.valor = QString::number(result);

                }else{
                    char  aux1 = op1.valor.at(0).toLatin1();
                    int result =0+ aux1;
                    r.valor = QString::number(result);

                }

                break;
            }default:{

                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico ";

                break;
            }

            }

            break;
        }

        case BOOL:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = INT;
                QString valor = op1.valor;

                if( ( valor.toLower().compare("true") ==0) ||  (valor.toLower().compare("verdadero")==0) ){

                    int result = op2.valor.toInt() +1;
                    r.valor = QString::number(result);

                }else{
                    r.valor = op2.valor;

                }
                break;
            }
            case STRING:{

                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+"  no se puede sumar string y bool \n";
                QTextStream(stdout) << "Error Semantico" << endl;
                break;
            }
            case BOOL:{

                r.tipo =BOOL;
                QString valor1 = op1.valor;
                QString valor2 = op2.valor;

                if(  ((valor1.toLower().compare("true") ==0) ||  (valor1.toLower().compare("verdadero")==0))||
                     ((valor2.toLower().compare("true") ==0) ||  (valor2.toLower().compare("verdadero")==0))
                     ){

                    r.valor ="true";

                }else{
                    r.valor ="false";

                }


                break;
            }
            case DOUBLE:{

                r.tipo = DOUBLE;
                QString valor = op1.valor;

                if( ( valor.toLower().compare("true") ==0) ||  (valor.toLower().compare("verdadero")==0) ){

                    double result = op1.valor.toDouble() +1;
                    r.valor = QString::number(result);

                }else{
                    r.valor = op1.valor;

                }

                break;
            }
            case CHAR:{

                QString valor = op1.valor;

                if( ( valor.toLower().compare("true") ==0) ||  (valor.toLower().compare("verdadero")==0) ){

                    char aux = op1.valor.at(0).toLatin1();
                    int result = aux +1;
                    r.valor = QString::number(result);

                }else{
                    char aux = op1.valor.at(0).toLatin1();
                    int result = aux;
                    r.valor = QString::number(result);

                }


                break;
            }
            default:{


                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"No se pueden sumar los tipos");
                break;
            }

            }

            break;
        }

        default:{

            r.tipo = ERROR;
            r.valor ="null";

            break;
        }
        }


        break;
    }
    case RESTA :
    {

        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = OPERACION(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {
            case INT:{
                r.tipo = INT;
                int result = op1.valor.toInt()- op2.valor.toInt();
                r.valor = QString::number(result);
                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar int string\n";
                QTextStream(stdout) << "Error Semantico" << endl;
                break;
            }
            case DOUBLE:{

                r.tipo = DOUBLE;
                double result = op1.valor.toDouble() - op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{

                r.tipo = INT;
                char aux= op2.valor.at(0).toLatin1();
                int result = op1.valor.toInt()  - aux;
                r.valor = QString::number(result);

                break;
            }
            case BOOL:{

                r.tipo = INT;
                QString valor = op2.valor;

                if( (valor.toLower().compare("true")==0)||(valor.toLower().compare("verdadero")==0)  )
                {
                    int result = op1.valor.toInt() +1;
                    r.valor = QString::number(result);
                }
                else{
                    r.valor = op1.valor;
                }


                break;
            }default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se pueden restar los tipos");
                break;
            }
            }
            break;
        }

        case STRING:{

            switch (op2.tipo) {
            case INT:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar un string a un int \n";
                QTextStream(stdout) << "Error Semantico" << endl;

                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar un string a un string \n";
                QTextStream(stdout) << "Error Semantico" << endl;

                break;
            }
            case DOUBLE:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar un string a un double \n";
                QTextStream(stdout) << "Error Semantico" << endl;

                break;
            }
            case CHAR:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar un string a un char \n";
                QTextStream(stdout) << "Error Semantico" << endl;

                break;
            }
            case BOOL:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar un string a un bool \n";
                QTextStream(stdout) << "Error Semantico" << endl;

                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se puedne restar los tipos");
                break;
            }


            }
            break;
        }

        case DOUBLE:{

            switch (op2.tipo) {
            case INT:{

                r.tipo = DOUBLE;
                double result = op1.valor.toDouble()- op2.valor.toInt();
                r.valor= QString::number(result);

                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                resultado+="Error Semantico: linea:"+QString::number(r.linea);
                resultado+=" col:"+QString::number(r.columna)+" no se  pueden restar double a un  string\n";
                QTextStream(stdout) << "Error Semantico" << endl;
                break;
            }
            case DOUBLE:{
                r.tipo = DOUBLE;
                double result= op1.valor.toDouble()-op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{

                r.tipo = DOUBLE;
                double result= op1.valor.toDouble() - op2.valor.at(0).toLatin1();
                r.valor = QString::number(result);

                break;
            }
            case BOOL:{

                r.tipo = DOUBLE;
                QString valor = op2.valor.toLower();

                if( (valor.compare("true")==0||(valor.compare("verdadero")==0)) )
                {
                    double result = op1.valor.toDouble()-1;
                    r.valor = QString::number(result);

                }else{
                    r.valor = op1.valor;
                }


                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden restar  los tipos");

                break;
            }


            }
            break;
        }

        case CHAR:{

            switch (op2.tipo) {
            case INT:{

                r.tipo = INT;
                int result = op1.valor.at(0).toLatin1()-op2.valor.toInt();
                r.valor = QString::number(result);
                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r, "no se puede restar un chara un string");
                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;
                double result =op1.valor.at(0).toLatin1()- op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{
                r.tipo =INT;
                int result = op1.valor.at(0).toLatin1()-op2.valor.at(0).toLatin1();
                r.valor =QString::number(result);
                break;
            }
            case BOOL:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se puede restar un bool a un char");
                break;
            }
            default:{

                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden restar los tipos");
                break;
            }


            }
            break;
        }

        case BOOL:{

            switch (op2.tipo) {
            case INT:{
                r.tipo = INT;

                if(condBool(op1.valor))
                {
                    int result = 1-op2.valor.toInt();
                    r.valor = QString::number(result);

                }else{

                    int result = op2.valor.toInt()*(-1);
                    r.valor = QString::number(result);

                }

                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"No se puede restar un string a un bool");

                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;

                if(condBool(op1.valor))
                {
                    double result = 1- op2.valor.toDouble();
                    r.valor = QString::number(result);
                }else{
                    double result = op2.valor.toDouble()*(-1);
                    r.valor = QString::number(result);
                }


                break;
            }
            case CHAR:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se puede restar char a un bool");
                break;
            }
            case BOOL:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se puede restar bool a un boll");
                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden restar lor tipos");
                break;
            }

            }
            break;
        }

        default:{

            r.tipo = ERROR;
            r.valor ="null";
            Msgerror(r,"no se puden resta los tipos");
            break;
        }

        }

        break;
    }
    case POR :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = OPERACION(&der);
        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = INT;
                int result = op1.valor.toInt() * op2.valor.toInt();
                r.valor = QString::number(result);
                break;
            }
            case STRING:{

                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"No de puede multiplicar un int con un string");
                break;
            }
            case DOUBLE:{
                r.tipo = STRING;
                double result = op1.valor.toDouble()* op2.valor.toDouble();
                r.valor = QString::number(result);
                break;
            }
            case CHAR:{
                r.tipo = INT;
                int result = op1.valor.toInt()* op2.valor.at(0).toLatin1();
                r.valor = QString::number(result);
                break;
            }
            case BOOL:{
                r.tipo = INT;

                if(condBool(op2.valor)){
                    r.valor = op1.valor;
                }else{

                    r.valor = "0";
                }

                break;
            }
            default:{

                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden multiplicar los tipos");

                break;
            }
            }
            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = STRING;
                Msgerror(r,"No se puede MULTIPLICAR  un string y un int");

                break;
            }
            case STRING:{
                r.tipo = STRING;
                Msgerror(r,"No se puede MULTIPLICAR  un string y un string");

                break;
            }
            case DOUBLE:{
                r.tipo = STRING;
                Msgerror(r,"No se puede MULTIPLICAR  un string y un double");

                break;
            }
            case CHAR:{
                r.tipo = STRING;
                Msgerror(r,"No se puede MULTIPLICAR  un string y un char");

                break;
            }
            case BOOL:{
                r.tipo = STRING;
                Msgerror(r,"No se puede MULTIPLICAR  un string y un bool");

                break;
            }default:{

                r.tipo=ERROR;
                r.valor="null";
                Msgerror(r,"NO se pueden multiplicar los tipos");
                break;
            }


            }
            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{

                r.tipo= DOUBLE;
                double result = op1.valor.toDouble()* op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case STRING:{

                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se puede multplicar un double con un string");

                break;
            }
            case DOUBLE:{
                r.tipo = DOUBLE;
                double result = op1.valor.toDouble()* op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{
                r.tipo= DOUBLE;
                double result=op1.valor.toDouble()* op2.valor.at(0).toLatin1();
                r.valor = QString::number(result);

                break;
            }
            case BOOL:{
                r.tipo = DOUBLE;

                if(condBool(op2.valor)){
                    r.valor = op1.valor;
                }else{

                    r.valor ="0";
                }

                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden multiplicar los tipos");
                break;
            }
            }
            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = INT;
                int result = op1.valor.at(0).toLatin1() * op2.valor.toInt();
                r.valor = QString::number(result);

                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"NO se puede multiplicar un char con un string");

                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;
                double result = op1.valor.at(0).toLatin1() * op2.valor.toDouble();
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{
                r.tipo=INT;
                int result = op1.valor.at(0).toLatin1()* op2.valor.at(0).toLatin1();
                r.valor = QString::number(result);

                break;
            }
            case BOOL:{
                r.tipo =INT;

                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;
                }else{
                    r.valor = "0";

                }

                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden multiplicar los tipos");
                break;
            }
            }
            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case INT:{

                r.tipo = INT;

                if(condBool(op1.valor))
                {
                    r.valor = op2.valor;
                }else{

                    r.valor ="0";
                }
                break;
            }
            case STRING:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r, "NO se puede multiplicar un Bool y un string " );

                break;
            }
            case DOUBLE:{

                r.tipo = DOUBLE;

                if(condBool(op1.valor))
                {
                    r.valor = op2.valor;
                }else{

                    r.valor ="0";
                }

                break;
            }
            case CHAR:{
                r.tipo = INT;

                if(condBool(op1.valor))
                {
                    r.valor = op2.valor.at(0).toLatin1();
                }else{

                    r.valor ="0";
                }

                break;
            }
            case BOOL:{

                r.tipo =BOOL;
                if( condBool(op1.valor) && condBool(op2.valor) )
                {
                    r.valor ="true";

                }else{

                    r.valor ="false";

                }

                break;
            }
            default:{
                r.tipo = ERROR;
                r.valor ="null";
                Msgerror(r,"no se pueden multiplicar los tipos");
                break;
            }
            }
            break;
        }
        default:{

            r.tipo = ERROR;
            r.valor ="null";
            Msgerror(r,"no se pueden multiplicar los tipos");
            break;
        }
        }

        break;
    }
    case DIV :
    {
        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = OPERACION(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo= INT;

                if(divCero(op2.valor)){

                    int result =op1.valor.toInt()/op2.valor.toInt();
                    r.valor =QString::number(result);

                }else{
                    r.tipo =ERROR;
                    r.valor="null";
                    Msgerror(r,"no se puede dividir por cero");
                }
                
                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"No se puede dividir un entero y un string");
                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;

                if(divCero(op2.valor)){
                    double result = op1.valor.toDouble()/ op2.valor.toDouble();
                    r.valor = QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"no se puede dividr por cero");
                }

                break;
            }
            case CHAR:{

                r.tipo = INT;

                if(op2.valor.at(0).toLatin1()!=0)
                {
                    int result = op1.valor.toInt()/ op2.valor.at(0).toLatin1();
                    r.valor =QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"no se puede dividir entre cero");
                }

                break;
            }
            case BOOL:{
                r.tipo = INT;

                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;

                }else{

                    r.tipo =ERROR;
                    r.valor="null";


                    Msgerror(r,"no se puede dividir entre cero");

                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se pueden dividir los tipos");
                break;
            }
            }
            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case INT:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no de puede dividir un string con un entero");
                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no de puede dividir un string con un string");

                break;
            }
            case DOUBLE:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no de puede dividir un string con un double");

                break;
            }
            case CHAR:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no de puede dividir un string con un char");
                break;
            }
            case BOOL:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no de puede dividir un string con un bool");

                break;
            }

            default:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se pueden dividir los tipos");

                break;
            }

            }
            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =DOUBLE;
                if(divCero(op2.valor))
                {
                    r.tipo = DOUBLE;
                    double result= op1.valor.toDouble()/ op2.valor.toDouble();
                    r.valor = QString::number(result);

                }else {

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se pude dividir por cero");

                }

                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO se pude dividir  un double con un string");
                break;
            }
            case DOUBLE:{
                r.tipo= DOUBLE;

                if(divCero(op2.valor)){
                    double result = op1.valor.toDouble()/op2.valor.toDouble();
                    r.valor = QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se puede dividir por cero");
                }


                break;
            }
            case CHAR:{
                r.tipo = DOUBLE;
                if(op2.valor.at(0).toLatin1()==0){

                    double result = op1.valor.toDouble()/op2.valor.at(0).toLatin1();
                    r.valor = QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";


                    Msgerror(r,"NO se puede dividir por cero");
                }
                break;
            }
            case BOOL:{
                r.tipo =DOUBLE;
                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;
                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se pude dividir por cero");

                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se pueden dividir los tipos");
                break;
            }
            }
            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{
                r.tipo = INT;

                if(divCero(op2.valor))
                {
                    int result = op1.valor.at(0).toLatin1() / op2.valor.toInt();
                    r.valor = QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";


                    Msgerror(r,"NO se pude dividr por cero");
                }
                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"No se puede dividir un char con string");
                break;
            }
            case DOUBLE:{
                r.tipo = DOUBLE;
                if(divCero(op2.valor))
                {
                    double result = op1.valor.at(0).toLatin1()/op2.valor.toDouble();
                    r.valor = QString::number(result);

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se pude dividir por cero ");
                }

                break;
            }
            case CHAR:{

                r.tipo = CHAR;

                if(op2.valor.at(0).toLatin1()!=0)
                {
                    int result = op1.valor.at(0).toLatin1()/op2.valor.at(0).toLatin1();
                    r.valor = QString::number(result);
                }else{
                    r.tipo =ERROR;
                    r.valor="null";


                    Msgerror(r,"NO se pude dividir por cero" );
                }

                break;
            }
            case BOOL:{
                r.tipo = INT;

                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se puede dividir por cero");
                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden dividir los tipos");
                break;
            }
            }
            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =INT;
                if(condBool(op1.valor))
                {
                    int result = 1/op2.valor.toInt();
                    r.valor = QString::number(result);
                }else{
                    r.valor = "0";
                }

                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO se puede dividir un bool con un string");
                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;
                if(condBool(op1.valor))
                {
                    double result = 1/op2.valor.toDouble();
                    r.valor = QString::number(result);
                }else{
                    r.valor = "0";
                }

                break;
            }
            case CHAR:{
                r.tipo = DOUBLE;

                if(op2.valor.at(0).toLatin1()!=0)
                {
                    if(condBool(op1.valor))
                    {
                        double result =1/op2.valor.at(0).toLatin1();
                        r.valor = QString::number(result);

                    }else
                    {
                        r.valor = "0";

                    }

                }else{

                    r.tipo =ERROR;
                    r.valor="null";

                    Msgerror(r,"NO se puede dividir por cero");
                }

                break;
            }
            case BOOL:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO se puede divir un bool con un bool");
                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se pueden dividir los tipos");
                break;
            }

            }
            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se pueden dividr lor tipos");
            break;
        }
        }

        break;
    }
    case POTENCIA :
    {

        NodoAST iz = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&iz);
        NodoAST der = raiz->hijos.at(1);
        Resultado op2 = OPERACION(&der);

        switch (op1.tipo) {

        case INT:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =INT;
                qreal result =  qPow(op1.valor.toInt(),op2.valor.toInt());
                r.valor = QString::number(result);
                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"NO SE PUEDE ELEVAR UN INT A UN STRING");
                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;
                qreal result =  qPow(op1.valor.toDouble(),op2.valor.toDouble());
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{
                r.tipo =INT;
                qreal result =  qPow(op1.valor.toInt(),op2.valor.at(0).toLatin1());
                r.valor = QString::number(result);

                break;
            }
            case BOOL:{
                r.tipo =INT;

                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;
                }else{
                    qreal result =  qPow(op1.valor.toInt(),0);
                    r.valor = QString::number(result);

                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden optenciar los tipos ");
                break;
            }
            }
            break;
        }
        case STRING:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se puede elevar un int a un string");

                break;
            }
            case STRING:{

                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se puede elevar un string a un string");
                break;
            }
            case DOUBLE:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se puede elevar un double a un string");

                break;
            }
            case CHAR:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se puede elevar un char a un string");

                break;
            }
            case BOOL:{
                r.tipo =ERROR;
                r.valor="null";

                Msgerror(r,"no se puede elevar un bool a un string");

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden potenciar los tipos" );
                break;
            }
            }
            break;
        }
        case DOUBLE:{

            switch (op2.tipo) {

            case INT:{
                r.tipo =DOUBLE;
                qreal result =  qPow(op1.valor.toDouble(),op2.valor.toDouble());
                r.valor = QString::number(result);
                break;
            }
            case STRING:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"NO se puede elevar un string a un double");

                break;
            }
            case DOUBLE:{
                r.tipo =ERROR;
                r.valor="null";
                qreal result =  qPow(op1.valor.toDouble(),op2.valor.toDouble());
                r.valor = QString::number(result);

                break;
            }
            case CHAR:{

                r.tipo =DOUBLE;
                qreal result =  qPow(op1.valor.toDouble(),op2.valor.at(0).toLatin1());
                r.valor = QString::number(result);
                break;
            }
            case BOOL:{

                r.tipo =DOUBLE;
                if(condBool(op2.valor))
                {
                    r.valor = op1.valor;

                }else{

                    qreal result =  qPow(op1.valor.toDouble(),0);
                    r.valor = QString::number(result);
                }
                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden potenciar los tipos");
                break;
            }
            }
            break;
        }
        case CHAR:{

            switch (op2.tipo) {

            case INT:{

                r.tipo =INT;
                qreal result =  qPow(op1.valor.at(0).toLatin1()  ,op2.valor.toInt());
                r.valor = QString::number(result);
                break;
            }
            case STRING:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se puede elevar un string a un char");

                break;
            }
            case DOUBLE:{

                r.tipo =DOUBLE;
                qreal result =  qPow(op1.valor.at(0).toLatin1()  ,op2.valor.toDouble());
                r.valor = QString::number(result);
                break;
            }
            case CHAR:{

                r.tipo =INT;
                qreal result =  qPow(op1.valor.at(0).toLatin1()  ,op2.valor.at(0).toLatin1());
                r.valor = QString::number(result);
                break;
            }
            case BOOL:{

                r.tipo =INT;

                if(condBool(op2.valor)){
                    qreal result =  qPow(op1.valor.at(0).toLatin1()  ,1);
                    r.valor = QString::number(result);

                }else{

                    qreal result =  qPow(op1.valor.at(0).toLatin1()  ,0);
                    r.valor = QString::number(result);
                }

                break;
            }
            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden potenciar los tipos");
                break;
            }

            }
            break;
        }
        case BOOL:{

            switch (op2.tipo) {

            case INT:{

                r.tipo =INT;
                if(condBool(op1.valor))
                {
                    qreal result =  qPow(1 ,op2.valor.toInt());
                    r.valor = QString::number(result);
                }else{
                    qreal result =  qPow(0 ,op2.valor.toInt());
                    r.valor = QString::number(result);
                }

                break;
            }
            case STRING:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pude elvar un string a un bool");
                break;
            }
            case DOUBLE:{
                r.tipo =DOUBLE;
                if(condBool(op1.valor))
                {
                    qreal result =  qPow(1 ,op2.valor.toDouble());
                    r.valor = QString::number(result);
                }else{
                    qreal result =  qPow(0 ,op2.valor.toDouble());
                    r.valor = QString::number(result);
                }

                break;
            }
            case CHAR:{
                r.tipo =INT;
                if(condBool(op1.valor))
                {
                    qreal result =  qPow(1 ,op2.valor.at(0).toLatin1());
                    r.valor = QString::number(result);
                }else{

                    qreal result =  qPow(0,op2.valor.at(0).toLatin1());
                    r.valor = QString::number(result);

                }

                break;
            }
            case BOOL:{
                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pude elvar un bool a un bool");

                break;
            }

            default:{

                r.tipo =ERROR;
                r.valor="null";
                Msgerror(r,"no se pueden potenciar los tipos");
                break;
            }

            }
            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se pueden potenciar los tipos" );
            break;
        }
        }

        break;
    }
    case MENOS :
    {
        NodoAST hijo = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&hijo);

        switch (op1.tipo) {

        case INT:{
            r.tipo =INT;
            int result = op1.valor.toInt()*(-1);
            r.valor =QString::number(result);
            break;
        }case STRING:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se convertir a negativo un string");
            break;
        }
        case DOUBLE:{
            r.tipo =DOUBLE;
            double result = op1.valor.toDouble()*(-1);
            r.valor =QString::number(result);
            break;
        }
        case CHAR:{
            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede covertir a negativo un char");
            break;
        }
        case BOOL:{
            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede convertir a nevativo un bool");
            break;
        }
        default:{


            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se comvertir a negativo los valores");
            break;

        }



        }


        break;

    }
    case AUMENTO :
    {

        NodoAST hijo = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&hijo);

        switch (op1.tipo) {

        case INT:{
            r.tipo =INT;
            int result = op1.valor.toInt()+1;
            r.valor =QString::number(result);
            break;
        }
        case STRING:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede aumentar un string");
            break;
        }
        case DOUBLE:{
            r.tipo =DOUBLE;
            double result = op1.valor.toDouble()+1;
            r.valor =QString::number(result);
            break;
        }
        case CHAR:{
            r.tipo =CHAR;
            int result =op1.valor.at(0).toLatin1()+1;
            r.valor =QString::number(result);
            break;
        }
        case BOOL:{
            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede aumentar un bool");
            break;
        }
        default:{


            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede aumentar el valor");
            break;
        }


        }

        break;
    }
    case DECREMENTO :
    {
        NodoAST hijo = raiz->hijos.at(0);
        Resultado op1 = OPERACION(&hijo);

        switch (op1.tipo) {

        case INT:{
            r.tipo =INT;
            int result = op1.valor.toInt()-1;
            r.valor =QString::number(result);
            break;
        }
        case STRING:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede decrementar un string");
            break;
        }
        case DOUBLE:{
            r.tipo =DOUBLE;
            double result = op1.valor.toDouble()-1;
            r.valor =QString::number(result);
            break;
        }
        case CHAR:{
            r.tipo =CHAR;
            int result =op1.valor.at(0).toLatin1()-1;
            r.valor =QString::number(result);
            break;
        }
        case BOOL:{
            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no se puede decrementar un bool");
            break;
        }
        default:{

            r.tipo =ERROR;
            r.valor="null";
            Msgerror(r,"no s epuede aumentar los valores" );
            break;
        }


        }



        break;
    }
    default:{

        Resultado r1 =VALOR(raiz);
        r.tipo = r1.tipo;
        r.valor = r1.valor;

        break;
    }
    }

    return r;
}
//******************************************************************************
//*************************** contValor ****************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
Resultado accion::VALOR(NodoAST* raiz){

    Resultado r = Resultado();
    r.linea = raiz->linea;
    r.columna = raiz->columna;

    switch (raiz->tipo_) {

    case IDENTIFICADOR :
    {


        Variable* VariableDeclarada = listaVariables.value(raiz->valor);
        if(VariableDeclarada!= nullptr){
            r.tipo =VariableDeclarada->tipo_;
            r.valor =VariableDeclarada->valor;

        }else{

            r.tipo = ERROR;
            r.valor="null";
            Msgerror(r,"No existe una declaracion de \""+raiz->valor+"\"");

        }



        break;
    }

    case CADENA :
    {
        r.tipo = STRING;
        r.valor = raiz->valor.replace("\"","");
        break;
    }
    case ENTERO :
    {
        r.tipo = INT;
        r.valor = raiz->valor;
        break;
    }
    case DECIMAL :
    {
        r.tipo = DOUBLE;
        r.valor = raiz->valor;
        break;
    }
    case BOOLEANO :
    {
        r.tipo = BOOL;
        r.valor = raiz->valor;
        break;
    }
    case CARACTER :
    {
        r.tipo = CHAR;
        r.valor = raiz->valor.replace("\'","");
        break;
    }
    case ARREGLO :
    {
        r.tipo = ARREGLO;

        std::cout<<"aun estamos trabajando en arreglo capo pronto estara disponible :v"<<std::endl;
        break;
    }


    }


    return r;
}
//******************************************************************************
//**************** COsas que se repiten ****************************************
//******************************************************************************
//******************************************************************************
void accion::Msgerror(Resultado r, QString Msg){


    resultado+="Error Semantico: linea: "+QString::number(r.linea);
    resultado+=" col: "+QString::number(r.columna)+Msg+"\n";
    QTextStream(stdout) << "Error Semantico" << endl;


}

bool accion::condBool(QString valor){


    if((valor.toLower().compare("true")==0)||(valor.toLower().compare("verdadero")==0)){
        return true;
    }else{

        return false;
    }
}

bool accion::divCero(QString valor){

    if(valor.toInt()==0){

        return false;
    }else{

        return  true;
    }


}

bool accion::validaArray(NodoAST *raiz, Resultado r){

    //verificamos si el valor que hay en el indice es un entero
    if(esEntero(r)){
        int i = r.valor.toInt();
        array1* arr = listaarray.value(raiz->valor);

        //verficamos si exite el array
        if(arr){

            QString valor = arr->obtener(i);

            //verificamos si no  nos pasamos de posicion
            if(valor!="vacio")
            {
                return true;
            }else{
                Msgerror(r," Posicion ["+QString::number(i)+"] esta fuera de rango");
                return false;
            }

        }else{
            Msgerror(r," No existe el array ["+raiz->valor+"]");
            return false;
        }

    }

}
bool accion::validaPos(QString valor, int i, Resultado r){


    if(valor=="vacio")
    {
        return true;
    }else{
        Msgerror(r," Posicion ["+QString::number(i)+"] esta fuera de rango");
        return false;
    }
}
//******************************************************************************
//**************** DImensiones ****************************************
//******************************************************************************
//******************************************************************************
void accion::Dimensiones(NodoAST *raiz, NodoAST* dimension,Resultado tk_valor){

    int tamanio = dimension->hijos.size();


    switch (tamanio) {

    case 1:{

        NodoAST auxIndex = dimension->hijos.at(0);
        Resultado Index = OPERACION(&auxIndex);

        if(validaArray(raiz,Index)){
            int i = Index.valor.toInt();
            array1* lol = listaarray.value(raiz->valor);
            lol->anadir(i,tk_valor.valor);
        }

        break;
    }
    case 2:{
        resultado+="estamos trabajando en vectores de dos dimensiones!!!";

        break;
    }
    case 3:{

        resultado+="estamos trabajando en vectores de tres dimensiones!!!";
        break;
    }default :{

        resultado+="No podes usar arrary mayor a tres dimensiones crack :v";
        break;
    }

    }




}
//******************************************************************************
//**************** declarArray1 ****************************************
//******************************************************************************
//******************************************************************************
void  accion::declaraArray1(int tipo, NodoAST* fila, int tamanio, NodoAST* listaid ){



    if(tamanio == fila->hijos.size()){



        QList<Resultado> cont =QList<Resultado>();

        for (int y= 0; y< fila->hijos.size(); y++)
        {
            NodoAST celda = fila->hijos.at(y);
            Resultado r = Resultado();
            r = contValor(&celda);
            cont.append(r);
        }


        for (int x= 0; x< listaid->hijos.size(); x++)
        {
            NodoAST id = listaid->hijos.at(x);
            array1* arr = new array1(tipo,tamanio);

            for (int y= 0; y< cont.size(); y++)
            {

                Resultado actual = cont.at(y);
                if(tipo == actual.tipo){
                    arr->anadir(y,actual.valor);

                    if(y == cont.size()-1){
                        listaarray.insert(id.valor,arr);
                    }

                }else {
                    if(x==0){

                        Msgerror(actual," EL tipo  de la celda ["+QString::number(y)+"] no es compatible con el tipo declarado");
                    }



                }

            }

        }



    }else{
        resultado+="El tamanio declarado no es igual al tamanio del vector";
    }




}
//******************************************************************************
//**************** Es un entero ?****************************************
//******************************************************************************
//******************************************************************************
bool accion::esEntero(Resultado r){


    if(r.tipo ==INT){

        return true;
    }else{
        Msgerror(r,"El tamanio del vector no es un entero");
        return  false;
    }

}









