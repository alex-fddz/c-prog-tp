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
    char parsed_num[20] = "";
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
    const char *stock_info_ind = "View equity details for ";
    double value;
    unsigned s_i = 0;
    stock *Stocks = (stock*)malloc(sizeof(*Stocks) * 0);

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
            // Increase Stocks array size
            Stocks = (stock*)realloc(Stocks, sizeof(*Stocks) * (s_i + 1));

            // Get stock info: Name 
            Stocks[s_i].name = parseHTMLLine(line);
            // -Read next line & get Current Price
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            value = parseNumStr(parseHTMLLine(line));
            Stocks[s_i].current_price = value;
            // -Read next line & get Day Change
            fgets(line, MAX_LINE_CHARS, stocks_file); 
            value = parseNumStr(parseHTMLLine(line));
            Stocks[s_i].day_change = value;

            printf("%s,%.2f,%.2f\n", Stocks[s_i].name, Stocks[s_i].current_price, Stocks[s_i].day_change);

            s_i++;
        }
    }

    // Free Stocks mem & close file
    free(Stocks);
    fclose(stocks_file);

    return 1;
}
