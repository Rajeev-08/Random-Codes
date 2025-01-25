#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("\nEnter the size of disk: ");
    scanf("%d", &size);

    int block[size];
    for (int i = 0; i < size; i++)
        block[i] = -1;

    int n;
    printf("\nEnter the number of files: ");
    scanf("%d", &n);

    int *table[n], length[n];
    for (int i = 0; i < n; i++) {
        table[i] = NULL;
        length[i] = -1;

        int l;
        printf("\nEnter the length of file %d: ", i);
        scanf("%d", &l);

        if (l > size) {
            printf("File can't be allocated.\n");
        } else {
            table[i] = (int*)malloc(l * sizeof(int));
            length[i] = l;
            for (int j = 0; j < l; j++) {
                int rnd_no;
                do {
                    rnd_no = rand() % size;
                } while (block[rnd_no] != -1);
                block[rnd_no] = i;
                table[i][j] = rnd_no;
            }
        }
    }

    printf("\nFile Table\nFile\tBlocks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
        if (table[i] != NULL) {
            for (int j = 0; j < length[i]; j++) {
                printf("%d ", table[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nDisk Layout:\n");
    for (int i = 0; i < size; i++) 
        printf("%d ", block[i] == -1 ? -1 : block[i]);

    return 0;
}
