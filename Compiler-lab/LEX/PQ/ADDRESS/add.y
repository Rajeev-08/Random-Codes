%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
%}

%union { char *str; }

%token NAME PLACE PIN PHONE COLON NL INVALID
%token <str> STRING PINNUM PHONE_NUM

%%
address : name_line place_line pin_line phone_line
        ;

name_line : NAME COLON STRING NL
          ;

place_line : PLACE COLON STRING NL
           ;

pin_line : PIN COLON PINNUM NL
         | PIN COLON INVALID NL   { yyerror("Invalid PIN: should be 6 digits and not start with 0"); }
         ;

phone_line : PHONE COLON PHONE_NUM NL
           | PHONE COLON INVALID NL   { yyerror("Invalid Phone number format: should be stdcode-number"); }
           ;
%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter the address details (one per line):\n");
    if (yyparse() == 0)
        printf("\n✅ Valid Address Format!\n");
    else
        printf("\n❌ Invalid Address Format!\n");
    return 0;
}
