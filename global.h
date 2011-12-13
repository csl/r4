/* TO BE COMPLETED (when necessary by adding new globals) */

#include "javaclass.h"
#include "bytecode.h"

struct Symbol
{
	char *lexptr;
	int  token;
	int  localvar;		/* not needed any longer */
};

typedef struct Symbol Symbol;

typedef char *Type;		/* a type descriptor (JVM) */

struct Entry
{
	struct Entry *next;	/* next in linked list or NULL */
	Symbol *sym;		/* symbol (identifier) */
	Type type;		/* its type */
	int place;		/* its place */
	struct Table *table;	/* its table (when entry is a function) */
};

typedef struct Entry Entry;

struct Table
{
	struct Table *prev;	/* the previous table (parent) */
	struct Entry *list;	/* linked list of entries */
	int width;		/* cumulative width of entries in table */
	int level;		/* global (0) or local (1) level */
};

typedef struct Table Table;

typedef char* Backpatchlist;

struct Expr
{
	Backpatchlist *truelist;
	Backpatchlist *falselist;
	Type type;
};

typedef struct Expr Expr;


extern Symbol *lookup(char*);
extern Symbol *insert(char*, int);

// create a new table and link to previous table in hierarchy:
extern Table *mktable(Table *prev);
// print table
extern void dumptable(Table *table);
// add width information to table:
extern void addwidth(Table *table, int width);
// enter a declaration to the table for symbol with type and place:
extern Entry *enter(Table *table, Symbol *sym, Type type, int place);
// enter a procedure (function) to the table:
extern Entry *enterproc(Table *table, Symbol *sym, Type type, Table *newtable);
// find the level at which the variable is declared (0=global, 1=local, -1 when not found):
extern int getlevel(Table *table, Symbol *sym);
// find the type of a variable (NULL when not found):
extern Type gettype(Table *table, Symbol *sym);
// find the place of a variable:
extern int getplace(Table *table, Symbol *sym);

// return a new function type:
extern Type mkfun(Type args, Type result);
// return a pair of types to construct argument list for functions:
extern Type mkpair(Type type1, Type type2);
// return void type:
extern Type mkvoid();
// return int type:
extern Type mkint();
// return float type:
extern Type mkfloat();
// if type is function, get return type (or NULL):
extern Type mkret(Type type);

// check if type is void:
extern int isvoid(Type type);
// check if type is int:
extern int isint(Type type);
// check if type is float:
extern int isfloat(Type type);
// check if two types are equal:
extern int iseq(Type type1, Type type2);

extern void init();
extern void error();

extern int yylex();
extern int yyparse();
extern int yyerror(char*);

extern FILE *yyin;
extern int yylineno;

extern int errnum;

extern Backpatchlist* makelist(int location);
void backpathlist(Backpatchlist *list, int location);
Backpatchlist* mergelist(Backpatchlist *list1, Backpatchlist *list2);
