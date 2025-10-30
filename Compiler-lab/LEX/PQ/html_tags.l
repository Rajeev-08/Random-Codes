%{
#include <stdio.h>
%}

TAG     \<[ \t\/]*[a-zA-Z0-9]+[ \t]*\>     // matches <tag> or </tag>
NAME    [a-zA-Z0-9]+                       // tag name pattern

%%
\<[ \t]*([a-zA-Z0-9]+)[^>]*\>     { 
    printf("Start Tag: %s\n", yytext + 1); 
}

\<[ \t]*\/([a-zA-Z0-9]+)[^>]*\>   { 
    printf("End Tag: %s\n", yytext + 2); 
}

.|\n    ;   // ignore other characters
%%

int main() {
    printf("HTML Tag Names Found:\n\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
