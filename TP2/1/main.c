#include <stdio.h>
#include <stdlib.h>

#include "exchange.h"

int main(int argc, char **argv) {
    // Initialize 2 float variables
    float f1 = 0.0, f2 = 0.0;

    if (argc >= 1+2) {
        // Get values from cmd arguments (if given)
        f1 = atof(argv[1]);
        f2 = atof(argv[2]);
    } else {
        // Prompt user for 2 numbers
        printf("Please input two decimal numbers, separated by a space. > ");
        scanf(" %f %f", &f1, &f2);
    }

    // printf("Input 2 decimal numbers separated by a space: > ");
    printf("\nProvided values are f1 = %.4f and f2 = %.4f.\n", f1, f2);
    exchange(&f1, &f2);
    printf("Swapped values are f1 = %.4f and f2 = %.4f.\n\n", f1, f2);

    return 0;
}
