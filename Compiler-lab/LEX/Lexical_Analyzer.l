%{
#include <stdio.h>
%}

/* Patterns */
PREPROCESSOR   \#[ \t]*include[ \t]*([<"][a-zA-Z0-9_.]+[>"])
KEYWORD        int|void|float|char|double|if|else|for|while|return
IDENTIFIER     [a-zA-Z_][a-zA-Z0-9_]*
NUMBER         [0-9]+
OPERATOR       [+\-*/=<>!]
SPECIAL        [;,\(\){}]

%%

{PREPROCESSOR}  { printf("Preprocessor Directive: %s\n", yytext); }
{KEYWORD}       { printf("Keyword: %s\n", yytext); }
{IDENTIFIER}    { printf("Identifier: %s\n", yytext); }
{NUMBER}        { printf("Number: %s\n", yytext); }
{OPERATOR}      { printf("Operator: %s\n", yytext); }
{SPECIAL}       { printf("Special Symbol: %s\n", yytext); }

[ \t\n]+        ;  /* Ignore whitespace */

.               { printf("Unknown: %s\n", yytext); }

%%

int main() {
    printf("Lexical Analysis:\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
