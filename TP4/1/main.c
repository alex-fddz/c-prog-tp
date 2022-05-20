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
    char containing_str[] = "View equity details for ";
    char *res;

    // Download stock market information
    // getStocks();

    // Open (and validate) stocks file
    stocks_file = fopen("stocks.txt", "r");
    if (stocks_file == NULL) return -1;

    // Read file lines
    while (!feof(stocks_file)) {
        fgets(line, MAX_LINE_CHARS, stocks_file);

        // Find containing string indicating stock info start
        res = strstr(line, containing_str);
        if (res != NULL) {
            printf("%s", line);
        }
    }

    fclose(stocks_file);

    return 1;
}
