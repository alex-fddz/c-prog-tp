#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaration of File pointer
    FILE *binfile;
    double number;

    // Open file as read-only
    binfile = fopen("function_data_bin", "r");

    // Validate file pointer
    if (binfile != NULL) {
        fread(&number, sizeof(double), 1, binfile);
        printf("%f\n", number);
//        // Process the data
//        do {
//            fread(binfile, "%f %f\n", &x, &y); 
//            printf("x is %f and y is %f\n", x, y);
//        } while ( !feof(binfile) );
//
//        // do{ }while( !feof(binfile) );
    }

    fclose(binfile); // Close the file.
    printf("OK.\n");

    return 1;
}
