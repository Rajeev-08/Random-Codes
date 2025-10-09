%{
#include "y.tab.h"
%}

%%
[0-9]+          { yylval = atoi(yytext); return NUMBER; }
[ \t]           ;   /* Ignore spaces */
\n              { return '\n'; }
.               { return yytext[0]; }
%%

int yywrap() { return 1; }
