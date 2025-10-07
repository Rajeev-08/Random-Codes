%{
#include "y.tab.h"
extern YYSTYPE yylval;
%}

%%

[0-9]+     { yylval.symbol = yytext[0]; return NUMBER; }
[a-z]      { yylval.symbol = yytext[0]; return LETTER; }
\n         { return 0; }

%%
