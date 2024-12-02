#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

#define ARRAY_SIZE 5
#define MATRIX_SIZE 2

// Data for sum calculation
int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array_sum = 0;

// Data for matrix multiplication
int matrixA[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2}, {3, 4}};
int matrixB[MATRIX_SIZE][MATRIX_SIZE] = {{5, 6}, {7, 8}};
int resultMatrix[MATRIX_SIZE][MATRIX_SIZE] = {0};

// Data for string manipulation
char str[] = "hello, world!";
char resultStr[sizeof(str)];

// Thread function for calculating sum of an array
void* calculate_sum(void* arg) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array_sum += array[i];
    }
    printf("Sum of array: %d\n", array_sum);
    pthread_exit(NULL);
}

// Thread function for performing matrix multiplication
void* multiply_matrices(void* arg) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printf("Matrix multiplication result:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

// Thread function for converting string to uppercase
void* to_uppercase(void* arg) {
    for (int i = 0; i < sizeof(str); i++) {
        resultStr[i] = toupper(str[i]);
    }
    printf("Uppercase string: %s\n", resultStr);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;

    // Create threads
    if (pthread_create(&thread1, NULL, calculate_sum, NULL) != 0) {
        perror("Failed to create thread for sum calculation");
        return 1;
    }

    if (pthread_create(&thread2, NULL, multiply_matrices, NULL) != 0) {
        perror("Failed to create thread for matrix multiplication");
        return 1;
    }

    if (pthread_create(&thread3, NULL, to_uppercase, NULL) != 0) {
        perror("Failed to create thread for string manipulation");
        return 1;
    }

    // Wait for all threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Main thread: All computations are complete.\n");

    return 0;
}
