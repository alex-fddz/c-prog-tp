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

struct StockInfo {
    char *name;
    float current_price;
    double day_change;
};

typedef struct StockInfo stock;

char *parseHTMLLine(char *line) {
    // HTML tag delimiters & var init
    const char d[3] = "<>";
    char *token; 
    unsigned i = 0;

    // Split line into tokens 
    token = strtok(line, d);
    while( token != NULL ) {
        token = strtok(NULL, d);
        if (i == 2) break;
        i++;
    }
    return token;
}

int main() {
    FILE *stocks_file;
    char line[MAX_LINE_CHARS];
    char stock_info_ind[] = "View equity details for ";
    char *value;
    stock Stock;

    // Download stock market information
    // getStocks();

    // Open (and validate) stocks file
    stocks_file = fopen("stocks.txt", "r");
    if (stocks_file == NULL) return -1;

    // Read file lines
    while (!feof(stocks_file)) {
        fgets(line, MAX_LINE_CHARS, stocks_file);

        // Find containing string indicating stock info start
        if (strstr(line, stock_info_ind) != NULL) {
            // Get stock info from each following line
            Stock.name = parseHTMLLine(line);
            fgets(line, MAX_LINE_CHARS, stocks_file); // read next line
            Stock.current_price = atof(parseHTMLLine(line));
            fgets(line, MAX_LINE_CHARS, stocks_file); // read next line
            Stock.day_change = atof(parseHTMLLine(line));

            printf("%s\t%lf\t%lf\n", Stock.name, Stock.current_price, Stock.day_change);
        }
    }

    // Close stocks file
    fclose(stocks_file);

    return 1;
}
