#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaration of File pointer
    FILE *binfile;

    // Initialize memory allocation for numbers
    float *numbers;
    int nums = 0;
    numbers = (float*)malloc(sizeof(float) * nums);

    // Open file as read-only
    binfile = fopen("function_data_bin", "r");
    
    // Validate file pointer
    if (binfile != NULL) {
        // Process the data
        do {
            numbers = (float*)realloc(numbers, sizeof(float) * nums + 1);

            fread(&numbers[nums], sizeof(float), 1, binfile);
            printf("%f\n", numbers[nums]);
            nums++;

        } while ( !feof(binfile) );
    }
    
    free(numbers);
    fclose(binfile); // Close the file.
    printf("OK. %d\n", nums);

    return 1;
}
