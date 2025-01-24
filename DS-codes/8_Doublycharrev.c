#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, char data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int isPalindrome(struct Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    while (head != tail) {
        if (head->data != tail->data) {
            return 0;
        }
        head = head->next;
        tail = tail->prev;
    }

    return 1;
}

void reverseList(struct Node** head) {
    Node* temp = NULL;
    Node* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct Node* head = NULL;
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character from fgets input

    for (int i = 0; i < strlen(str); i++) {
        insertEnd(&head, str[i]);
    }

    printf("Original List: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome. Reversing...\n");
        reverseList(&head);
        printf("Reversed List: ");
        printList(head);
    }

    return 0;
}
