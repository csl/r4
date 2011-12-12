/* TODO: TO BE COMPLETED */

%option noyywrap
%option yylineno

%x COMMENTS

%{

#include "global.h"
#include "mycc.h"

#define YY_NO_UNISTD_H

static int localvar = 3;	/* JVM first local var index */

static int install_id();
static int install_int();
static int install_oct();
static int install_hex();
static int install_chr();
static int install_fp();
static int install_str();

%}

quote	\'
ditto	\"
back	\\
digit           [0-9]
alpha           [a-zA-Z_]
id              {alpha}({alpha}|{digit})*
hex		  [{digit}a-zA-Z]
exp		  [eE][+-]{digit}+
int             {digit}+
ch		  [^\n\'"]
EN 		  [\r\n]  
SP 		[ \t\r\n]

%%

[ \t\v\n\f\r]                  /* skip white space */
"//".*{EN}+      			  
"/*".*."*/"
<COMMENTS>"*/"{SP}*       { BEGIN INITIAL; }  
<COMMENTS>.|{SP}     
"/*"             		  { BEGIN COMMENTS; }  
{id}                           { return install_id(); }
{int}                          { return install_int(); }
0({digit})+                    {  return install_oct(); }
0(x|X).*{hex}+                   {  return install_hex(); }
{quote}({back}{ch}|{back}{back}|{back}{quote}|{back}{ditto}|{ch}|{ditto})*{quote}                        {  return install_chr(); }
{digit}*.{digit}*({exp})       {  return install_fp(); }
{ditto}({back}{ch}|{back}{back}|{back}{quote}|{back}{ditto}|{ch}|{quote})*{ditto} {  return install_str(); }
"+="                           { return PA; }
"-="                           { return NA; }
"*="                           { return TA; }
"/="                           { return DA; }
"%="                           { return MA; }
"&="                           { return AA; }
"^="                           { return XA; }
"|="                           { return OA; }
"<<="                          { return LA; }
">>="                          { return RA; }
"||"                           { return OR; }
"&&"                           { return AN; }
"=="                           { return EQ; }
"!="                           { return NE; }
"<="                           { return LE; }
">="                           { return GE; }
"<<"                           { return LS; }
">>"                           { return RS; }
"++"                           { return PP; }
"--"                           { return NN; }
"->"                           { return AR; }
"<%"                           { return '{'; }
"%>"                           { return '}'; }
"<:"                           { return '['; }
":>"                           { return ']'; }
[!$%&()*+,\-./:;<=>?\[\]^{|}~] { return yytext[0]; }
.                              { yyerror("Unknown character ignored"); }

%%

/* install_id - add identifier to symbol table if not already there and assign it a JVM local var index */
static int install_id()
{
	yylval.sym = lookup(yytext);
	if (!yylval.sym)
	{
		yylval.sym = insert(yytext, ID);
		yylval.sym->localvar = localvar++;
	}
	return yylval.sym->token;
}

/* install_int - convert decimal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_int()
{
	sscanf(yytext, "%u", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_oct - convert octal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_oct()
{
	sscanf(yytext, "%o", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_hex - convert hexadecimal yytext[] to yylval.num and return INT8, INT16, or INT32 */
static int install_hex()
{
	sscanf(yytext, "%x", &yylval.num);

	if (yylval.num < 128)
		return INT8;

	if (yylval.num < 32368)
		return INT16;

	return INT32;
}

/* install_chr - convert ASCII character yytext[1] to yylval.num and return INT8 */
static int install_chr()
{
	/* TODO: TO BE COMPLETED */
	sscanf(yytext[1], "%c", &yylval.num);
	
	return INT8;
}

/* install_fp - convert float yytext[] into float yylval.flt and return FLT */
static int install_fp()
{
	/* TODO: TO BE COMPLETED */
	sscanf(yytext, "%f", &yylval.flt);

	return FLT;
}

/* install_str - duplicate yytext[] string and assign to yylval.str without the quotes */
static int install_str()
{
	/* TODO: TO BE COMPLETED */
	strcpy(yylval.str, yytext);

	return STR;
}
