%{
#include "y.tab.h"
%}

%%
"for"           { return FOR; }
"while"         { return WHILE; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMICOLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }

[^\s;{}()]+     { yylval.str = strdup(yytext); return WORD; }  // identifier, numbers, operators

[ \t\n]+        ;   // ignore whitespace
.               { return yytext[0]; }
%%

int yywrap() { return 1; }
