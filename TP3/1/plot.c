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
    if (n==0) return -1;

    // Generate normal distribution 
    low_bound = -3 * std;
    upp_bound = 3 * std;
    step_size = (upp_bound - low_bound) / n;
    for (double x = low_bound; x <= upp_bound; x += step_size) {
        y =  (pow(M_E, (-0.5) * pow(x * mean / std, 2))) / (std * sqrt(2*M_PI));
        printf("%f %f\n", x, y);
    }

    drawPlot(filename);
    
    return 1;
}
