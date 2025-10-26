%{
#include "y.tab.h"
#include <string.h>
%}

%option noyywrap

%%

"do"        { return DO; }
"while"     { return WHILE; }


";"         { return SEMI; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }


"<="        { return REL_OP; }
">="        { return REL_OP; }
"=="        { return REL_OP; }
"!="        { return REL_OP; }
"<"         { return REL_OP; }
">"         { return REL_OP; }


[a-zA-Z_][a-zA-Z0-9_]* { return ID; }

[ \t\n]+    ;

.           { printf("Unknown character: %c\n", *yytext); }

%%
