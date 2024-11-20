String Function Assignment-

1. 1. WAP to prompt and read a line of text with words separated by space. Tokenise and extract the words. Display them. Implement the following functions for this.
a. int tokenise(char *arr); //tokenise and display tokens , return number of tokens to the caller [Use strtok() to tokenise]

ans: 
#include <stdio.h>
#include <string.h>

int tokenise(char *arr) {
    int count = 0;
    char *token = strtok(arr, " ");
    
    while (token != NULL) {
        printf("Token %d: %s\n", count + 1, token);
        count++;
        token = strtok(NULL, " ");
    }
    
    return count;
}

int main() {
    char input[256];
    
    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    int num_tokens = tokenise(input);
    printf("Number of tokens: %d\n", num_tokens);
    
    return 0;
}
______________________________________________________________________________________________________________________________________

2. 2. Implement your own strncat() which shall concatenate n characters from src to dest.

char *strncat(char *dest, const char *src, size_t n)
#include <stdio.h>

char *my_strncat(char *dest, const char *src, size_t n) {
    char *dest_ptr = dest;

    // Move dest_ptr to the end of dest string
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    // Append up to n characters from src to dest
    while (n-- && *src != '\0') {
        *dest_ptr++ = *src++;
    }

    // Null-terminate the resulting string
    *dest_ptr = '\0';

    return dest;
}

int main() {
    char dest[50] = "Hello, ";
    const char *src = "world!";
    size_t n = 3;

    printf("Before concatenation: %s\n", dest);
    my_strncat(dest, src, n);
    printf("After concatenation: %s\n", dest);

    return 0;
}
________________________________________________________________________________________________________________________________________

3. WAP to
a. Search for and replace the vowel characters (upper and lower case) with “ay” in a word read from user. Consider a maximum word length of 40 characters.
b. Identify the test inputs to be used
c. Display updated string

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_vowels(char *word) {
    char result[100] = ""; // Buffer to store the result
    int j = 0; // Index for the result buffer

    for (int i = 0; word[i] != '\0'; i++) {
        char ch = word[i];
        if (strchr("AEIOUaeiou", ch)) {
            result[j++] = 'a';
            result[j++] = 'y';
        } else {
            result[j++] = ch;
        }
    }
    result[j] = '\0'; // Null-terminate the result string
    strcpy(word, result); // Copy the result back to the original word
}

int main() {
    char word[41]; // Buffer to store the input word (max 40 characters + null terminator)

    printf("Enter a word (max 40 characters): ");
    scanf("%40s", word); // Read a word from the user

    replace_vowels(word); // Replace vowels with "ay"

    printf("Updated string: %s\n", word); // Display the updated string

    return 0;
}
