#include<stdio.h>
#include<math.h>
char infix[100],postfix[100],stack[100]; 
int estack[100];
int i,j=0,top=-1;


int prec(char c){
  switch(c){
    case '+': 
    case '-':return 1;break; 
    case '/': 
    case '*': return 2;break;
    case '^': return 3;break;
    default:return 0;
  }
}

int isop(char c){
    switch(c){
    case '+': 
    case '-': 
    case '/': 
    case '*':
    case '^': return 1;break;
    default:return 0;

  }
  
}

int operate(int a, int b, char c) {
    switch (c) {
        case '+': return (a + b); break;
        case '-': return (b - a); break;  // Reverse order for subtraction
        case '/': return (b / a); break;  // Reverse order for division
        case '*': return (a * b); break;
        case '^': return pow(a, b); break;
        default: return 0;
    }
}



char *intopo(char infix[],char postfix[]){
    char c,op;
stack[++top]='(';
for(i=0;infix[i]!='\0';i++){
    c=infix[i];
    if(isop(c)){
        
        while(top>=0&&prec(stack[top])>=prec(c)){
            op=stack[top--];
            if(op=='('){
                break;
            }
            postfix[j++]=op;
        }
        stack[++top]=c;
    }else if(!isop(c)&&c!='('&&c!=')'){
        postfix[j++]=c;
    }else if(c=='('){
        stack[++top]=c;
    }else if(c==')'){
        while(top>=0){
                op=stack[top--];
                if(c=='('){
                    break;
                }
               postfix[j++]=op;
        }
        
    }
}


while(top>=0){
    op=stack[top--];
    if(op=='('){
        continue;
    }
    postfix[j++]=op;
}
postfix[j]='\0';
return postfix;

}


int eval(char postfix[]) {
    char c;
    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (isop(c)) {
            int operand2 = estack[top--];
            int operand1 = estack[top--];
            estack[++top] = operate(operand1, operand2, c);
        } else {
            estack[++top] = c - '0';  // Convert character to integer
        }
    }
    return estack[top];
}


int main(){
    printf("enter an infix exp :");
    scanf("%s",infix);
    intopo(infix,postfix);
   for(i=0;postfix[i]!='\0';i++){
        printf("%c",postfix[i]);
    }
    printf("\n result : %d",eval(postfix));
    
}
