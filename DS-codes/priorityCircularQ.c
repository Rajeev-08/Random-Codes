#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5
// Define the structure for a priority element
struct Priority {
int value;
int priority;
};
// Define the circular queue
struct Priority cq[MAX_SIZE];
int front = -1;
int rear = -1;
// Function to check if the circular queue is empty
bool isEmpty() {
return front == -1 && rear == -1;
}
// Function to check if the circular queue is full
bool isFull() {
return ((rear + 1) % MAX_SIZE == front);
}
// Function to enqueue an element with priority
void enqueue(int value, int priority) {
if (isFull()) {
printf("Queue is full. Cannot enqueue.\n");
return;
}
struct Priority newItem;
newItem.value = value;
newItem.priority = priority;
if (isEmpty()) {
front = rear = 0;
cq[rear] = newItem;
} else {
int pos = rear;
while (pos >= front && newItem.priority < cq[pos].priority) {
cq[(pos + 1) % MAX_SIZE] = cq[pos];
pos = (pos - 1 + MAX_SIZE) % MAX_SIZE;
}
cq[(pos + 1) % MAX_SIZE] = newItem;
rear = (rear + 1) % MAX_SIZE;
}
}
// Function to dequeue the element with the highest priority
void dequeue() {
if (isEmpty()) {
printf("Queue is empty. Cannot dequeue.\n");
return;
}
printf("Dequeued: value = %d, priority = %d\n", cq[front].value, 
cq[front].priority);
if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % MAX_SIZE;
}
}
// Function to display the elements in the queue
void display() {
if (isEmpty()) {
    printf("Queue is empty.\n");
return;
}
printf("Elements in the queue:\n");
int i = front;
do {
printf("value = %d, priority = %d\n", cq[i].value, cq[i].priority);
i = (i + 1) % MAX_SIZE;
} while (i != (rear + 1) % MAX_SIZE);
}
int main() {
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
if (isFull()) {
printf("Queue is full. Cannot enqueue.\n");
} else {
int value, priority;
printf("Enter value and priority: ");
scanf("%d %d", &value, &priority);
enqueue(value, priority);
}
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