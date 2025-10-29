#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char prod[MAX][MAX];  // Productions
int n;                // Number of productions

// Function declarations
void findFirst(char, int, int);
void findFollow(char);
char first[100], follow[100];  // Increased size

int isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

// ---------- FIND FIRST ----------
void findFirst(char c, int q1, int q2) {
    if (!isNonTerminal(c)) {  // Terminal
        if (!strchr(first, c))
            strncat(first, &c, 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            if (prod[i][2] == '#') { // Epsilon
                if (!strchr(first, '#'))
                    strncat(first, "#", 1);
            } else if (!isNonTerminal(prod[i][2])) {
                if (!strchr(first, prod[i][2]))
                    strncat(first, &prod[i][2], 1);
            } else {
                findFirst(prod[i][2], q1, q2);
            }
        }
    }
}

// ---------- FIND FOLLOW ----------
void findFollow(char c) {
    if (prod[0][0] == c) {  // Start symbol
        if (!strchr(follow, '$'))
            strncat(follow, "$", 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(prod[i]); j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0') {
                    first[0] = '\0';  // Clear first before reuse
                    findFirst(prod[i][j + 1], 0, 0);
                    for (int k = 0; k < strlen(first); k++) {
                        if (first[k] != '#' && !strchr(follow, first[k]))
                            strncat(follow, &first[k], 1);
                    }
                    if (strchr(first, '#') && prod[i][0] != c)
                        findFollow(prod[i][0]);
                } else if (prod[i][0] != c)
                    findFollow(prod[i][0]);
            }
        }
    }
}

// ---------- MAIN ----------
int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (like E=E+T):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    char c;
    printf("\nEnter the non-terminal to find FIRST & FOLLOW: ");
    scanf(" %c", &c);

    first[0] = '\0';
    findFirst(c, 0, 0);
    printf("FIRST(%c) = { ", c);
    for (int i = 0; i < strlen(first); i++)
        printf("%c ", first[i]);
    printf("}\n");

    follow[0] = '\0';
    findFollow(c);
    printf("FOLLOW(%c) = { ", c);
    for (int i = 0; i < strlen(follow); i++)
        printf("%c ", follow[i]);
    printf("}\n");

    return 0;
}
