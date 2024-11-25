#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareBooks(const void *a, const void *b);

int main() {
    int N;
    
    // Read the number of books
    scanf("%d", &N);
    
    // Array to store books, each with title, author, and genre
    char books[N][3][100];

    // Input book details
    for (int i = 0; i < N; i++) {
        // Read the title, author, and genre of each book
        scanf(" %[^\n]", books[i][0]);  // Title (reads a full line including spaces)
        scanf(" %[^\n]", books[i][1]);  // Author (reads a full line including spaces)
        scanf(" %[^\n]", books[i][2]);  // Genre (reads a full line including spaces)
    }

    // Sort the books array by genre using qsort and the custom comparison function
    qsort(books, N, sizeof(books[0]), compareBooks);

    // Output the book titles in the sorted order of genres
    for (int i = 0; i < N; i++) {
        printf("%s\n", books[i][0]);
    }

    return 0;
}

// Function to compare two books based on genre


int compareBooks(const void *a, const void *b) {
    // Cast to the appropriate type
    char (*bookA)[3][100] = (char (*)[3][100])a;
    char (*bookB)[3][100] = (char (*)[3][100])b;

    // Genre order: children -> fiction -> non-fiction
    char *genreOrder[] = {"children", "fiction", "non-fiction"};
    int genreA = 0, genreB = 0;

    // Find the genre of bookA and bookB and map it to a number based on predefined order
    for (int i = 0; i < 3; i++) {
        if (strcmp((*bookA)[2], genreOrder[i]) == 0) {
            genreA = i;
        }
        if (strcmp((*bookB)[2], genreOrder[i]) == 0) {
            genreB = i;
        }
    }

    return genreA - genreB;  // Return the difference to determine the order
}


// Function prototype for compareBooks

