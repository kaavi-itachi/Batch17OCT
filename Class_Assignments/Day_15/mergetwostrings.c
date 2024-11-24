#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Read the input strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character if present

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character if present

    // Call the function to alternate merge the strings
    alternateMerge(str1, str2);

    return 0;
}

void alternateMerge(char str1[], char str2[]) {
    int i = 0, j = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a result array to store the merged string
    char result[len1 + len2 + 1];  // +1 for the null terminator

    int k = 0;  // Index for result array

    // Merge characters alternately
    while (i < len1 && j < len2) {
        result[k++] = str2[j++];  // Add one character from str2
        result[k++] = str1[i++];  // Add one character from str1
    }

    // If there are remaining characters in str1
    while (i < len1) {
        result[k++] = str1[i++];
    }

    // If there are remaining characters in str2
    while (j < len2) {
        result[k++] = str2[j++];
    }

    result[k] = '\0';  // Null terminate the result string

    // Output the merged string
    printf("Merged String: %s\n", result);
}


