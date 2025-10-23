%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*    { return ID; }
[ \t\n]+                ;      /* Ignore whitespace */
.                       { return yytext[0]; } /* Invalid char */
%%

int yywrap() { return 1; }
