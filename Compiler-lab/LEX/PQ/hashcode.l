%{
#include <stdio.h>
%}

%%
.+      {
            int i;
            printf("Input: %s\n", yytext);
            printf("Hash Code: ");
            for(i = 0; yytext[i] != '\0'; i++)
                printf("%d", (int)yytext[i]);   // print ASCII equivalent
            printf("\n");
        }

\n      ;   // ignore newline
.       ;   // ignore any other character
%%

int main() {
    printf("Enter a string to compute its hash code:\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
