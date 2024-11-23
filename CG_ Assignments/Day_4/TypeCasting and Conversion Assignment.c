Type casting and Conversions Assignment:

1. Refer the code snippet below perform the operations marked in TBD section, display the results using appropriate format specifier, display results.

#include <stdbool.h>
int main()
{
int i = 123;
short s = 98;
bool b = true;
char c = 'Y';
float d = 235.789;
//TBD – perform operations below and display result using appropriate format specifier
b+c
s * i
c * d
c = c+b
d = d+c
b = -d
return 0;
}

ans : #include <stdio.h>

int main()
{
    int i = 123;
    short s = 98;
    int b = 1;  // Use int to represent boolean (1 = true, 0 = false)
    char c = 'Y';
    float d = 235.789;

    // Perform operations and display results

    // b + c : Adding boolean value to a character. (bool is promoted to int, char is promoted to int)
    printf("b + c = %d\n", b + c);

    // s * i : Multiplying short and int (result will be int)
    printf("s * i = %d\n", s * i);

    // c * d : Multiplying char (converted to int) and float
    printf("c * d = %.2f\n", c * d);

    // c = c + b : Adding boolean to character and assigning the result to char
    c = c + b;
    printf("c = c + b: %c\n", c);

    // d = d + c : Adding char (converted to int) to float and assigning to float
    d = d + c;
    printf("d = d + c: %.2f\n", d);

    // b = -d : Assigning negative of float (converted to int) to int (used as boolean)
    b = -d;
    printf("b = -d: %d\n", b);

    return 0;
}
