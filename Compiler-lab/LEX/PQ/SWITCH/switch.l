%{
#include "y.tab.h"
%}

%%
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }
"int"|"char"    { return TYPE; }
[0-9]+          { return NUM; }
[a-zA-Z_][a-zA-Z0-9_]*   { return ID; }
":"             { return COLON; }
";"             { return SEMI; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[ \t\n]+        ;   // ignore whitespace
.               { /* ignore unrecognized characters */ }
%%
int yywrap() { return 1; }
