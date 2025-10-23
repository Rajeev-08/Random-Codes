%{
#include <stdio.h>
#include <string.h>

int roman_to_int(char *r) {
    int val = 0, prev = 0, n;
    for (int i = strlen(r)-1; i >= 0; i--) {
        switch(r[i]) {
            case 'I': n = 1; break;
            case 'V': n = 5; break;
            case 'X': n = 10; break;
            case 'L': n = 50; break;
            case 'C': n = 100; break;
            case 'D': n = 500; break;
            case 'M': n = 1000; break;
            default: n = 0;
        }
        val += (n < prev) ? -n : n;
        prev = n;
    }
    return val;
}

char first[50], second[50];
int c = 0;
%}

%%
[A-Z]+   { if (c==0) strcpy(first, yytext); else strcpy(second, yytext); c++; }
[ \t\n]+ ;
%%

int main() {
    printf("Enter two Roman numerals: ");
    yylex();
    if (c == 2) printf("Sum: %d\n", roman_to_int(first)+roman_to_int(second));
    else printf("Please enter two numerals.\n");
    return 0;
}
int yywrap(){
    return 1;
    
}
