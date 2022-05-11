#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __unix__
#define drawPlot() \
    system("gnuplot --persist -e 'plot \"function_data\"'");
#else
#error "OS not supported!"    
#endif

int main(int argc, char** argv) {
    // Variable initialization
    FILE *df; // File to store the function data
    double mean, std, n; // Input params
    double low_bound, upp_bound, step_size, x, y; // Calc params 

    // Check for complete parameter input
    if (argc < 4) {
        printf("Please provide the complete parameters.\n");
        return 0;
    }

    // Gather params
    mean = atof(argv[1]);
    std = atof(argv[2]);
    n = atof(argv[3]);

    // Check params are valid
    if (n==0 || std==0) {
        printf("Invalid Parameters!\n");
        return -1;
    }

    // Calc required params for normal distribution generation
    low_bound = mean - 3 * std;
    upp_bound = mean + 3 * std;
    step_size = (upp_bound - low_bound) / n;

    // Create file for writing
    df = fopen("function_data", "w");
    if (df != NULL) { // For each linearly-spaced x value,
        for (double x = low_bound; x <= upp_bound; x += step_size) {
            // Calculate y as per a normal distribution
            y = pow(M_E, -(pow(x - mean, 2)) / (2 * pow(std, 2))) / sqrt(2 * M_PI * pow(std, 2));
            // Write out the x,y pair to the data file 
            fprintf(df, "%f %f\n", x, y);
        }
    }
    fclose(df); // Close the file

    // Plot the result
    drawPlot();
    
    return 1;
}
