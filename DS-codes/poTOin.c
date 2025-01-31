#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100][100];
int top=-1;


void push(char*item){
   strcpy(stack[++top],item);
}

char*pop(){
    return stack[top--];
}

int isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

void intopo(char postfix[]){
    char operand1[100],operand2[100],temp[100];
    char c;
    for(int i=0;postfix[i]!='\0';i++){
        c=postfix[i];
        if(isalnum(c)){
            sprintf(temp,"%c",c);
            push(temp);
        }
        
        else if(isOperator(c)){
            strcpy(operand2,pop());
            strcpy(operand1,pop());
            sprintf(temp,"(%s%c%s)",operand1,c,operand2);
            push(temp);
        }
    }
    printf("\ninfix : %s",stack[top]);
}

int main(){
    char postfix[100];
    printf("enter a post exp :");
    scanf("%s",postfix);
    intopo(postfix);
}