#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

void toUppercase(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for uppercase conversion");
        exit(1);
    }

    FILE *outputFile = fopen("output.txt", "w"); // Open an output file to save uppercase letters
    if (!outputFile) {
        perror("Error opening output file");
        fclose(file);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        fputc(toupper(ch), outputFile);  // Convert to uppercase and write to output file
    }

    fclose(file);
    fclose(outputFile);
    printf("All characters converted to uppercase and saved to 'output.txt'.\n");
}

void count_a_characters(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for character count");
        exit(1);
    }

    int characters = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == 'a' || ch == 'A')  // Count both 'a' and 'A'
            characters++;
    }

    fclose(file);
    printf("Total number of 'a' characters: %d\n", characters);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    pid_t pid1, pid2;

    // Create first child to convert to uppercase
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid1 == 0) {
        // In the first child process
        toUppercase(filename);
        exit(0);
    }

    // Create second child to count 'a' characters
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid2 == 0) {
        // In the second child process
        count_a_characters(filename);
        exit(0);
    }

    // Parent process waits for both children to complete
    wait(NULL);
    wait(NULL);

    printf("Parent process: Both children have completed their tasks.\n");
    return 0;
}
