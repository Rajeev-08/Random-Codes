%{
#include "y.tab.h"
#include <string.h>
%}

%%
"Name"              { return NAME; }
"Place"             { return PLACE; }
"Pin"               { return PIN; }
"Phone"             { return PHONE; }
":"                 { return COLON; }

[1-9][0-9]{5}       { yylval.str = strdup(yytext); return PINNUM; }     /* valid 6-digit, not starting with 0 */
0[0-9]{5}           { yylval.str = strdup(yytext); return INVALID; }    /* invalid PIN (starts with 0) */

0[0-9]{3}-[0-9]{6,7} { yylval.str = strdup(yytext); return PHONE_NUM; } /* stdcode-number format */

[A-Za-z][A-Za-z ]*  { yylval.str = strdup(yytext); return STRING; }     /* Name/Place can have letters & spaces */

\n                  { return NL; }
[ \t]+              ;   /* ignore spaces and tabs */
.                   { return INVALID; }
%%

int yywrap() { return 1; }
