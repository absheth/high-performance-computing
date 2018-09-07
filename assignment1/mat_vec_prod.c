#include <stdio.h>
#include <stdlib.h>


//TODO
void load_matrix() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("./fs_183_1.mtx", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int line_count = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu :\n", read);
        //
        printf("%s", line);
        line_count += 1;
        if(line_count == 1) {
            continue;
        } else if (line_count == 2) {

        } else {

        }
    }
    printf("Final line count: %d\n", line_count);

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);

}

//TODO
void get_vector() {

}

int main(void) {
    fprintf(stdout, "This is main method\n");

    //TODO
    // Declare the matrix

    //TODO
    // Load the matrix
    //
    load_matrix();

    //TODO
    // Generate the vector
    get_vector();
    return 0;
}
