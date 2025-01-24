#include<stdio.h>
#include<stdlib.h>
struct node{
    int co;
    int exp;
    struct node*next;
};

struct node* insert(struct node* head, int C, int E) {
    struct node* ptr;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->co = C;
    new->exp = E;
    new->next = NULL;

    if (head == NULL || head->exp < E) {
        new->next = head;
        head = new;
    } else {
        ptr = head;
        while (ptr->next != NULL && ptr->next->exp >= E) {
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    return head;
}

void print(struct node*head){
    if(head==NULL){
        printf("not avia");
    }else{
        struct node*ptr=head;
        while(ptr!=NULL){
            printf("%dx^%d",ptr->co,ptr->exp);
            ptr=ptr->next;
            if(ptr!=NULL){
            printf(" + ");
            }
            else{
            printf("\n");
            }
        }
    }
}

void polyadd(struct node*head1,struct node*head2){
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    struct node*head3=NULL;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->exp==ptr2->exp){
            head3=insert(head3,ptr1->co+ptr2->co,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if(ptr1->exp>ptr2->exp){
            head3=insert(head3,ptr1->co,ptr1->exp);
            ptr1=ptr1->next;
        }else if(ptr1->exp<ptr2->exp){
            head3=insert(head3,ptr2->co,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->co,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->co,ptr2->exp);
        ptr2=ptr2->next;
    }
    printf("reuslt\n");
    print(head3);
}
void polymul(struct node*head1,struct node*head2){
     struct node*ptr1=head1;
    struct node*ptr2=head2;
    struct node*head3=NULL;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            head3=insert(head3,ptr1->co*ptr2->co,ptr1->exp+ptr2->exp);
            ptr2=ptr2->next;

        }
        ptr1=ptr1->next;
        ptr2=head2;
    }
    printf("after mul\n");
    print(head3);
}
struct node*create(struct node*head){
    int n,E;
int C;
    printf("enter the no of terms :\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("enter the cofeffient and exponenent term %d : ",i);
    scanf("%d%d",&C,&E);
    head=insert(head,C,E);
}
return head;
}


int main(){
    struct node*head1=NULL;
    struct node*head2=NULL;
    printf("enter the first polynomial\n");
    head1=create(head1);
    printf("enter the second polynomial\n");
    head2=create(head2);
    polyadd(head1,head2);
    polymul(head1,head2);
}