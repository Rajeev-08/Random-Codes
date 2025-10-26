%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

"if"            { return IF; }
"else"          { return ELSE; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[0-9]+          { return NUM; }
"=="|"!="|"<"|">"|"<="|">=" { return RELOP; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMICOLON; }
[ \t\n]+        { /* Ignore whitespace */ }
.               { printf("Invalid character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}
