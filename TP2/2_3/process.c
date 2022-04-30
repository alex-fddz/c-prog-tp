#include <stdio.h>
#include <stdlib.h>

// Declaring the enum argument for chosen letter case
enum casetype {lower_case, upper_case};

char* transformString(char* string, enum casetype sel_case) {
    switch (sel_case) {
        case lower_case:
            printf("lower %d", sel_case);
            break;
        case upper_case:
            printf("upper %d", sel_case);
            break;
        default:
            printf("default %d", sel_case);
            break;
    }

    return string;
}

int main() {
    // Initialize program variables
    char *str; // given string
    char in_char; // incoming character
    int str_len = 0; // length of given string
    int input_case_opt; // option input for case transformation 
    enum casetype selected_case; // variable of type casetype
    // int word_count = 1;

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

    str = transformString(str, selected_case);
    printf("Here are the words that you gave after changing the case:\n");
    printf("%s", str);


    printf("\n\n");
    // Free dynamically allocated memory
    free(str);

    // for (int word = 0; word < word_count; word++) {
    //     free(text[word]);
    // }
    // free(text);

    return 1;
}
