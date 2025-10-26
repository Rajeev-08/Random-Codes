%{
#include <stdio.h>
#include <ctype.h>
%}

%%

[a-z]       { putchar(toupper(yytext[0])); }   // convert lowercase to uppercase
[A-Z]       { putchar(tolower(yytext[0])); }   // convert uppercase to lowercase
.|\n        { putchar(yytext[0]); }           // print other characters as-is
%%

int yywrap() { return 1; }

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = fp;
    }

    yylex();   // process input
    if (argc > 1) fclose(fp);
    return 0;
}
