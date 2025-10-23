%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

/* Tokens */
%token NUM ID

/* Operator precedence and associativity */
%left '+' '-'
%left '*' '/'
%left UMINUS

%%
/* Grammar rules */
E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | '(' E ')'
  | '-' E %prec UMINUS
  | NUM
  | ID
  ;
%%

int main() {
    printf("Enter an arithmetic expression:\n");
    if (yyparse() == 0)
        printf("Valid expression\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid expression\n");
}
