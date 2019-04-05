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
%token<TEXT> tk_show;
%token<TEXT> tk_if;
%token<TEXT> tk_else;
%token<TEXT> tk_para tk_repetir;




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
%type<nodito> OPERACION;
%type<nodito> LISTA_MOSTRAR;
%type<nodito> MOSTRAR;
%type<nodito> VALOR_TITULO;
%type<nodito> LISTA_IF;
%type<nodito> ELSE;
%type<nodito> SI;
%type<nodito> LISTA_FOR;
%type<nodito> LISTA_REPETIR;
%type<nodito> REPETIR;
%type<nodito> FOR;
%type<nodito> FOR_COND;
%type<nodito> LISTA_AUMENTO;
%type<nodito> AUMENTO;


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
        | LISTA_AUMENTO  
          {
            $$=$1;
          }
;



LISTA_AUMENTO: LISTA_AUMENTO AUMENTO
                {
                    $$=$1;
                    $$->add(*$2);
                }
             | AUMENTO
                {
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_AUMENTO","");
                    $$->add(*$1);
                }
;

AUMENTO: OPERACION puntocoma
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
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_REPETIR","");
                    $$->add(*$1);
                } 
;

REPETIR: tk_repetir pari CONT_VALOR pard llavei LISTA_CUERPO llaved
             {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"REPETIR","");
                nod->add(*$3); 
                nod->add(*$6);
                $$=nod;
             }
       | tk_repetir pari CONT_VALOR pard llavei              llaved
             {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"REPETIR","");
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
              $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_FOR","");
              $$->add(*$1);
            }
;

FOR:  tk_para pari FOR_COND  CONT_VALOR puntocoma OPERACION pard llavei LISTA_CUERPO llaved
        {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"FOR","");
                nod->add(*$3); 
                nod->add(*$4);
                nod->add(*$6);
                nod->add(*$9);
                $$=nod;
        }
     |tk_para pari FOR_COND  CONT_VALOR puntocoma OPERACION pard llavei              llaved
        {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"FOR","");
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
                    $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_MOSTRAR","");
                    $$->add(*$1);
                }  
;


MOSTRAR: tk_show pari VALOR_TITULO coma CONT_VALOR pard puntocoma
          {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"SHOW","");
                nod->add(*$3); 
                nod->add(*$5);
                $$=nod;
          }
;



VALOR_TITULO: identificador
              { $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);}
            | cadena
              { $$ = new NodoAST(@1.first_line, @1.first_column,"cadena",$1);}
            | identificador LISTA_DIMENSION  
               {
                  $$ = new NodoAST(@1.first_line, @1.first_column,"iden",$1);
                  $$->add(*$2);
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


LISTA_DIMENSION: LISTA_DIMENSION cori OPERACION cord
                  {
                     $$=$1;
                     $$->add(*$3);
                  }
               | cori OPERACION cord  
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
          | OPERACION;
          
;          

OPERACION: OPERACION suma OPERACION
            {
                NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"suma",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | OPERACION menos OPERACION
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"resta",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | OPERACION multi OPERACION
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"por",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | OPERACION division OPERACION
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"div",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | OPERACION potencia OPERACION
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"potencia",$2); 
                nod->add(*$1); nod->add(*$3); $$=nod;
            }
          | menos OPERACION %prec UMINUS
                { $$ = new NodoAST(@1.first_line, @1.first_column,"menos",$1); $$->add(*$2);}

          | pari OPERACION pard
            {$$=$2;}

          | OPERACION aumento
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"aumento",$2); 
                nod->add(*$1); $$=nod;
            }
          | OPERACION decremento
            {
                NodoAST *nod = new NodoAST(@2.first_line, @2.first_column,"decremento",$2); 
                nod->add(*$1); $$=nod;
            }

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


LISTA_IF: LISTA_IF SI
          {
            $$=$1;
            $$->add(*$2);
          }
        | SI
          {
            $$ = new NodoAST(@1.first_line, @1.first_column,"LISTA_IF","");
            $$->add(*$1);
          } 
;



SI: tk_if pari CONT_VALOR pard llavei LISTA_CUERPO  ELSE
       {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"IF",""); 
          nod->add(*$3);
          nod->add(*$6);
          nod->add(*$7);
          $$=nod;
       } 
    |tk_if pari CONT_VALOR pard llavei   ELSE  
    {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"IF",""); 
          nod->add(*$3); 
          nod->add(*$6);
          $$=nod;
    } 
;


ELSE: llaved tk_else SI
      {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"ELSE_IF",""); 
          nod->add(*$3);
          $$=nod;
      } 
    | llaved tk_else llavei LISTA_CUERPO llaved
      {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"ELSE",""); 
          nod->add(*$4);
          $$=nod;
      } 
    |  llaved  tk_else llavei  llaved
      {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"ELSE_VACIO :v","");
          $$=nod;
      } 
    | llaved
      {
          NodoAST *nod = new NodoAST(@1.first_line, @1.first_column,"LLAVE_QUE_CIERRA :v","");
          $$=nod;
      }
;


%%
