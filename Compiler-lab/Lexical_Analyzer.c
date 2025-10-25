#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[20], operators[] = "+-*/%=<>!";
    FILE *fp;
    int i, j = 0;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') && j != 0) {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else if (isdigit(buffer[0]))
                printf("Number: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }

   
        for (i = 0; i < 9; i++) {
            if (ch == operators[i])
                printf("Operator: %c\n", ch);
        }

        if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}')
            printf("Special Symbol: %c\n", ch);
    }

    fclose(fp);
    return 0;
}
/* input.c
int main() {
    int a = 10, b = 20;
    int c = a + b;
    return 0;
}    

*/
