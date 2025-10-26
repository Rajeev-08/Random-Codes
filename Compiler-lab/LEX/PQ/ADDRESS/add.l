%{
#include "y.tab.h"
#include <string.h>

%}

%%
"Name"          { return NAME; }
"Place"         { return PLACE; }
"Pin"           { return PIN; }
"Phone"         { return PHONE; }

":"             { return COLON; }

[a-zA-Z]+       { yylval.str = strdup(yytext); return WORD; }

[1-9][0-9]{5}   { yylval.str = strdup(yytext); return PINSIX; }   // valid pin: 6 digits, not starting with 0
0[0-9]{5}       { yylval.str = strdup(yytext); return BADPIN; }   // invalid pin starting with 0

[0-9]{3,5}-[0-9]{6,8}  { yylval.str = strdup(yytext); return PHONEFORMAT; }  // stdcode-number format
[0-9]+-[0-9]+          { yylval.str = strdup(yytext); return BADPHONE; }     // wrong length

[ \t\r\n]+      ;   // Ignore whitespace and newlines
.               { return INVALID; }
%%

int yywrap() { return 1; }
