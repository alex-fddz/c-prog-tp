#include <stdio.h>
#include "currencies.h"

int main() {
    // Display a title
    printf("\n|--- Currency Converter (by Javier FERNANDEZ) ---|\n");

    // Currency conversion variables
    double eurToGbp = EUR_TO_GBP;
    double eurToUsd = EUR_TO_USD;
    double gbpToUsd = eurToUsd / eurToGbp;

    displayCurrencies(eurToGbp, eurToUsd, gbpToUsd);

    if (askForRateChange()) {
        promptChangeRates(&eurToGbp, &eurToUsd, &gbpToUsd);
    }

    // Build a conversion matrix
    double convMatrix[3][3] = {
        {1, 1/eurToGbp, 1/eurToUsd},
        {eurToGbp, 1, 1/gbpToUsd},
        {eurToUsd, gbpToUsd, 1}
    };

    // Start of curency conversion process
    // printf("\n|--- Currency Conversion --|\n");

    int inCurr = promptCurrency(IN);
    double inQty = promptInputQty(inCurr);
    int outCurr = promptCurrency(OUT);
    
    double outQty = convertCurr(inQty, inCurr, outCurr, convMatrix);
    
    displayCurrencyConversion(inQty, inCurr, outQty, outCurr);

    return 0;
}
