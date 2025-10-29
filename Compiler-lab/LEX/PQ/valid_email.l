%{
#include <stdio.h>
%}

%option noyywrap

/* ---------- Regular Definitions ---------- */
USERNAME   [a-zA-Z0-9._%+-]+
DOMAIN     [a-zA-Z0-9.-]+
EXTENSION  [a-zA-Z]{2,}

/* ---------- Rules Section ---------- */
%%
{USERNAME}@{DOMAIN}\.{EXTENSION}    { printf("Valid Email ID\n"); }
.|\n                                 { printf("Invalid Email ID\n"); }
%%

int main() {
    printf("Enter an email ID: ");
    yylex();
    return 0;
}
