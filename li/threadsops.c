#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100

char sharedMemory[BUFFER_SIZE];  // Shared memory area
pthread_mutex_t mutex;           // Mutex for synchronizing access

// Function to write a message to shared memory
void *writeThreadFunc(void *arg) {
    pthread_mutex_lock(&mutex);  // Lock the mutex

    // Write message to shared memory
    snprintf(sharedMemory, BUFFER_SIZE, "Hello There");
    printf("Thread 1: Written to shared memory: %s\n", sharedMemory);

    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

// Function to read, display, and invert case in shared memory
void *readAndInvertThreadFunc(void *arg) {
    pthread_mutex_lock(&mutex);  // Lock the mutex

    // Read and display the message from shared memory
    printf("Thread 2: Read from shared memory: %s\n", sharedMemory);

    // Invert the case of each character
    for (int i = 0; i < strlen(sharedMemory); i++) {
        if (islower(sharedMemory[i])) {
            sharedMemory[i] = toupper(sharedMemory[i]);
        } else if (isupper(sharedMemory[i])) {
            sharedMemory[i] = tolower(sharedMemory[i]);
        }
    }
    printf("Thread 2: Inverted case and updated shared memory: %s\n", sharedMemory);

    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the first thread to write the initial message
    pthread_create(&thread1, NULL, writeThreadFunc, NULL);

    // Wait for the first thread to finish writing
    pthread_join(thread1, NULL);

    // Create the second thread to read and invert the case
    pthread_create(&thread2, NULL, readAndInvertThreadFunc, NULL);

    // Wait for the second thread to finish
    pthread_join(thread2, NULL);

    // Now, the first thread reads the modified message
    pthread_mutex_lock(&mutex);  // Lock the mutex
    printf("Thread 1: Final read from shared memory: %s\n", sharedMemory);
    pthread_mutex_unlock(&mutex);  // Unlock the mutex

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
