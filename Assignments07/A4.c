#include <stdio.h>

int reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int rotateEveryK(int arr[], int n, int k) {
    for (int i = 0; i < n; i += k) {
        int end = (i + k - 1 < n) ? i + k - 1 : n - 1;
        reverse(arr, i, end);
    }
}

int printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateEveryK(arr, n, k);
    printArray(arr, n);

    return 0;
}
