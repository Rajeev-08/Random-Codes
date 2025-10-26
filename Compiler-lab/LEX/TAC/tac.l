%{
#include "y.tab.h"
%}

%option noyywrap

%%
[a-zA-Z]    {yylval.symbol=yytext[0];return LETTER;}
[0-9]       {yylval.symbol=yytext[0];return NUM;}
[ \t]       ;
\n          {return '\n';}
.          { return yytext[0]; }

%%
