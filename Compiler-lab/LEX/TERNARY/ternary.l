%{
#include "ternary.tab.h"
#include <string.h>
%}

%option noyywrap

%%

"="     { return EQUAL; }
"?"     { return QUESTION; }
":"     { return COLON; }
";"     { return SEMI; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return ID;
}

[ \t\n]+   ;  // Ignore whitespace

.          { printf("Unknown character: %c\n", *yytext); }

%%
