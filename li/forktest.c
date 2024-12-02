//     Forking a child process and making the child process execute a program. 

 

// The program may be  related to working  with  array, matrix, files  or string manipulations. (eg:- finding row sum/column sum of a matrix, changing cases of a character string, counting for character occurance in a string, finding the sum of digits of a given number,  counting for words in a file, counting for white spaces(blanks, tabs or newlines) in a file etc.)  

// Hint:- Write the program(code of the child process) in a separate file, compile and create its exe. Invoke this file name in the exec command. 




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "standard syntax:%s<values>\n", argv[0] );
    }
    pid_t pid = fork();
    if(pid<0){
        perror("fork failed to excecute");
        exit(1);    
    }
    else if(pid == 0){
        printf("Child process (PID: %d) generating even series:\n", getpid());
        execl("./sum", "sum", argv[1], argv[2], (char *)NULL);
        perror("exec failed");
        exit(1);
    }
    else {
        // Parent process: Waits for child and then executes odd_series program
        wait(NULL);  // Wait for child to complete
        printf("Parent process (PID: %d)\n", getpid());
        printf("All process complete");
    }
} 