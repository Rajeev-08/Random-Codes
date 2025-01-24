#include<stdio.h>
#include<stdlib.h>
#define n 5
int f=-1,r=-1,q[n];
void Enqueue(){
    if(f==(r+1)%n){
        printf("overflow");
        return;
    }if(f==-1&&r==-1){
        f=r=0;
    }else{
        r=(r+1)%n;
    }printf("enter the value : ");
    scanf("%d",&q[r]);
}
void Dequeue(){
    if(f==-1&&r==-1){
        printf("underflow");
    }if(f==r){
        
        f=r=-1;
    }else{
        f=(f+1)%n;
    }
}
void Display(){
    if(f==-1&&r==-1){
        printf("underflow");
    }if(f<=r){
        for(int i=f;i<=r;i++){
            printf("%d ",q[i]);
        }}else{
             for(int i=f;i<=n;i++){
            printf("%d ",q[i]);
        }
        }}

int main() {
    int choice, data;
    printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
    do {
        
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
