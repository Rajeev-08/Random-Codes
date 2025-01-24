#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue using two stacks
struct Queue {
    struct Node* stack1; // For enqueue operation
    struct Node* stack2; // For dequeue operation
};

// Function to initialize a new queue
void initializeQueue(struct Queue* queue) {
    queue->stack1 = NULL;
    queue->stack2 = NULL;
}

// Function to push a node onto a stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from a stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 represents an empty value
    }

    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);

    return data;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    // Push the element onto stack1
    push(&(queue->stack1), value);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    // If both stacks are empty, the queue is empty
    if (queue->stack1 == NULL && queue->stack2 == NULL) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 represents an empty value
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (queue->stack2 == NULL) {
        while (queue->stack1 != NULL) {
            int data = pop(&(queue->stack1));
            push(&(queue->stack2), data);
        }
    }

    // Pop the front element from stack2
    return pop(&(queue->stack2));
}

// Function to display elements in the queue
void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->stack2;

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = queue->stack1;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    int choice, value;

    do {
        printf("\nQueue using Two Stacks Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                break;

            case 2:
                printf("Dequeue: %d\n", dequeue(&myQueue));
                break;

            case 3:
                displayQueue(&myQueue);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
