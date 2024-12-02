#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Define the front and rear pointers for the circular queue
struct Node *front = NULL, *rear = NULL;

// Function prototypes
void insert();   // Function to insert an element into the circular queue
void delet();    // Function to delete an element from the circular queue
void display();  // Function to display all the elements in the circular queue

int main() {
    int choice;
    printf("CIRCULAR LINKED LIST IMPLEMENTATION OF QUEUES\n\n");
    
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

// Function to insert an element at the rear of the circular queue
void insert() {
    struct Node* temp;
    // Allocate memory for a new node
    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the element to be inserted in the queue: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    // If the queue is empty, set front and rear to the new node
    if (front == NULL) {
        front = rear = temp;
        rear->next = front;  // Circular link to the front node
    } else {
        // Otherwise, link the new node to the current rear and update rear
        rear->next = temp;
        rear = temp;
        rear->next = front;  // Maintain circular link
    }
    printf("%d inserted into the queue.\n", temp->data);
}

// Function to delete an element from the front of the circular queue
void delet() {
    if (front == NULL) {  // Check if the queue is empty
        printf("Queue underflow\n");
        return;
    }

    struct Node* temp = front;

    // If the queue has only one node
    if (front == rear) {
        printf("The deleted element from the queue is: %d\n", front->data);
        front = rear = NULL;
    } else {
        // Remove the front element and update the front pointer
        printf("The deleted element from the queue is: %d\n", front->data);
        front = front->next
