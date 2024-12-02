#include<stdio.h>
#include<stdlib.h>



void main(int argc, char *argv[]){
	if (argc !=3){
		fprintf(stderr, "right format: %s<values>", argv[0]);
	}
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);

	int sum = n1+n2;
	printf("\n");

	printf("sum of %d and %d is %d", n1, n2, sum);
	printf("\n");
 
}