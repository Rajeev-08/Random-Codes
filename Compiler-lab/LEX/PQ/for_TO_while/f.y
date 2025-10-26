%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    char *str;
}

%token FOR WHILE LBRACE RBRACE SEMICOLON LPAREN RPAREN
%token <str> WORD

%%
program : for_loop ;

for_loop : FOR LPAREN init SEMICOLON cond SEMICOLON incr RPAREN LBRACE stmts RBRACE
         {
             printf("1. For loop identified\n\n");
             printf("2. Equivalent while loop:\n\n");
             printf("%s;\n", $3);
             printf("while(%s) {\n", $5);
             printf("    %s;\n", $7);  // increment goes first
             printf("    %s;\n", $10); // statements
             printf("}\n");
         }
         ;

init : WORD       { $$ = $1; }
     ;

cond : WORD       { $$ = $1; }
     ;

incr : WORD       { $$ = $1; }
     ;

stmts : WORD      { $$ = $1; }
      ;

%%

int main() {
    printf("Enter a simple for loop:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Syntax Error: %s\n", s);
}
