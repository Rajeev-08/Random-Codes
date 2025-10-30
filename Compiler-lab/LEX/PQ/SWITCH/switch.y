%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token SWITCH CASE DEFAULT BREAK TYPE NUM ID
%token COLON SEMI LBRACE RBRACE LPAREN RPAREN

%%
program : switch_stmt { printf("✅ Valid switch-case statement\n"); }
        ;

switch_stmt : SWITCH LPAREN ID RPAREN LBRACE case_list default_part RBRACE
            ;

case_list : case_list case_stmt
          | case_stmt
          ;

case_stmt : CASE NUM COLON stmt_list BREAK SEMI
          ;

default_part : DEFAULT COLON stmt_list
             | /* empty */
             ;

stmt_list : stmt_list stmt
          | stmt
          ;

stmt : ID SEMI
     | /* empty */
     ;
%%

void yyerror(const char *s) {
    printf("❌ Invalid switch-case statement\n");
}

int main() {
    printf("Enter a switch-case statement:\n");
    yyparse();
    return 0;
}
