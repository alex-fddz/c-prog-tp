#include <stdio.h>

int logical_operator_use(char x) { 
    char a, b;

    if (x=='A' || x=='a') {
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
    }
    else if (x=='O' || x=='o') {

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
    }
    else if (x=='X' || x=='x') {
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
    }
    else {
        return 1;
    }
    
    return 0;
} 
