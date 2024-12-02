#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to be executed by the first thread
void *threadOneFunc(void *arg) {
    printf("This is thread one\n");
    return NULL;
}

// Function to be executed by the second thread
void *threadTwoFunc(void *arg) {
    printf("This is thread two\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, threadOneFunc, NULL) != 0) {
        perror("Failed to create thread one");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, threadTwoFunc, NULL) != 0) {
        perror("Failed to create thread two");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished.\n");
    return 0;
}
