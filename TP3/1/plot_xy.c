#include <stdio.h>

int main() {
    float x = 0, y = 0;

    // Declaration of File pointer
    FILE *datafile;

    // Open file as read-only
    datafile = fopen("function_data", "r");

    // Validate file pointer
    if (datafile != NULL) {
        // Process the data
        while ( fscanf(datafile, "%f %f", &x, &y) != EOF ) {
            printf("x is %f and y is %f\n", x, y);
        }
        // do{ }while( !feof(datafile) );
    }
    fclose(datafile); // Close the file.

    return 1;
}
