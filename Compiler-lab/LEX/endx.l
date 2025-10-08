%{
#include<stdio.h>
%}
%%
[a-zA-Z0-9]*x    {  printf("Found sring ending with 'x' : %s\n",yytext);  }
.|\n              {  }
%%
int main(){
yylex();
return 0;
}
int yywrap(){
return 1;
]
