%{
#include <stdio.h>
#include <stdlib.h>

int charCount = 0;   // Count letters
int digitCount = 0;  // Count numbers
FILE *file;
%}

%%

[0-9]+       { digitCount += yyleng; }       // Count numbers (digits)
[a-zA-Z]+    { charCount += yyleng; }        // Count letters (characters)
.|\n         { /* ignore other characters */ }

%%

int main() {
    // Open the file directly
    file = fopen("input.txt", "r");  // Replace with your file name

    yyin = file;  // Lex reads input from this file
    yylex();      // Start lexical analysis

    printf("Total letters (characters): %d\n", charCount);
    printf("Total numbers (digits): %d\n", digitCount);

    fclose(file);
    return 0;
}

int yywrap() {
    return 1;
  }
