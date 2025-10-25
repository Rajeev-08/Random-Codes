%{
#include <stdio.h>
#include <ctype.h>

int yylex(void);
void yyerror(char *s);
char add_to_table(char a, char b, char op);

int idx = 0;
char temp = 'A' - 1;

struct expr {
    char operand1, operand2, op, result;
} arr[20];

%}

%union {
    char symbol;
}

%left '+' '-'
%left '*' '/'
%token <symbol> NUMBER LETTER
%type <symbol> expr

%%
 
stmt: LETTER '=' expr '\n' {
          add_to_table($1, $3, '=');
      }
    ;

expr: expr '+' expr { $$ = add_to_table($1, $3, '+'); }
    | expr '-' expr { $$ = add_to_table($1, $3, '-'); }
    | expr '*' expr { $$ = add_to_table($1, $3, '*'); }
    | expr '/' expr { $$ = add_to_table($1, $3, '/'); }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER        { $$ = $1; }
    | LETTER        { $$ = $1; }
    ;

%%

char add_to_table(char a, char b, char op) {
    temp++;
    arr[idx].operand1 = a;
    arr[idx].operand2 = b;
    arr[idx].op = op;
    arr[idx].result = temp;
    idx++;

    printf("%c = %c %c %c\n", temp, a, op, b);
    return temp;
}

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    printf("Error: %s\n", s);
}
