%{
#include <stdio.h>
#include <stdlib.h>

void toRoman(int num) {
    if (num <= 0 || num > 3999) {
        printf("Invalid number! Enter a number between 1 and 3999.\n");
        return;
    }

    struct {
        int value;
        const char *symbol;
    } romanMap[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    printf("Roman numeral: ");
    for (int i = 0; i < 13; i++) {
        while (num >= romanMap[i].value) {
            printf("%s", romanMap[i].symbol);
            num -= romanMap[i].value;
        }
    }
    printf("\n");
}
%}

%%
[0-9]+    { toRoman(atoi(yytext)); }
.|\n      ;   
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a decimal number (1-3999): ");
    yylex();
    return 0;
}
