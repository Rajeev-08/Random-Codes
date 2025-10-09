%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER

%%
calclist:
      /* empty */
    | calclist expr '\n' { printf("= %d\n", $2); }
    ;

expr:
      NUMBER              { $$ = $1; }
    | expr '+' expr       { $$ = $1 + $3; }
    | expr '-' expr       { $$ = $1 - $3; }
    | expr '*' expr       { $$ = $1 * $3; }
    | expr '/' expr       { 
                              if ($3 == 0) {
                                printf("Error: Division by zero!\n");
                                $$ = 0;
                              } else $$ = $1 / $3;
                           }
    | '(' expr ')'        { $$ = $2; }
    ;
%%

int main() {
    printf("Enter expressions (Ctrl+C to exit):\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}


/*
yacc -d calc.y
lex calc.l
gcc lex.yy.c y.tab.c -o calc
./calc

*/
