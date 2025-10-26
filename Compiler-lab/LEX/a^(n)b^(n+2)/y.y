
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token A B

%%
S : A S B
  | B B
  ;
%%

int main() {
    printf("Enter a string of a's and b's:\n");
    if (yyparse() == 0)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");
    return 0;
}

void yyerror(const char *s) {
}
