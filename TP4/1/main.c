#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
#define getStocks() \
    system("wget --quiet --output-document=stocks.txt https://www.hl.co.uk/shares/stock-market-summary/ftse-100");
#else
#error "OS not supported!"    
#endif

int main() {
    // Download stock market information
    getStocks();

    return 1;
}
