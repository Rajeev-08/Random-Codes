#include<stdio.h>
#include<math.h>
 char infix[100],postfix[100],stack[100],c,ch;
int top=-1,j=0,i,estack[100];
int evaluate(int a,int b,char c){
    switch(c){
        case '^':return(pow(a,b));
        case '*':return(a*b);
        case '/':return(a/b);
        case '+':return(a+b);
        case '-':return(a-b);
        default : return 0;
    }
}

int prec(char c){
    switch(c){
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        default: return 0;
    }
}
int isoper(char c){
    switch(c){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
                 return 1;
        default : return 0;
    }
}
char *infixTOpostfix(char infix[],char postfix[]){
stack[++top]='(';
for(i=0;infix[i]!='\0';i++){
     c=infix[i];
    if(!isoper(c)&&c!='('&&c!=')'){
        postfix[j++]=c;
    }else if(c=='('){
        stack[++top]=c;
    }else if(isoper(c)){
        while(top>=0&&prec(c)<=prec(stack[top])){
             ch=stack[top--];
            if(ch=='(')
            break;
            postfix[j++]=ch;
        }
        stack[++top]=c;
    }else if(c==')'){
        while(top>=0){
                ch=stack[top--];
                if(ch=='(')
                break;
                postfix[j++]=ch;
        }
    }
}
while(top>=0){
    ch=stack[top--];
    if(ch=='(')
    continue;
    postfix[j++]=ch;
}
postfix[j]='\0';
return postfix;
}
int evalpost(char postfix[]){
    for(i=0;postfix[i]!='\0';i++){
        c=postfix[i];
        if(isoper(c)){
            estack[++top]=evaluate(estack[top--],estack[top--],c);
        }else{
            estack[++top]=c-48;
        }
    }
    return estack[top];
}
int main(){
   
    printf("enter the infix : ");
    scanf("%s",infix);
    infixTOpostfix(infix,postfix);
    printf("postfix form\n");
    for(i=0;postfix[i]!='\0';i++){
        printf("%c",postfix[i]);
    }
        printf("\n");
        printf("result = %d\n",evalpost(postfix));   
}