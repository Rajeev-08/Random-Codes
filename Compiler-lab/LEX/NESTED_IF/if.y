%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
int nesting_level = 0; /* Counter to track nesting level */
%}

%token IF ELSE ID NUM RELOP LPAREN RPAREN LBRACE RBRACE SEMICOLON

%%

program:
    statement_list
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    if_statement
    | other_statement
    ;

if_statement:
    IF LPAREN condition RPAREN LBRACE statement_list RBRACE {
        printf("IF statement at nesting level %d\n", nesting_level);
        nesting_level--; /* Decrease nesting level after exiting IF block */
    }
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE {
        printf("IF-ELSE statement at nesting level %d\n", nesting_level);
        nesting_level--; /* Decrease nesting level after exiting IF-ELSE block */
    }
    ;

condition:
    ID RELOP ID
    | ID RELOP NUM
    ;

other_statement:
    ID SEMICOLON
    | /* empty */
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter the IF control statements (end with Ctrl+D):\n");
    yyparse();
    return 0;
}
