#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("\nEnter the size of disk: ");
    scanf("%d", &size);

    int i, j, block[size], n;
    for (i = 0; i < size; i++)
        block[i] = -1;

    printf("\nEnter the number of files: ");
    scanf("%d", &n);

    int start[n], length[n];
    int st = 0, l;

    for (i = 0; i < n; i++) {
        start[i] = -1;
        length[i] = -1;

        printf("\nEnter the starting address and length for file %d: ", i);
        scanf("%d %d", &st, &l);

        if (st >= size || st < 0 || (st + l) > size) {
            printf("\nInvalid range\n");
            continue;
        }

        int flag = 0;
        for (j = st; j < (st + l); j++) {
            if (block[j] > -1) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\nFile can't be allocated due to overlap\n");
        } else {
            start[i] = st;
            length[i] = l;
            for (j = st; j < (st + l); j++) {
                block[j] = i;
            }
        }
    }

    printf("\nFile Table\nFile Name\tStart\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d", i);
        if (start[i] != -1) {
            printf("\t\t%d\t%d\n", start[i], length[i]);
        } else {
            printf("\t\tNILL\tNILL\n");
        }
    }

    printf("\nBlock Representation\n");
    for (i = 0; i < size; i++) {
        if (block[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", block[i]);
        }
    }

    return 0;
}
