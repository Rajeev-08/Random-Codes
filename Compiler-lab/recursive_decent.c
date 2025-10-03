#include <stdio.h>
 #include <ctype.h>
 const char *input;
 char lookahead;   
void E();
 void Eprime();
 void T();
 void Tprime();
 void F();
 void match(char expected);
 // Match expected character and move to next
 void match(char expected) {
    if (lookahead == expected) {
        lookahead = *++input; // move to next character
    } else {
        printf("Syntax Error: expected '%c', got '%c'\n", expected, lookahead);
        exit(1);
    }
 }
 // E -> T E'
 void E() {
    T();
    Eprime();
 }
 // E' -> + T E' | - T E' | ε
 void Eprime() {
    if (lookahead == '+') {
        match('+');
        T();
        Eprime();
    } else if (lookahead == '-') {
        match('-');
        T();
        Eprime();
    } 
}
 // T -> F T'
 void T() {
    F();
    Tprime();
 }
 // T' -> * F T' | / F T' | ε
 void Tprime() {
    if (lookahead == '*') {
        match('*');
        F();
        Tprime();
    } else if (lookahead == '/') {
        match('/');
        F();
        Tprime();
    } 
}
 // F -> ( E ) | id
 void F() {
    if (lookahead == '(') {
        match('(');
        E();
        match(')');
    } else if (isdigit(lookahead)) {
        while (isdigit(lookahead)) lookahead = *++input; // consume number
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
