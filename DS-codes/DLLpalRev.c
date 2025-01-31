#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
    struct node*next;
    struct node*prev;
};
char text[100];
char item;
struct node*head=NULL;
struct node*new=NULL;
struct node*tail=NULL;
  

void getNode(char item){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=item;
    new->next=new->prev=NULL;

}

void insert(char item){
    getNode(item);
    if(head==NULL)
{  
    head=new;
}
else{
    struct node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new;
    new->prev=ptr;
}
}

int isp(){
    tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    while(head!=tail){
        if(head->data!=tail->data){
            return 0;
        }
        else{
            head=head->next;
            tail=tail->prev;
        }
       
    }
     return 1;
}


struct node*rev(struct node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }else{
        struct node*newList=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return newList;
    }
}

void print(struct node*head){
    struct node*ptr=head;
    while(ptr!=NULL){
        printf("%c",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node*newList;
printf("\nenter a string :");
scanf("%s",text);
for(int i=0;text[i]!='\0';i++){
    insert(text[i]);
}
if(isp()){
    printf("\nPallindrome");
}else{
    printf("\nNot");
    printf("\nreversed List :");
    newList=rev(head);
    print(newList);
    
}
}
