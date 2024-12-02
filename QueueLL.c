#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct node {
    int data;
    struct node *link;
} *front, *rear;

// Function prototypes
void insert();   // Function to insert an element into the queue
void delet();    // Function to delete an element from the queue
void display();  // Function to display all the elements in the queue

int main() {
    int choice;
    printf("LINKED LIST IMPLEMENTATION OF QUEUES\n\n");
    do {
        // Display the menu
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Sorry, invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

// Function to insert an element at the rear of the queue
void insert() {
    struct node *temp;

    // Allocate memory for a new node
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted in the queue: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    // If the queue is empty, set front and rear to the new node
    if (rear == NULL) {
        front = rear = temp;
    } else {
        // Otherwise, link the new node to the current rear and update rear
        rear->link = temp;
        rear = temp;
    }
}

// Function to delete an element from the front of the queue
void delet() {
    struct node *temp;
    if (front == NULL) {  // Check if the queue is empty
        printf("Queue underflow\n");
    } else {
        // Remove the front element and free its memory
        temp = front;
        printf("The deleted element from the queue is: %d\n", front->data);
        front = front->link;
        free(temp);

        // If the queue becomes empty, reset both front and rear to NULL
        if (front == NULL) {
            rear = NULL;
        }
    }
}

// Function to display all the elements in the queue
void display() {
    struct node *temp;
    temp = front;
    if (front == NULL) {
        printf("Queue underflow\n");
    } else {
        printf("The elements of the queue are:\n");
        while (temp) {  // Traverse from front to rear
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}
