/*Your task is to find the leaders in the array. An element is leader if it is greater than all the elements to its right side.
And the rightmost element is always a leader.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Read the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to find and print leaders
    findLeaders(arr, n);

    // Free the dynamically allocated memory for the array
    free(arr);

    return 0;
}

void findLeaders(int *arr, int n) {
    int *leaders = (int *)malloc(n * sizeof(int));  // Allocate memory for storing leaders
    int leaderCount = 0;
    
    // Start from the rightmost element, which is always a leader
    int maxRight = arr[n - 1];
    leaders[leaderCount++] = maxRight;

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            leaders[leaderCount++] = arr[i];
        }
    }

    // Print the leaders in reverse order
    printf("Leaders: ");
    for (int i = leaderCount - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(leaders);
}


