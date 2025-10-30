%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toRoman(int num, char *result) {
    struct {
        int value;
        char *symbol;
    } roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"}, {1, "I"}
    };

    result[0] = '\0'; 

    for (int i = 0; i < 13; i++) {
        while (num >= roman[i].value) {
            strcat(result, roman[i].symbol);
            num -= roman[i].value;
        }
    }
}
%}
%option noyywrap
%%
[0-9]+ {
    int num = atoi(yytext);
    char roman[50];
    toRoman(num, roman);
    printf("%d : %s\n", num, roman);
    
}
[ \t\n]+   ;
.          ;
%%

int main() {
    printf("Enter decimal numbers :\n");
    yylex();
    return 0;
}
