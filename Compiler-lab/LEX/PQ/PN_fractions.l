%{
#include <stdio.h>
#include <stdlib.h>

int pos_count = 0;
int neg_count = 0;
%}

%%
[-]?[0-9]+\/[-]?[0-9]+ {
    int num, den;
    sscanf(yytext, "%d/%d", &num, &den);

    if (den != 0) {
        double val = (double)num / den;
        if (val > 0)
            pos_count++;
        else if (val < 0)
            neg_count++;
    }
}

%%

int main() {
    printf("Enter fractions (format a/b, one or more):\n");
    yylex();
    printf("Number of positive fractions: %d\n", pos_count);
    printf("Number of negative fractions: %d\n", neg_count);
    return 0;
}

int yywrap(){
    return 1;
}
