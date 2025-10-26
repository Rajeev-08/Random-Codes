%{
#include <stdio.h>
#include <ctype.h>
FILE *fp;
%}

%%

[a-z]       { putchar(toupper(yytext[0])); }   // convert lowercase to uppercase
[A-Z]       { putchar(tolower(yytext[0])); }   // convert uppercase to lowercase
.|\n        { putchar(yytext[0]); }           // print other characters as-is
%%

int yywrap() { return 1; }

int main() {
  fp = fopen("input.txt", "r");
        yyin = fp;
    yylex();   
    fclose(fp);
    return 0;
}
