%{
#include<stdio.h>
int sc=0,wc=0,lc=0,cc=0;
%}
%%
[\n]  {  lc++;  cc+=yyleng;}
[ \t]  {  sc++;  cc+=yyleng;}
[^\t\n ]  {  wc++;  cc+=yyleng;}
%%

int main(){
printf("Enter the input:\n");
yylex();
printf("lines= %d\n spaces= %d\n words= %d\n No. of chars=%d\n",lc,sc,wc,cc);
}

int yywrap(){
return 1;
}

/*
lex slwc.l
gcc lex.yy.c
./a.out
*/
