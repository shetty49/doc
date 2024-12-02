#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure for a circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // if (newNode == NULL) {
    //     printf("Memory allocation failed\n");
    //     exit(1);
    // }
    newNode->data = data;
    newNode->next = newNode;  // Point to itself
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    new_node->next = *head;
    temp->next = new_node;
    *head = new_node;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = *head;
}

// Function to insert a node at a specific position (middle) in the circular linked list
void insertAtPosition(struct Node** head, int new_data, int position) {
    struct Node* new_node = createNode(new_data);
    if (position == 1) {  // Insert at beginning
        insertAtBeginning(head, new_data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position != 1) {
        printf("Position out of bounds\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to demonstrate insertion at different positions
int main() {
    struct Node* head = NULL;

    // Insert at the end
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 7);
    printf("Original List:\n");
    printList(head);

    // Insert at the beginning
    insertAtBeginning(&head, 1);
    printf("After inserting 1 at the beginning:\n");
    printList(head);

    // Insert at position 3 (middle)
    insertAtPosition(&head, 4, 3);
    printf("After inserting 4 at position 3:\n");
    printList(head);

    // Insert at the end
    insertAtEnd(&head, 9);
    printf("After inserting 9 at the end:\n");
    printList(head);

    return 0;
}
