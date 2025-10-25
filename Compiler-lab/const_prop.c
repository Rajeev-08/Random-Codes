#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char expr[50];
    int val[26] = {0};   // store values for a-z
    printf("Enter expressions (e.g., a=5, b=10, c=a+b). Type 'end' to stop.\n");

    while (1) {
        printf(">>> ");
        scanf("%s", expr);
        if (strcmp(expr, "end") == 0) break;

        char var = expr[0];
        char *rhs = strchr(expr, '=') + 1;

        int num1 = 0, num2 = 0;
        char op = 0;
        char left[10] = "", right[10] = "";

        // split operands and operator
        int i = 0, j = 0;
        while (rhs[i] && !strchr("+-*/", rhs[i])) left[j++] = rhs[i++];
        left[j] = '\0';
        if (rhs[i]) op = rhs[i++];
        strcpy(right, rhs + i);

        // evaluate left operand
        if (isalpha(left[0]))
            num1 = val[left[0] - 'a'];
        else
            num1 = atoi(left);

        // if no operator (like f=e)
        if (!op) {
            val[var - 'a'] = num1;
            continue;
        }

        // evaluate right operand
        if (isalpha(right[0]))
            num2 = val[right[0] - 'a'];
        else
            num2 = atoi(right);

        // perform operation
        switch (op) {
            case '+': val[var - 'a'] = num1 + num2; break;
            case '-': val[var - 'a'] = num1 - num2; break;
            case '*': val[var - 'a'] = num1 * num2; break;
            case '/': val[var - 'a'] = num2 ? num1 / num2 : 0; break;
        }
    }

    printf("\nAfter Constant Propagation:\n");
    for (int i = 0; i < 26; i++) {
        if (val[i] != 0)
            printf("%c = %d\n", i + 'a', val[i]);
    }

    return 0;
}
