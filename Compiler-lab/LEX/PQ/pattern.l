%{
#include <stdio.h>
%}

%option noyywrap

%%
"up"        { printf("|"); }
"down"      { printf("|"); }
"top"       { printf("--"); }
"bottom"    { printf("__"); }
"sin"        { printf("__|--|"); }

[ \t\n]+   ;   /* Ignore whitespace */
.          { printf("\nInvalid Input\n"); }
%%

int main() {
    printf("Enter the input pattern: ");
    yylex();
    return 0;
}
