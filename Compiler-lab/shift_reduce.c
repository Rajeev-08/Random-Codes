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
        if (t > 2 && s[t-3]=='(' && s[t-2]=='S' && s[t-1]==')') {
            t -= 3;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 2 && s[t-3]=='{' && s[t-2]=='S' && s[t-1]=='}') {
            t -= 3;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 2 && s[t-3]=='[' && s[t-2]=='S' && s[t-1]==']') {
            t -= 3;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 1 && s[t-2]=='(' && s[t-1]==')') {
            t -= 2;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 1 && s[t-2]=='{' && s[t-1]=='}') {
            t -= 2;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 1 && s[t-2]=='[' && s[t-1]==']') {
            t -= 2;
            s[t++] = 'B';
            changed = 1;
            printStack();
            continue;
        }
        if (t > 1 && s[t-2]=='S' && s[t-1]=='B') {
            t--;
            changed = 1;
            printStack();
            continue;
        }
        if (t > 0 && s[t-1]=='B') {
            s[t-1] = 'S';
            changed = 1;
            printStack();
            continue;
        }
    } while (changed);
}

int main() {
    printf("Grammar:\nS->SB | B\nB->(S) | {S} | [S] | () | {} | []\n");
    printf("Enter input: ");
    if (scanf("%255s", b) != 1) return 0;
    while (b[p] != '\0') {
        s[t++] = b[p++];
        printStack();
        R();
    }
    R();
    if (t == 1 && s[0] == 'S') printf("Success\n");
    else {
        printf("Failed\n");
        printStack();
    }
    return 0;
}

Output:
Grammar:
S->SB | B
B->(S) | {S} | [S] | () | {} | []
Enter input: (){}([])
