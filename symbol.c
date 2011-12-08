/* TODO: TO BE COMPLETED */

#include "global.h"

int Nhash = 255;

#define SYMMAX 100 
#define STRMAX 100 

char lexemes[STRMAX];

/* Table */
struct Symbol symtable [SYMMAX];
/* Last used table entry */
int  lastentry = 0;
int  lastchar = -1;    


Symbol *lookup(char *s)
{
  int p;

  for (p=lastentry; p>0; p=p-1) {
    if (strcmp(symtable[p].lexptr,s)==0) {
      return &symtable[p];
    }
  }

  return 0;

}

Symbol *insert(char *s, int tok)
{
  int len;
  len = strlen(s);

  if (lastentry+1>=SYMMAX) {
    error ("Symbol table overflow!");
  }

  if (lastchar+len+1>=STRMAX) {
    error ("Lexem array overflow!");
  }

  lastentry++;
  symtable[lastentry].token = tok;
  symtable[lastentry].lexptr = &lexemes[lastchar+1];
  lastchar = lastchar + len + 1;
  strcpy(symtable[lastentry].lexptr, s);

  return &symtable[lastentry];

}
