%{
#include <stdio.h>
#include <stdlib.h>

int hour, min, sec;
%}

%%

([0-2][0-9]):([0-5][0-9]):([0-5][0-9])  {
    sscanf(yytext, "%d:%d:%d", &hour, &min, &sec);
    if(hour < 0 || hour > 23) {
        printf("Invalid hour!\n");
        return 0; 
    }
    if(hour >= 0 && hour < 12)
        printf("Good Morning\n");
    else if(hour >= 12 && hour < 17)
        printf("Good Afternoon\n");
    else
        printf("Good Evening\n");
}

[ \t\n]+     ;  // ignore whitespace/newline
.            { printf("Invalid input format!\n"); }
%%

int yywrap() { return 1; }

int main() {
    printf("Enter time in HH:MM:SS format:\n");
    yylex();
    return 0;
}
