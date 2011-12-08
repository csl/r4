CC=gcc
CPP=g++
YACC=yacc
#YACC=bison -y
#LEX=lex
LEX=flex
LIBS=
COFLAGS=-g
CWFLAGS=-Wall
CIFLAGS=
CMFLAGS=
CFLAGS= $(CWFLAGS) $(COFLAGS) $(CIFLAGS) $(CMFLAGS)
all:		mycc
mycc:		mycc.o bytecode.o error.o init.o javaclass.o lex.yy.o symbol.o table.o type.o backpatch.o
		$(CC) -o mycc mycc.o bytecode.o error.o init.o javaclass.o lex.yy.o symbol.o table.o type.o backpatch.o
mycc.c:		mycc.y
		$(YACC) -o mycc.c -d -v mycc.y
lex.yy.c:	mycc.l mycc.c
		$(LEX) mycc.l
.c.o:
		$(CC) $(CFLAGS) -c $<
clean:
		rm -f mycc core *.o mycc.h mycc.c lex.yy.c y.output Code.class
