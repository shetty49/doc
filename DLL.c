#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // if (newNode == NULL) {
    //     printf("Memory allocation failed\n");
    //     exit(1);
    // }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to insert a node at a specific position (middle) in the doubly linked list
void insertAtPosition(struct Node** head, int new_data, int position) {
    struct Node* new_node = createNode(new_data);
    if (position == 1) {  // Insert at beginning
        insertAtBeginning(head, new_data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
