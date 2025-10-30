%{
#include <stdio.h>
%}

%%
^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$    { printf("Valid Email ID: %s\n", yytext); }
.+                                                   { printf("Invalid Email ID: %s\n", yytext); }
%%

int main() {
    printf("Enter an email ID: ");
    yylex();
    return 0;
}

int yywrap(){return 1;}
