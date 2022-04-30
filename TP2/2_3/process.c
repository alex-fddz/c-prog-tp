#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize program variables
    char *str; // given string
    char in_char; // incoming character
    int str_len = 0; // length of given string
    // int word_count = 1;

    // Allocate memory for at least 1 character 
    str = (char*)malloc(sizeof(char) * 1);

    printf("Please give your text and press enter when you finish:\n> ");

    // Save char by char
    while (( in_char = getchar()) != '\n' ) {
        str_len++;
        // Resize string mem alloc and save incoming char
        str = (char*)realloc(str, sizeof(char) * str_len + 1);
        str[str_len - 1] = in_char; 
    }
    str[str_len] = '\0'; // add end-of-str char

    printf("str = %s\n", str);
    printf("Length of str = %d\n", str_len);


    // Free dynamically allocated memory
    free(str);

    // for (int word = 0; word < word_count; word++) {
    //     free(text[word]);
    // }
    // free(text);

    return 1;
}
