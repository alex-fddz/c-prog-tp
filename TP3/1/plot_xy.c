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
        do {
            fscanf(datafile, "%f %f\n", &x, &y); 
            printf("x is %f and y is %f\n", x, y);
        } while ( !feof(datafile) );

        // do{ }while( !feof(datafile) );
    }
    fclose(datafile); // Close the file.

    return 1;
}
