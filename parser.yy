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

    std::cout << mens <<" "<<yytext<<" "<<yylineno<<" "<<columna<<std::endl;
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
%token<TEXT> tk_show;
%token<TEXT> tk_if;
%token<TEXT> tk_else;
%token<TEXT> tk_para tk_repetir;
%token<TEXT> tk_public;
%token<TEXT> tk_main;




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
%type<nodito> LISTA_CUERPO;
%type<nodito> LISTA_IMPRIMIR;
%type<nodito> IMPRIMIR;
%type<nodito> OPERACION;
%type<nodito> LISTA_MOSTRAR;
%type<nodito> MOSTRAR;
%type<nodito> LISTA_IF;
%type<nodito> ELSE;
%type<nodito> SI;
%type<nodito> LISTA_FOR;
%type<nodito> LISTA_REPETIR;
%type<nodito> REPETIR;
%type<nodito> FOR;
%type<nodito> FOR_COND;
%type<nodito> E;
%type<nodito> A;



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

INICIO:    tk_public tk_main llavei  LISTA_CUERPO llaved
          {
                $$ = new NodoAST(yylineno+1, columna+1,"INICIO","");
                $$->add(*$4);
                raiz =$$;
          }


;

LISTA_CUERPO: LISTA_CUERPO CUERPO
              {
                $$=$1;
                $$->add(*$2);
              }

            | CUERPO
              {
                $$ = new NodoAST(yylineno+1, columna+1,"LISTA_CUERPO","");
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
        | LISTA_MOSTRAR
          {
            $$=$1;
          }    
        | LISTA_IF
          {
            $$=$1;
          } 
        | LISTA_FOR
          {
            $$=$1;
          }
        | LISTA_REPETIR
          {
            $$=$1;
          } 
;



LISTA_REPETIR: LISTA_REPETIR REPETIR 
                {
                    $$=$1;
                    $$->add(*$2);
                }
             | REPETIR
                {
                    $$ = new NodoAST(yylineno+1, columna+1,"LISTA_REPETIR","");
                    $$->add(*$1);
                } 
;

REPETIR: tk_repetir pari CONT_VALOR pard llavei LISTA_CUERPO llaved
             {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"REPETIR","");
                nod->add(*$3); 
                nod->add(*$6);
                $$=nod;
             }
       | tk_repetir pari CONT_VALOR pard llavei              llaved
             {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"REPETIR","");
                nod->add(*$3);
                $$=nod;
             }
;


LISTA_FOR: LISTA_FOR FOR
            {
              $$=$1;
              $$->add(*$2);
            }
         | FOR
            {
              $$ = new NodoAST(yylineno+1, columna+1,"LISTA_FOR","");
              $$->add(*$1);
            }
;

FOR:  tk_para pari FOR_COND  CONT_VALOR puntocoma OPERACION pard llavei LISTA_CUERPO llaved
        {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"FOR","");
                nod->add(*$3); 
                nod->add(*$4);
                nod->add(*$6);
                nod->add(*$9);
                $$=nod;
        }
     |tk_para pari FOR_COND  CONT_VALOR puntocoma OPERACION pard llavei              llaved
        {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"FOR","");
                nod->add(*$3); 
                nod->add(*$4);
                nod->add(*$6);
                $$=nod;
        }
;


FOR_COND: ASIGNACION
          {
            $$=$1;
          } 
        | DECLARACION
          { 
            $$=$1;
          } 
;


LISTA_MOSTRAR: LISTA_MOSTRAR MOSTRAR
                {
                    $$=$1;
                    $$->add(*$2);
                }
             | MOSTRAR
                {
                    $$ = new NodoAST(yylineno+1, columna+1,"LISTA_MOSTRAR","");
                    $$->add(*$1);
                }  
;


MOSTRAR: tk_show pari CONT_VALOR coma CONT_VALOR pard puntocoma
          {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"SHOW","");
                nod->add(*$3); 
                nod->add(*$5);
                $$=nod;
          }
;




LISTA_IMPRIMIR: LISTA_IMPRIMIR IMPRIMIR
                  {
                    $$=$1;
                    $$->add(*$2);
                  }
              | IMPRIMIR 
                  {
                    $$ = new NodoAST(yylineno+1, columna+1,"LISTA_IMPRIMIR","");
                    $$->add(*$1);
                  }           
;

IMPRIMIR: tk_imprimir pari CONT_VALOR pard puntocoma
           {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"IMPRIMIR",""); 
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
                    $$ = new NodoAST(yylineno+1, columna+1,"LISTA_ASIGNACION","");
                    $$->add(*$1);
                  }
;

ASIGNACION: LISTA_VAR  puntocoma
            {
                
                $$=$1;
            }

;

LISTA_VAR: LISTA_VAR tk_igual CONT_VALOR
            {
              $$=$1;
              $$->add(*$3);
            }
         | CONT_VALOR
            {
              $$ = new NodoAST(yylineno+1, columna+1,"ASIGNACION","");
              $$->add(*$1);
            }
;





LISTA_DECLARACION: LISTA_DECLARACION DECLARACION
                  {
                    $$=$1;
                    $$->add(*$2);
                  }
                 | DECLARACION
                  {
                    $$ = new NodoAST(yylineno+1, columna+1,"LISTA_DECLARACION","");
                    $$->add(*$1);
                  }
;


DECLARACION: TIPO_DATO LISTA_ID tk_igual CONT_VALOR puntocoma
              {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"DECLARACIONVAR1",""); 
                nod->add(*$1); 
                nod->add(*$2); 
                nod->add(*$4);
                $$=nod;
              }
           | TIPO_DATO LISTA_ID puntocoma
               {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"DECLARACIONVAR2",""); 
                nod->add(*$1); 
                nod->add(*$2);
                $$=nod;
              }  
           | TIPO_DATO tk_arreglo LISTA_ID LISTA_DIMENSION puntocoma
              {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"DECLARACIONARRAY1",""); 
                nod->add(*$1); 
                nod->add(*$3); 
                nod->add(*$4);
                $$=nod;
              }
           | TIPO_DATO tk_arreglo LISTA_ID LISTA_DIMENSION tk_igual llavei ARRAY llaved puntocoma
              {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"DECLARACIONARRAY2",""); 
                nod->add(*$1); 
                nod->add(*$3); 
                nod->add(*$4);
                nod->add(*$7);
                $$=nod;
              } 
           | TIPO_DATO tk_arreglo LISTA_ID LISTA_DIMENSION tk_igual llavei LISTA_FILA llaved puntocoma
              {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"DECLARACIONARRAY3",""); 
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
            $$ =  new NodoAST(yylineno+1, columna+1,"Array","");
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
              $$ =  new NodoAST(yylineno+1, columna+1,"Fila","");
              $$->add(*$1);
            }
;

LISTA_DIMENSION: LISTA_DIMENSION cori OPERACION cord
                  {
                     $$=$1;
                     $$->add(*$3);
                  }
               | cori OPERACION cord  
                  {
                    $$ =  new NodoAST(yylineno+1, columna+1,"LISTA_DIMENSION","");
                    $$->add(*$2);
                  }       
;

TIPO_DATO: tk_string
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"tk_string",$1); 
                $$=nod;
            }
         | tk_bool
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"tk_bool",$1); 
                $$=nod;
            }
         | tk_int
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"tk_int",$1);
                $$=nod;
            }
         | tk_double
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"tk_double",$1);
                $$=nod;
            }
         | tk_char
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"tk_char",$1);
                $$=nod;
            }
;


LISTA_ID: LISTA_ID coma identificador
            {
              $$=$1;
              NodoAST *nodo = new NodoAST(yylineno+1, columna+1,"Iden",$3);
              $$->add(*nodo);
            }
        | identificador
            {
                $$ =  new NodoAST(yylineno+1, columna+1,"Lista_ID","");
                NodoAST *nodo = new NodoAST(yylineno+1, columna+1,"Iden",$1);
                $$->add(*nodo);
            }
;


CONT_VALOR: A
             {
                $$=$1;
            }
;


A:           A tk_and A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"and",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_or  A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"or",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }

          | A tk_mayorque A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"mayorque",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_menorque A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"menorque",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_mayorigual A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"mayorigual",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_menorigual A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"menorigual",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_igualacion A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"igualacion",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | A tk_diferenciacion A
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"diferenciacion",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | pari A pard
            {
                $$=$2;
            }
          | OPERACION
          {
            $$=$1;
          };
          
;          

OPERACION: E
            {
                $$=$1;
            }
;


E: E suma E
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"suma",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | E menos E
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"resta",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | E multi E
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"por",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | E division E
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"div",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | E potencia E
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"potencia",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | menos E %prec UMINUS
                { $$ = new NodoAST(yylineno+1, columna+1,"menos",$1); $$->add(*$2);}

          | pari E pard
            {$$=$2;}

          | E aumento
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"aumento",$2); 
                nod->add(*$1); $$=nod;
            }
          | E decremento
            {
                NodoAST *nod = new NodoAST(yylineno+1, columna+1,"decremento",$2); 
                nod->add(*$1); $$=nod;
            }

          | VALOR
            {$$=$1;}
;

VALOR: identificador
        { $$ = new NodoAST(yylineno+1, columna+1,"iden",$1);}
     |  cadena
        { $$ = new NodoAST(yylineno+1, columna+1,"cadena",$1);}
     |  entero
        { $$ = new NodoAST(yylineno+1, columna+1,"entero",$1);}
     |  decimal
        { $$ = new NodoAST(yylineno+1, columna+1,"decimal",$1);}
     |  booleano
        { $$ = new NodoAST(yylineno+1, columna+1,"boleano",$1);}
     |  caracter
        { $$ = new NodoAST(yylineno+1, columna+1,"char",$1);}
     | identificador LISTA_DIMENSION   
      {
         $$ = new NodoAST(yylineno+1, columna+1,"idenD",$1);
         $$->add(*$2);
      }
;     


LISTA_IF: LISTA_IF SI
          {
            $$=$1;
            $$->add(*$2);
          }
        | SI
          {
            $$ = new NodoAST(yylineno+1, columna+1,"LISTA_IF","");
            $$->add(*$1);
          } 
;


SI: tk_if pari CONT_VALOR pard llavei LISTA_CUERPO  ELSE
       {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"IF",""); 
          nod->add(*$3);
          nod->add(*$6);
          nod->add(*$7);
          $$=nod;
       } 
    |tk_if pari CONT_VALOR pard llavei   ELSE  
    {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"IF",""); 
          nod->add(*$3); 
          nod->add(*$6);
          $$=nod;
    } 
;


ELSE: llaved tk_else SI
      {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"ELSE_IF",""); 
          nod->add(*$3);
          $$=nod;
      } 
    | llaved tk_else llavei LISTA_CUERPO llaved
      {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"ELSE",""); 
          nod->add(*$4);
          $$=nod;
      } 
    |  llaved  tk_else llavei  llaved
      {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"ELSE_VACIO :v","");
          $$=nod;
      } 
    | llaved
      {
          NodoAST *nod = new NodoAST(yylineno+1, columna+1,"LLAVE_QUE_CIERRA :v","");
          $$=nod;
      }
;




%%
