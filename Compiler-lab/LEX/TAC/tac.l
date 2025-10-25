%{
#include "y.tab.h"
%}

%%

[a-zA-Z]       { yylval.symbol = yytext[0]; return LETTER; }
[0-9]          { yylval.symbol = yytext[0]; return NUMBER; }
[ \t]          ;   // ignore spaces and tabs
\n             { return '\n'; }   // handle newline as end of input
.              { return yytext[0]; }

%%

int yywrap() { return 1; }
