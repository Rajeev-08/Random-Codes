#include<stdio.h>
#define n 100
char stack[100],text[100];
int top=-1;


void push(char data){
    if(top==n-1){
        printf("overflow");
    }else{
        stack[++top]=data;
    }
}
char pop(){
    if(top==-1){
        printf("\nunderflow");
        return ' ';
    }else{ 
       return stack[top--];
    }
}

int ismatch(char data1,char data2){
    if(data1=='('&&data2==')'){
        return 1;
    }else if(data1=='{'&&data2=='}'){
        return 1;
    }else if(data1=='['&&data2==']'){
        return 1;
    }
}

int isbalenced(){
    for(int i=0;text[i]!='\0';i++){
        if(text[i]=='('||text[i]=='{'||text[i]=='['){
            push(text[i]);
        }else if(text[i]==')'||text[i]=='}'||text[i]==']'){
            if(top==-1){
                return 0;
            }else if(!ismatch(pop(),text[i])){
                return 0;
            }
        }
    }
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    printf("\nenter an expression with braces :");
    scanf("%s",text);
    if(isbalenced()){
        printf("\n the exp is balenced");

    }else{
        printf("\n the exp is unbalenced");
    }
}
