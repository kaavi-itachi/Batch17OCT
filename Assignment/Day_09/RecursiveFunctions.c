Recursive Functions:

1. WAP to calculate the maximum stack depth of a recursive call to a function. (For eg a factorial function ).

#include<stdio.h>
/*

*       Function Name   : factorial
*       Description     : calculates the factorial of a number n using recursion
*       Returns         : integer (factorial of n)
*/


// Global variable to keep track of maximum stack depth
int max_depth = 0;

int factorial(int n, int depth) {
    // Update maximum depth on each recursive call
    if (depth > max_depth) {
        max_depth = depth;
    }
    
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive call
    return n * factorial(n - 1, depth + 1);
}

int main() {
    int n;
    
    // Input from the user
    printf("Enter a number to compute factorial: ");
    scanf("%d", &n);
    
    // Calculate factorial and track the max depth
    int result = factorial(n, 1);  // Start depth at 1
    
    printf("Factorial of %d is %d\n", n, result);
    printf("Maximum stack depth: %d\n", max_depth);
    
    return 0;
}
_________________________________________________________________________________________________


2. What is tail recursion? Why is it important? Give an example#include <stdio.h>

Tail Recursion: ail recursion occurs when the recursive call is the last operation in the function,
meaning that no additional work (such as operations or function calls) is done after the recursive call.
Efficiency: Tail recursion is important because it can be optimized by the compiler or interpreter through
a process called tail call optimization (TCO). With TCO, the compiler reuses the current function's
stack frame for the next recursive call instead of adding a new frame to the stack, thus preventing stack overflow and improving performance.
Memory Optimization: Tail recursion is memory-efficient because it doesn’t require additional stack frames for each function call.

#include <stdio.h>

/*

*       Function Name   : factorial_tail_recursive
*       Description     : calculates the factorial of a number n using tail recursion
*       Returns         : integer (factorial of n)
*/

// Tail-recursive factorial function
int factorial_tail_recursive(int n, int accumulator) {
    // Base case
    if (n == 0 || n == 1) {
        return accumulator;
    }
    
    // Recursive call (tail recursion)
    return factorial_tail_recursive(n - 1, n * accumulator);
}

int main() {
    int n;
    
    // Input from the user
    printf("Enter a number to compute factorial (tail-recursive): ");
    scanf("%d", &n);
    
    // Call tail-recursive factorial with accumulator initialized to 1
    int result = factorial_tail_recursive(n, 1);
    
    printf("Factorial of %d is %d\n", n, result);
    
    return 0;
}
