#include <stdio.h>

int main() {
    printf("The size of a variable type char is x%lu\n", sizeof(char));
    printf("The size of a variable type int is x%lu\n", sizeof(int));
    printf("The size of a variable type short is x%lu\n", sizeof(short));
    printf("The size of a variable type unsigned short is x%lu\n", sizeof(unsigned short));
    printf("The size of a variable type long is x%lu\n", sizeof(long));
    printf("The size of a variable type float is x%lu\n", sizeof(float));
    printf("The size of a variable type double is x%lu\n", sizeof(double));

    return 0;
}
