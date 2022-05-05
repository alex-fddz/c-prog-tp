#include <stdio.h>
#include <ctype.h>

void printChars(int n) {
    int printable = 0;
    int non_printable = 0;

    printf("\n> Attempting to print %d characters:\n", n);

    for (int c = -128; c <= n-128; c++) {
        if ( isprint(c) ) {
            putchar(c); 
            printf(" %d \n", c);
            printable++;
        } else {
            non_printable++;
        }
    }
    printf("  > %d printable chars.\n", printable);
    printf("  > %d non-printable chars.\n", non_printable);
}

int main() {
    // print normal char range
    printChars(255);
    
    // print normal 1000 characters
    printChars(1000);

    printf("\n > The amount of printable characters remain the same but the non printable characters increases because char type variables only has 255 possible values (out of which only 95 are printable). If more char values are attempted to be 'put', they simply do not exist (normal).\n");

    return 1;
}
