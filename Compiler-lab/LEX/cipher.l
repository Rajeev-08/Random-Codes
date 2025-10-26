%{
#include <stdio.h>
#include <ctype.h>


char shiftChar(char c) {
    if (isupper(c))
        return ((c - 'A' + 3) % 26) + 'A';
    else if (islower(c))
        return ((c - 'a' + 3) % 26) + 'a';
    else
        return c;
}
%}

%%
[a-zA-Z]   { putchar(shiftChar(yytext[0])); }   // Encrypt letters
.|\n       { putchar(yytext[0]); }              // Print other chars as-is
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text to encrypt (Caesar Cipher with shift 3):\n");
    yylex();
    return 0;
}
