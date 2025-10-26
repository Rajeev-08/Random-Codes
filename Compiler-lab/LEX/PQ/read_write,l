%{
#include <stdio.h>

int scanf_count = 0;
int printf_count = 0;
%}

%%

"scanf" {
    scanf_count++;
    printf("readf");
}

"printf" {
    printf_count++;
    printf("writef");
}

.|\n {
    putchar(yytext[0]);   // print all other characters as-is
}

%%

int yywrap() { return 1; }

int main() {
    printf("Enter C program (Ctrl+D to end):\n");
    yylex();
    printf("\n\nNumber of scanf statements: %d\n", scanf_count);
    printf("Number of printf statements: %d\n", printf_count);
    return 0;
}
