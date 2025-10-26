%{
#include <stdio.h>

int a_count = 0;   // counts number of a's
%}

%%

a       { a_count++; }   // count 'a'
b       ;                // ignore 'b'
\n      {
            if (a_count % 2 == 1)
                printf("Accepted: odd number of a's\n");
            else
                printf("Rejected: even number of a's\n");
            a_count = 0;   // reset for next line
        }
.       ;   // ignore other characters
%%

int yywrap() { return 1; }

int main() {
    printf("Enter strings over {a,b} (end each line with Enter):\n");
    yylex();
    return 0;
}
