#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declaring the enum argument for chosen letter case
enum casetype {lower_case, upper_case};

/* Transform each char in a char array to 
   upper or lower case (or not) */
char* transformString(char* string, enum casetype sel_case) {
    int ch = 0; // var to track character in string

    switch (sel_case) {
        case lower_case: // Change to Lower Case
            while (string[ch] != '\n') {
                string[ch] = tolower(string[ch]);
                ch++;
            }
            break;
        case upper_case: // Change to Upper Case
            while (string[ch] != '\n') {
                string[ch] = toupper(string[ch]);
                ch++;
            }
            break;
        default: // Do nothing
            break;
    }

    return string;
}

int main() {
    // Initialize program variables
    char *str; // given string (char array)
    char in_char; // incoming character (input)
    unsigned int str_len = 0; // length of given string
    int input_case_opt; // option input for case transformation 
    enum casetype selected_case; // variable of type casetype
    char **text; // table of text (array of char arrays)
    unsigned int word_count = 0; // stats: word count
    unsigned float avg_letters = 0; // stats: avg letters per word

    // Allocate memory for at least 1 character 
    str = (char*)malloc(sizeof(char) * 1);

    printf("Please give your text and press enter when you finish:\n> ");

    // Save char by char
    while (( in_char = getchar()) != '\n' ) {
        str_len++;
        // Resize string mem alloc and save next/incoming char
        str = (char*)realloc(str, sizeof(char) * str_len + 1);
        str[str_len - 1] = in_char; 
    }
    str[str_len] = '\0'; // add end-of-str char

    printf("You gave the following string: %s", str);

    // Prompt for case type selection
    printf("\nPlease choose if you want to change your string to "
            "lower-case (type 0) or upper-case (type 1). "
            "Other values will not alter the string.\n> ");
    scanf(" %d", &input_case_opt);
    selected_case = input_case_opt; // assign input to enum var 

    // Transform string to Upper or Lower case
    str = transformString(str, selected_case);
    printf("Here are the words that you gave after changing the case:\n");
    printf("%s", str);

    /* Get string stats (word count and avg chars per word) */
    // Process the string and build the text table


    printf("\n\n");
    // Free dynamically allocated memory
    free(str);

    return 1;
}
