#include<stdio.h>
#include<stdlib.h>
int choice ,data;
struct node{
    int data;
    struct node*next;
};
struct node*front=NULL;
struct node*ptr=NULL;

struct node*rear=NULL;
struct node *new=NULL;


void enq(){
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("not enough mem");

    }
    new->data=data;
    
    if(front==NULL&&rear==NULL){
        front=rear=new;
        new->next=NULL;

    }else{
        ptr=front;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new;
        new->next=NULL;
    }
}

void deq(){
    if(front==NULL&&rear==NULL){
        printf("empty");
    }else{
    data=front->data;
    printf("%d got deleted ",data);
   
        ptr=front;
        front=front->next;
        free(ptr);
        if(front==NULL){
            rear=NULL;
        }
    
    }
}


void dis(){
    if(front==NULL&&rear==NULL){
        printf("empty");
    }else{
        ptr=front;
        while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
    }
}



int main(){
    do{
        printf("\n1.enq\n2.deq\n3.display\n4.exit");
        printf("\nenter the choice");
        scanf("%d",&choice);
    switch(choice){
        case 1: printf("\nenter the element to enque : ");
        scanf("%d",&data);
        enq();
        break;

        case 2: deq();
        break;
        case 3: dis();

    }
    }while(choice!=4);
}