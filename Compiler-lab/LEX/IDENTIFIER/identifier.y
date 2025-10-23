%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

/* Token */
%token ID

%%
start : ID { printf("Valid identifier\n"); }
      ;
%%

int main() {
    printf("Enter an identifier: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid identifier\n");
}
