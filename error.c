#include "global.h"

int errnum = 0;

/* yyerror - invoked by yyparse to report a syntax error */
int yyerror(char *msg)
{
	fprintf(stderr, "line %d: %s\n", yylineno, msg);

	if (errnum++ > 10)
		error("Too many errors: jumping ship");

	return 0;
}

/* error - report error and exit */
void error(char *msg)
{
	fprintf(stderr, "%s\n", msg);

	exit(1);
}
