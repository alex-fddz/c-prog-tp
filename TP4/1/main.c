#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_CHARS 400

#ifdef __unix__
#define getStocks() \
    printf("Downloading stock market information . . .\n"); \
    system("wget --quiet --output-document=stocks.txt https://www.hl.co.uk/shares/stock-market-summary/ftse-100"); \
    printf("Stock market information retrieved !\n");
#else
#error "OS not supported!"    
#endif

int main() {
    FILE *stocks_file;
    char line[MAX_LINE_CHARS];

    // Download stock market information
    getStocks();

    // Open (and validate) stocks file
    stocks_file = fopen("stocks.txt", "r");
    if (stocks_file == NULL) return -1;

    int i = 0;
    while (!feof(stocks_file) && i < 10) {
        fgets(line, MAX_LINE_CHARS, stocks_file);
        printf("%s", line);
        i++;
    }

    fclose(stocks_file);

    return 1;
}
