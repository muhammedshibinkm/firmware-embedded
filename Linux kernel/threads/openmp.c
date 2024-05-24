#include <omp.h>
#include <stdio.h>

#define N 1000  // Define the size of the arrays

int main(int argc, char *argv[]) {
    int i;
    int a[N], b[N], c[N];  // Declare arrays a, b, and c

    // Initialize arrays a and b
    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    /* sequential code */
    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
        }

        #pragma omp single
        printf("I am a parallel region.\n");
    }
    /* sequential code */

    // Print the result array c
    printf("Result array c:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
