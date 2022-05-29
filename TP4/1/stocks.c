/* Stocks Library definition */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stocks.h"

// Get value from HTML line
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

// Program Help
void showHelp() {
    printf("Usage: ./stocks [FIELD]\n"
    " Where [FIELD] can take values from {1,2,3}"
    " and corresponds to the field by which the stocks will be ordered:"
    " by Name, Current Price (p), or Day Change, respectively.\n");
}

// Comparison Sort Function for Name
int compare_name(const void *a, const void *b) {
    // Cast the input args as stocks
    stock *stockA = (stock*)a;
    stock *stockB = (stock*)b;
    // Dereference stocks' name, return such that a goes before b
    return (stockA->name - stockB->name);
}

// Comparison Sort Function for Current Price
int compare_current_price(const void *a, const void *b) {
    // Cast the input args as stocks
    stock *stockA = (stock*)a;
    stock *stockB = (stock*)b;
    // Dereference stocks' current_price, return such that a goes before b
    return (stockA->current_price - stockB->current_price);
}

// Comparison Sort Function for Day Change
int compare_day_change(const void *a, const void *b) {
    // Cast the input args as stocks
    stock *stockA = (stock*)a;
    stock *stockB = (stock*)b;
    // Dereference stocks' day_change, return such that a goes before b
    return (stockA->day_change - stockB->day_change);
}

