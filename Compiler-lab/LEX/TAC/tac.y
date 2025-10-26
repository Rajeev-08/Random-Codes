%{
#include<stdio.h>
#include<ctype.h>
int yylex(void);
void yyerror(const char*s);

char print(char a,char b,char op);

int idx=0;
char temp='A'-1;
%}

%union{
    char symbol;
}

%left '+' '-'
%left '*' '/'
%token <symbol> LETTER NUM
%type <symbol> expr

%%
stmt: LETTER '=' expr '\n'  {
    print($1,$3,'=');
    }
    ;

expr: expr '+' expr {$$=print($1,$3,'+');}
    |expr '-' expr {$$=print($1,$3,'-');}
    |expr '*' expr {$$=print($1,$3,'*');}
    |expr '/' expr {$$=print($1,$3,'/');}
    | '(' expr ')' {$$=$2}
    |NUM             {$$=$1;}
    |LETTER         {$$=$1;}
    ;


%%

char print(char a,char b,char op){
    temp++;
    printf("%c=%c %c %c\n",temp,a,op,b);
    idx++;
    return temp;
} 

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
