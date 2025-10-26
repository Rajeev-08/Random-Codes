%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
int valid = 1;   // flag for validation
%}

%union {
    char *str;
}

%token NAME PLACE PIN PHONE COLON WORD INVALID
%token PINSIX BADPIN PHONEFORMAT BADPHONE
%type <str> WORD PINSIX PHONEFORMAT

%%
address : name_line place_line pin_line phone_line
        {
            if (valid)
                printf("\n✅ Valid Address Format\n");
            else
                printf("\n❌ Invalid Address Format\n");
        }
        ;

name_line : NAME COLON WORD
          | NAME COLON INVALID { valid = 0; }
          ;

place_line : PLACE COLON WORD
           | PLACE COLON INVALID { valid = 0; }
           ;

pin_line : PIN COLON PINSIX
         | PIN COLON BADPIN   { valid = 0; }
         | PIN COLON INVALID  { valid = 0; }
         ;

phone_line : PHONE COLON PHONEFORMAT
           | PHONE COLON BADPHONE  { valid = 0; }
           | PHONE COLON INVALID   { valid = 0; }
           ;
%%

int main() {
    printf("Enter the Address Details:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    valid = 0;
}
