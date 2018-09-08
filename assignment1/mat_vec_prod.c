#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
// Populate matrix from the file
void load_matrix(double **matrix_ptr, int *row, int *column) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("fs_183_1.mtx", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int line_count = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        int total_lines;
        line_count += 1;
        if(line_count == 1) {
            continue;
        } else if (line_count == 2) {
            *row = atoi(strtok(line, " "));
            *column = atoi(strtok(NULL, " "));
            total_lines = atoi(strtok(NULL, " "));
            *matrix_ptr = (double *) malloc(sizeof(double) * (*row) * (*column));
            memset(*matrix_ptr, 0, (*row) * (*column) * sizeof(double));
        } else {
            int temp_r, temp_c;
            double temp_value;
            char *eptr;
            temp_r = atoi(strtok(line, " "));
            temp_c = atoi(strtok(NULL, " "));
            temp_value = atof(strtok(NULL, " "));

            *(*matrix_ptr + (temp_r-1) * (*column) + (temp_c-1)) = temp_value;
        }
    }

    fclose(fp);
    if (line)
        free(line);
}

// Popluta the vector with formula: sin(2*pi*i/182)
void get_vector(double **vector_ptr, int column) {
    int i;
    *vector_ptr= (double *) malloc(sizeof(double) * column);
    memset(*vector_ptr, 0, column * sizeof(double));

    for (i = 0; i < column; i++) {
        // *(*vector + i) = sin((2 * M_PI * i)/182) ;
        *(*vector_ptr + i) = sin((2*M_PI*i)/182);
    }
}

void mat_vec_product(double **matrix_ptr, double **vector_ptr, double **prod_result_ptr, double *l2_norm, int row, int column, int times) {

    struct timeval start, end;

    int i, j, k;
    double sum = 0.0, prod_sum = 0.0;

    *prod_result_ptr = (double *) malloc(sizeof(double) * row);

    int x;
    gettimeofday(&start, NULL);
    for (x = 0; x < times; x++) {

        memset(*prod_result_ptr, 0, row * sizeof(double));
        for (i = 0; i < row; i++) {
            for(j = 0; j < column; j++) {
                *(*prod_result_ptr + i) += *(*matrix_ptr + i * column + j) * *(*vector_ptr + j);
            }
        }
    }
    gettimeofday(&end, NULL);


    // fprintf(stdout, "Start | sec: %d, usec %d \n", start.tv_sec, start.tv_usec);
    // fprintf(stdout, "End | sec: %d, usec %d \n", end.tv_sec, end.tv_usec);

    double time_taken = ((end.tv_sec + end.tv_usec*1.0e-6) - (start.tv_sec + start.tv_usec*1.0e-6))/(1.0*times);
    for (i = 0; i < row; i++) {
        sum += pow(*(*prod_result_ptr + i), 2.0);

    }
    *l2_norm = sqrt(sum);
    fprintf(stdout, "l2_norm : %lf \n", *l2_norm);
    fprintf(stdout, "time_taken in seconds: %lf \n", time_taken);
    fprintf(stdout, "megaFLOPS: %lf \n", (2*row*column)/(time_taken*1000000.0));

}

int main(int argc, char **argv) {

    fprintf(stdout, "\n");
    // fprintf(stdout, "Argc --> %d\n", argc);
    int i, j, times;
    if (argc > 1) {
        times = atoi(argv[1]);
    } else {
        times = 10000;
        fprintf(stdout, "Running  %d by default and taking average.\n", times);
        fprintf(stdout, "It can also be run as: ./mat_vev_prod <times>.\n");
        fprintf(stdout, "\n");
    }
    double *matrix_ptr, *vector_ptr, *prod_result_ptr;
    double l2_norm;
    int row, column;

    // Load the matrix
    load_matrix(&matrix_ptr, &row, &column);

    // Generate the vector
    get_vector(&vector_ptr, column);

    // Peform calculations
    mat_vec_product(&matrix_ptr, &vector_ptr, &prod_result_ptr, &l2_norm, row, column, times);
    fprintf(stdout, "\n");

    // fprintf(stdout, "Rows: %d | ", row);
    // fprintf(stdout, "Columns: %d \n", column);
    // for (i = 0; i < row; i++) {
    //     for (j = 0; j < column; j++) {
    //         fprintf(stdout, "i: %d, j: %d ==> %.13e \n", i, j, *(matrix + i*(column) + j));
    //     }
    //     fprintf(stdout, "\n");
    // }

    // Release memory
    free(matrix_ptr);
    free(vector_ptr);
    free(prod_result_ptr);

    return 0;
}
