#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int top = -1;
char array[MAX_SIZE][100];

int isEmpty() {
    return top == -1;
}

char* peek() {
    return array[top];
}

char* pop() {
    if (!isEmpty())
        return array[top--];
    return NULL;
}

void push(char* op) {
    strcpy(array[++top], op);
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char* postfixToInfix(char* postfix) {
    int len = strlen(postfix);
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            push(operand);
        } else {
            char operand1[100], operand2[100], temp[100];
            strcpy(operand1, pop());
            strcpy(operand2, pop());
            sprintf(temp, "(%s%c%s)", operand2, postfix[i], operand1);
            push(temp);
        }
    }
    return array[0];
}

int main() {
    char postfix[MAX_SIZE];
    
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    char* infix = postfixToInfix(postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);

    return 0;
}
