#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to act as the head of the merged list
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;

    // Traverse both lists and append nodes based on their values
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append any remaining nodes from list1 or list2
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Store the head of the merged list
    struct Node* mergedList = dummy->next;
    // Free the dummy node
    free(dummy);
    return mergedList;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for a linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the mergeLists function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element into List 1\n");
        printf("2. Insert element into List 2\n");
        printf("3. Merge Lists\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert into List 1: ");
                scanf("%d", &data);
                if (list1 == NULL)
                    list1 = newNode(data);
                else {
                    struct Node* temp = list1;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode(data);
                }
                break;
            case 2:
                printf("Enter element to insert into List 2: ");
                scanf("%d", &data);
                if (list2 == NULL)
                    list2 = newNode(data);
                else {
                    struct Node* temp = list2;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode(data);
                }
                break;
            case 3:
                mergedList = mergeLists(list1, list2);
                printf("Merged List: ");
                printList(mergedList);
                // Free the memory allocated for the merged list
                freeList(mergedList);
                mergedList = NULL;
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the input lists
    freeList(list1);
    freeList(list2);

    return 0;
}
