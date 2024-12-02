#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the circular queue

// Circular Queue structure using an array
struct CircularQueue {
    int items[SIZE];  // Array to hold the queue elements
    int front;        // Front points to the element to be removed
    int rear;         // Rear points to the position where the next element is to be added
};

// Function prototypes
void enqueue(struct CircularQueue* q, int element);  // Function to add an element to the circular queue
int dequeue(struct CircularQueue* q);  // Function to remove an element from the circular queue
void display(struct CircularQueue* q);  // Function to display all elements in the circular queue
int isFull(struct CircularQueue* q);  // Function to check if the circular queue is full
int isEmpty(struct CircularQueue* q);  // Function to check if the circular queue is empty

int main() {
    struct CircularQueue q;  // Declare a circular queue
    q.front = -1;  // Initialize front
    q.rear = -1;   // Initialize rear

    int choice, element;
    printf("CIRCULAR QUEUE IMPLEMENTATION USING ARRAYS\n\n");

    while (1) {
        // Display menu
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Enqueue operation
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:  // Dequeue operation
                element = dequeue(&q);
                if (element != -1)
                    printf("The deleted element is: %d\n", element);
                break;
            case 3:  // Display the queue
                display(&q);
                break;
            case 4:  // Exit the program
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* q) {
    // If the next position is front, the queue is full
    return ((q->rear + 1) % SIZE == q->front);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* q) {
    // If front is -1, the queue is empty
    return (q->front == -1);
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* q, int element) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    } else {
        if (isEmpty(q)) {  // If the queue is empty, initialize front to 0
            q->front = 0;
        }
        // Increment rear in a circular fashion
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = element;  // Add the element to the queue
        printf("%d enqueued to the queue\n", element);
    }
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    int element;
    if (isEmpty(q)) {  // If the queue is empty
        printf("Queue Underflow\n");
        return -1;
    } else {
        element = q->items[q->front];  // Get the front element
        if (q->front == q->rear) {  // If the queue has only one element
            q->front = -1;
            q->rear = -1;
        } else {
            // Increment front in a circular fashion
            q->front = (q->front + 1) % SIZE;
        }
        return element;
    }
}

// Function to display all elements in the circular queue
void display(struct CircularQueue* q) {
    int i;
    if (isEmpty(q)) {  // If the queue is empty
        printf("Queue is empty\n");
        return;
    } else {
        printf("The elements in the circular queue are: ");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE) {  // Traverse in a circular fashion
            printf("%d ", q->items[i]);
        }
        printf("%d\n", q->items[i]);  // Print the last element
    }
}
