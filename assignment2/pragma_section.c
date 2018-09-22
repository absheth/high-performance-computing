#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 1000
int main () {


    // printf("\n"); 

    printf("------------------------\n"); 
    // const int N = 1000;
    int x[N], i, max_x, min_x, sum, sum2, threadid;
    float mean, mean2, var;

    max_x = 0;
    min_x = 100;
    sum = 0;
    sum2 = 0;

    /* Initialize x */
    srand(1.0); // Initialize random variable seed
#pragma omp parallel for
    for (i=0; i<N; i++) {
        x[i] = rand();
    }

#pragma omp parallel private(i, threadid) shared(x)
    {
        
    threadid = omp_get_thread_num();
     
#pragma omp sections
        {
            
            /* fork 3 different threads */
            {
                
                printf("Thread id: %d working min-max\n", threadid);
                for (i=0; i<N; i++) { /* find min & max of x */
                    if (x[i] > max_x) {
                        max_x = x[i];
                    }

                    if (x[i] < min_x) {
                        min_x = x[i];
                    }
                }
                printf ("The max of x = %d\n", max_x); 
                printf ("The min of x = %d\n", min_x); 
                
                printf("\n");
            }

#pragma omp section
            { /* Calculate the mean of x */
            
                printf("Thread id: %d working mean\n", threadid);
                for (i=0; i<N; i++) {
                    sum = sum + x[i];
                }
                mean = sum/N;
                printf("Mean of x = %f\n", mean);
                printf("\n");
            }
#pragma omp section
            {
                
                printf("Thread id: %d working mean2\n", threadid);
                for (i=0; i<N; i++) {
                    sum2 = sum2 + x[i]*x[i];
                }
                mean2 = sum2/N;
            }
        }
    }
    threadid = omp_get_thread_num();
    printf("Thread id: %d <-- in the outer loop.\n", threadid);
    var = mean2 - mean*mean;
    printf("variance of x = %f\n", var); 
    printf("------------------------\n"); 
    return 0;
}

