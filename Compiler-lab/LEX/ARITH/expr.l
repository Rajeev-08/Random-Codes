%{
#include "y.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUM; }
[a-zA-Z]+   { return ID; }
[ \t\n]+    ;     /* Ignore whitespace */
.            { return yytext[0]; }
%%

int yywrap() { return 1; }
