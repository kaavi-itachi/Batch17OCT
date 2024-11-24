//rotate array every kth element

#include <stdio.h>

int main() {
    int n, k;
    
    // Read the size of the array and the value of k
    scanf("%d", &n);
    scanf("%d", &k);
    
    // Declare the array and read its elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Process the array in chunks of k
    for (int i = 0; i < n; i += k) {
        // Calculate the end index of the current chunk
        int end = (i + k - 1 < n) ? (i + k - 1) : (n - 1);
        reverseArray(arr, i, end); // Reverse the chunk from index i to end
    }
    
    // Output the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Function to reverse a part of the array between indices 'start' and 'end'
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


