// odd_series.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;  // Declare n here before it's used

    if (argc == 2) {
        n = atoi(argv[1]);
    } else {
        printf("Enter the number of terms (n): ");
        scanf("%d", &n);
    }

    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        return 1;
    }

    printf("Odd series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", 2*i+1);  // Formula for odd numbers: 1, 3, 5, 7, ...
    }
    printf("\n");

    return 0;
}
