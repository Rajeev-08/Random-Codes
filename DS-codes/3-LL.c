#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*new=NULL;
struct node*ptr=NULL;
struct node*prev=NULL;
int val;
void getnode(){
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("NoT enough memory");
    }else{
        printf("enter the value to be inserted : ");
        scanf("%d",&val);
        new->data=val;
    }
}
void display(){
    ptr=head;
    if(ptr==NULL){
        printf("list is empty ");
    }else{
        printf("elments are\n");
        while(ptr!=NULL){
            printf("\n%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void create(){
    getnode();
    new->next=NULL;
    head=new;
}
void INback(){
    getnode();
    new->next=NULL;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }ptr->next=new;
}
void INfront(){
    getnode();
    new->next=head;
    head=new;
}
void INposition(){
    int key;
    if(head==NULL){
        create();
    }else{
        printf("enter the element after where you want to insert : ");
        scanf("%d",&key);
        ptr=head;
        while((ptr->next!=NULL)&&(ptr->data!=key)){
            ptr=ptr->next;
        }if (ptr==NULL){
            printf("element with key %d not found on the list",key);
        }else{
            getnode();
            new->next=ptr->next;
            ptr->next=new;
        }

    }
}
void delfront(){

    if(head==NULL){
        printf("list is empty");
    }else{
        ptr=head;
    
        head=head->next;
        free(ptr);
    }
}
void delend(){
    if(head==NULL){
        printf("list is empty");
    }else if(head->next==NULL){
        free(head);
        head=NULL;
    }else{
        ptr=head;
        while(ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;
        }free(ptr);
        prev->next=NULL;
    }
}
void delpos(){
    if(head==NULL){
        printf("empty");
    }else{
        ptr=head;
        printf("enter the value to delete : ");
        scanf("%d",&val);
        while(ptr!=NULL&&ptr->data==val){
            prev=ptr;
            ptr=ptr->next;
        }if(ptr==NULL){
            printf("element not found");
        }else{
            prev->next=ptr->next;
            free(ptr);

        }
    }
}
int main() {
    int choice;

    while (1) {
            printf("\n1. Create a Linked List\n2. Display the Linked List\n3. Exit\n4. Insert at the back\n5. Insert at the front\n6. Insert at a position\n7. Delete from the end\n8. Delete from the front\n9. Delete from a position\n");

        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                // Deallocate memory before exiting
                while (head != NULL) {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0; // or break; to exit the loop
            case 4:
                INback();
                break;
            case 5:
                INfront();
                break;
            case 6:
                INposition();
                break;
            case 7:
                delend();
                break;
            case 8:
                delfront();
                break;
            case 9:
                delpos();
                break;
            default:
                printf("\nInvalid Operation\n");
        }
    }
}
