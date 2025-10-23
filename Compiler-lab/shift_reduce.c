#include <stdio.h>
#include <string.h>

char s[256], b[256];
int t = 0, p = 0;

void printStack() {
    int i;
    printf("Stack: ");
    for (i = 0; i < t; ++i) putchar(s[i]);
    printf("\n");
}

void R() {
    int changed;
    do {
        changed = 0;
        // Reduction: (E) -> E
        if (t >= 3 && s[t-3] == '(' && s[t-2] == 'E' && s[t-1] == ')') {
            t -= 3;
            s[t++] = 'E';
            changed = 1;
            printStack();
            continue;
        }
        // Reduction: E+E -> E
        if (t >= 3 && s[t-3] == 'E' && s[t-2] == '+' && s[t-1] == 'E') {
            t -= 3;
            s[t++] = 'E';
            changed = 1;
            printStack();
            continue;
        }
        // Reduction: E*E -> E
        if (t >= 3 && s[t-3] == 'E' && s[t-2] == '*' && s[t-1] == 'E') {
            t -= 3;
            s[t++] = 'E';
            changed = 1;
            printStack();
            continue;
        }
        // Reduction: i -> E
        if (t >= 1 && s[t-1] == 'i') {
            s[t-1] = 'E';
            changed = 1;
            printStack();
            continue;
        }
    } while (changed);
}

int main() {
    printf("Grammar:\n");
    printf("E -> E+E | E*E | (E) | i\n\n");

    printf("Enter input: ");
    if (scanf("%255s", b) != 1) return 0;

    while (b[p] != '\0') {
        s[t++] = b[p++];
        printStack();
        R();
    }

    R();
    if (t == 1 && s[0] == 'E') 
        printf("Success: Input accepted.\n");
    else {
        printf("Failed: Invalid expression.\n");
        printStack();
    }

    return 0;
}
