#include<stdio.h>
int S[10][10],T[10][10];
void Sparse(int A[10][10],int r,int c){
    int i,j,k=1;
    S[0][0]=r;
    S[0][1]=c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if (A[i][j]!=0)
            {
                S[k][0]=i;
                S[k][1]=j;
                S[k][2]=A[i][j];
                k++;
            }
        }
    }

S[0][2]=k-1;
printf(" Tuple form");
printf("\n");
for(i=0;i<k;i++){
    for(j=0;j<3;j++){
        
        printf("\t\t%d",S[i][j]);
    }
    printf("\n");
}
}
void Transpose() {
    int r, c, k, i, j;
    T[0][0] = S[0][1];
    T[0][1] = S[0][0];
    T[0][2] = S[0][2];
    k = 1;

    printf("Transpose Matrix:\n");
    for (i = 0; i < S[0][1]; i++) {
        for (j = 1; j <=S[0][2]; j++) {
            if (S[j][1] == i) {
                T[k][0] = S[j][1];
                T[k][1] = S[j][0];
                T[k][2] = S[j][2];
                k = k + 1;
            }
        }
    }

    for (i = 0; i < k; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int i,j,A[10][10],r,c;
    printf("Enter the number of rows and  columns of the matrix : ");
    scanf("%d%d",&r,&c);
    printf("enter the matrix");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
            Sparse(A,r,c);
            Transpose();
    }