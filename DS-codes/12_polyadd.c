#include <stdio.h>
#include <stdlib.h>

struct poly {
    int exp;
    int coef;
};

int main() 
{
    int i, j, k, n, m;
    printf("Enter the size of the first polynomial : ");
    scanf("%d", &n);
    printf("Enter the size of the second polynomial : ");
    scanf("%d", &m);
    struct poly a[n], b[m], sum[n+m];
    printf("Enter the polynomial 1\n");
    for (i = 0; i < n; i++) {
        printf("Enter coef x^ exp : ");
        scanf("%d %d", &a[i].coef, &a[i].exp);
    }

    printf("Enter the polynomial 2\n");
    for (i = 0; i < m; i++) {
        printf("Enter coef x^ exp : ");
        scanf("%d %d", &b[i].coef, &b[i].exp);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < n && j < m) {
        if (a[i].exp == b[j].exp) {
            sum[k].coef = a[i].coef + b[j].coef;
            sum[k].exp = a[i].exp;
            i++;
            j++;
            k++;
        } else if (a[i].exp < b[j].exp) {
            sum[k].coef = b[j].coef;
            sum[k].exp = b[j].exp;
            j++;
            k++;
        } else {
            sum[k].coef = a[i].coef;
            sum[k].exp = a[i].exp;
            i++;
            k++;
        }
    }

    while (i < n) {
        sum[k].coef = a[i].coef;
        sum[k].exp = a[i].exp;
        i++;
        k++;
    }

    while (j < m) {
        sum[k].coef = b[j].coef;
        sum[k].exp = b[j].exp;
        j++;
        k++;
    }

    printf("Resultant polynomial after addition:\n");
    for (i = 0; i < k; i++) {
        printf("%dx^%d ", sum[i].coef, sum[i].exp);
        if (i < k - 1) {
            printf("+ ");
        }
    }
    printf("\n");

    return 0;
}
