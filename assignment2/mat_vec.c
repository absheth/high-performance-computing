#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    const int size = 10000;
    int i, j;

    double *A, *x, *b;
    A = (double *) malloc(size * size *sizeof(double));
    x = (double *) malloc(size * sizeof(double));
    b = (double *) malloc(size * sizeof(double));

    // arbitrarily initialize the matrix vector

    for (j = 0; j<size; j++) {
        for (i=0; i<size; i++) {
            A[size*j+i] = sin(0.01*(size*j+i));
        }
        b[j] = cos(0.01*j);
        x[j] = 0.0;
    }

    // Matrix vector multiplication
    for (j=0; j<size; j++) {
        for (i=0; i<size; i++) {
            x[j] += A[size*j+i]*b[i];
        }
    }
    printf("x[%d] = %g\n", 5050, x[5050]);

    free(A);
    free(x);
    free(b);
    return 0;
}
