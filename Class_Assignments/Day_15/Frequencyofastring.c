#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the maximum number of words we can handle
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Structure to store word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    char str[500];

    // Read the input string
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Find and print the word frequency
    findWordFrequency(str);

    return 0;
}


// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to find frequency of each word in the string
void findWordFrequency(char *str) {
    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    // Tokenize the string using space and punctuation as delimiters
    char *token = strtok(str, " ,.-");

    while (token != NULL) {
        // Convert the word to lowercase to make counting case-insensitive
        toLowerCase(token);

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If word is not found, add it to the array
        if (!found) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        // Get the next word
        token = strtok(NULL, " ,.-");
    }

    // Print the frequency of each word
    printf("\nWord Frequency:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s = %d\n", words[i].word, words[i].count);
    }
}

