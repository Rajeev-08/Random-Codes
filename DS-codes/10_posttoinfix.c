#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char** array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char* peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char* pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return NULL;
}

void push(struct Stack* stack, char* op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char* postfixToInfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int len = strlen(postfix);
    for (int i = 0; i < len; i++) {
        if (isOperand(postfix[i])) {
            char* operand = (char*)malloc(2);
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(stack, operand);
        } else {
            char* operand1 = pop(stack);
            char* operand2 = pop(stack);
            char* temp = (char*)malloc(strlen(operand2) + 3 + strlen(operand1));
            sprintf(temp, "(%s%c%s)", operand2, postfix[i], operand1);
            push(stack, temp);
        }
    }
    return stack->array[0];
}

int main() {
    char postfix[] = "abc/-ad/e-*";
    char* infix = postfixToInfix(postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);

    return 0;
}
