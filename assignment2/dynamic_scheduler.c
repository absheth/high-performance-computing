#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000000

int main (int argc, char *argv[]) {
    // int i, k;
    int nthreads, threadid, i; 
    double a[N], b[N], result[N];

    // Initialize
    for (i = 0; i < N; i++) {
        a[i] = 1.0 * i;    
        b[i] = 2.0 * i;    
    }

    int chunk = 7;
#pragma omp parallel private(threadid)
{ //fork
    threadid = omp_get_thread_num();
#pragma omp for schedule(dynamic, chunk)
    for (i = 0; i < N; i++) {
        result[i] = a[i] + b[i];
        printf("Thread id: %d working on index %d\n", threadid, i);
    }
    
} // join

    printf(" TEST result[19] = %g\n", result[19]);
    return 0;
}
