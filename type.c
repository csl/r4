#include "global.h"

Type mkfun(Type args, Type result)
{ Type type = (Type)malloc(strlen(args) + strlen(result) + 3);
  if (!type)
    error("Out of memory");
  sprintf(type, "(%s)%s", args, result);
  printf("mkfun: %s\n", type);
  return type;
}

Type mkpair(Type type1, Type type2)
{ Type type = (Type)malloc(strlen(type1) + strlen(type2) + 1);
  if (!type)
    error("Out of memory");
  strcpy(type, type1);
  strcat(type, type2);
  return type;
}

Type mkvoid()
{ return "V";
}

Type mkint()
{ return "I";
}

Type mkfloat()
{ return "F";
}

Type mkret(Type type)
{ char *s;
  if (type)
  { s = strrchr(type, ')');
    if (s)
      return s + 1;
  }
  return NULL;
}

int isvoid(Type type)
{ 
printf("isvoid\n");
return type && !strcmp(type, "V");
}

int isint(Type type)
{
printf("isint\n");
 return type && !strcmp(type, "I");
}

int isfloat(Type type)
{ 
printf("isfloat\n");
return type && !strcmp(type, "F");
}

int iseq(Type type1, Type type2)
{ 
printf("isseq\n");
return type1 && type2 && !strcmp(type1, type2);
}
