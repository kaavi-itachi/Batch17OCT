//Write a program to find the  n-th number made of prime digits

#include <stdio.h>


int main() {
    int T, N;
    scanf("%d", &T); // Number of test cases

    // Process each test case
    while (T--) {
        scanf("%d", &N); // The N-th number in the sequence
        
        int count = 0;
        int num = 2; // Start from the smallest prime digit number
        
        // Find the N-th prime digit number
        while (count < N) {
            if (isPrimeDigitNumber(num)) {
                count++; // If the number is made of prime digits, increment the count
            }
            num++; // Check the next number
        }
        // Output the N-th prime digit number
        printf("%d\n", num - 1); // num - 1 is the N-th valid number
    }

    return 0;
}

// Function to check if a number is made of prime digits only
int isPrimeDigitNumber(int num) {
    // Prime digits are: 2, 3, 5, 7
    while (num > 0) {
        int digit = num % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7) {
            return 0; // If a digit is not prime, return 0 (not a valid prime digit number)
        }
        num /= 10;
    }
    return 1; // If all digits are prime, return 1
}

