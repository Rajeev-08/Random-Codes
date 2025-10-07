%{
#include<stdio.h>
int c=0;
FILE *out;
%}
%%
"//".* {c++;}
"/*"([^*]|\*+[^*/])*"*"+"/" {c++;}
.|\n {fputc(yytext[0],out);}
%%

int main(){
    FILE *in=fopen("input.c","r");
    out =fopen("output.c","w");
    yyin=in;
    yylex();
    fclose(in);
    fclose(out);
    printf("total comments=%d\n",c);
    return 0;
}
int yywrap(){
    return 1;
}
