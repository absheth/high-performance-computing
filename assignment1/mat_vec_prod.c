#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO
void load_matrix(long long *matrix_ptr, int *row, int *column) {
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
            fprintf(stdout, "Rows: %d | ", *row);
            fprintf(stdout, "Columns: %d | ", *column);
            fprintf(stdout, "Total lines: %d\n", total_lines);
            matrix_ptr = (long long *) malloc(sizeof(long long) * (*row) * (*column));
            memset(matrix_ptr, 0, r*c);
        } else {
            int temp_r, temp_c;
            long long temp_value;
            char *eptr;
            // char tmp_str[255];
            // memset(&tmp_str, 0, 255);
            temp_r = atoi(strtok(line, " "));
            temp_c = atoi(strtok(NULL, " "));
            // temp_value = strtoll(strtok(NULL, " "), &eptr, 10);
            // strcpy(tmp_str, strtok(NULL, " "));
            
            // temp_value = strtoll(tmp_str, &eptr, 10);
            temp_value = atof(strtok(NULL, " "));
            fprintf(stdout, "temp_r: %d | ", temp_r);
            fprintf(stdout, "temp_c: %d | ", temp_c);
            // fprintf(stdout, "char value: %s | ", tmp_str);
            fprintf(stdout, "converted : %e \n", temp_value);
            // fprintf(stdout, "converted : %s\n", eptr);
            
             
        }
    }
    printf("Final line count: %d\n", line_count);

    fclose(fp);
    if (line)
        free(line);
    // exit(EXIT_SUCCESS);

}

//TODO
void get_vector() {

}

int main(void) {
    fprintf(stdout, "\n");
    fprintf(stdout, "This is main method\n");
    int i, j;
    long long *matrix;
    int row, column;

    //TODO
    // Load the matrix
    load_matrix(matrix, &row, &column);
    // for (i = 0; i < row; i++) {
    //     for (j = 0; j < row; j++) {
    //         fprintf(stdout, "i: %d, j: %d ==> %e", i, j, *(matrix + i*column + j));
    //     }
    //     fprintf(stdout, "\n");
    // }
    //TODO
    // Generate the vector
    get_vector();
    fprintf(stdout, "\n");
    return 0;
}
