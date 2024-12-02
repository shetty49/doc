// WAP to perform following operations
// a. Extracting Maximum element from Heap
// b. Inserting element into Heap

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the heap

typedef struct {
    int arr[MAX_SIZE];
    int size; // Current size of the heap
} MaxHeap;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max heap property after insertion
void heapifyUp(MaxHeap* heap, int index) {
    int parent = (index - 1) / 2;
    if (index && heap->arr[parent] < heap->arr[index]) {
        swap(&heap->arr[parent], &heap->arr[index]);
        heapifyUp(heap, parent);
    }
}

// Function to insert an element into the Max Heap
void insert(MaxHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full. Cannot insert %d\n", value);
        return;
    }
    heap->arr[heap->size] = value; // Insert new element at the end
    heap->size++; // Increase the size of the heap
    heapifyUp(heap, heap->size - 1); // Restore the max heap property
}

// Function to maintain the max heap property after extraction
void heapifyDown(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

// Function to extract the maximum element from the Max Heap
int extractMax(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot extract maximum.\n");
        return -1; // Return -1 if heap is empty
    }
    int max = heap->arr[0]; // Get the maximum element
    heap->arr[0] = heap->arr[heap->size - 1]; // Move the last element to the root
    heap->size--; // Decrease the size of the heap
    heapifyDown(heap, 0); // Restore the max heap property
    return max; // Return the maximum element
}

// Function to print the heap
void printHeap(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
    heap.size = 0; // Initialize the heap size

    // Insert elements into the heap
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    insert(&heap, 25);

    printf("Max Heap: ");
    printHeap(&heap);

    // Extract maximum element
    int max = extractMax(&heap);
    printf("Extracted maximum element: %d\n", max);

    printf("Max Heap after extraction: ");
    printHeap(&heap);

    return 0;
}
