#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "exchange.h"

int main() {
    // Variable initialization 
    float **M; // matrix M
    int ms = 0; // matrix size
    srand(time(NULL)); // initialize random generator

    // Prompt for matrix size
    printf("Enter the size of the matrix. > ");
    scanf(" %d", &ms);

    printf("\nInitial matrix:\n");
    // Dynamically allocate a square matrix of size ms
    // - Allocate memory for rows
    M = (float**)malloc(sizeof(float*) * ms);
    for (int i = 0; i < ms; i++) {

        // - Allocate memory for columns
        M[i] = (float*)malloc(sizeof(float) * ms);
        for (int j = 0; j < ms; j++) {

            // Set Mij to a random value between 0 and 10
            M[i][j] = (float)rand() / RAND_MAX * 10;

            // Print each value
            printf("%.2f\t", M[i][j]);
        }
        // Print next row 
        printf("\n");
    }

    // Transpose the matrix
    for (int i = 0; i < ms-1; i++) {
        for (int j = 1+i; j < ms; j++) {
            exchange(&M[i][j], &M[j][i]); // Exchange
        }
    }

    // Print result
    printf("\nTransposed matrix:\n");
    for (int i = 0; i < ms; i++) {
        for (int j = 0; j < ms; j++) {
            printf("%.2f\t", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // Memory De-Allocation 
    for (int i = 0; i < ms; i++) {
        free(M[i]);
    }
    free(M);

    return 1;
}
