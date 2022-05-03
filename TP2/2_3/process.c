#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Declaring the enum argument for chosen letter case
enum casetype {lower_case, upper_case};

/* Transform each char in a char array to 
   upper or lower case (or not) */
char* transformString(char* string, enum casetype sel_case) {
    unsigned int ch = 0; // var to track character in string

    switch (sel_case) {
        case lower_case: // Change to Lower Case
            while (string[ch] != '\0') {
                string[ch] = tolower(string[ch]);
                ch++;
            }
            break;
        case upper_case: // Change to Upper Case
            while (string[ch] != '\0') {
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
    char *word;
    const char s[2] = " "; // separator for strtok
    char *token; // token for strtok
    unsigned int word_count = 0; // stats: word count
    //unsigned int word_len = 0; // stats: current work length
    unsigned int total_letters = 0; // stats: total word letters (non space chars)
    float avg_letters = 0; // stats: avg letters per word

    // Allocate memory for at least 1 character 
    str = (char*)malloc(sizeof(char) * 1);
    // Allocate memory for text table 
    text = (char**)malloc(sizeof(char*) * 0);

    printf("Please give your text and press enter when you finish:\n> ");

    // Save char by char 
    while (( in_char = getchar()) != '\n' ) {
        str_len++;
        // Resize string mem alloc and save next/incoming char (main str)
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
    token = strtok(str, s); // Get the first token/word 
    while( token != NULL ) { // Walk through other tokens/words
        // Extend text table and Save word to text
        word_count++;
        text = (char**)realloc(text, sizeof(char*) * word_count);
        // word = (char*)malloc(sizeof(char) * strlen(token));
        // strcpy(word, token);
        text[word_count-1] = token;
        total_letters += strlen(token); // Add up letter count

        // Get next word/token
        token = strtok(NULL, s);
   }

   // Calculate average letters per word
   if (word_count > 0) avg_letters = (float)total_letters / (float)word_count;

   printf("\nThe total number of words is %d and the average number "
            "of letters per word is %.2f.\n", word_count, avg_letters);

    // Free dynamically allocated memory
    free(str);
    // for (int w = 0; w < word_count; w++) {
    //     free(text[w]);
    // } 
    free(text);

    return 1;
}
