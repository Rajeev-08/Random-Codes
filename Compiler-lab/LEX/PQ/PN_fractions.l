%{
#include <stdio.h>
#include <stdlib.h>

int pos_count = 0;
int neg_count = 0;
%}

%%

[-]?[0-9]+/[-]?[0-9]+   {
    int num, denom;
    char *ptr = strdup(yytext);
    sscanf(ptr, "%d/%d", &num, &denom);

    if ((num > 0 && denom > 0) || (num < 0 && denom < 0))
        pos_count++;
    else if ((num > 0 && denom < 0) || (num < 0 && denom > 0))
        neg_count++;
}
.|\n                       ;   // ignore other characters
%%

int yywrap() { return 1; }

int main() {
    printf("Enter fractions (format a/b, one or more):\n");
    yylex();
    printf("Number of positive fractions: %d\n", pos_count);
    printf("Number of negative fractions: %d\n", neg_count);
    return 0;
}
