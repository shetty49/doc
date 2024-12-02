#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void generateFibonacci(int n){
	int a=0,b=1, next, i;
	for(i=0;i<=n;i++){
		printf(" %d ", a);
		next = a+b;
		a = b;
		b = next;
	}
	printf("\n");
}

void main(int argc, char *argv[]){


	int n;
	pid_t pid = fork();

	if(argc !=2){
		fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        exit(1);
	}

	n = atoi(argv[1]);
	if(n<0){
		printf("child process is not created");
		exit(1);
	}
	else if(pid == 0){
		printf("Child process (PID: %d) generating Fibonacci sequence:\n", getpid());
		generateFibonacci(n);
		exit(0);
	}
	else{
		wait(NULL);
        printf("Parent process (PID: %d): Child process has completed.\n", getpid());
	}
	// return 0;
}