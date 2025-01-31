#include<stdio.h>
int a[100],b[100],n,i,j,k;
void swap(int*a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void print(int a[])
{
    printf("\nSorted Array :");
    for(i=1;i<=n;i++){
   printf("%d ",a[i]);
   }
}  

void maxheapify(int a[],int n,int i){
    int large=i;
    int l=2*i;
    int r=2*i+1;
    if(l<=n&&a[l]>a[large]){
        large=l;
    }
    if(r<=n&&a[r]>a[large]){
        large=r;
    }
    if(large!=i){
        swap(&a[large],&a[i]);
        maxheapify(a,n,large);
    }
}
void heapsort(int a[],int n){
    for(i=n/2;i>=1;i--){
        maxheapify(a,n,i);
    }
    for(i=n;i>1;i--){
         swap(&a[1],&a[i]);
        maxheapify(a,i-1,1);
       
    }
}

int main(){
    int choice;
    printf("\nenter the size of array :");
    scanf("%d",&n);
    printf("enter the array :");
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    print(a);

}