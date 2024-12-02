#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>



void count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for character count");
        exit(1);
    }

    int words = 0;
    bool in_word = false;
    char ch;
    while((ch = fgetc(file)) != EOF){
        if(isspace(ch)){
            in_word = false;
        }else{
            if(!in_word){
            words++;
            in_word = true;
            }
        }
        
    }

    fclose(file);
    printf("Total number of words: %d\n", words);
}

void invertCase(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for uppercase conversion");
        exit(1);
    }

    FILE *outputFile = fopen("output1.txt", "w"); // Open an output file to save uppercase letters
    if (!outputFile) {
        perror("Error opening output file");
        fclose(file);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
          if (islower(ch)) {
            fputc(toupper(ch), outputFile);  // Convert lowercase to uppercase
        } else if (isupper(ch)) {
            fputc(tolower(ch), outputFile);  // Convert uppercase to lowercase
        } else {
            fputc(ch, outputFile);  // Leave non-alphabet characters as is
        }
    }

    fclose(file);
    fclose(outputFile);
    printf("All characters are inverted and saved to 'output1.txt'.\n");
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
        count_words(filename);
        exit(0);
    }

    // Create second child to count 'a' characters
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid2 == 0) {
        // In the second child process
        invertCase(filename);
        exit(0);
    }

    // Parent process waits for both children to complete
    wait(NULL);
    wait(NULL);

    printf("Parent process: Both children have completed their tasks.\n");
    return 0;
}
