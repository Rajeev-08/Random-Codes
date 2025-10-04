#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char *input;
char lookahead;

void E();
void Eprime();
void T();
void Tprime();
void F();
void match(char expected);

void match(char expected) {
    if (lookahead == expected) {
        printf("Matched '%c'\n", lookahead);
        lookahead = *++input; // move to next character
    } else {
        printf("Syntax Error: expected '%c', got '%c'\n", expected, lookahead);
        exit(1);
    }
}

void E() {
    printf("Apply Rule: E -> T E'\n");
    T();
    Eprime();
}

void Eprime() {
    if (lookahead == '+') {
        printf("Apply Rule: E' -> + T E'\n");
        match('+');
        T();
        Eprime();
    } else if (lookahead == '-') {
        printf("Apply Rule: E' -> - T E'\n");
        match('-');
        T();
        Eprime();
    } else {
        printf("Apply Rule: E' -> ε\n");
    }
}

void T() {
    printf("Apply Rule: T -> F T'\n");
    F();
    Tprime();
}

void Tprime() {
    if (lookahead == '*') {
        printf("Apply Rule: T' -> * F T'\n");
        match('*');
        F();
        Tprime();
    } else if (lookahead == '/') {
        printf("Apply Rule: T' -> / F T'\n");
        match('/');
        F();
        Tprime();
    } else {
        printf("Apply Rule: T' -> ε\n");
    }
}

void F() {
    if (lookahead == '(') {
        printf("Apply Rule: F -> ( E )\n");
        match('(');
        E();
        match(')');
    } else if (isdigit(lookahead)) {
        printf("Apply Rule: F -> number\n");
        printf("Matched number: ");
        while (isdigit(lookahead)) {
            printf("%c", lookahead);
            lookahead = *++input; // consume number
        }
        printf("\n");
    } else {
        printf("Syntax Error: unexpected '%c'\n", lookahead);
        exit(1);
    }
}

int main() {
    char str[100];
    printf("Enter expression: ");
    scanf("%s", str);

    input = str;
    lookahead = *input;

    E(); // start parsing

    if (lookahead == '\0') {
        printf("Parsing successful!\n");
    } else {
        printf("Syntax Error: unexpected '%c'\n", lookahead);
    }
    return 0;
}
