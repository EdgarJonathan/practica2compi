/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.yy" /* yacc.c:339  */



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



#line 88 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tk_int = 258,
    tk_double = 259,
    tk_bool = 260,
    tk_char = 261,
    tk_string = 262,
    tk_not = 263,
    tk_igual = 264,
    tk_menorque = 265,
    tk_mayorque = 266,
    tk_or = 267,
    tk_and = 268,
    tk_igualacion = 269,
    tk_diferenciacion = 270,
    tk_menorigual = 271,
    tk_mayorigual = 272,
    aumento = 273,
    decremento = 274,
    cori = 275,
    cord = 276,
    coma = 277,
    identificador = 278,
    entero = 279,
    decimal = 280,
    caracter = 281,
    booleano = 282,
    cadena = 283,
    pari = 284,
    pard = 285,
    suma = 286,
    menos = 287,
    multi = 288,
    division = 289,
    potencia = 290,
    puntocoma = 291,
    llavei = 292,
    llaved = 293,
    tk_arreglo = 294,
    tk_imprimir = 295,
    tk_show = 296,
    tk_if = 297,
    tk_else = 298,
    tk_para = 299,
    tk_repetir = 300,
    UMINUS = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parser.yy" /* yacc.c:355  */


//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class NodoAST *nodito;



#line 184 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   121,   127,   134,   138,   143,   147,   151,
     155,   159,   163,   171,   176,   183,   191,   196,   203,   210,
     219,   224,   231,   240,   252,   256,   264,   269,   277,   288,
     290,   292,   299,   304,   311,   319,   324,   331,   340,   345,
     352,   362,   367,   375,   383,   390,   398,   409,   414,   421,
     426,   434,   439,   448,   453,   458,   463,   468,   477,   483,
     493,   498,   504,   509,   514,   519,   524,   529,   534,   538,
     543,   548,   553,   558,   563,   566,   569,   574,   580,   584,
     586,   588,   590,   592,   594,   596,   604,   609,   618,   626,
     636,   642,   648,   653
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tk_int", "tk_double", "tk_bool",
  "tk_char", "tk_string", "tk_not", "tk_igual", "tk_menorque",
  "tk_mayorque", "tk_or", "tk_and", "tk_igualacion", "tk_diferenciacion",
  "tk_menorigual", "tk_mayorigual", "aumento", "decremento", "cori",
  "cord", "coma", "identificador", "entero", "decimal", "caracter",
  "booleano", "cadena", "pari", "pard", "suma", "menos", "multi",
  "division", "potencia", "puntocoma", "llavei", "llaved", "tk_arreglo",
  "tk_imprimir", "tk_show", "tk_if", "tk_else", "tk_para", "tk_repetir",
  "UMINUS", "$accept", "INICIO", "LISTA_CUERPO", "CUERPO", "LISTA_AUMENTO",
  "AUMENTO", "LISTA_REPETIR", "REPETIR", "LISTA_FOR", "FOR", "FOR_COND",
  "LISTA_MOSTRAR", "MOSTRAR", "VALOR_TITULO", "LISTA_IMPRIMIR", "IMPRIMIR",
  "LISTA_ASIGNACION", "ASIGNACION", "LISTA_VAR", "VAR",
  "LISTA_DECLARACION", "DECLARACION", "ARRAY", "LISTA_FILA",
  "LISTA_DIMENSION", "TIPO_DATO", "LISTA_ID", "CONT_VALOR", "OPERACION",
  "VALOR", "LISTA_IF", "SI", "ELSE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     350,   -90,   -90,   -90,   -90,   -90,   -12,   -90,   -90,   -90,
     -90,   -90,   443,   443,   -10,    16,    47,    49,    60,   109,
     350,   -90,   443,   -90,    75,   -90,    78,   -90,   116,   -90,
     119,   -90,   443,   -90,    -3,   -90,   129,   -90,    18,   472,
     352,   -90,   128,   -90,   443,   141,   403,   130,   443,    87,
     443,    11,   443,   -90,   -90,   -90,   352,   -90,   -90,   -90,
     -90,   -90,   446,   443,   -90,   -90,   -90,   139,    99,   443,
     443,   443,   443,   443,   443,   443,   443,   -90,   -90,   443,
     443,   443,   443,   443,   -90,   -90,    93,   443,   -90,    83,
     -12,   -90,   149,   386,   443,   -90,   -90,   394,   -90,   -11,
     443,   156,   -90,   -90,   480,    36,   -90,   -90,   -90,   -90,
     120,   120,    67,    67,   130,   -90,   421,   147,   141,   443,
     150,    48,   151,    12,    56,   -90,   -90,   -90,   415,   140,
     443,   170,   152,   -90,   -90,   154,   143,   140,   -90,   428,
     -90,   200,   155,   -90,   114,   -90,   163,   -90,   443,    66,
     230,   -90,   260,    69,   472,   164,   173,   -90,   290,   -90,
     320,   443,   -90,   443,   -90,   -90,   -90,   472,    79,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    55,    56,    54,    57,    53,    79,    81,    82,    84,
      83,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,    12,    14,    11,    17,    10,    21,     8,    27,
       7,    33,     6,    36,     0,    39,     5,    42,     0,    40,
      68,    78,     9,    87,     0,    85,     0,    74,     0,     0,
       0,     0,     0,     1,     3,    13,     0,    16,    20,    26,
      32,    35,    68,     0,    37,    41,    59,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
       0,     0,     0,     0,    15,    86,     0,     0,    75,     0,
      29,    30,     0,     0,     0,    24,    25,     0,    38,     0,
       0,     0,    63,    62,    61,    60,    66,    67,    65,    64,
      69,    70,    71,    72,    73,    52,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    58,    51,    34,     0,     0,
       0,     0,     0,    45,    43,     0,    93,     0,    89,     0,
      19,     0,     0,    28,     0,    88,     0,    18,     0,     0,
       0,    90,     0,     0,    50,     0,     0,    92,     0,    23,
       0,     0,    48,     0,    46,    91,    22,    49,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -75,   -18,   -90,   169,   -90,   189,   -90,   190,
     -90,   -90,   191,   -90,   -90,   187,   -90,    -9,   -90,   157,
     -90,    54,   -90,    55,   -89,   -90,   172,   -45,     0,   -90,
     -90,   -38,    84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      94,    28,    29,    92,    30,    31,    32,    33,    34,    35,
      36,    37,   149,   153,    45,    38,    68,    39,    62,    41,
      42,    43,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,   118,    54,    89,    85,    93,    63,    97,    44,    44,
     123,   101,    46,    47,     1,     2,     3,     4,     5,    48,
      40,   132,    56,    61,   102,   103,   104,   105,   106,   107,
     108,   109,    87,    64,     6,     7,     8,     9,    10,    11,
      12,    66,    95,    13,    86,    49,    69,    70,   133,   121,
      73,    74,    75,    76,   137,   124,   141,    67,    69,    70,
      71,    72,    73,    74,    75,    76,    69,    70,    71,    72,
      73,    74,    75,    76,   128,   158,    50,   160,    51,   110,
     111,   112,   113,   114,   130,    77,    78,   116,   155,    52,
      65,   161,   134,    69,    70,    71,    72,    73,    74,    75,
      76,   161,    83,   154,   156,    96,   151,   162,   100,    53,
      90,    77,    78,   117,   115,    91,   167,   169,   154,    54,
      18,   101,    17,    54,    79,    80,    81,    82,    83,    40,
     139,    40,     1,     2,     3,     4,     5,    40,    77,    78,
      54,    40,    54,     1,     2,     3,     4,     5,    77,    78,
      40,   150,    40,    81,    82,    83,    16,    15,    40,    14,
      40,    87,    66,     6,     7,     8,     9,    10,    11,    12,
      16,   119,    13,     1,     2,     3,     4,     5,   136,   125,
      14,    15,    16,   127,    17,    18,   144,   129,   131,   142,
     143,    55,   148,     6,     7,     8,     9,    10,    11,    12,
     152,   163,    13,     1,     2,     3,     4,     5,   140,   164,
      14,    15,    16,    57,    17,    18,    58,    60,   168,    59,
      98,   145,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     1,     2,     3,     4,     5,   147,    99,
      14,    15,    16,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     1,     2,     3,     4,     5,   157,     0,
      14,    15,    16,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     1,     2,     3,     4,     5,   159,     0,
      14,    15,    16,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     1,     2,     3,     4,     5,   165,     0,
      14,    15,    16,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,     1,     2,     3,     4,     5,   166,     0,
      14,    15,    16,     0,    17,    18,     0,     0,     0,     0,
      77,    78,     0,     6,     7,     8,     9,    10,    11,    12,
       0,     0,    13,    79,    80,    81,    82,    83,    84,     0,
      14,    15,    16,     0,    17,    18,    69,    70,    71,    72,
      73,    74,    75,    76,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,   120,     0,     0,     0,
       0,    77,    78,     0,   122,    69,    70,    71,    72,    73,
      74,    75,    76,    88,    79,    80,    81,    82,    83,    77,
      78,     0,   126,     0,     0,   135,    77,    78,     0,     0,
       0,     0,    79,    80,    81,    82,    83,     0,   146,    79,
      80,    81,    82,    83,    77,    78,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,     0,    79,    80,    81,
      82,    83,    69,    70,    71,    72,    73,    74,    75,    76,
      69,    70,     0,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
       0,    90,    20,    48,    42,    50,     9,    52,    20,    20,
      99,    22,    12,    13,     3,     4,     5,     6,     7,    29,
      20,     9,    22,    32,    69,    70,    71,    72,    73,    74,
      75,    76,    20,    36,    23,    24,    25,    26,    27,    28,
      29,    23,    51,    32,    44,    29,    10,    11,    36,    94,
      14,    15,    16,    17,   129,   100,   131,    39,    10,    11,
      12,    13,    14,    15,    16,    17,    10,    11,    12,    13,
      14,    15,    16,    17,   119,   150,    29,   152,    29,    79,
      80,    81,    82,    83,    36,    18,    19,    87,    22,    29,
      36,    22,    36,    10,    11,    12,    13,    14,    15,    16,
      17,    22,    35,   148,    38,    51,   144,    38,     9,     0,
      23,    18,    19,    30,    21,    28,   161,    38,   163,   137,
      45,    22,    44,   141,    31,    32,    33,    34,    35,   129,
     130,   131,     3,     4,     5,     6,     7,   137,    18,    19,
     158,   141,   160,     3,     4,     5,     6,     7,    18,    19,
     150,    37,   152,    33,    34,    35,    42,    41,   158,    40,
     160,    20,    23,    23,    24,    25,    26,    27,    28,    29,
      42,    22,    32,     3,     4,     5,     6,     7,    38,    23,
      40,    41,    42,    36,    44,    45,    43,    37,    37,    37,
      36,    22,    37,    23,    24,    25,    26,    27,    28,    29,
      37,    37,    32,     3,     4,     5,     6,     7,    38,    36,
      40,    41,    42,    24,    44,    45,    26,    30,   163,    28,
      63,   137,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,     7,    38,    67,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,     7,    38,    -1,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,     7,    38,    -1,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,     7,    38,    -1,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,     3,     4,     5,     6,     7,    38,    -1,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      18,    19,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    31,    32,    33,    34,    35,    36,    -1,
      40,    41,    42,    -1,    44,    45,    10,    11,    12,    13,
      14,    15,    16,    17,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    18,    19,    -1,    30,    10,    11,    12,    13,    14,
      15,    16,    17,    30,    31,    32,    33,    34,    35,    18,
      19,    -1,    21,    -1,    -1,    30,    18,    19,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    -1,    30,    31,
      32,    33,    34,    35,    18,    19,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    31,    32,    33,
      34,    35,    10,    11,    12,    13,    14,    15,    16,    17,
      10,    11,    -1,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    23,    24,    25,    26,
      27,    28,    29,    32,    40,    41,    42,    44,    45,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    72,    74,
      75,    76,    77,    78,    20,    71,    75,    75,    29,    29,
      29,    29,    29,     0,    50,    52,    75,    54,    56,    59,
      62,    64,    75,     9,    36,    68,    23,    39,    73,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    31,
      32,    33,    34,    35,    36,    78,    75,    20,    30,    74,
      23,    28,    60,    74,    57,    64,    68,    74,    66,    73,
       9,    22,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    21,    75,    30,    71,    22,
      30,    74,    30,    71,    74,    23,    21,    36,    74,    37,
      36,    37,     9,    36,    36,    30,    38,    49,    79,    75,
      38,    49,    37,    36,    43,    79,    30,    38,    37,    69,
      37,    78,    37,    70,    74,    22,    38,    38,    49,    38,
      49,    22,    38,    37,    36,    38,    38,    74,    70,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      60,    60,    61,    61,    62,    63,    63,    64,    65,    65,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     1,     7,     6,
       2,     1,    10,     9,     1,     1,     2,     1,     7,     1,
       1,     2,     2,     1,     5,     2,     1,     2,     3,     1,
       1,     2,     1,     5,     2,     5,     9,     5,     3,     3,
       1,     4,     3,     1,     1,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     7,     6,
       3,     5,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 117 "parser.yy" /* yacc.c:1646  */
    { raiz =(yyval.nodito);}
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 122 "parser.yy" /* yacc.c:1646  */
    {
                (yyval.nodito)=(yyvsp[-1].nodito);
                (yyval.nodito)->add(*(yyvsp[0].nodito));
              }
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "parser.yy" /* yacc.c:1646  */
    {
                (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"INICIO","");
                (yyval.nodito)->add(*(yyvsp[0].nodito));
              }
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 144 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 152 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 172 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1667 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 177 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_AUMENTO","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1676 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
          }
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 192 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_REPETIR","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-6]).first_line, (yylsp[-6]).first_column,"REPETIR","");
                nod->add(*(yyvsp[-4].nodito)); 
                nod->add(*(yyvsp[-1].nodito));
                (yyval.nodito)=nod;
             }
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-5]).first_line, (yylsp[-5]).first_column,"REPETIR","");
                nod->add(*(yyvsp[-3].nodito));
                (yyval.nodito)=nod;
             }
#line 1723 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 220 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito)=(yyvsp[-1].nodito);
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_FOR","");
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 1741 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-9]).first_line, (yylsp[-9]).first_column,"FOR","");
                nod->add(*(yyvsp[-7].nodito)); 
                nod->add(*(yyvsp[-6].nodito));
                nod->add(*(yyvsp[-4].nodito));
                nod->add(*(yyvsp[-1].nodito));
                (yyval.nodito)=nod;
        }
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 241 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-8]).first_line, (yylsp[-8]).first_column,"FOR","");
                nod->add(*(yyvsp[-6].nodito)); 
                nod->add(*(yyvsp[-5].nodito));
                nod->add(*(yyvsp[-3].nodito));
                (yyval.nodito)=nod;
        }
#line 1766 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 257 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
          }
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 265 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 270 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_MOSTRAR","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 278 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-6]).first_line, (yylsp[-6]).first_column,"SHOW","");
                nod->add(*(yyvsp[-4].nodito)); 
                nod->add(*(yyvsp[-2].nodito));
                (yyval.nodito)=nod;
          }
#line 1811 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 289 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"iden",(yyvsp[0].TEXT));}
#line 1817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 291 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"cadena",(yyvsp[0].TEXT));}
#line 1823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 293 "parser.yy" /* yacc.c:1646  */
    {
                  (yyval.nodito) = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"iden",(yyvsp[-1].TEXT));
                  (yyval.nodito)->add(*(yyvsp[0].nodito));
               }
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 305 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_IMPRIMIR","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 312 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"IMPRIMIR",""); 
                nod->add(*(yyvsp[-2].nodito));
                (yyval.nodito)=nod;
           }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 320 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 325 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_ASIGNACION","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 332 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"ASIGNACION",""); 
                nod->add(*(yyvsp[-1].nodito)); 
                (yyval.nodito)=nod;
            }
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 341 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito)=(yyvsp[-2].nodito);
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 346 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_VAR","");
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 353 "parser.yy" /* yacc.c:1646  */
    {
          (yyval.nodito)=(yyvsp[0].nodito);
       }
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1923 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 368 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_DECLARACION","");
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                  }
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 376 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"DECLARACIONVAR",""); 
                nod->add(*(yyvsp[-4].nodito)); 
                nod->add(*(yyvsp[-3].nodito)); 
                nod->add(*(yyvsp[-1].nodito));
                (yyval.nodito)=nod;
              }
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 384 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"DECLARACIONVAR",""); 
                nod->add(*(yyvsp[-1].nodito)); 
                nod->add(*(yyvsp[0].nodito));
                (yyval.nodito)=nod;
              }
#line 1955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 391 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"DECLARACIONARRAY",""); 
                nod->add(*(yyvsp[-4].nodito)); 
                nod->add(*(yyvsp[-2].nodito)); 
                nod->add(*(yyvsp[-1].nodito));
                (yyval.nodito)=nod;
              }
#line 1967 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 399 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-8]).first_line, (yylsp[-8]).first_column,"DECLARACIONARRAY",""); 
                nod->add(*(yyvsp[-8].nodito)); 
                nod->add(*(yyvsp[-6].nodito)); 
                nod->add(*(yyvsp[-5].nodito));
                nod->add(*(yyvsp[-2].nodito));
                (yyval.nodito)=nod;
              }
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 410 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-4].nodito);
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 1989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 415 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) =  new NodoAST((yylsp[-2]).first_line, (yylsp[-2]).first_column,"Array","");
            (yyval.nodito)->add(*(yyvsp[-1].nodito));
        }
#line 1998 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 422 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito)=(yyvsp[-2].nodito);
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 2007 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 427 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito) =  new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"Fila","");
              (yyval.nodito)->add(*(yyvsp[0].nodito));
            }
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 435 "parser.yy" /* yacc.c:1646  */
    {
                     (yyval.nodito)=(yyvsp[-3].nodito);
                     (yyval.nodito)->add(*(yyvsp[-1].nodito));
                  }
#line 2025 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 440 "parser.yy" /* yacc.c:1646  */
    {
                    (yyval.nodito) =  new NodoAST((yylsp[-2]).first_line, (yylsp[-2]).first_column,"Lista_Dimension","");
                    (yyval.nodito)->add(*(yyvsp[-1].nodito));
                  }
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 449 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"tk_string",(yyvsp[0].TEXT)); 
                (yyval.nodito)=nod;
            }
#line 2043 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 454 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"tk_bool",(yyvsp[0].TEXT)); 
                (yyval.nodito)=nod;
            }
#line 2052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 459 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"tk_int",(yyvsp[0].TEXT));
                (yyval.nodito)=nod;
            }
#line 2061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 464 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"tk_double",(yyvsp[0].TEXT));
                (yyval.nodito)=nod;
            }
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 469 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"tk_char",(yyvsp[0].TEXT));
                (yyval.nodito)=nod;
            }
#line 2079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 478 "parser.yy" /* yacc.c:1646  */
    {
              (yyval.nodito)=(yyvsp[-2].nodito);
              NodoAST *nodo = new NodoAST((yylsp[-2]).first_line, (yylsp[-2]).first_column,"Iden",(yyvsp[0].TEXT));
              (yyval.nodito)->add(*nodo);
            }
#line 2089 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 484 "parser.yy" /* yacc.c:1646  */
    {
                (yyval.nodito) =  new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"Lista_ID","");
                NodoAST *nodo = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"Iden",(yyvsp[0].TEXT));
                (yyval.nodito)->add(*nodo);
            }
#line 2099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 494 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"and",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2108 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 499 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"or",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2117 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 505 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"mayorque",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2126 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 510 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"menorque",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 515 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"mayorigual",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 520 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"menorigual",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 525 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"asignacions",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2162 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 530 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"diferenciacion",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2171 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 539 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-2]).first_line, (yylsp[-2]).first_column,"suma",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 544 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"resta",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 549 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"por",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2198 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 554 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"div",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 559 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"potencia",(yyvsp[-1].TEXT)); 
                nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;
            }
#line 2216 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 564 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"menos",(yyvsp[-1].TEXT)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 567 "parser.yy" /* yacc.c:1646  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2228 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 570 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"aumento",(yyvsp[0].TEXT)); 
                nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)=nod;
            }
#line 2237 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 575 "parser.yy" /* yacc.c:1646  */
    {
                NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"decremento",(yyvsp[0].TEXT)); 
                nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)=nod;
            }
#line 2246 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 581 "parser.yy" /* yacc.c:1646  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2252 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 585 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"iden",(yyvsp[0].TEXT));}
#line 2258 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 587 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"cadena",(yyvsp[0].TEXT));}
#line 2264 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 589 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"entero",(yyvsp[0].TEXT));}
#line 2270 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 591 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"decimal",(yyvsp[0].TEXT));}
#line 2276 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 593 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"boleano",(yyvsp[0].TEXT));}
#line 2282 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 595 "parser.yy" /* yacc.c:1646  */
    { (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"char",(yyvsp[0].TEXT));}
#line 2288 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 597 "parser.yy" /* yacc.c:1646  */
    {
         (yyval.nodito) = new NodoAST((yylsp[-1]).first_line, (yylsp[-1]).first_column,"iden",(yyvsp[-1].TEXT));
         (yyval.nodito)->add(*(yyvsp[0].nodito));
      }
#line 2297 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 605 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito)=(yyvsp[-1].nodito);
            (yyval.nodito)->add(*(yyvsp[0].nodito));
          }
#line 2306 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 610 "parser.yy" /* yacc.c:1646  */
    {
            (yyval.nodito) = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LISTA_IF","");
            (yyval.nodito)->add(*(yyvsp[0].nodito));
          }
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 619 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[-6]).first_line, (yylsp[-6]).first_column,"IF",""); 
          nod->add(*(yyvsp[-4].nodito));
          nod->add(*(yyvsp[-1].nodito));
          nod->add(*(yyvsp[0].nodito));
          (yyval.nodito)=nod;
       }
#line 2327 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 627 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[-5]).first_line, (yylsp[-5]).first_column,"IF",""); 
          nod->add(*(yyvsp[-3].nodito)); 
          nod->add(*(yyvsp[0].nodito));
          (yyval.nodito)=nod;
    }
#line 2338 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 637 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[-2]).first_line, (yylsp[-2]).first_column,"ELSE_IF",""); 
          nod->add(*(yyvsp[0].nodito));
          (yyval.nodito)=nod;
      }
#line 2348 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 643 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[-4]).first_line, (yylsp[-4]).first_column,"ELSE",""); 
          nod->add(*(yyvsp[-1].nodito));
          (yyval.nodito)=nod;
      }
#line 2358 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 649 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[-3]).first_line, (yylsp[-3]).first_column,"ELSE_VACIO :v","");
          (yyval.nodito)=nod;
      }
#line 2367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 654 "parser.yy" /* yacc.c:1646  */
    {
          NodoAST *nod = new NodoAST((yylsp[0]).first_line, (yylsp[0]).first_column,"LLAVE_QUE_CIERRA :v","");
          (yyval.nodito)=nod;
      }
#line 2376 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2380 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 661 "parser.yy" /* yacc.c:1906  */

