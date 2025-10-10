%{
#include <stdio.h>
%}

/* Patterns */
DIGIT   [0-9]

%%

{DIGIT}+                    { printf("INTEGER\t%s\n", yytext); }
{DIGIT}+"."{DIGIT}+         { printf("FLOAT\t%s\n", yytext); }
[ \t\n]+                    ;   /* ignore whitespace */
.                           { printf("INVALID\t%s\n", yytext); }

%%

int main() {
    printf("Enter numbers (Ctrl+D to end):\n");
    yylex();
    return 0;
}
