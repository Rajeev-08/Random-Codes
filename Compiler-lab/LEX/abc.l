%{
#include<stdio.h>
%}

%%
abc     { printf("ABC"); }
.|\n    {ECHO;}
%%
int main(){
    yylex();

}
int yywrap(){
    return 1;
}
