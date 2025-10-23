%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(char *s);

char *x, *a, *b, *c; // To store parts of the ternary
%}

%union {
    char *str;
}

%token <str> ID
%token EQUAL QUESTION COLON SEMI

%%

Stmt:
    ID EQUAL ID QUESTION ID COLON ID SEMI
{
    x = $1;
    a = $3;
    b = $5;
    c = $7;

    printf("if (%s) \n\t%s = %s; \nelse \n\t%s = %s; \n", a, x, b, x, c);
};
%%

int main() {
    printf("Enter ternary expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}
