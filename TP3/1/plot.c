#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __unix__
#define drawPlot(f) \
    system("gnuplot --persist -e 'plot \"function_data\"'");
#else
#error "OS not supported!"    
#endif

int main(int argc, char** argv) {
    // Variable initialization
    double mean, std, n; // Input params
    double low_bound, upp_bound, step_size; // Calc params 
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
    if (n==0) return -1;

    // Generate normal distribution 
    low_bound = -3 * std;
    upp_bound = 3 * std;
    step_size = (upp_bound - low_bound) / n;

    drawPlot(filename);
    
    return 1;
}
