#include <stdio.h>
#include <omp.h>
#define N 1000000
int main () {
    int i, k;
    float a[N], b[N];
    float dot_prod;
    dot_prod = 0.0;

    // Initialize
    for (k = 0; k < N; k++) {
        a[k] = 3.0 * k;    
        b[k] = 1.8 * k;    
    }

#pragma omp parallel 
{
#pragma omp for reduction(+:dot_prod)
    for (i = 0; i < N; i++) {
        dot_prod = dot_prod + a[i] * b[i];
        // printf("i: %d\n", i);
    }
    
}

    printf("Inner product of a[] and b[] = %f\n", dot_prod);
    return 0;
}
