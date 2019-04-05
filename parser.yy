%{


#include "scanner.h"//se importa el header del analisis sintactico
#include "NodoAST.h"
#include "qdebug.h"
#include <iostream>
extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern NodoAST *raiz; // Raiz del arbol

int yyerror(const char* mens)
{

    std::cout << mens <<" "<<yytext<< std::endl;
    return 0;
}


%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;


}

//TERMINALES DE TIPO TEXT, SON STRINGS



%token<TEXT>  tk_int tk_double tk_bool tk_char tk_string; 
%token<TEXT>  tk_not tk_igual tk_menorque tk_mayorque tk_or tk_and tk_igualacion; 
%token<TEXT>  tk_diferenciacion tk_menorigual tk_mayorigual aumento decremento; 
%token<TEXT> cori cord coma identificador; 
%token<TEXT> entero;
%token<TEXT> decimal;
%token<TEXT> caracter;
%token<TEXT> booleano;
%token<TEXT> cadena;
%token<TEXT> pari;
%token<TEXT> pard;
%token<TEXT> suma;
%token<TEXT> menos;
%token<TEXT> multi;
%token<TEXT> division;
%token<TEXT> potencia;
%token<TEXT> puntocoma;
%token<TEXT> llavei llaved;
%token<TEXT> tk_arreglo;
%token<TEXT> tk_imprimir;




/*No terimanesl*/
%type<nodito> INICIO;
%type<nodito> DECLARACION;
%type<nodito> TIPO_DATO;
%type<nodito> CONT_VALOR;
%type<nodito> LISTA_ID;
%type<nodito> VALOR;
%type<nodito> LISTA_DECLARACION;
%type<nodito> LISTA_DIMENSION;
%type<nodito> ARRAY;
%type<nodito> LISTA_FILA;
%type<nodito> CUERPO;
%type<nodito> LISTA_ASIGNACION;
%type<nodito> ASIGNACION;
%type<nodito> LISTA_VAR;
%type<nodito> VAR;
%type<nodito> LISTA_CUERPO;
%type<nodito> LISTA_IMPRIMIR;
%type<nodito> IMPRIMIR;


%left tk_or
%left tk_and
%left tk_not
%left tk_diferenciacion tk_igualacion tk_mayorque tk_menorque tk_menorigual tk_mayorigual
%left suma menos
%left multi division
%left potencia
%left UMINUS


%start INICIO
%%

INICIO: LISTA_CUERPO { raiz =$$;} 
;


LISTA_CUERPO: LISTA_CUERPO CUERPO
              {
                $$=$1;
                $$->add(*$2);
              }

            | CUERPO
              {
                $$ = new NodoAST(@1.first_line, @1.first_column,"INICIO","");
                $$->add(*$1);
              }
;

CUERPO: LISTA_DECLARACION 
          {
            $$=$1;
          }
       | LISTA_ASIGNACION
          {
            $$=$1;
          }
          
       | LISTA_IMPRIMIR  
          {
            $$=$1;
          } 
          
;



LISTA_IMPRIMIR: LISTA_IMPRIMIR IMPRIMIR
                  {
                    $$=$1;
                    $$->add(*$2);
                  }
              | IMPRIMIR 
                  {
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_IMPRIMIR","");
                    $$->add(*$1);
                  }           
;

IMPRIMIR: tk_imprimir pari CONT_VALOR pard puntocoma
           {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"IMPRIMIR",""); 
                nod->add(*$3);
                $$=nod;
           }
;

LISTA_ASIGNACION: LISTA_ASIGNACION ASIGNACION
                  {
                    $$=$1;
                    $$->add(*$2);
                  }
                | ASIGNACION
                  {
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_ASIGNACION","");
                    $$->add(*$1);
                  }
;

ASIGNACION: LISTA_VAR tk_igual CONT_VALOR puntocoma
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"ASIGNACION",""); 
                nod->add(*$1); 
                nod->add(*$3);
                $$=nod;
            }

;

LISTA_VAR: LISTA_VAR tk_igual VAR
            {
              $$=$1;
              $$->add(*$3);
            }
         | VAR
            {
              $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_VAR","");
              $$->add(*$1);
            }
;

VAR: identificador
      { $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);}
   | identificador LISTA_DIMENSION 
      {
         $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);
         $$->add(*$2);
      }
;




LISTA_DECLARACION: LISTA_DECLARACION DECLARACION
                  {
                    $$=$1;
                    $$->add(*$2);
                  }
                 | DECLARACION
                  {
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_DECLARACION","");
                    $$->add(*$1);
                  }
;


DECLARACION: TIPO_DATO LISTA_ID tk_igual CONT_VALOR puntocoma
              {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"DECLARACIONVAR",""); 
                nod->add(*$1); 
                nod->add(*$2); 
                nod->add(*$4);
                $$=nod;
              }
           | TIPO_DATO LISTA_ID 
               {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"DECLARACIONVAR",""); 
                nod->add(*$1); 
                nod->add(*$2);
                $$=nod;
              }  
           | TIPO_DATO tk_arreglo LISTA_ID LISTA_DIMENSION puntocoma
              {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"DECLARACIONARRAY",""); 
                nod->add(*$1); 
                nod->add(*$3); 
                nod->add(*$4);
                $$=nod;
              }
           | TIPO_DATO tk_arreglo LISTA_ID LISTA_DIMENSION tk_igual llavei ARRAY llaved puntocoma
              {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"DECLARACIONARRAY",""); 
                nod->add(*$1); 
                nod->add(*$3); 
                nod->add(*$4);
                nod->add(*$7);
                $$=nod;
              }  
;

ARRAY: ARRAY coma llavei LISTA_FILA llaved
        {
            $$=$1;
            $$->add(*$4);
        } 
     |llavei LISTA_FILA llaved
        {
            $$ =  new NodoAST(@1.first_line, @1.first_column,"Array","");
            $$->add(*$2);
        } 
;

LISTA_FILA: LISTA_FILA coma CONT_VALOR
            {
              $$=$1;
              $$->add(*$3);
            } 
          | CONT_VALOR
            {
              $$ =  new NodoAST(@1.first_line, @1.first_column,"Fila","");
              $$->add(*$1);
            }
;


LISTA_DIMENSION: LISTA_DIMENSION cori CONT_VALOR cord
                  {
                     $$=$1;
                     $$->add(*$3);
                  }
               | cori CONT_VALOR cord  
                  {
                    $$ =  new NodoAST(@1.first_line, @1.first_column,"Lista_Dimension","");
                    $$->add(*$2);
                  }       
;



TIPO_DATO: tk_string
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"tk_string",$1); 
                $$=nod;
            }
         | tk_bool
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"tk_bool",$1); 
                $$=nod;
            }
         | tk_int
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"tk_int",$1);
                $$=nod;
            }
         | tk_double
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"tk_double",$1);
                $$=nod;
            }
         | tk_char
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"tk_char",$1);
                $$=nod;
            }
;



LISTA_ID: LISTA_ID coma identificador
            {
              $$=$1;
              NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"Iden",$3);
              $$->add(*nodo);
            }
        | identificador
            {
                $$ =  new NodoAST(@1.first_line, @1.first_column,"Lista_ID","");
                NodoAST *nodo = new NodoAST(@1.first_line, @1.first_column,"Iden",$1);
                $$->add(*nodo);
            }
;



CONT_VALOR: CONT_VALOR tk_and CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"and",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_or  CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"or",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }

          | CONT_VALOR tk_mayorque CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"mayorque",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_menorque CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"menorque",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_mayorigual CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"mayorigual",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_menorigual CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"menorigual",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_igualacion CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"asignacions",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR tk_diferenciacion CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"diferenciacion",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }

          | CONT_VALOR suma CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"suma",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR menos CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"resta",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR multi CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"por",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR division CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"div",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | CONT_VALOR potencia CONT_VALOR
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"potencia",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | menos CONT_VALOR %prec UMINUS
                { $$ = new NodoAST(@1.first_line, @1.first_column,"menos",$1); $$->add(*$2);}
          | pari CONT_VALOR pard
            {$$=$2;}
          | VALOR
            {$$=$1;}
;          

VALOR: identificador
        { $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);}
     |  cadena
        { $$ = new NodoAST(@1.first_line, @1.first_column,"cadena",$1);}
     |  entero
        { $$ = new NodoAST(@1.first_line, @1.first_column,"entero",$1);}
     |  decimal
        { $$ = new NodoAST(@1.first_line, @1.first_column,"decimal",$1);}
     |  booleano
        { $$ = new NodoAST(@1.first_line, @1.first_column,"boleano",$1);}
     |  caracter
        { $$ = new NodoAST(@1.first_line, @1.first_column,"char",$1);}
     | identificador LISTA_DIMENSION   
      {
         $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);
         $$->add(*$2);
      }
;     


%%
