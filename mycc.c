#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20050813

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 4 "mycc.y"
#include "global.h"

#define MAXFUN 100
#define MAXFLD 100

static struct ClassFile cf;

/* stacks of symbol tables and offsets, depth is just 2 in C (global/local) */
static Table *tblptr[2];
static int offset[2];

/* stack pointers (index into tblptr[] and offset[]) */
static int tblsp = -1;
static int offsp = -1;

static Type return_type;

static char buffer[255];	

/* stack operations */
#define top_tblptr	(tblptr[tblsp])
#define top_offset	(offset[offsp])
#define push_tblptr(t)	(tblptr[++tblsp] = t)
#define push_offset(n)	(offset[++offsp] = n)
#define pop_tblptr	(tblsp--)
#define pop_offset	(offsp--)

/* flag to indicate we are compiling main's body (to differentiate 'return') */
static int is_in_main = 0;
/*
struct Expr
{
	Backpatchlist *truelist;
	Backpatchlist *falselist;
};

typedef struct Expr Expr;
*/
#line 45 "mycc.y"
typedef union
{ Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
  /*Expr exp;*/
} YYSTYPE;
#line 71 "mycc.c"
#define ID 257
#define INT8 258
#define INT16 259
#define INT32 260
#define FLT 261
#define STR 262
#define DO 263
#define ELSE 264
#define FLOAT 265
#define FOR 266
#define IF 267
#define INT 268
#define MAIN 269
#define RETURN 270
#define VOID 271
#define WHILE 272
#define BREAK 273
#define PA 274
#define NA 275
#define TA 276
#define DA 277
#define MA 278
#define AA 279
#define XA 280
#define OA 281
#define LA 282
#define RA 283
#define OR 284
#define AN 285
#define EQ 286
#define NE 287
#define LE 288
#define GE 289
#define LS 290
#define RS 291
#define PP 292
#define NN 293
#define AR 294
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    8,   10,    9,    9,    9,   12,   12,   14,   16,
   15,   17,   17,   13,    5,    5,    5,    7,    7,    6,
    6,   18,   18,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   21,   21,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,    1,    2,    3,    4,   22,   20,
};
short yylen[] = {                                         2,
    2,    0,    2,    2,    2,    0,    5,    7,    0,    0,
    4,    2,    0,    2,    1,    1,    1,    4,    2,    3,
    2,    2,    0,    1,    2,   10,    9,   11,   17,    3,
    2,    3,    2,    3,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    3,    2,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    4,    0,    0,    0,    0,    0,    0,
};
short yydefred[] = {                                      2,
    0,    6,    0,   17,   16,    0,   15,    0,    0,    4,
    5,    0,    0,   14,    0,    9,   10,   20,    0,    0,
   13,    7,    0,    0,    0,   19,    0,    0,    0,   12,
    0,    8,    0,   21,    0,    0,   77,   78,   79,   80,
   81,   84,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   23,   11,   24,    0,   22,    0,
   18,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,   76,    0,    0,    0,    0,    0,
   84,   31,   69,   70,   67,   68,   73,   74,    0,    0,
   72,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   25,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   30,    0,   71,   32,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   63,   64,   65,   82,    0,
    0,    0,    0,    0,    0,    0,   84,    0,    0,    0,
    0,   86,    0,   86,    0,   84,   86,   84,   86,    0,
   84,    0,    0,    0,   84,   27,    0,   84,    3,   26,
   28,    0,    0,   86,    0,   84,    0,   29,
};
short yydgoto[] = {                                       1,
    0,   77,  153,  166,    8,    9,   24,    2,    3,  175,
   59,   10,   11,   19,   22,   20,   25,   31,   60,  152,
  123,    0,
};
short yysindex[] = {                                      0,
    0,    0,  -61,    0,    0,  -34,    0, -253,  -43,    0,
    0,  -30,  -27,    0, -235,    0,    0,    0,  -84,  -51,
    0,    0, -214,  -17,  -51,    0,  -84,  -51, -207,    0,
  -33,    0, -201,    0,   -2,  255,    0,    0,    0,    0,
    0,    0,   25,   29,   51,   42,   19,   51,   51,   51,
   51, -169, -160,   51,    0,    0,    0, -156,    0,  125,
    0,    0,   51,   51,   51,   51,   51,   51,   51,   51,
   51,   51,   51,    0,    0,   51,   27,   51,   51,  156,
    0,    0,    0,    0,    0,    0,    0,    0,  280,  -15,
    0,   51,   51,   51,   51,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   51,   51,   51,   51,   51,    0,
  294,  294,  294,  294,  294,  294,  294,  294,  294,  294,
  294,  294,  -10, -155,  294,  294,    0,   51,    0,    0,
  325,  339,  360,  104,  413,  -28,  -28,  -28,  -28,  -28,
  -28,   38,   38,  153,  153,    0,    0,    0,    0,   51,
   72,   67,   87,  294,  294,   51,    0,   27,   88,  294,
   51,    0,   27,    0,  294,    0,    0,    0,    0, -128,
    0,   98,   84,   27,    0,    0,   89,    0,    0,    0,
    0,   51,  294,    0,  111,    0,   27,    0,
};
short yyrindex[] = {                                      0,
    0,    0,  159,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -39,  -12,   -4,   18,   79,   86,   96,  116,  117,  130,
  137,   32,    0,    0,  106,  128,    0,    0,    0,    0,
   54,   74,   30,    7,   20,  558,  601,  621,  632,  716,
  724,  450,  462,  421,  433,    0,    0,    0,    0,    0,
    0,    0,    0,  128,   75,    0,    0,    0,    0,  128,
    0,    0,    0,    0,  114,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  138,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,  633, -119, -131,  163,    0,    0,    0,    0,    0,
   48,    0,  155,    0,  165,    0,    0,  127,  878,   14,
    0,    0,
};
#define YYTABLESIZE 1060
short yytable[] = {                                      50,
   15,   36,   58,   13,   36,   12,   54,   21,  109,   48,
   16,   49,   17,  107,  105,   14,  106,   50,  108,   36,
   58,   18,   21,   27,   54,   57,   28,   48,   37,   49,
  149,   37,  168,  150,  159,  171,   38,  173,   21,   38,
  164,   23,   26,   57,   23,  169,   37,   51,   23,   34,
   51,   23,  185,   23,   38,   61,   62,   52,   39,   50,
   52,   39,   58,   52,   78,   51,   54,   23,   79,   48,
   50,   49,   35,   50,  109,   35,   39,   82,   52,  107,
  105,   81,  106,   50,  108,   57,   58,   87,   50,   55,
   54,   56,   51,   48,   48,   49,   88,   48,   47,   47,
   51,   91,   47,   47,   47,   47,   47,   55,   47,  130,
   51,  156,   48,   52,   49,   34,  151,   49,   34,   40,
   47,   47,   40,   47,  124,  157,   41,  158,  163,   41,
   51,   23,   49,   23,   23,  174,   42,   40,  177,   42,
  109,   96,  178,   52,   41,  107,  105,  181,  106,   55,
  108,  186,   51,   50,   42,   47,   43,   44,    1,   43,
   44,  109,   96,  100,   88,  102,  107,  105,   85,  106,
   45,  108,   85,   45,   43,   44,   51,   46,   88,   30,
   46,   90,   23,  110,  100,   47,  102,   29,   45,  109,
   33,   32,  109,   96,  107,   46,  184,  107,  105,  108,
  106,    0,  108,    4,    0,  162,    5,    6,    0,    7,
  167,    0,    0,    4,  127,  100,    5,  102,   95,    7,
    0,  179,   35,   36,   37,   38,   39,   40,   41,   42,
    0,    0,   43,   44,  188,    0,   45,    0,   46,   47,
   35,   36,   37,   38,   39,   40,   41,   42,   94,   95,
   43,   44,    0,    0,   45,    0,   46,   47,   52,   53,
    0,  103,  104,    0,   23,   23,   23,   23,   23,   23,
   23,   23,    0,    0,   23,   23,   52,   53,   23,   94,
   23,   23,   35,   36,   37,   38,   39,   40,   41,   42,
   51,   51,   43,   44,   76,    0,   45,    0,   46,   47,
   23,   23,    0,   52,   52,    0,    0,   36,   37,   38,
   39,   40,   41,   50,   50,   63,  109,   96,   52,   53,
  129,  107,  105,    0,  106,    0,  108,    0,    0,    0,
  109,   96,    0,    0,    0,  107,  105,   48,  106,  100,
  108,  102,   52,   53,    0,   47,   47,   47,   47,   47,
   47,   47,   47,  100,    0,  102,    0,   49,   49,    0,
    0,  109,   96,    0,    0,    0,  107,  105,    0,  106,
    0,  108,    0,   95,    0,  109,   96,    0,    0,    0,
  107,  105,    0,  106,  100,  108,  102,   95,    0,   97,
   98,   99,  101,  103,  104,    0,  109,   96,  100,    0,
  102,  107,  105,   94,  106,    0,  108,    0,   92,   93,
   97,   98,   99,  101,  103,  104,    0,   94,   95,  100,
    0,  102,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,    0,    0,    0,    0,   92,
   93,   97,   98,   99,  101,  103,  104,    0,   94,  109,
    0,    0,    0,   95,  107,  105,    0,  106,   61,  108,
    0,   61,   94,   61,   61,   61,    0,    0,    0,    0,
   62,    0,  100,   62,  102,   62,   62,   62,    0,   61,
   61,    0,   61,    0,    0,    0,    0,   59,    0,    0,
   59,   62,   62,   59,   62,    0,    0,    0,    0,   60,
    0,    0,   60,    0,    0,   60,    0,    0,   59,   59,
    0,   59,    0,    0,   61,    0,    0,    0,    0,    0,
   60,   60,    0,   60,    0,    0,   62,    0,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,    0,    0,
    0,    0,    0,   59,   61,    0,   74,   75,    0,    0,
    0,    0,    0,    0,    0,   60,   62,    0,    0,    0,
    0,    0,    0,   92,   93,   97,   98,   99,  101,  103,
  104,    0,    0,   59,    0,    0,    0,   92,   93,   97,
   98,   99,  101,  103,  104,   60,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   53,    0,    0,   53,    0,
    0,   53,    0,    0,    0,    0,    0,    0,    0,   93,
   97,   98,   99,  101,  103,  104,   53,   53,    0,   53,
    0,    0,    0,    0,   97,   98,   99,  101,  103,  104,
    0,    0,    0,    0,    0,    0,    0,    0,   54,    0,
    0,   54,    0,    0,   54,   97,   98,   99,  101,  103,
  104,   53,    0,    0,    0,    0,    0,    0,   57,   54,
   54,   57,   54,    0,   57,    0,    0,    0,    0,   55,
    0,    0,   55,    0,    0,   55,    0,    0,    0,   57,
   57,   53,   57,    0,    0,    0,    0,    0,    0,    0,
   55,   55,    0,   55,   54,    0,    0,    0,   97,   98,
   99,  101,  103,  104,   61,   61,   61,   61,   61,   61,
   61,   61,    0,  128,   57,    0,   62,   62,   62,   62,
   62,   62,   62,   62,   54,   55,    0,    0,    0,    0,
    0,    0,    0,   59,   59,   59,   59,   59,   59,   59,
   59,    0,    0,    0,   57,   60,   60,   60,   60,   60,
   60,   60,   60,   58,    0,   55,   58,    0,    0,   58,
    0,   56,    0,    0,   56,    0,    0,   56,    0,    0,
    0,    0,    0,    0,   58,   58,    0,   58,    0,    0,
    0,    0,   56,   56,    0,   56,    0,    0,    0,  161,
    0,    0,    0,    0,    0,    0,    0,    0,  170,    0,
  172,    0,    0,  176,    0,    0,    0,  180,    0,   58,
  182,    0,    0,    0,    0,    0,    0,   56,  187,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
    0,   53,   53,   53,   53,   53,   53,   56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   54,   54,   54,   54,   54,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   57,   57,   57,   57,   57,   57,
    0,    0,    0,    0,    0,   55,   55,   55,   55,   55,
   55,    0,   80,    0,    0,   83,   84,   85,   86,    0,
    0,   89,    0,    0,    0,    0,    0,    0,    0,    0,
  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,
  121,    0,    0,  122,    0,  125,  126,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  131,
  132,  133,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,  145,  146,  147,  148,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
   58,   58,   58,   58,   58,  154,    0,   56,   56,   56,
   56,   56,   56,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  155,    0,    0,
    0,    0,    0,  160,    0,    0,    0,    0,  165,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  183,
};
short yycheck[] = {                                      33,
   44,   41,   36,  257,   44,   40,   40,   44,   37,   43,
   41,   45,   40,   42,   43,   59,   45,   33,   47,   59,
   36,  257,   59,   41,   40,   59,   44,   43,   41,   45,
   41,   44,  164,   44,  154,  167,   41,  169,  123,   44,
  160,   33,  257,   59,   36,  165,   59,   41,   40,  257,
   44,   43,  184,   45,   59,  257,   59,   38,   41,   33,
   41,   44,   36,   44,   40,   59,   40,   59,   40,   43,
   41,   45,   41,   44,   37,   44,   59,   59,   59,   42,
   43,   40,   45,   33,   47,   59,   36,  257,   59,  123,
   40,  125,  126,   43,   41,   45,  257,   44,   37,   38,
   94,  258,   41,   42,   43,   44,   45,  123,   47,  125,
  126,   40,   59,   94,   41,   41,  272,   44,   44,   41,
   59,   60,   44,   62,   77,   59,   41,   41,   41,   44,
  124,  123,   59,  125,  126,  264,   41,   59,   41,   44,
   37,   38,   59,  124,   59,   42,   43,   59,   45,  123,
   47,   41,  126,  124,   59,   94,   41,   41,    0,   44,
   44,   37,   38,   60,   59,   62,   42,   43,   41,   45,
   41,   47,   59,   44,   59,   59,  126,   41,   41,   25,
   44,   55,   20,   59,   60,  124,   62,   25,   59,   37,
   28,   27,   37,   38,   42,   59,  183,   42,   43,   47,
   45,   -1,   47,  265,   -1,  158,  268,  269,   -1,  271,
  163,   -1,   -1,  265,   59,   60,  268,   62,   94,  271,
   -1,  174,  256,  257,  258,  259,  260,  261,  262,  263,
   -1,   -1,  266,  267,  187,   -1,  270,   -1,  272,  273,
  256,  257,  258,  259,  260,  261,  262,  263,  124,   94,
  266,  267,   -1,   -1,  270,   -1,  272,  273,  292,  293,
   -1,  290,  291,   -1,  256,  257,  258,  259,  260,  261,
  262,  263,   -1,   -1,  266,  267,  292,  293,  270,  124,
  272,  273,  256,  257,  258,  259,  260,  261,  262,  263,
  284,  285,  266,  267,   40,   -1,  270,   -1,  272,  273,
  292,  293,   -1,  284,  285,   -1,   -1,  257,  258,  259,
  260,  261,  262,  284,  285,   61,   37,   38,  292,  293,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,  284,   45,   60,
   47,   62,  292,  293,   -1,  284,  285,  286,  287,  288,
  289,  290,  291,   60,   -1,   62,   -1,  284,  285,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   94,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   60,   47,   62,   94,   -1,  286,
  287,  288,  289,  290,  291,   -1,   37,   38,   60,   -1,
   62,   42,   43,  124,   45,   -1,   47,   -1,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  124,   94,   60,
   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,  124,   37,
   -1,   -1,   -1,   94,   42,   43,   -1,   45,   38,   47,
   -1,   41,  124,   43,   44,   45,   -1,   -1,   -1,   -1,
   38,   -1,   60,   41,   62,   43,   44,   45,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   59,   60,   44,   62,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   59,   60,
   -1,   62,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   59,   60,   -1,   62,   -1,   -1,   94,   -1,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,   -1,   -1,
   -1,   -1,   -1,   94,  124,   -1,  292,  293,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   94,  124,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   -1,  124,   -1,   -1,   -1,  284,  285,  286,
  287,  288,  289,  290,  291,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,  289,  290,  291,   59,   60,   -1,   62,
   -1,   -1,   -1,   -1,  286,  287,  288,  289,  290,  291,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,
   -1,   41,   -1,   -1,   44,  286,  287,  288,  289,  290,
  291,   94,   -1,   -1,   -1,   -1,   -1,   -1,   38,   59,
   60,   41,   62,   -1,   44,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,   59,
   60,  124,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   -1,   62,   94,   -1,   -1,   -1,  286,  287,
  288,  289,  290,  291,  284,  285,  286,  287,  288,  289,
  290,  291,   -1,   81,   94,   -1,  284,  285,  286,  287,
  288,  289,  290,  291,  124,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   -1,   -1,  124,  284,  285,  286,  287,  288,
  289,  290,  291,   38,   -1,  124,   41,   -1,   -1,   44,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,  157,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  166,   -1,
  168,   -1,   -1,  171,   -1,   -1,   -1,  175,   -1,   94,
  178,   -1,   -1,   -1,   -1,   -1,   -1,   94,  186,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,  284,  285,  286,  287,  288,  289,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
   -1,   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,
  289,   -1,   45,   -1,   -1,   48,   49,   50,   51,   -1,
   -1,   54,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   73,   -1,   -1,   76,   -1,   78,   79,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   92,
   93,   94,   95,   96,   97,   98,   99,  100,  101,  102,
  103,  104,  105,  106,  107,  108,  109,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,
  285,  286,  287,  288,  289,  128,   -1,  284,  285,  286,
  287,  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  150,   -1,   -1,
   -1,   -1,   -1,  156,   -1,   -1,   -1,   -1,  161,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  182,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,"'$'","'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,
0,0,0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","INT8","INT16","INT32",
"FLT","STR","DO","ELSE","FLOAT","FOR","IF","INT","MAIN","RETURN","VOID","WHILE",
"BREAK","PA","NA","TA","DA","MA","AA","XA","OA","LA","RA","OR","AN","EQ","NE",
"LE","GE","LS","RS","PP","NN","AR",
};
char *yyrule[] = {
"$accept : prog",
"prog : Mprog exts",
"Mprog :",
"else_stmt : ELSE stmt",
"exts : exts func",
"exts : exts decl",
"exts :",
"func : MAIN '(' ')' Mmain block",
"func : type ID '(' Margs args ')' block",
"Mmain :",
"Margs :",
"block : '{' decls stmts '}'",
"decls : decls decl",
"decls :",
"decl : list ';'",
"type : VOID",
"type : INT",
"type : FLOAT",
"args : args ',' type ID",
"args : type ID",
"list : list ',' ID",
"list : type ID",
"stmts : stmts stmt",
"stmts :",
"stmt : ';'",
"stmt : expr ';'",
"stmt : IF '(' expr M ')' stmt N L else_stmt L",
"stmt : WHILE '(' L expr M ')' stmt N L",
"stmt : DO L stmt WHILE '(' expr M N L ')' ';'",
"stmt : FOR '(' expr O ';' L expr M N ';' L expr O N ')' L stmt",
"stmt : RETURN expr ';'",
"stmt : BREAK ';'",
"stmt : '{' stmts '}'",
"stmt : error ';'",
"exprs : exprs ',' expr",
"exprs : expr",
"expr : ID '=' expr",
"expr : ID PA expr",
"expr : ID NA expr",
"expr : ID TA expr",
"expr : ID DA expr",
"expr : ID MA expr",
"expr : ID AA expr",
"expr : ID XA expr",
"expr : ID OA expr",
"expr : ID LA expr",
"expr : ID RA expr",
"expr : ID",
"expr : expr OR expr",
"expr : expr AN expr",
"expr : expr '|' expr",
"expr : expr '^' expr",
"expr : expr '&' expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr LE expr",
"expr : expr GE expr",
"expr : expr LS expr",
"expr : expr RS expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '%' expr",
"expr : '!' expr",
"expr : '~' expr",
"expr : '+' expr",
"expr : '-' expr",
"expr : '(' expr ')'",
"expr : '$' INT8",
"expr : PP ID",
"expr : NN ID",
"expr : ID PP",
"expr : ID NN",
"expr : INT8",
"expr : INT16",
"expr : INT32",
"expr : FLT",
"expr : STR",
"expr : ID '(' exprs ')'",
"K :",
"L :",
"M :",
"N :",
"P :",
"O :",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 718 "mycc.y"

int main(int argc, char **argv)
{
	// init the compiler
	init();

	// set up a new class file structure
	init_ClassFile(&cf);

	// class has public access
	cf.access = ACC_PUBLIC;

	// class name is "Code"
	cf.name = "Code";

	// field counter (incremented for each field we add)
	cf.field_count = 0;

	// method counter (incremented for each method we add)
	cf.method_count = 0;

	// allocate an array of MAXFLD fields
	cf.fields = (struct FieldInfo*)malloc(MAXFLD * sizeof(struct FieldInfo));

	// allocate an array of MAXFUN methods
	cf.methods = (struct MethodInfo*)malloc(MAXFUN * sizeof(struct MethodInfo));

	if (!cf.methods)
		error("Out of memory");

	if (argc > 1)
		if (!(yyin = fopen(argv[1], "r")))
			error("Cannot open file for reading");

	if (yyparse() || errnum > 0)
		error("Compilation errors: class file not saved");

	fprintf(stderr, "Compilation successful: saving %s.class\n", cf.name);

	// save class file
	save_classFile(&cf);

	return 0;
}

#line 613 "mycc.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 93 "mycc.y"
{ addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
break;
case 2:
#line 99 "mycc.y"
{ push_tblptr(mktable(NULL));
			  push_offset(0);
			}
break;
case 3:
#line 104 "mycc.y"
{}
break;
case 7:
#line 112 "mycc.y"
{ /* need a temporary table pointer*/
			  printf("main func\n");
			  Table *table;
			  /* the type of main is a JVM type descriptor*/
			  Type type = mkfun("[Ljava/lang/String;", "V");

			  /* emit the epilogue part of main()*/
			  emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
			  emit(iload_2);
			  emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
			  emit(return_);
			  /* method has public access and is static*/
			  cf.methods[cf.method_count].access = ACC_PUBLIC | ACC_STATIC;
			  /* method name is "main"*/

			  cf.methods[cf.method_count].name = "main";
			  /* method descriptor of "void main(String[] arg)"*/
			  cf.methods[cf.method_count].descriptor = type;
			  /* local variables*/
			  cf.methods[cf.method_count].max_locals = top_offset;
			  /* max operand stack size of this method*/
			  cf.methods[cf.method_count].max_stack = 100;
			  /* length of bytecode is in the emitter's pc variable*/
			  cf.methods[cf.method_count].code_length = pc;
			  /* must copy code to make it persistent*/
			  cf.methods[cf.method_count].code = copy_code();
			  if (!cf.methods[cf.method_count].code)
				error("Out of memory");
			  /* advance to next method to store in method array*/
			  cf.method_count++;
			  if (cf.method_count > MAXFUN)
			  	error("Max number of functions exceeded");
			  /* add width information to table*/
			  table = top_tblptr;
			  addwidth(table, top_offset);
			  /* exit the local scope by popping*/
			  pop_tblptr;
			  pop_offset;
			  /* enter the function in the global table*/
			  enterproc(top_tblptr, yyvsp[-4].sym, type, table);
			  printf("main func exit\n");
			}
break;
case 8:
#line 155 "mycc.y"
{  /* TASK 3: TO BE COMPLETED */
			  Table *table;
              /* the type of function is a JVM type descriptor*/
              Type type = mkfun(yyvsp[-2].typ, yyvsp[-6].typ);

              /* method has public access and is static*/
              cf.methods[cf.method_count].access = ACC_PUBLIC | ACC_STATIC;

              /* method name is ID*/
              cf.methods[cf.method_count].name = yyvsp[-5].sym->lexptr;
              cf.methods[cf.method_count].descriptor = type;
              cf.methods[cf.method_count].code_length = pc;

              /* must copy code to make it persistent*/
              cf.methods[cf.method_count].code = copy_code();

              if (!cf.methods[cf.method_count].code)
                error("Out of memory");

              cf.methods[cf.method_count].max_stack = 100;
	       	  cf.methods[cf.method_count].max_locals = top_offset;

              /* advance to next method to store in method array*/
              cf.method_count++;
              if (cf.method_count > MAXFUN)
                error("Max number of functions exceeded");

              table = top_tblptr;
              addwidth(table, top_offset);

              pop_tblptr;
              pop_offset;

              enterproc(top_tblptr, yyvsp[-5].sym->lexptr, type, table);
			  printf("func exit\n");
	    }
break;
case 9:
#line 199 "mycc.y"
{ int label1, label2;

			  Table *table;
			  /* create new table for local scope of main()*/
			  table = mktable(top_tblptr);
			  /* push it to create new scope*/
			  push_tblptr(table);
			  /* for main(), we must start with offset 3 in the local variables of the frame*/
			  push_offset(3);
			  /* init code block to store stmts*/
			  init_code();
			  /* emit the prologue part of main()*/
			  emit(aload_0);
			  emit(arraylength);
			  emit2(newarray, T_INT);
			  emit(astore_1);
			  emit(iconst_0);
			  emit(istore_2);
			  label1 = pc;
			  emit(iload_2);
			  emit(aload_0);
			  emit(arraylength);
			  label2 = pc;
			  emit3(if_icmpge, PAD);
			  emit(aload_1);
			  emit(iload_2);
			  emit(aload_0);
			  emit(iload_2);
			  emit(aaload);
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I"));
			  emit(iastore);
			  emit32(iinc, 2, 1);
			  emit3(goto_, label1 - pc);
			  backpatch(label2, pc - label2);
			  /* global flag to indicate we're in main()*/
			  is_in_main = 1;
			  printf("Mmain exit\n");
			}
break;
case 10:
#line 240 "mycc.y"
{ /* TASK 3: TO BE COMPLETED */
			  Table *table = mktable(top_tblptr);
			  push_tblptr(table);
              push_offset(0);

			  init_code();
			  is_in_main = 0;
			  printf("margs exit\n");
	    		}
break;
case 11:
#line 260 "mycc.y"
{
	printf("block exit\n");
}
break;
case 15:
#line 273 "mycc.y"
{ yyval.typ = mkvoid(); }
break;
case 16:
#line 274 "mycc.y"
{ yyval.typ = mkint(); }
break;
case 17:
#line 275 "mycc.y"
{ yyval.typ = mkfloat(); }
break;
case 18:
#line 279 "mycc.y"
{ enter(top_tblptr, yyvsp[0].sym, yyvsp[-1].typ, top_offset++);
			  yyval.typ = mkpair(yyvsp[-3].typ, yyvsp[-1].typ);
			}
break;
case 19:
#line 282 "mycc.y"
{ enter(top_tblptr, yyvsp[0].sym, yyvsp[-1].typ, top_offset++);
			  yyval.typ = yyvsp[-1].typ;
			}
break;
case 20:
#line 287 "mycc.y"
{ /* TASK 1 and 4: TO BE COMPLETED */
			if (top_tblptr->level == 0)
			{
				cf.fields[cf.field_count].access = ACC_STATIC;			
				cf.fields[cf.field_count].name = yyvsp[0].sym->lexptr;		
				cf.fields[cf.field_count].descriptor = yyvsp[-2].typ;
		    	cf.field_count++;
				enter(top_tblptr, yyvsp[0].sym, yyvsp[-2].typ, constant_pool_add_Fieldref(&cf, cf.name, yyvsp[0].sym->lexptr, yyvsp[-2].typ));
			}
			else
			{
			  printf("list, local var = %s\n", yyvsp[0].sym->lexptr);
			  enter(top_tblptr, yyvsp[0].sym, yyvsp[-2].typ, top_offset++);
			}

		    yyval.typ = yyvsp[-2].typ;
	 	}
break;
case 21:
#line 304 "mycc.y"
{ /* TASK 1 and 4: TO BE COMPLETED */
            if (top_tblptr->level == 0)
            {
                cf.fields[cf.field_count].access = ACC_STATIC;
                cf.fields[cf.field_count].name = yyvsp[0].sym->lexptr;
                cf.fields[cf.field_count].descriptor = yyvsp[-1].typ;
                cf.field_count++;
                enter(top_tblptr, yyvsp[0].sym, yyvsp[-1].typ, constant_pool_add_Fieldref(&cf, cf.name, yyvsp[0].sym->lexptr, yyvsp[-1].typ));
            }
            else
			{
				printf("local var = %s\n", yyvsp[0].sym->lexptr);
			 	enter(top_tblptr, yyvsp[0].sym, yyvsp[-1].typ, top_offset++);
			}

			yyval.typ = yyvsp[-1].typ;
		}
break;
case 25:
#line 329 "mycc.y"
{ emit(pop); /* does not leave a value on the stack */ }
break;
case 26:
#line 334 "mycc.y"
{   backpatch(yyvsp[-6].loc, yyvsp[-2].loc - yyvsp[-6].loc); 
                    backpatch(yyvsp[-3].loc, yyvsp[0].loc - yyvsp[-3].loc); }
break;
case 27:
#line 337 "mycc.y"
{ backpatch(yyvsp[-4].loc, yyvsp[0].loc - yyvsp[-4].loc); 
        	                 backpatch(yyvsp[-1].loc, yyvsp[-6].loc - yyvsp[-1].loc); }
break;
case 28:
#line 340 "mycc.y"
{ backpatch(yyvsp[-4].loc, yyvsp[-2].loc - yyvsp[-4].loc); backpatch(yyvsp[-3].loc, yyvsp[-9].loc - yyvsp[-3].loc); }
break;
case 29:
#line 342 "mycc.y"
{ 
				backpatch(yyvsp[-8].loc, yyvsp[-1].loc - yyvsp[-8].loc);  
				emit3(goto_, yyvsp[-6].loc-pc); 
				backpatch(yyvsp[-9].loc, pc - yyvsp[-9].loc);
			    backpatch(yyvsp[-3].loc, yyvsp[-11].loc - yyvsp[-3].loc); 
                                  }
break;
case 30:
#line 349 "mycc.y"
{ 

				if (is_in_main)
			  		emit(istore_2);
			    else 
			  		emit(ireturn);
/*
			    else if (isint(return_type) && isint($2.type))
			  	emit(ireturn);
			    else if (isint(return_type) && isint($2.type))
			  	emit(freturn);
			    else
			  	error("Type error");
*/
			}
break;
case 31:
#line 364 "mycc.y"
{ /* BREAK is optional to implement */
			  error("break not implemented");
			}
break;
case 32:
#line 368 "mycc.y"
{
			printf("stmts exit\n");
		}
break;
case 33:
#line 371 "mycc.y"
{ yyerrok; }
break;
case 36:
#line 379 "mycc.y"
{ 
				printf("%s = expr, \n", yyvsp[-2].sym->lexptr);
			    int place = getplace(top_tblptr, yyvsp[-2].sym);
			    emit(dup);
			    if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
			    {
				/*if (isfloat($3.type)*/
				/*	emit2(f2i); */
				if (getlevel(top_tblptr, yyvsp[-2].sym) == 0) 
					emit3(putstatic, place); 
				else
					emit2(istore, place); 
                               }
			    else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
			    {
				/*if (isint($3.type))*/
				/*	emit2(i2f); */
				if (getlevel(top_tblptr, yyvsp[-2].sym) == 0) 
					emit3(putstatic, place); 
				else
					emit2(fstore, place); 

				emit2(fstore, place); 
			    }
			   else 
				error("Type error");

			    /*$$.type = $3.type;*/
	 }
break;
case 37:
#line 408 "mycc.y"
{ 

		  int place;
            	  if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            	   }

			emit(iadd); 
			emit(dup); 

            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
            	place = getplace(top_tblptr, yyvsp[-2].sym);
            	if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                	emit2(istore, place);
            	else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
              }
	 }
break;
case 38:
#line 430 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(swap); emit(isub); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 39:
#line 450 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(imul); emit(dup); 
			/*emit2(istore, $1->localvar); */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 40:
#line 470 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
                }
	     emit(swap); emit(idiv); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 41:
#line 490 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(swap); emit(irem); emit(dup); 
			/*emit2(istore, $1->localvar); */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 42:
#line 510 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(iand); emit(dup); 
			emit2(istore, yyvsp[-2].sym->localvar);  
		  }
break;
case 43:
#line 523 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(swap); emit(ixor); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 44:
#line 543 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(swap); emit(ior); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 45:
#line 563 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
            }
			emit(swap); emit(ishl); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
            }
		  }
break;
case 46:
#line 583 "mycc.y"
{ 
			/*emit2(iload, $1->localvar); */
            int place;
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                 place = getplace(top_tblptr, yyvsp[-2].sym);
                 if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                     emit2(fload, place);
               }
            emit(swap); emit(ishr); emit(dup); 
			/*emit2(istore, $1->localvar);  */
            if (getlevel(top_tblptr, yyvsp[-2].sym) == 1) {
                place = getplace(top_tblptr, yyvsp[-2].sym);
                if (isint(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, yyvsp[-2].sym)))
                    emit2(fstore, place);
                }
           }
break;
case 47:
#line 603 "mycc.y"
{ int place;

		printf("id start\n");
		if (getlevel(top_tblptr, yyvsp[0].sym) == 0)
		{
			emit3( getstatic, getplace(top_tblptr, yyvsp[0].sym));
		}
               else
		{
               		place = getplace(top_tblptr, yyvsp[0].sym);
                    		if (isint(gettype(top_tblptr, yyvsp[0].sym)))
                    			emit2(iload, place);
				else if (isfloat(gettype(top_tblptr, yyvsp[0].sym)))
                        		emit2(fload, place);
		}
		printf("id exit\n");
	 }
break;
case 48:
#line 620 "mycc.y"
{ emit(ior); }
break;
case 49:
#line 621 "mycc.y"
{ emit(iand); }
break;
case 50:
#line 622 "mycc.y"
{ emit(ior); }
break;
case 51:
#line 623 "mycc.y"
{ emit(ixor); }
break;
case 52:
#line 624 "mycc.y"
{ emit(iand); }
break;
case 53:
#line 625 "mycc.y"
{ emit3(if_icmpeq,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
break;
case 54:
#line 626 "mycc.y"
{ emit3(if_icmpne,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
break;
case 55:
#line 627 "mycc.y"
{ emit3(if_icmplt,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
break;
case 56:
#line 628 "mycc.y"
{ emit3(if_icmpgt,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1);  }
break;
case 57:
#line 629 "mycc.y"
{ emit3(if_icmple,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
break;
case 58:
#line 630 "mycc.y"
{ emit3(if_icmpge,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
break;
case 59:
#line 631 "mycc.y"
{ emit(ishl); }
break;
case 60:
#line 632 "mycc.y"
{ emit(ishr); }
break;
case 61:
#line 633 "mycc.y"
{	 
		/*if (iseq($1->type, $3->type))*/
		/*{*/

			/*if (isint($1->type))*/
			    emit(iadd);
			/*else*/
			  /*  emit(fadd);*/
		/*}*/
		/*else*/
	/*	{*/
	/*	}*/

		/*$$.type = $1.type;*/
	   }
break;
case 62:
#line 648 "mycc.y"
{ emit(isub); }
break;
case 63:
#line 649 "mycc.y"
{ emit(imul); }
break;
case 64:
#line 650 "mycc.y"
{ emit(idiv); }
break;
case 65:
#line 651 "mycc.y"
{ emit(irem); }
break;
case 66:
#line 652 "mycc.y"
{ emit(irem); }
break;
case 67:
#line 660 "mycc.y"
{ error("! operator not implemented"); }
break;
case 68:
#line 661 "mycc.y"
{ error("~ operator not implemented"); }
break;
case 69:
#line 663 "mycc.y"
{ error("unary + operator not implemented"); }
break;
case 70:
#line 665 "mycc.y"
{ emit(ineg); }
break;
case 72:
#line 667 "mycc.y"
{ /* check that we are in main()*/
			  if (is_in_main)
			  {	
			    emit(aload_1);
			  	emit2(bipush, yyvsp[0].num);
			  	emit(iaload);
			  }
			  else
			  	error("invalid use of $# in function");
			}
break;
case 73:
#line 677 "mycc.y"
{ emit2(iload, yyvsp[0].sym->localvar); emit2(bipush, 1); emit(iadd); emit(dup); emit2(istore, yyvsp[0].sym->localvar); }
break;
case 74:
#line 678 "mycc.y"
{ emit2(iload, yyvsp[0].sym->localvar); emit2(bipush, 1); emit(isub); emit(dup); emit2(istore, yyvsp[0].sym->localvar); }
break;
case 75:
#line 679 "mycc.y"
{ emit2(iload, yyvsp[-1].sym->localvar); emit(dup); emit2(bipush, 1); emit(iadd); emit2(istore, yyvsp[-1].sym->localvar); }
break;
case 76:
#line 680 "mycc.y"
{  emit2(iload, yyvsp[-1].sym->localvar); emit(dup); emit2(bipush, 1); emit(isub); emit2(istore, yyvsp[-1].sym->localvar); }
break;
case 77:
#line 681 "mycc.y"
{ printf("INT8 = %d\n", yyvsp[0].num); emit2(bipush, yyvsp[0].num); }
break;
case 78:
#line 682 "mycc.y"
{ printf("INT16\n"); emit3(sipush, yyvsp[0].num); }
break;
case 79:
#line 683 "mycc.y"
{ printf("INT32\n"); emit2(ldc, constant_pool_add_Integer(&cf, yyvsp[0].num)); }
break;
case 80:
#line 684 "mycc.y"
{ error("float constant not supported"); }
break;
case 81:
#line 685 "mycc.y"
{ /* We do not need to implement strings: */
			  error("string constant not supported");
			}
break;
case 82:
#line 689 "mycc.y"
{
			  printf("ID ( exprs ), cf.name=%s, %s %s\n",cf.name, yyvsp[-3].sym->lexptr, gettype(top_tblptr, yyvsp[-3].sym));
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, yyvsp[-3].sym->lexptr, /*gettype(top_tblptr, $1)*/ "(I)I"));
			  printf("exit ID ( exprs )\n");

			  /*$$.type = mkret(gettype(top_tblptr, $1));*/
			}
break;
case 83:
#line 698 "mycc.y"
{ yyval.loc = pc; emit3(ifne, 0); }
break;
case 84:
#line 701 "mycc.y"
{ yyval.loc = pc; }
break;
case 85:
#line 704 "mycc.y"
{ yyval.loc = pc; emit3(ifeq, 0); }
break;
case 86:
#line 707 "mycc.y"
{ yyval.loc = pc; emit3(goto_, 0); }
break;
case 87:
#line 710 "mycc.y"
{ emit(pop); }
break;
case 88:
#line 713 "mycc.y"
{ emit(pop); }
break;
#line 1544 "mycc.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
