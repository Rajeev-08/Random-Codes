#include<stdio.h>
#include<string.h>
#define n 20
char txt[100],stack[n];
int top=-1;
void  push(char data){
    if(top==n-1){
        printf("full");
        return;
    }else{
        stack[++top]=data;
    }
}
char pop(){
    if(top==-1){
        printf("empty");
       
    }
        char data=stack[top--];
        return data;
}
int ismatch(char a,char b){
    if(a=='('&&b==')'){
        return 1;
    }else if(a=='{'&&b=='}'){
        return 1;
    }else if(a=='['&&b==']'){
        return 1;
    }else{
    return 0;
    }
}
int isbal(char txt[]){
    for(int i=0;i<strlen(txt);i++){
        if(txt[i]=='('||txt[i]=='{'||txt[i]=='['){
            push(txt[i]);
        }else if(txt[i]==')'||txt[i]=='}'||txt[i]==']'){
            if(top==-1){
            return 0;
            }else if(!ismatch(pop(),txt[i])){
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
    printf("enter an expression with parenthesis : ");
    scanf("%s",txt);
    if(isbal(txt)){
        printf("balanced");
    }else{
        printf("not");
    }
}