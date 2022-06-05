/* Stocks Library */

#ifndef STOCKS_H_
#define STOCKS_H_

#define MAX_LINE_CHARS 400
#define MAX_STK_NAME_CHARS 100

#define SORT_BY_NAME   1
#define SORT_BY_PRICE  2
#define SORT_BY_CHANGE 3

#ifdef __unix__
#define getStocks() \
    printf("Downloading stock market information . . .\n"); \
    system("wget --quiet --output-document=stocks.txt https://www.hl.co.uk/shares/stock-market-summary/ftse-100"); \
    printf("Stock market information retrieved !\n");
#else
#error "OS not supported!"    
#endif

struct StockInfo {
    char name[MAX_STK_NAME_CHARS];
    double current_price;
    double day_change;
};

typedef struct StockInfo stock;

// Get value from HTML line
char *parseHTMLLine(char *line); 

// Remove thousand separator (,) from number string
double parseNumStr(char *num_str); 

// Program Help
void showHelp(); 

// Comparison Sort Function for Name
int compare_name(const void *a, const void *b);

// Comparison Sort Function for Current Price
int compare_current_price(const void *a, const void *b);

// Comparison Sort Function for Day Change
int compare_day_change(const void *a, const void *b);

#endif /* STOCKS_H_ */
