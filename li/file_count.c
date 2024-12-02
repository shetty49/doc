#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void count_lines(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for line count");
        exit(1);
    }

    int lines = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);
    printf("Total number of lines: %d\n", lines);
}

void count_characters(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for character count");
        exit(1);
    }

    int characters = 0;
    while (fgetc(file) != EOF) {
        characters++;
    }

    fclose(file);
    printf("Total number of characters: %d\n", characters);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    pid_t pid1, pid2;

    // Create first child to count lines
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid1 == 0) {
        // In the first child process
        count_lines(filename);
        exit(0);
    }

    // Create second child to count characters
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid2 == 0) {
        // In the second child process
        count_characters(filename);
        exit(0);
    }

    // Parent process waits for both children to complete
    wait(NULL);
    wait(NULL);

    printf("Parent process: Both children have completed their tasks.\n");
    return 0;
}
