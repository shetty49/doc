#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <stdbool.h>

#define FILENAME "sample.txt"
#define OUTPUT_FILENAME "output.txt"

// Function to create a sample file with some text content
void create_sample_file() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error creating sample file");
        exit(1);
    }
    fprintf(file, "This is a SAMPLE Text with Some UpperCASE and LowerCASE letters.\n");
    fprintf(file, "Let's count the number of words, and also change the case.\n");
    fclose(file);
    printf("Sample file created with content.\n");
}

// Thread function to count the number of words in the file
void *count_words(void *arg) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file for word count");
        pthread_exit(NULL);
    }

    int word_count = 0;
    bool in_word = false;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            in_word = false;
        } else {
            if (!in_word) {
                word_count++;
                in_word = true;
            }
        }
    }

    fclose(file);
    printf("Total number of words in the file: %d\n", word_count);
    pthread_exit(NULL);
}

// Thread function to change uppercase characters to lowercase in the file
void *convert_to_lowercase(void *arg) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file for case conversion");
        pthread_exit(NULL);
    }

    FILE *output_file = fopen(OUTPUT_FILENAME, "w");
    if (!output_file) {
        perror("Error opening output file for case conversion");
        fclose(file);
        pthread_exit(NULL);
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        fputc(tolower(ch), output_file);
    }

    fclose(file);
    fclose(output_file);
    printf("All uppercase characters converted to lowercase and saved in '%s'.\n", OUTPUT_FILENAME);
    pthread_exit(NULL);
}

// Thread function to write a message at the end of the file
void *write_message(void *arg) {
    FILE *file = fopen(OUTPUT_FILENAME, "a"); // Append mode
    if (!file) {
        perror("Error opening file to append message");
        pthread_exit(NULL);
    }

    fprintf(file, "\nThree threads have visited this file.\n");
    fclose(file);
    printf("Message written to the end of '%s'.\n", OUTPUT_FILENAME);
    pthread_exit(NULL);
}

int main() {
    create_sample_file();

    pthread_t thread1, thread2, thread3;

    // Create threads
    if (pthread_create(&thread1, NULL, count_words, NULL) != 0) {
        perror("Error creating word count thread");
        exit(1);
    }
    if (pthread_create(&thread2, NULL, convert_to_lowercase, NULL) != 0) {
        perror("Error creating case conversion thread");
        exit(1);
    }
    if (pthread_create(&thread3, NULL, write_message, NULL) != 0) {
        perror("Error creating message writing thread");
        exit(1);
    }

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Main program completed.\n");
    return 0;
}
