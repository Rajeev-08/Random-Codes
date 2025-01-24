#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure for a student
struct Student {
    int rollNo;
    char name[50];
    int marks;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int rollNo, const char* name, int marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    snprintf(newStudent->name, sizeof(newStudent->name), "%s", name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the end of the linked list
void insertStudent(struct Student** head, int rollNo, const char* name, int marks) {
    struct Student* newStudent = createStudent(rollNo, name, marks);

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to delete a student with a given Roll No.
void deleteStudent(struct Student** head, int rollNo) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Student* temp = *head;
    struct Student* prev = NULL;

    // Search for the student with the given Roll No.
    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    // If the student is found, delete it
    if (temp != NULL) {
        if (prev != NULL) {
            prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        free(temp);
        printf("Student with Roll No. %d deleted successfully.\n", rollNo);
    } else {
        printf("Student with Roll No. %d not found.\n", rollNo);
    }
}

// Function to search and display details of a student with a given Roll No.
void searchStudent(struct Student* head, int rollNo) {
    struct Student* temp = head;
    while (temp != NULL && temp->rollNo != rollNo) {
        temp = temp->next;
    }

    if (temp != NULL) {
        printf("Student details for Roll No. %d:\n", rollNo);
        printf("Name: %s\n", temp->name);
        printf("Marks: %d\n", temp->marks);
    } else {
        printf("Student with Roll No. %d not found.\n", rollNo);
    }
}

// Function to find the student with the highest marks
struct Student* findHighestMarkStudent(struct Student* head) {
    struct Student* temp = head;
    struct Student* highestMarkStudent = NULL;
    int maxMarks = INT_MIN;

    while (temp != NULL) {
        if (temp->marks > maxMarks) {
            maxMarks = temp->marks;
            highestMarkStudent = temp;
        }
        temp = temp->next;
    }

    return highestMarkStudent;
}

// Function to display the list of students
void displayList(struct Student* head) {
    struct Student* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List of Students:\n");
    while (temp != NULL) {
        printf("Roll No.: %d, Name: %s, Marks: %d\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Student** head) {
    struct Student* temp = *head;
    struct Student* next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
}

int main() {
    struct Student* head = NULL;
    int choice, rollNo, marks;
    char name[50];

    do {
        printf("\nStudent Database Operations:\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Find Student with Highest Marks\n");
        printf("5. Display List\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No.: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Marks: ");
                scanf("%d", &marks);
                insertStudent(&head, rollNo, name, marks);
                break;

            case 2:
                printf("Enter Roll No. to delete: ");
                scanf("%d", &rollNo);
                deleteStudent(&head, rollNo);
                break;

            case 3:
                printf("Enter Roll No. to search: ");
                scanf("%d", &rollNo);
                searchStudent(head, rollNo);
                break;

            case 4:
                {
                    struct Student* highestMarkStudent = findHighestMarkStudent(head);
                    if (highestMarkStudent != NULL) {
                        printf("Student with the highest marks:\n");
                        printf("Roll No.: %d, Name: %s, Marks: %d\n",
                               highestMarkStudent->rollNo, highestMarkStudent->name, highestMarkStudent->marks);
                    } else {
                        printf("No students in the list.\n");
                    }
                }
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    // Free the allocated memory for the linked list
    freeList(&head);

    return 0;
}
