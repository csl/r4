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
typedef union
{ Symbol *sym;  /* token value yylval.sym is the symbol table entry of an ID */
  unsigned num; /* token value yylval.num is the value of an int constant */
  float flt;    /* token value yylval.flt is the value of a float constant */
  char *str;    /* token value yylval.str is the value of a string constant */
  unsigned loc; /* location of instruction to backpatch */
  Type typ;	/* type descriptor */
  /*Expr exp;*/
} YYSTYPE;
extern YYSTYPE yylval;
