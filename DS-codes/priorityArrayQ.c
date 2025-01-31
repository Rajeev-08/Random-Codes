#include<stdio.h>
#include<stdlib.h>
#define n 6
struct Priority{
    int value;
    int priority;
};
struct Priority q[n];
int f=-1,r=-1,i;
void enqueue(int value, int priority) {
    if (r == n - 1) {
        printf("Overflow. Cannot enqueue.\n");
        return;
    }
    struct Priority item;
    item.value = value;
    item.priority = priority;
    // Find the correct position to maintain priority order
      int i = r;
    while (i >= 0 && item.priority < q[i].priority) {
        q[i + 1] = q[i];
        i--;
    }
    q[i + 1] = item;
    r++;
}
void dequeue(){
    if(r==-1){
        printf("underflow");
        return;
    }
    printf("dequeued va=%d ,priority=%d \n",q[0].value,q[0].priority);
    for(int i=0;i<r;i++){
        q[i]=q[i+1];
    }
    r--;
}
void display() {
    if (r == -1) {
        printf("Queue is empty. Cannot display.\n");
        return;
    }
    printf("Elements are:\n");
    for (i = 0; i <= r; i++) {
        printf("value=%d, priority=%d\n", q[i].value, q[i].priority);
    }
    printf("\n");
}
int main() {
    int val, priority;
    int choice;   
    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:  
                    printf("Enter value and priority: ");
                    scanf("%d %d", &val, &priority);
                    enqueue(val, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}