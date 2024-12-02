// Write a program to insert N Student information into the Doubly Linked List. Write a
// function to
// a. Search a Student and display his details.
// b. Display the details of the students who have scored above 90 in Math’s and
// Science

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int mathScore;
    int scienceScore;
    struct Student* prev;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(char* name, int math, int science) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->mathScore = math;
    newStudent->scienceScore = science;
    newStudent->prev = newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student into the doubly linked list
void insertStudent(struct Student** head, char* name, int math, int science) {
    struct Student* newStudent = createStudent(name, math, science);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->prev = temp;
    }
    printf("Inserted student: %s\n", name);
}

// Function to search a student by name
void searchStudent(struct Student* head, char* name) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Student found:\nName: %s\nMath Score: %d\nScience Score: %d\n", temp->name, temp->mathScore, temp->scienceScore);
            return;
        }
        temp = temp->next;
    }
    printf("Student with name %s not found.\n", name);
}

// Function to display students who scored above 90 in Math and Science
void displayHighScorers(struct Student* head) {
    struct Student* temp = head;
    int found = 0;
    printf("Students who scored above 90 in both Math and Science:\n");
    while (temp != NULL) {
        if (temp->mathScore > 90 && temp->scienceScore > 90) {
            printf("Name: %s, Math Score: %d, Science Score: %d\n", temp->name, temp->mathScore, temp->scienceScore);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No students found with scores above 90 in both subjects.\n");
    }
}

// Function to display all students
void displayAllStudents(struct Student* head) {
    struct Student* temp = head;
    printf("All students in the list:\n");
    while (temp != NULL) {
        printf("Name: %s, Math Score: %d, Science Score: %d\n", temp->name, temp->mathScore, temp->scienceScore);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Student* head = NULL;
    int n, math, science;
    char name[50];

    printf("Enter the number of students to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter Math score of student %d: ", i + 1);
        scanf("%d", &math);
        printf("Enter Science score of student %d: ", i + 1);
        scanf("%d", &science);
        insertStudent(&head, name, math, science);
    }

    printf("\n--- Searching for a student ---\n");
    printf("Enter the name of the student to search: ");
    scanf("%s", name);
    searchStudent(head, name);

    printf("\n--- Displaying high scorers ---\n");
    displayHighScorers(head);

    printf("\n--- Displaying all students ---\n");
    displayAllStudents(head);

    return 0;
}
