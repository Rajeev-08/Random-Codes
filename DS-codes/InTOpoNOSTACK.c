#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infix_to_postfix(char* infix, char* postfix) {
    int i, j;
    int len = strlen(infix);
    int top = -1; // Index of top of the operator queue
    char operator_queue[MAX_SIZE]; // Operator queue

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') { // Operand
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            operator_queue[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && operator_queue[top] != '(') {
                postfix[j++] = operator_queue[top--];
            }
            top--; // Discard the '('
        } else { // Operator
            while (top != -1 && precedence(operator_queue[top]) >= precedence(infix[i])) {
                postfix[j++] = operator_queue[top--];
            }
            operator_queue[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[j++] = operator_queue[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
