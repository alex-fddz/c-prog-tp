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
        // Process the data
        do {

            fread(&number, sizeof(double), 1, binfile);
            printf("%f\n", number);

        } while ( !feof(binfile) );
    }

    fclose(binfile); // Close the file.
    printf("OK.\n");

    return 1;
}
