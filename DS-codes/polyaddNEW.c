#include<stdio.h>
struct poly{
    int coef;
    int exp;
};
struct poly a[50],b[50],sum[100],item;
int i,j,k,n1,n2,m;

void insert(struct poly c[],int coef,int exp){
    item.exp=exp;
    item.coef=coef;

  if(c[0].coef==0){
    c[0]=item;
    m++;
   }else{
    k=m;
    while(k>=0&&c[k].exp<exp){
        c[k+1]=c[k];
        k--;

    }
    c[k+1]=item;
    m++;
   }
}

void add(){
    i=0;
    j=0;
    k=0;
    
    while(i<n1&&j<n2){
        if(a[i].exp==b[j].exp){
            insert(sum,a[i].coef+b[j].coef,a[i].exp);
            i++;
            j++;
            k++;
            
        }else if(a[i].exp>b[j].exp){
            insert(sum,a[i].coef,a[i].exp);
            i++;
            k++;

        }else if(a[i].exp<b[j].exp){
            insert(sum,b[j].coef,b[j].exp);
            j++;
            k++;
        }
    }
    while(i<n1){
         insert(sum,a[i].coef,a[i].exp);
            i++;
            k++;

    }
    while(j<n2){
        insert(sum,b[j].coef,b[j].exp);
            j++;
            k++;

    }
    printf("\n result:");
     for(i=0;i<k;i++){
        printf("%dx^%d ",sum[i].coef,sum[i].exp);
        if(i<k-1){
            printf("+");
        }
    }
}

void print(struct poly a[],int n){
    for(i=0;i<n;i++){
        printf("%dx^%d ",a[i].coef,a[i].exp);
        if(i<n-1){
            printf("+");
        }
    }
}
int main(){
    int exp,coef;
    printf("\n Enter the size of the poly 1 :");
    scanf("%d",&n1);
    
    printf("\n Enter the size of the poly 2 :");
    scanf("%d",&n2);

    printf("\nEnter the polynomial 1:");
    for(int i=0;i<n1;i++){
    printf("\nEnter %dth coef ,exp :",i);
    scanf("%d%d",&coef,&exp);
    insert(a,coef,exp);
    }
    

    printf("\nEnter the polynomial 2:");
    for(int i=0;i<n2;i++){
    printf("\nEnter %dth coef ,exp :",i);
    scanf("%d%d",&coef,&exp);
    insert(b,coef,exp);
    }
    printf("\npoly 1:");
    print(a,n1);
    printf("\n");
printf("\npoly 2:");

    print(b,n2);
    add();
    
}