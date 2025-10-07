%{
#include<stdio.h>
int vc=0,cc=0;
%}

%%
[aeiouAEIOU]  { vc++; }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]   {cc++;}

%%
int main(){
    yylex();
    printf("Vowels= %d\n Consonants= %d",vc,cc);
    return 0;

}
int yywrap(){
    return 1;
}
