// WAP to implement stack operations PUSH and POP using 2 Queues.

#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset queue if it's now empty
    } else {
        q->front++;
    }
    return data;
}

// Stack structure using two queues
struct Stack {
    struct Queue q1, q2;
};

// Initialize the stack
void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Function to push an element onto the stack
void push(struct Stack *s, int data) {
    enqueue(&s->q2, data); // Enqueue data to q2

    // Move all elements from q1 to q2
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap q1 and q2 pointers
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    printf("Pushed %d onto stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Main function to test the stack implementation
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    push(&s, 40);
    printf("Popped element: %d\n", pop(&s));

    return 0;
}
