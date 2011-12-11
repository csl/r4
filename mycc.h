
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 44 "mycc.y"
 Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
  //Expr exp;



/* Line 1676 of yacc.c  */
#line 143 "mycc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


