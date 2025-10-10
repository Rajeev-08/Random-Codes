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

        // --- F -> (E)
        if (t > 2 && s[t-3]=='(' && s[t-2]=='E' && s[t-1]==')') {
            t -= 3;
            s[t++] = 'F';
            changed = 1;
            printStack();
            continue;
        }

        // --- F -> id (a-z or A-Z)
        if (t > 0 && ((s[t-1]>='a' && s[t-1]<='z') || (s[t-1]>='A' && s[t-1]<='Z'))) {
            s[t-1] = 'F';
            changed = 1;
            printStack();
            continue;
        }

        // --- T -> T * F
        if (t > 2 && s[t-3]=='T' && s[t-2]=='*' && s[t-1]=='F') {
            t -= 3;
            s[t++] = 'T';
            changed = 1;
            printStack();
            continue;
        }

        // --- T -> T / F
        if (t > 2 && s[t-3]=='T' && s[t-2]=='/' && s[t-1]=='F') {
            t -= 3;
            s[t++] = 'T';
            changed = 1;
            printStack();
            continue;
        }

        // --- T -> F
        if (t > 0 && s[t-1]=='F') {
            s[t-1] = 'T';
            changed = 1;
            printStack();
            continue;
        }

        // --- E -> E + T
        if (t > 2 && s[t-3]=='E' && s[t-2]=='+' && s[t-1]=='T') {
            t -= 3;
            s[t++] = 'E';
            changed = 1;
            printStack();
            continue;
        }

        // --- E -> E - T
        if (t > 2 && s[t-3]=='E' && s[t-2]=='-' && s[t-1]=='T') {
            t -= 3;
            s[t++] = 'E';
            changed = 1;
            printStack();
            continue;
        }

        // --- E -> T
        if (t > 0 && s[t-1]=='T') {
            s[t-1] = 'E';
            changed = 1;
            printStack();
            continue;
        }

    } while (changed);
}

int main() {
    printf("Grammar:\n");
    printf("E -> E + T | E - T | T\n");
    printf("T -> T * F | T / F | F\n");
    printf("F -> (E) | id\n");
    printf("---------------------------------\n");
    printf("Enter input: ");
    if (scanf("%255s", b) != 1) return 0;

    while (b[p] != '\0') {
        s[t++] = b[p++];
        printStack();
        R();
    }

    R();

    if (t == 1 && s[0] == 'E')
        printf(" Success: String accepted by grammar.\n");
    else {
        printf(" Failed: String not accepted.\n");
        printStack();
    }

    return 0;
}
