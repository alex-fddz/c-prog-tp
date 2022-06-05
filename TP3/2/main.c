#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
#define drawPlot() \
    system("gnuplot --persist -e 'plot \"function_data\"'");
#else
#error "OS not supported!"    
#endif

void parseBinToTxt() {
    // Declaration of File pointers
    FILE *binfile; // Binary data file (read)
    FILE *txtfile; // Text data file (write)

    // Initialize memory allocation for numbers
    float *numbers;     // Array to store numbers
    int nums = 0;       // Total number of numbers
    int n = 0;          // Number of x,y pairs
    float x = 0, y = 0; // Values for x,y pair
    numbers = (float*)malloc(sizeof(float) * nums);

    // Open binary file as read-only
    binfile = fopen("function_data_bin", "r");
    if (binfile != NULL) { 
        do { // Read data & save numbers to array
            numbers = (float*)realloc(numbers, sizeof(float) * nums + 1);
            fread(&numbers[nums], sizeof(float), 1, binfile);
            nums++;
            // printf("%f\n", numbers[nums]);
        } while ( !feof(binfile) ); nums--; // There is 1 extra loop... ?
    }
    fclose(binfile); // Close the -read- file.
    
    // Open file for writing
    txtfile = fopen("function_data", "w");
    if (txtfile != NULL) { // Process numbers for x,y pairs
        n = nums / 2;
        for (int i = 0; i < n; i++) {
            x = numbers[i];
            y = numbers[n+i];
            // Write out to text file
            fprintf(txtfile, "%f %f\n", x, y);
        }
    }
    fclose(txtfile); // Close the -write- file. 

    free(numbers);
}

int main() {
    parseBinToTxt(); // Parse Binary data file
    drawPlot();      // Plot data from text file

    return 0;
}

