/* Currencies library C file */

#include <stdio.h>
#include "currencies.h"

// Currency symbols array ("dictionary") 
char* currSym[3] = {"€", "£", "$"};

// Display currencies
void displayCurrencies(double eurToGbp, double eurToUsd, double gbpToUsd) {
    printf("\n|-Exchange Rates:-|\n");
    printf("|   1 %s = %.2lf %s  |\n", currSym[EUR], eurToGbp, currSym[GBP]);
    printf("|   1 %s = %.2lf %s  |\n", currSym[EUR], eurToUsd, currSym[USD]);
    printf("|   1 %s = %.2lf %s  |\n", currSym[GBP], gbpToUsd, currSym[USD]);
}

// Prompt user to override exchange rates
int askForRateChange() {
    int in = 0;
    do {
        printf("\nUse current exchange rates (1) or provide new ones (2)? > ");
        scanf("%d", &in);

        // check for valid input
        switch(in) {
            case 1: return 0;
            case 2: return 1;
            default: printf("\nInvalid choice!");
        }

    } while(1);
    return -1;
}

// Override exchange rates with user input
void promptChangeRates(double *eurToGbp, double *eurToUsd, double *gbpToUsd) {
    printf("\n| Input new Exchange Rates: \n");
    printf("|  1 %s is how many %s? > ", currSym[EUR], currSym[GBP]);
    scanf("%lf", &*eurToGbp);
    printf("|  1 %s is how many %s? > ", currSym[EUR], currSym[USD]);
    scanf("%lf", &*eurToUsd);
    *gbpToUsd = *eurToUsd / *eurToGbp;
    printf("|  Then 1 %s is %.2lf %s.\n", currSym[GBP], *gbpToUsd, currSym[USD]);
}

// Prompt for input/output currency
int promptCurrency(char io) {
    char* typeIO[2] = {" input", "output"};
    int curr;

    printf("\n| -Select %s currency- |\n|  1: %s  |  2: %s  |  3: %s  | ", 
        typeIO[io], currSym[EUR], currSym[GBP], currSym[USD]);
    
    do {
        printf("> ");
        scanf("%d", &curr);
        // check for valid input
        if ( curr == 1 || curr == 2 || curr == 3 ) break;
        printf("Please select a valid option. ");
    } while(1);
    
    return curr; 
}

// Prompt for input quantity
double promptInputQty(int inputCurrency) {
    double  qty;

    printf("\n Enter the amount in %s > ", currSym[inputCurrency-1]);
    scanf("%lf", &qty);
    
    return qty;
}

// Calculate output quantity 
double convertCurr(double inQty, int inCurr, int outCurr, double convMatrix[3][3]) {
    double outQty = inQty * convMatrix[outCurr-1][inCurr-1];

    return outQty;
}

// Display currency conversion result
void displayCurrencyConversion(double inQty, int inCurr, double outQty, int outCurr) {
    printf("\n\n => %.2lf %s = %.2lf %s\n\n", 
        inQty, currSym[inCurr-1], outQty, currSym[outCurr-1]);
}
