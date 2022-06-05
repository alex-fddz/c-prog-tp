#include <stdio.h>

int main() {
    char a;
    char b;
    
    printf("|--- AND ---|\n|_a_|_b_|_=_|\n");
    a = 0; b = 0;
    printf("| %d | %d | %d |\n", a, b, a && b);
    a = 0; b = 1;
    printf("| %d | %d | %d |\n", a, b, a && b);
    a = 1; b = 0;
    printf("| %d | %d | %d |\n", a, b, a && b);
    a = 1; b = 1;
    printf("| %d | %d | %d |\n", a, b, a && b);
    printf("|-----------|\n\n");

    printf("|--- OR ----|\n|_a_|_b_|_=_|\n");
    a = 0; b = 0;
    printf("| %d | %d | %d |\n", a, b, a || b);
    a = 0; b = 1;
    printf("| %d | %d | %d |\n", a, b, a || b);
    a = 1; b = 0;
    printf("| %d | %d | %d |\n", a, b, a || b);
    a = 1; b = 1;
    printf("| %d | %d | %d |\n", a, b, a || b);
    printf("|-----------|\n\n");

    printf("|--- XOR ---|\n|_a_|_b_|_=_|\n");
    a = 0; b = 0;
    printf("| %d | %d | %d |\n", a, b, a ^ b);
    a = 0; b = 1;
    printf("| %d | %d | %d |\n", a, b, a ^ b);
    a = 1; b = 0;
    printf("| %d | %d | %d |\n", a, b, a ^ b);
    a = 1; b = 1;
    printf("| %d | %d | %d |\n", a, b, a ^ b);
    printf("|-----------|\n\n");

    return 0;
}
