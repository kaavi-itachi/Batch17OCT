/*Problem Statement:
Given an unsorted array a of size N of non-negative integers, 
find a continuous sub-array which adds to a given number sum.*/

#include <stdio.h>

int main() {
    int n, sum;

    // Read the size of the array
    scanf("%d", &n);

    int arr[n];

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the target sum
    scanf("%d", &sum);

    // Call the function to find the subarray
    findSubarrayWithGivenSum(arr, n, sum);

    return 0;
}
void findSubarrayWithGivenSum(int arr[], int n, int sum) {
    int current_sum = 0;
    int start = 0;

    // Iterate through the array
    for (int end = 0; end < n; end++) {
        // Add current element to the current sum
        current_sum += arr[end];

        // If current_sum exceeds the given sum, reduce it by removing elements from the start
        while (current_sum > sum && start <= end) {
            current_sum -= arr[start];
            start++;
        }

        // Check if we have found the subarray with the exact sum
        if (current_sum == sum) {
            printf("Sum found between indexes %d and %d\n", start, end);
            return;
        }
    }

    // If no subarray is found
    printf("No subarray found\n");
}


