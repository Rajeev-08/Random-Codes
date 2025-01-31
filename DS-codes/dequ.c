#include<stdio.h>
int q[100],n,f=-1,r=-1,i;

void inf(int item){
    if(f==0&&r==n-1){
        printf("\nfull");

    }else if(f==-1&&r==-1){
        f=r=0;
        q[f]=item;
    }else if(f==0&&r!=n-1){
       i=r;
        while(i>=f){
            q[i+1]=q[i];
            i--;
        }
        q[i+1]=item;
        r++;

    }else{
        f--;
        q[f]=item;
    }


}

void inr(int item){
    if(r==n-1){
        printf("\nfull");

    }else if(f==-1&&r==-1){
        f=r=0;
        q[r]=item;
    }else{
        r++;
        q[r]=item;
    }
}
void delf(){
    if(f==-1){
        printf("\nempty");
    }
    if(f==0&&r==0){
        f=r=-1;
    }else {
        f++;

    }
}

void delr(){
    if(f==-1&&r==-1){
        printf("\nempty");
    }else if(f==0&&r==0){
        f=r=-1;
    }else{
        r--;
    }
}

void dis(){
    if(f==-1){
        printf("\n empty");
    }else{
        for(i=f;i<=r;i++){
            printf("%d ",q[i]);
        }
    }
}

int main(){
    int choice,data;
    printf("\nenter the size :");
    scanf("%d",&n);
    do{
        printf("\n1.inf\n2.inr\n3.delf\n4.delr\n5.dis");
        printf("\nenter the choice :");
        scanf("%d",&choice);  
        switch(choice){
            case 1:printf("\nEnter the data to insert :");
            scanf("%d",&data);
            inf(data);break;
            case 2:printf("\nEnter the data to insert :");
            scanf("%d",&data);
            inr(data);break;
            case 3:delf();break;
            case 4: delr();break;
            case 5:dis();
            break;
        }
        
          
}while(choice!=6);
}