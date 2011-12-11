
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "mycc.y"

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


/* Line 189 of yacc.c  */
#line 113 "mycc.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INT8 = 259,
     INT16 = 260,
     INT32 = 261,
     FLT = 262,
     STR = 263,
     DO = 264,
     ELSE = 265,
     FLOAT = 266,
     FOR = 267,
     IF = 268,
     INT = 269,
     MAIN = 270,
     RETURN = 271,
     VOID = 272,
     WHILE = 273,
     BREAK = 274,
     RA = 275,
     LA = 276,
     OA = 277,
     XA = 278,
     AA = 279,
     MA = 280,
     DA = 281,
     TA = 282,
     NA = 283,
     PA = 284,
     OR = 285,
     AN = 286,
     GE = 287,
     LE = 288,
     NE = 289,
     EQ = 290,
     RS = 291,
     LS = 292,
     NN = 293,
     PP = 294,
     AR = 295
   };
#endif
/* Tokens.  */
#define ID 258
#define INT8 259
#define INT16 260
#define INT32 261
#define FLT 262
#define STR 263
#define DO 264
#define ELSE 265
#define FLOAT 266
#define FOR 267
#define IF 268
#define INT 269
#define MAIN 270
#define RETURN 271
#define VOID 272
#define WHILE 273
#define BREAK 274
#define RA 275
#define LA 276
#define OA 277
#define XA 278
#define AA 279
#define MA 280
#define DA 281
#define TA 282
#define NA 283
#define PA 284
#define OR 285
#define AN 286
#define GE 287
#define LE 288
#define NE 289
#define EQ 290
#define RS 291
#define LS 292
#define NN 293
#define PP 294
#define AR 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 44 "mycc.y"
 Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
  //Expr exp;



/* Line 214 of yacc.c  */
#line 240 "mycc.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 252 "mycc.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,    61,    48,    35,     2,
      55,    56,    46,    44,    60,    45,    53,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
      36,    20,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    33,    58,    50,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    38,    39,    40,
      41,    42,    43,    51,    52,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    16,    17,    23,
      31,    32,    33,    38,    41,    42,    45,    47,    49,    51,
      56,    59,    63,    66,    69,    70,    72,    75,    86,    96,
     108,   126,   130,   133,   137,   140,   144,   146,   150,   154,
     158,   162,   166,   170,   174,   178,   182,   186,   190,   192,
     196,   200,   204,   208,   212,   216,   220,   224,   228,   232,
     236,   240,   244,   248,   252,   256,   260,   264,   268,   271,
     274,   277,   280,   284,   287,   290,   293,   296,   299,   301,
     303,   305,   307,   309,   311,   316,   321,   322,   323,   324
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    66,    -1,    -1,    10,    77,    -1,
      66,    67,    -1,    66,    72,    -1,    -1,    15,    55,    56,
      68,    70,    -1,    73,     3,    55,    69,    74,    56,    70,
      -1,    -1,    -1,    57,    71,    76,    58,    -1,    71,    72,
      -1,    -1,    75,    59,    -1,    17,    -1,    14,    -1,    11,
      -1,    74,    60,    73,     3,    -1,    73,     3,    -1,    75,
      60,     3,    -1,    73,     3,    -1,    76,    77,    -1,    -1,
      59,    -1,    79,    59,    -1,    13,    55,    79,    81,    56,
      77,    82,    80,    65,    80,    -1,    18,    55,    80,    79,
      81,    56,    77,    82,    80,    -1,     9,    80,    77,    18,
      55,    79,    81,    82,    80,    56,    59,    -1,    12,    55,
      79,    83,    59,    80,    79,    81,    82,    59,    80,    79,
      83,    82,    56,    80,    77,    -1,    16,    79,    59,    -1,
      19,    59,    -1,    57,    76,    58,    -1,     1,    59,    -1,
      78,    60,    79,    -1,    79,    -1,     3,    20,    79,    -1,
       3,    30,    79,    -1,     3,    29,    79,    -1,     3,    28,
      79,    -1,     3,    27,    79,    -1,     3,    26,    79,    -1,
       3,    25,    79,    -1,     3,    24,    79,    -1,     3,    23,
      79,    -1,     3,    22,    79,    -1,     3,    21,    79,    -1,
       3,    -1,    79,    31,    79,    -1,    79,    32,    79,    -1,
      79,    33,    79,    -1,    79,    34,    79,    -1,    79,    35,
      79,    -1,    79,    41,    79,    -1,    79,    40,    79,    -1,
      79,    36,    79,    -1,    79,    37,    79,    -1,    79,    39,
      79,    -1,    79,    38,    79,    -1,    79,    43,    79,    -1,
      79,    42,    79,    -1,    79,    44,    79,    -1,    79,    45,
      79,    -1,    79,    46,    79,    -1,    79,    47,    79,    -1,
      79,    48,    79,    -1,    79,    48,    79,    -1,    49,    79,
      -1,    50,    79,    -1,    44,    79,    -1,    45,    79,    -1,
      55,    79,    56,    -1,    61,     4,    -1,    52,     3,    -1,
      51,     3,    -1,     3,    52,    -1,     3,    51,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     3,    55,    78,    56,    -1,     3,    55,    74,    56,
      -1,    -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    97,   102,   104,   105,   106,   109,   148,
     197,   236,   254,   257,   258,   261,   264,   265,   266,   269,
     273,   278,   294,   311,   312,   316,   317,   319,   324,   327,
     329,   335,   349,   352,   353,   356,   357,   361,   389,   411,
     431,   451,   471,   491,   504,   524,   544,   564,   584,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   628,   629,   630,   631,   632,   640,   641,
     642,   644,   646,   647,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   668,   674,   684,   687,   690,   696
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT8", "INT16", "INT32", "FLT",
  "STR", "DO", "ELSE", "FLOAT", "FOR", "IF", "INT", "MAIN", "RETURN",
  "VOID", "WHILE", "BREAK", "'='", "RA", "LA", "OA", "XA", "AA", "MA",
  "DA", "TA", "NA", "PA", "OR", "AN", "'|'", "'^'", "'&'", "'<'", "'>'",
  "GE", "LE", "NE", "EQ", "RS", "LS", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "'~'", "NN", "PP", "'.'", "AR", "'('", "')'", "'{'", "'}'", "';'",
  "','", "'$'", "$accept", "prog", "Mprog", "else_stmt", "exts", "func",
  "Mmain", "Margs", "block", "decls", "decl", "type", "args", "list",
  "stmts", "stmt", "exprs", "expr", "L", "M", "N", "O", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   124,    94,    38,    60,    62,   287,   288,
     289,   290,   291,   292,    43,    45,    42,    47,    37,    33,
     126,   293,   294,    46,   295,    40,    41,   123,   125,    59,
      44,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    66,    66,    67,    67,
      68,    69,    70,    71,    71,    72,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    81,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     0,     5,     7,
       0,     0,     4,     2,     0,     2,     1,     1,     1,     4,
       2,     3,     2,     2,     0,     1,     2,    10,     9,    11,
      17,     3,     2,     3,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     0,     0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     7,     1,     2,    18,    17,     0,    16,     5,
       6,     0,     0,     0,    22,    15,     0,    10,    11,    21,
       0,     0,    14,     8,     0,     0,    24,    20,     0,     0,
      13,     0,     0,     9,     0,    22,     0,    48,    79,    80,
      81,    82,    83,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    12,    25,     0,
      23,     0,    19,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    76,     0,     0,     0,
       0,     0,    86,    32,    70,    71,    68,    69,    75,    74,
       0,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    37,    47,    46,    45,    44,    43,    42,    41,
      40,    39,    38,     0,     0,    36,     0,    89,    87,    31,
       0,    72,    33,    49,    50,    51,    52,    53,    56,    57,
      59,    58,    55,    54,    61,    60,    62,    63,    64,    65,
      66,    85,    84,     0,     0,     0,     0,    87,    35,     0,
      86,     0,     0,    87,     0,    88,     0,    88,    87,    86,
      88,    86,    88,     0,    86,     0,     0,     0,    86,    28,
       0,    86,     4,    27,    29,     0,    89,    88,     0,    86,
       0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   178,     4,     9,    20,    21,    23,    26,
      10,    24,    25,    12,    32,    60,   124,    61,    78,   156,
     169,   155
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
     -99,     1,   -99,   -99,    64,   -99,   -99,   -47,   -99,   -99,
     -99,    27,    51,   -10,    13,   -99,    70,   -99,   -99,   -99,
      30,    66,   -99,   -99,    95,    26,    66,   -99,    30,    66,
     -99,   100,   118,   -99,   102,   -99,    53,    15,   -99,   -99,
     -99,   -99,   -99,   -99,    60,    61,   229,    65,    69,   229,
     229,   229,   229,   126,   129,   229,   -99,   -99,   -99,   131,
     -99,   260,   -99,   -99,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   -99,   -99,   214,   196,   229,
     229,   289,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     318,   137,   -99,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   -99,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,    40,    48,   344,   115,   344,   344,   -99,
     229,   -99,   -99,   361,   377,   392,   406,   419,   -31,   -31,
     -31,   -31,   -31,   -31,    47,    47,   111,   111,   -99,   -99,
     -99,   -99,   -99,   229,    92,    89,    96,   344,   344,   229,
     -99,   196,    98,   344,   229,   -99,   196,   -99,   344,   -99,
     -99,   -99,   -99,   141,   -99,   104,   105,   196,   -99,   -99,
     106,   -99,   -99,   -99,   -99,   229,   344,   -99,   110,   -99,
     196,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   133,   -99,
     145,     3,    97,   -99,   116,   -76,   -99,   -46,   -72,   -92,
     -98,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      81,     3,   126,    84,    85,    86,    87,    11,    13,    90,
     130,   104,   105,   106,   107,   108,   109,   110,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    31,
      14,   125,    34,   127,   128,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    17,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   162,    75,    76,    18,   171,
      77,   167,   174,    19,   176,     5,   172,     5,     6,     7,
       6,     8,    28,     8,   157,   165,    29,    22,   164,   188,
     170,   106,   107,   108,   109,   110,   151,   173,    27,   175,
      29,   182,   179,    35,   152,    62,   183,   158,   153,   185,
      15,    16,    63,   163,   191,    79,    80,   190,   168,    36,
      82,    37,    38,    39,    40,    41,    42,    43,    83,    88,
      44,    45,    89,   154,    46,    92,    47,    48,    36,   186,
      37,    38,    39,    40,    41,    42,    43,   159,   160,    44,
      45,   177,   161,    46,   166,    47,    48,   108,   109,   110,
     180,    33,    49,    50,   181,   184,   189,    51,    52,    53,
      54,    30,    91,    55,   123,    56,    57,    58,   187,    59,
       0,    49,    50,     0,     0,     0,    51,    52,    53,    54,
       0,     0,    55,     0,    56,   132,    58,    36,    59,    37,
      38,    39,    40,    41,    42,    43,     0,     0,    44,    45,
       0,     0,    46,     0,    47,    48,     0,    37,    38,    39,
      40,    41,    42,     0,     0,     5,     0,     0,     6,     0,
       0,     8,    37,    38,    39,    40,    41,    42,     0,     0,
      49,    50,     0,     0,     0,    51,    52,    53,    54,     0,
       0,    55,     0,    56,     0,    58,     0,    59,    49,    50,
       0,     0,     0,    51,    52,    53,    54,     0,     0,    55,
       0,     0,     0,    49,    50,    59,     0,     0,    51,    52,
      53,    54,     0,     0,    55,     0,     0,     0,     0,     0,
      59,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   131,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      46,     0,    78,    49,    50,    51,    52,     4,    55,    55,
      82,    42,    43,    44,    45,    46,    47,    48,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    26,
       3,    77,    29,    79,    80,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    56,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   157,    51,    52,    55,   167,
      55,   163,   170,     3,   172,    11,   168,    11,    14,    15,
      14,    17,    56,    17,   130,   161,    60,    57,   160,   187,
     166,    44,    45,    46,    47,    48,    56,   169,     3,   171,
      60,   177,   174,     3,    56,     3,   178,   153,    60,   181,
      59,    60,    59,   159,   190,    55,    55,   189,   164,     1,
      55,     3,     4,     5,     6,     7,     8,     9,    59,     3,
      12,    13,     3,    18,    16,     4,    18,    19,     1,   185,
       3,     4,     5,     6,     7,     8,     9,    55,    59,    12,
      13,    10,    56,    16,    56,    18,    19,    46,    47,    48,
      56,    28,    44,    45,    59,    59,    56,    49,    50,    51,
      52,    26,    56,    55,    77,    57,    58,    59,   186,    61,
      -1,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    57,    58,    59,     1,    61,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      -1,    -1,    16,    -1,    18,    19,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    -1,    -1,    14,    -1,
      -1,    17,     3,     4,     5,     6,     7,     8,    -1,    -1,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    -1,
      -1,    55,    -1,    57,    -1,    59,    -1,    61,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    44,    45,    61,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,    66,    11,    14,    15,    17,    67,
      72,    73,    75,    55,     3,    59,    60,    56,    55,     3,
      68,    69,    57,    70,    73,    74,    71,     3,    56,    60,
      72,    73,    76,    70,    73,     3,     1,     3,     4,     5,
       6,     7,     8,     9,    12,    13,    16,    18,    19,    44,
      45,    49,    50,    51,    52,    55,    57,    58,    59,    61,
      77,    79,     3,    59,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    51,    52,    55,    80,    55,
      55,    79,    55,    59,    79,    79,    79,    79,     3,     3,
      79,    76,     4,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    59,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    74,    78,    79,    77,    79,    79,    59,
      80,    56,    58,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    56,    56,    60,    18,    83,    81,    79,    79,    55,
      59,    56,    81,    79,    80,    77,    56,    81,    79,    82,
      77,    82,    81,    80,    82,    80,    82,    10,    65,    80,
      56,    59,    77,    80,    59,    80,    79,    83,    82,    56,
      80,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 91 "mycc.y"
    { addwidth(top_tblptr, top_offset);
			  pop_tblptr;
			  pop_offset;
			}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 97 "mycc.y"
    { push_tblptr(mktable(NULL));
			  push_offset(0);
			}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 102 "mycc.y"
    {}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "mycc.y"
    { // need a temporary table pointer
			  Table *table;
			  // the type of main is a JVM type descriptor
			  Type type = mkfun("[Ljava/lang/String;", "V");
			  // emit the epilogue part of main()
			  emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
			  emit(iload_2);
			  emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
			  emit(return_);
			  // method has public access and is static
			  cf.methods[cf.method_count].access = ACC_PUBLIC | ACC_STATIC;
			  // method name is "main"
			  cf.methods[cf.method_count].name = "main";
			  // method descriptor of "void main(String[] arg)"
			  cf.methods[cf.method_count].descriptor = type;
			  // local variables
			  cf.methods[cf.method_count].max_locals = top_offset;
			  // max operand stack size of this method
			  cf.methods[cf.method_count].max_stack = 100;
			  // length of bytecode is in the emitter's pc variable
			  cf.methods[cf.method_count].code_length = pc;
			  // must copy code to make it persistent
			  cf.methods[cf.method_count].code = copy_code();
			  if (!cf.methods[cf.method_count].code)
				error("Out of memory");
			  // advance to next method to store in method array
			  cf.method_count++;
			  if (cf.method_count > MAXFUN)
			  	error("Max number of functions exceeded");
			  // add width information to table
			  table = top_tblptr;
			  addwidth(table, top_offset);
			  // exit the local scope by popping
			  pop_tblptr;
			  pop_offset;
			  // enter the function in the global table
			  enterproc(top_tblptr, (yyvsp[(1) - (5)].sym), type, table);
			}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 149 "mycc.y"
    {  /* TASK 3: TO BE COMPLETED */
		Table *table;
              // the type of function is a JVM type descriptor
              Type type = mkfun((yyvsp[(5) - (7)].typ), (yyvsp[(1) - (7)].typ));

              emit3(getstatic, constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;"));
              emit(iload_2);
              emit3(invokevirtual, constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V"));
              emit(return_);

              // method has public access and is static
              cf.methods[cf.method_count].access = ACC_PUBLIC | ACC_STATIC;

              // method name is ID
              cf.methods[cf.method_count].name = (yyvsp[(2) - (7)].sym);
              cf.methods[cf.method_count].descriptor = type;
              cf.methods[cf.method_count].code_length = pc;

              // must copy code to make it persistent
              cf.methods[cf.method_count].code = copy_code();

              if (!cf.methods[cf.method_count].code)
                error("Out of memory");

              cf.methods[cf.method_count].max_stack = 100;
	       cf.methods[cf.method_count].max_locals = top_offset;

              // advance to next method to store in method array
              cf.method_count++;
              if (cf.method_count > MAXFUN)
                error("Max number of functions exceeded");

              table = top_tblptr;
              addwidth(table, top_offset);

              pop_tblptr;
              pop_offset;

              enterproc(top_tblptr, (yyvsp[(2) - (7)].sym), type, table);
	    }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 197 "mycc.y"
    { int label1, label2;
			  Table *table;
			  // create new table for local scope of main()
			  table = mktable(top_tblptr);
			  // push it to create new scope
			  push_tblptr(table);
			  // for main(), we must start with offset 3 in the local variables of the frame
			  push_offset(3);
			  // init code block to store stmts
			  init_code();
			  // emit the prologue part of main()
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
			  // global flag to indicate we're in main()
			  is_in_main = 1;
			}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 236 "mycc.y"
    { /* TASK 3: TO BE COMPLETED */
			  Table *table = mktable(top_tblptr);
			  push_tblptr(table);
              		  push_offset(0);

			  init_code();
			  is_in_main = 0;
	    		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 264 "mycc.y"
    { (yyval.typ) = mkvoid(); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 265 "mycc.y"
    { (yyval.typ) = mkint(); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 266 "mycc.y"
    { (yyval.typ) = mkfloat(); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 270 "mycc.y"
    { enter(top_tblptr, (yyvsp[(4) - (4)].sym), (yyvsp[(3) - (4)].typ), top_offset++);
			  (yyval.typ) = mkpair((yyvsp[(1) - (4)].typ), (yyvsp[(3) - (4)].typ));
			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 273 "mycc.y"
    { enter(top_tblptr, (yyvsp[(2) - (2)].sym), (yyvsp[(1) - (2)].typ), top_offset++);
			  (yyval.typ) = (yyvsp[(1) - (2)].typ);
			}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 278 "mycc.y"
    { /* TASK 1 and 4: TO BE COMPLETED */
			if (top_tblptr->level == 0)
			{
				cf.fields[cf.field_count].access = ACC_STATIC;			
				cf.fields[cf.field_count].name = (yyvsp[(3) - (3)].sym)->lexptr;		
				cf.fields[cf.field_count].descriptor = (yyvsp[(1) - (3)].typ);
			    	cf.field_count++;
				enter(top_tblptr, (yyvsp[(1) - (3)].typ), (yyvsp[(3) - (3)].sym), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[(3) - (3)].sym)->lexptr, (yyvsp[(1) - (3)].typ)));
			}
			else
			{
			  enter(top_tblptr, (yyvsp[(1) - (3)].typ), (yyvsp[(3) - (3)].sym), top_offset);
			}

		    (yyval.typ) = (yyvsp[(1) - (3)].typ);
	 	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 294 "mycc.y"
    { /* TASK 1 and 4: TO BE COMPLETED */
            if (top_tblptr->level == 0)
            {
                cf.fields[cf.field_count].access = ACC_STATIC;
                cf.fields[cf.field_count].name = (yyvsp[(2) - (2)].sym)->lexptr;
                cf.fields[cf.field_count].descriptor = (yyvsp[(1) - (2)].typ);
                cf.field_count++;
                enter(top_tblptr, (yyvsp[(2) - (2)].sym), (yyvsp[(1) - (2)].typ), constant_pool_add_Fieldref(&cf, cf.name, (yyvsp[(2) - (2)].sym)->lexptr, (yyvsp[(1) - (2)].typ)));
            }
            else
			{
			 	enter(top_tblptr, (yyvsp[(2) - (2)].sym), (yyvsp[(1) - (2)].typ), top_offset++);
			}
			 (yyval.typ) = (yyvsp[(1) - (2)].typ);
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 317 "mycc.y"
    { emit(pop); /* does not leave a value on the stack */ }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 322 "mycc.y"
    {   backpatch((yyvsp[(4) - (10)].loc), (yyvsp[(8) - (10)].loc) - (yyvsp[(4) - (10)].loc)); 
                    backpatch((yyvsp[(7) - (10)].loc), (yyvsp[(10) - (10)].loc) - (yyvsp[(7) - (10)].loc)); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 325 "mycc.y"
    { backpatch((yyvsp[(5) - (9)].loc), (yyvsp[(9) - (9)].loc) - (yyvsp[(5) - (9)].loc)); 
        	                 backpatch((yyvsp[(8) - (9)].loc), (yyvsp[(3) - (9)].loc) - (yyvsp[(8) - (9)].loc)); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 328 "mycc.y"
    { backpatch((yyvsp[(7) - (11)].loc), (yyvsp[(9) - (11)].loc) - (yyvsp[(7) - (11)].loc)); backpatch((yyvsp[(8) - (11)].loc), (yyvsp[(2) - (11)].loc) - (yyvsp[(8) - (11)].loc)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 330 "mycc.y"
    { backpatch((yyvsp[(9) - (17)].loc), (yyvsp[(16) - (17)].loc) - (yyvsp[(9) - (17)].loc));  
				emit3(goto_,(yyvsp[(11) - (17)].loc)-pc); 
				backpatch((yyvsp[(8) - (17)].loc), pc - (yyvsp[(8) - (17)].loc));
			       backpatch((yyvsp[(14) - (17)].loc), (yyvsp[(6) - (17)].loc) - (yyvsp[(14) - (17)].loc)); 
                                  }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 336 "mycc.y"
    { if (is_in_main)
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

  case 32:

/* Line 1455 of yacc.c  */
#line 349 "mycc.y"
    { /* BREAK is optional to implement */
			  error("break not implemented");
			}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 353 "mycc.y"
    { yyerrok; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 361 "mycc.y"
    { 
			    int place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
			    emit(dup);
			    if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
			    {
				//if (isfloat($3.type)
				//	emit2(f2i); 
				if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 0) 
					emit3(putstatic, place); 
				else
					emit2(istore, place); 
                               }
			    else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
			    {
				//if (isint($3.type))
				//	emit2(i2f); 
				if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 0) 
					emit3(putstatic, place); 
				else
					emit2(fstore, place); 

				emit2(fstore, place); 
			    }
			   else 
				error("Type error");

			    //$$.type = $3.type;
	 }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 389 "mycc.y"
    { 

		  int place;
            	  if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            	   }

			emit(iadd); 
			emit(dup); 

            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
            	place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
            	if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                	emit2(istore, place);
            	else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
              }
	 }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 411 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(swap); emit(isub); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 431 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(imul); emit(dup); 
			//emit2(istore, $1->localvar); 
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 451 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
                }
	     emit(swap); emit(idiv); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 471 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(swap); emit(irem); emit(dup); 
			//emit2(istore, $1->localvar); 
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 491 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(iand); emit(dup); 
			emit2(istore, (yyvsp[(1) - (3)].sym)->localvar);  
		  }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 504 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(swap); emit(ixor); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 524 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(swap); emit(ior); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 544 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
            }
			emit(swap); emit(ishl); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
            }
		  }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 564 "mycc.y"
    { 
			//emit2(iload, $1->localvar); 
            int place;
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                 place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                 if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (3)].sym)), "I"))
                     emit2(iload, place);
                 else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                     emit2(fload, place);
               }
            emit(swap); emit(ishr); emit(dup); 
			//emit2(istore, $1->localvar);  
            if (getlevel(top_tblptr, (yyvsp[(1) - (3)].sym)) == 1) {
                place = getplace(top_tblptr, (yyvsp[(1) - (3)].sym));
                if (isint(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(istore, place);
                else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (3)].sym))))
                    emit2(fstore, place);
                }
           }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 584 "mycc.y"
    { int place;
		if (getlevel(top_tblptr, (yyvsp[(1) - (1)].sym)) == 0)
		{
			emit3( getstatic, getplace(top_tblptr, (yyvsp[(1) - (1)].sym)));
		}
               else
		{
               		place = getplace(top_tblptr, (yyvsp[(1) - (1)].sym));
                    		if (!strcmp(gettype(top_tblptr, (yyvsp[(1) - (1)].sym)), "I"))
                    			emit2(iload, place);
				else if (isfloat(gettype(top_tblptr, (yyvsp[(1) - (1)].sym))))
                        		emit2(fload, place);
		}
	 }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 598 "mycc.y"
    { emit(ior); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 599 "mycc.y"
    { emit(iand); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 600 "mycc.y"
    { emit(ior); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 601 "mycc.y"
    { emit(ixor); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 602 "mycc.y"
    { emit(iand); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 603 "mycc.y"
    { emit3(if_icmpeq,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 604 "mycc.y"
    { emit3(if_icmpne,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 605 "mycc.y"
    { emit3(if_icmplt,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 606 "mycc.y"
    { emit3(if_icmpgt,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1);  }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 607 "mycc.y"
    { emit3(if_icmple,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 608 "mycc.y"
    { emit3(if_icmpge,8); emit2(bipush,0); emit3(goto_,5); emit2(bipush,1); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 609 "mycc.y"
    { emit(ishl); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 610 "mycc.y"
    { emit(ishr); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 612 "mycc.y"
    { 
/*
		if (iseq($1.type, $3.type))
		{
			if (isint($1.type))
			    emit(iadd);
			else
			    emit(fadd);
		}
		else
		{
			error("Type error");
		}
*/
		//$$.type = $1.type;
	   }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 628 "mycc.y"
    { emit(isub); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 629 "mycc.y"
    { emit(imul); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 630 "mycc.y"
    { emit(idiv); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 631 "mycc.y"
    { emit(irem); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 632 "mycc.y"
    { emit(irem); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 640 "mycc.y"
    { error("! operator not implemented"); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 641 "mycc.y"
    { error("~ operator not implemented"); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 643 "mycc.y"
    { error("unary + operator not implemented"); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 645 "mycc.y"
    { emit(ineg); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 647 "mycc.y"
    { // check that we are in main()
			  if (is_in_main)
			  {	emit(aload_1);
			  	emit2(bipush, (yyvsp[(2) - (2)].num));
			  	emit(iaload);
			  }
			  else
			  	error("invalid use of $# in function");
			}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 656 "mycc.y"
    { emit2(iload, (yyvsp[(2) - (2)].sym)->localvar); emit2(bipush, 1); emit(iadd); emit(dup); emit2(istore, (yyvsp[(2) - (2)].sym)->localvar); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 657 "mycc.y"
    { emit2(iload, (yyvsp[(2) - (2)].sym)->localvar); emit2(bipush, 1); emit(isub); emit(dup); emit2(istore, (yyvsp[(2) - (2)].sym)->localvar); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 658 "mycc.y"
    { emit2(iload, (yyvsp[(1) - (2)].sym)->localvar); emit(dup); emit2(bipush, 1); emit(iadd); emit2(istore, (yyvsp[(1) - (2)].sym)->localvar); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 659 "mycc.y"
    {  emit2(iload, (yyvsp[(1) - (2)].sym)->localvar); emit(dup); emit2(bipush, 1); emit(isub); emit2(istore, (yyvsp[(1) - (2)].sym)->localvar); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 660 "mycc.y"
    {  emit2(iload, (yyvsp[(1) - (1)].sym)->localvar); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 661 "mycc.y"
    { emit2(bipush, (yyvsp[(1) - (1)].num)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 662 "mycc.y"
    { emit3(sipush, (yyvsp[(1) - (1)].num)); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 663 "mycc.y"
    { emit2(ldc, constant_pool_add_Integer(&cf, (yyvsp[(1) - (1)].num))); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 664 "mycc.y"
    { error("float constant not supported"); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 665 "mycc.y"
    { /* We do not need to implement strings: */
			  error("string constant not supported");
			}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 669 "mycc.y"
    {
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, (yyvsp[(1) - (4)].sym)->lexptr, gettype(top_tblptr, (yyvsp[(1) - (4)].sym))));

			  //$$.type = mkret(gettype(top_tblptr, $1));
			}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 675 "mycc.y"
    { /* TASK 3: TO BE COMPLETED */
			  emit3(invokestatic, constant_pool_add_Methodref(&cf, cf.name, (yyvsp[(1) - (4)].sym)->lexptr, gettype(top_tblptr, (yyvsp[(1) - (4)].sym))));
			  //error("function call not implemented");
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 684 "mycc.y"
    { (yyval.loc) = pc; }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 687 "mycc.y"
    { (yyval.loc) = pc; emit3(ifeq, 0); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 690 "mycc.y"
    { (yyval.loc) = pc; emit3(goto_, 0); }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 696 "mycc.y"
    { emit(pop); }
    break;



/* Line 1455 of yacc.c  */
#line 2614 "mycc.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 700 "mycc.y"


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


