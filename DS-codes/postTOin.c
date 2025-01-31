#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* item) {
    strcpy(stack[++top], item);
}

char* pop() {
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postfixToInfix(char postfix[]) {
    char operand1[MAX], operand2[MAX], temp[MAX];
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            sprintf(temp, "%c", postfix[i]);
            push(temp);
        } else if (isOperator(postfix[i])) {
            strcpy(operand2, pop());
            strcpy(operand1, pop());
            sprintf(temp, "(%s%c%s)", operand1, postfix[i], operand2);
            push(temp);
        }
    }
    printf("Infix expression: %s\n", stack[top]);
}

int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix);
    return 0;
}

