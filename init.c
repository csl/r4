#include "global.h"
#include "mycc.h"

struct Keyword
{	char *lexptr;
	int token;
};

static struct Keyword keywords[] =
{
	{ "do",		DO },
	{ "else",	ELSE },
	{ "float",	FLOAT },
	{ "for",	FOR },
	{ "if",		IF },
	{ "int",	INT },
	{ "main",	MAIN },
	{ "return",	RETURN },
	{ "void",	VOID },
	{ "while",	WHILE },
	{ "break",	BREAK },
	{ NULL }
};

/* init - populates global symbol table with keywords */
void init()
{
	struct Keyword *k;

	for (k = keywords; k->lexptr; k++)
		insert(k->lexptr, k->token);
}

