// Write a program to create a single linked list. The address of the head is to be stored in a
// separate structure which has two fields
// struct head {
//  struct node *head_ptr;
//  int num;
// };
// The head_ptr will store the pointer to the head node num: Is the count of the number of
// elements present in the linked list. Write implementations for insertion and deletion
// which will update the head structure appropriately




#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *next;
};

// Definition of the head structure to store head pointer and number of nodes
struct head {
    struct node *head_ptr;
    int num;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct head *h, int data) {
    struct node* newNode = createNode(data);
    if (h->head_ptr == NULL) {
        h->head_ptr = newNode;
    } else {
        struct node* temp = h->head_ptr;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    h->num++; // Increase the node count
    printf("Inserted %d into the list.\n", data);
}

// Function to delete a node by value
void deleteNode(struct head *h, int data) {
    struct node* temp = h->head_ptr;
    struct node* prev = NULL;

    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data) {
        h->head_ptr = temp->next; // Change head
        free(temp); // Free old head
        h->num--; // Decrease the node count
        printf("Deleted %d from the list.\n", data);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data was not found in the list
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free memory
    h->num--; // Decrease the node count
    printf("Deleted %d from the list.\n", data);
}

// Function to display the linked list
void displayList(struct head *h) {
    struct node* temp = h->head_ptr;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Number of nodes: %d\n", h->num);
}

// Main function
int main() {
    struct head h;   // Initialize the head structure
    h.head_ptr = NULL;
    h.num = 0;

    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(&h, data);
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&h, data);
                break;
            case 3:
                displayList(&h);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
