%{
#include <stdio.h>
#include <string.h>

char str[100];
%}

%%

[a-zA-Z]+ {
    strcpy(str, yytext);       // store the input string
    int len = strlen(str);
    while (len >= 2) {         // print until length >= 2
        for (int i = 0; i < len; i++)
            putchar(str[i]);
        printf("\n");
        len--;                 // remove last character
    }
}
\n      ;   // ignore newline
.       ;   // ignore other characters
%%

int yywrap() { return 1; }

int main() {
    printf("Enter a string:\n");
    yylex();
    return 0;
}
