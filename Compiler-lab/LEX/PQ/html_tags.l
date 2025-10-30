%{
#include <stdio.h>
%}

%%
\<[ \t]*([a-zA-Z0-9]+)[^>]*\>     { 
    printf("Start Tag: %s\n", yytext); 
}

\<[ \t]*\/([a-zA-Z0-9]+)[^>]*\>   { 
    printf("End Tag: %s\n", yytext ); 
}

.|\n    ;   // ignore other characters
%%

int main() {
    printf("HTML Tag Names Found:\n\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
