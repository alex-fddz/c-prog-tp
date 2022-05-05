/* Currencies library H file */

#ifndef CURRENCIES_H_
#define CURRENCIES_H_

// Prompt types
#define IN 0
#define OUT 1

// Default exchange rates
#define EUR_TO_GBP 0.84273612
#define EUR_TO_USD 1.1067995

// Currency symbols array ("dictionary") values
#define EUR 0
#define GBP 1
#define USD 2

// Display currencies
void displayCurrencies(double eurToGbp, double eurToUsd, double gbpToUsd); 

// Prompt user to override exchange rates
int askForRateChange();

// Override exchange rates with user input
void promptChangeRates(double *eurToGbp, double *eurToUsd, double *gbpToUsd) ;

// Prompt for input/output currency
int promptCurrency(char io); 

// Prompt for input quantity
double promptInputQty(int inputCurrency);

// Calculate output quantity 
double convertCurr(double inQty, int inCurr, int outCurr, double convMatrix[3][3]); 

// Display currency conversion result
void displayCurrencyConversion(double inQty, int inCurr, double outQty, int outCurr); 

#endif /* CURRENCIES_H_ */
