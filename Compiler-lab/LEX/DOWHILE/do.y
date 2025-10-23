%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(char *s);

%}

%union {
    char *str;
}

// Tokens
%token <str> ID
%token DO WHILE
%token REL_OP    // relational operators: <, >, <=, >=, ==, !=
%token SEMI      // ;
%token PLUS MINUS MUL DIV ASSIGN // +, -, *, /, =
%token LPAREN RPAREN LBRACE RBRACE

%%

// Grammar rules
Program:
    DoWhileStmt
;

DoWhileStmt:
    DO LBRACE Assignment SEMI RBRACE WHILE LPAREN Condition RPAREN SEMI
    {
        printf("Valid do-while loop detected.\n");
    }
;

Assignment:
    ID ASSIGN Expr
;

Expr:
    ID
    | ID PLUS ID
    | ID MINUS ID
    | ID MUL ID
    | ID DIV ID
;

Condition:
    ID REL_OP ID
;

%%

int main() {
    printf("Enter do-while loop:\n");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}
