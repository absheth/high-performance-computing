#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//TODO
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
        int r, c, total_lines;
        // printf("%s", line);
        line_count += 1;
        if(line_count == 1) {
            continue;
        } else if (line_count == 2) {
            *row = atoi(strtok(line, " "));
            *column = atoi(strtok(NULL, " "));
            total_lines = atoi(strtok(NULL, " "));
            //fprintf(stdout, "Rows: %d | ", *row);
            //fprintf(stdout, "Columns: %d | ", *column);
            //fprintf(stdout, "Total lines: %d\n", total_lines);
            *matrix_ptr = (double *) malloc(sizeof(double) * (*row) * (*column));
            memset(*matrix_ptr, 0, (*row) * (*column) * sizeof(double));
        } else {
            int temp_r, temp_c;
            double temp_value;
            char *eptr;
            temp_r = atoi(strtok(line, " "));
            temp_c = atoi(strtok(NULL, " "));
            temp_value = atof(strtok(NULL, " "));
            //fprintf(stdout, "temp_r: %d | ", temp_r);
            //fprintf(stdout, "temp_c: %d | ", temp_c);
            //fprintf(stdout, "converted : %.13e | ", temp_value);
            //fprintf(stdout, "line: %d | ", line_count);
            //fprintf(stdout, "index: %d \n", (temp_r-1) * (*column) + (temp_c-1));

            *(*matrix_ptr + (temp_r-1) * (*column) + (temp_c-1)) = temp_value;
        }
    }
    printf("Final line count: %d\n", line_count);

    fclose(fp);
    if (line)
        free(line);
    // exit(EXIT_SUCCESS);

}

//TODO
void get_vector(double **vector_ptr, int column) {
    int i;
    *vector_ptr= (double *) malloc(sizeof(double) * column);

    memset(*vector_ptr, 0, column * sizeof(double));
    // for (i = 0; i < column; i++) {
    //     fprintf(stdout, "i: %d ==> %.13e \n", i, *(vector+ i));
    // }
    // sin(2*pi*i/182)
    for (i = 0; i < column; i++) {
        // *(*vector + i) = sin((2 * M_PI * i)/182) ;
        *(*vector_ptr + i) = sin((2*M_PI*i)/182);
    }

}

mat_vec_product(double **matrix_ptr, double **vector_ptr, double **prod_result_ptr, double *l2_norm, int row, int column) {
    int i, j, k;
    double sum = 0.0, prod_sum = 0.0; 
    
    *prod_result_ptr = (double *) malloc(sizeof(double) * row);
    memset(*prod_result_ptr, 0, row * sizeof(double));
    
    for (i = 0; i < row; i++) {
        for(j = 0; j < column; j++) { 
             prod_sum += *(*matrix_ptr + i * column + j) * *(*vector_ptr + j);
        }
        *(*prod_result_ptr + i) = prod_sum;
        prod_sum = 0; 
    }
    for (i = 0; i < row; i++) {
        sum += pow(*(*prod_result_ptr + i), 2.0);
         
    }
    // for (i = 0; i < row; i++) {
    //     fprintf(stdout, "i: %d ==> %.13e \n", i, *(*prod_result_ptr+ i));
    // }
    *l2_norm = sqrt(sum);
    
    
    fprintf(stdout, "l2_norm : %lf \n", *l2_norm);

}

int main(void) {
    fprintf(stdout, "\n");
    fprintf(stdout, "This is main method\n");
    int i, j;
    double *matrix_ptr;
    double *vector_ptr;
    double *prod_result_ptr;
    double l2_norm;
    int row, column;

    //TODO
    // Load the matrix
    load_matrix(&matrix_ptr, &row, &column);

    // fprintf(stdout, "Rows: %d | ", row);
    // fprintf(stdout, "Columns: %d \n", column);
    // for (i = 0; i < row; i++) {
    //     for (j = 0; j < column; j++) {
    //         fprintf(stdout, "i: %d, j: %d ==> %.13e \n", i, j, *(matrix + i*(column) + j));
    //     }
    //     fprintf(stdout, "\n");
    // }
    //TODO
    // Generate the vector
    get_vector(&vector_ptr, column);
    // for (i = 0; i < column; i++) {
    //     fprintf(stdout, "i: %d ==> %.13e \n", i, *(vector_ptr+ i));
    // }

    mat_vec_product(&matrix_ptr, &vector_ptr, &prod_result_ptr, &l2_norm, row, column);
    fprintf(stdout, "\n");

    // Release memory
    free(matrix_ptr);
    free(vector_ptr);
    free(prod_result_ptr);

    return 0;
}
