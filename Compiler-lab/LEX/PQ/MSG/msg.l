%{
#include "y.tab.h"
%}

ALNUM   [a-zA-Z0-9]+
REAL    [0-9]+\.[0-9]{2}
WORD    [a-zA-Z]+

%%
{ALNUM}         { yylval.str = strdup(yytext); return STRING; }
{REAL}          { yylval.str = strdup(yytext); return REALNUM; }
[ \t]+          ;    // ignore spaces and tabs
\n              { return NEWLINE; }
.               ;    // ignore other characters
%%
int yywrap() { return 1; }
