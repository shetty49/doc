#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100 // Specifying the maximum limit of the queue

/* Global declaration of variables */
int queue[LIMIT]; // Array implementation of queue
int front, rear; // To insert and delete the data elements in the queue respectively
int choice; // To choose either of the 3 queue operations

void insert();  // Function used to insert the element into the queue
void delet();   // Function used to delete the element from the queue
void display(); // Function used to display all the elements in the queue according to FIFO rule

int main() {
    printf("ARRAY IMPLEMENTATION OF QUEUES\n\n");
    front = rear = -1; // Initializing front and rear to -1 indicates that it is empty

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
    } while(choice != 4);

    return 0;
}

void insert() {
    int element;
    if ((rear + 1) % LIMIT == front) {
        printf("Queue Overflow\n"); // Queue is full (circular)
    } else {
        if (front == -1) // Initial insert when the queue is empty
            front = 0;
        printf("Enter the element to be inserted in the queue: ");
        scanf("%d", &element);
        rear = (rear + 1) % LIMIT; // Increment rear in a circular manner
        queue[rear] = element;
        printf("%d inserted into the queue.\n", element);
    }
}

void delet() {
    if (front == -1) {
        printf("Queue Underflow\n"); // Queue is empty
    } else {
        printf("The deleted element in the queue is: %d\n", queue[front]);
        if (front == rear) { // Queue becomes empty after deletion
            front = rear = -1;
        } else {
            front = (front + 1) % LIMIT; // Increment front in a circular manner
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue underflow\n"); // Queue is empty
    } else {
        printf("The elements of the queue are:\n");
        int i = front;
        while (1) {
            printf("%d\n", queue[i]);
            if (i == rear) break;
            i = (i + 1) % LIMIT; // Traverse in a circular manner
        }
    }
}
