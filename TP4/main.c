#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stocks.h"

int main(int argc, char **argv) {
    FILE *stocks_file;          // HTML File with raw data
    char line[MAX_LINE_CHARS];  // Line read from HTML file
    const char *stock_info_ind = "View equity details for "; // Info Indicator
    double value;               // Aux. var for numeric values
    unsigned s_i = 0;           // Current Stock Index
    stock *Stocks = (stock*)malloc(sizeof(*Stocks) * 0); // Init Stocks array

    // Check for valid sort option input
    if (argc < 2) { 
        showHelp();
        return 0;
    }

    // Download stock market information
    getStocks();

    // Open (and validate) stocks file
    stocks_file = fopen("stocks.txt", "r");
    if (stocks_file == NULL) return -1;

    // Read file lines
    while (!feof(stocks_file)) {
        fgets(line, MAX_LINE_CHARS, stocks_file);

        // Find containing string indicating stock info start
        if (strstr(line, stock_info_ind) != NULL) {
            // Increase Stocks array size by one
            Stocks = (stock*)realloc(Stocks, sizeof(*Stocks) * (s_i + 1));

            // Get stock info: Name 
            strcpy(Stocks[s_i].name, parseHTMLLine(line));
            // -Read next line & get Current Price
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            value = parseNumStr(parseHTMLLine(line));
            Stocks[s_i].current_price = value;
            // -Read next line & get Day Change
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            value = parseNumStr(parseHTMLLine(line));
            Stocks[s_i].day_change = value;

            s_i++; // Increment Stock Index
        }
    }

    // Close File
    fclose(stocks_file);

    // Sort according to input
    switch(atoi(argv[1])) {
        case SORT_BY_NAME:
            printf("Sorting by Name:\n");
            qsort(Stocks, s_i, sizeof(stock), compare_name);
            break;
        case SORT_BY_PRICE:
            printf("Sorting by Current Price (p):\n");
            qsort(Stocks, s_i, sizeof(stock), compare_current_price);
            break;
        case SORT_BY_CHANGE:
            printf("Sorting by Day Change:\n");
            qsort(Stocks, s_i, sizeof(stock), compare_day_change);
            break;
        default:
            printf("Invalid field sort option.\n");
            showHelp();
    }

    // Print out Stocks array
    for (int i = 0; i < s_i; i++) {
        printf("\nStock #%d\n", i+1);
        printf("  Name: %s\n", Stocks[i].name);
        printf("  Current Price (p): %.2f\n", Stocks[i].current_price);
        printf("  Day Change: %.2f\n", Stocks[i].day_change);
    }

    // Free Stocks mem
    free(Stocks);

    return 1;
}
