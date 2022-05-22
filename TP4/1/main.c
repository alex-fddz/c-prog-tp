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
    double current_price;
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

// Remove thousand separator (,) from number string
double parseNumStr(char *num_str) {
    char parsed_num[20];
    const char s[2] = ","; 
    char *token;
    // Split number into tokens
    token = strtok(num_str, s);
    while( token != NULL ) {
        // Save tokens to Parsed Number
        strcat(parsed_num, token);
        token = strtok(NULL, s);
    }
    return atof(parsed_num);
}

int main() {
    FILE *stocks_file;
    char line[MAX_LINE_CHARS];
    char stock_info_ind[] = "View equity details for ";
    char *value;
    stock Stock;

    // Download stock market information
    //getStocks();

    // Open (and validate) stocks file
    stocks_file = fopen("stocks.txt", "r");
    if (stocks_file == NULL) return -1;

    // Read file lines
    while (!feof(stocks_file)) {
        fgets(line, MAX_LINE_CHARS, stocks_file);

        // Find containing string indicating stock info start
        if (strstr(line, stock_info_ind) != NULL) {
            // Get stock info: Name 
            Stock.name = parseHTMLLine(line);
            // -Read next line & get Current Price
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            Stock.current_price = parseNumStr(parseHTMLLine(line));
            // -Read next line & get Day Change
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            Stock.day_change = parseNumStr(parseHTMLLine(line));

            printf("%s, %lf, %lf\n", Stock.name, Stock.current_price, Stock.day_change);
        }
    }

    // Close stocks file
    fclose(stocks_file);

    return 1;
}
