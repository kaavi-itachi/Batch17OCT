/* Program to Remove all Characters in Second String which are present in First String*/

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Read the two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove the newline character from input

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove the newline character from input

    // Call the function to remove characters from str2 that are in str1
    removeChars(str1, str2);

    // Output the modified second string
    printf("Modified second string: %s\n", str2);

    return 0;
}

// Function to remove characters from second string that are present in first string
void removeChars(char *str1, char *str2) {
    int i, j, k = 0;
    int len2 = strlen(str2);

    // Iterate over each character of str2
    for (i = 0; i < len2; i++) {
        // Check if str2[i] exists in str1
        int found = 0;
        for (j = 0; str1[j] != '\0'; j++) {
            if (str2[i] == str1[j]) {
                found = 1;
                break;  // If found, don't add this character to the result
            }
        }

        // If the character is not found in str1, copy it to the new position
        if (!found) {
            str2[k++] = str2[i];
        }
    }

    // Null-terminate the modified string
    str2[k] = '\0';
}


