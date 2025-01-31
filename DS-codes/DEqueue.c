#include <stdio.h>
#include <stdlib.h>
#define n 4
int f = -1;
int r = -1;
int deque[n];
void insertFront() {
if ((r + 1) % n == f) {
printf("Deque is full. Cannot insert at the front.\n");
return;
}
if (f == -1 && r == -1) {
f = r = 0;
} else {
f = (f - 1 + n) % n;
}
printf("Enter the item to be added to the queue: ");
scanf("%d",&deque[f]);
}
void insertRear() {
if ((r + 1) % n == f) {
printf("Deque is full. Cannot insert at the rear.\n");
return;
}
if (f == -1 && r == -1) {
f = r = 0;
} else {
r = (r + 1) % n;
}
printf("Enter the item to be added to the queue: ");
scanf("%d",&deque[r]);
}
void deleteFront() {
if (f == -1 && r == -1) {
printf("Deque is empty. Cannot delete from the front.\n");
return;
}
printf("%d has been deleted...!\n",deque[f]);
if (f == r) {
f = r = -1;
} else {
f = (f + 1) % n;
}
}
void deleteRear() {
if (f == -1 && r == -1) {
printf("Deque is empty. Cannot delete from the rear.\n");
return;
}
printf("%d has been deleted...!\n",deque[r]);
if (f == r) {
f = r = -1;
} else {
r = (r - 1 + n) % n;
}
}
void display() {
if (f == -1 && r == -1) {
printf("Deque is empty.\n");
return;
}
int i = f;
printf("Queue elements are: ");
do
{
printf("\t%d", deque[i]);
i = (i + 1) % n;
} while (i != (r + 1) % n);
printf("\n");
}
void main()
{
printf("<<- Menu ->>\n1. Enqueue at front\n2. Enqueue at rear\n3.Dequeue at front\n4. Dequeue at rear\n5. Display the Deque\n6. Exit\n");
int choice;
while (1)
{
printf("\nEnter the operation to be executed:");
scanf("%d", &choice);
switch (choice)
{
case 1:
insertFront();
break;
case 2:
insertRear();
break;
case 3:
deleteFront();
break;
case 4:
deleteRear();
break;
case 5:
display();
break;
case 6:
exit(0);
default:
printf("Invalid Operation\n");
}
}
}
