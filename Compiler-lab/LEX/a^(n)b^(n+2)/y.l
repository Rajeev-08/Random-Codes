%{
#include "y.tab.h"
%}

%%
a       { return A; }
b       { return B; }
[ \t\n] ;        // ignore spaces and newlines
.       { return -1; }  // invalid char
%%

int yywrap() { return 1; }
