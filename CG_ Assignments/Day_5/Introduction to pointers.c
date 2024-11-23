Introduction to pointers:

1. Refer the code snippet below. int main()

{
char arr=”hello hi “;
int *ptr = arr;

printf(“sizeof ptr:%d, arr:%d”, sizeof(ptr), sizeof(arr));
display(ptr); // display the address in hex and contents using pointer
}

Perform the following.
a. Implement the display() function (Use the “0x%x” formatting specifier to print addresses in hexadecimal.)
b. comment on the sizeof(ptr) and sizeof(arr)

ans: a) 
#include <stdio.h>
void display(int *ptr) {
    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);
    printf("Contents at ptr: %d\n", *ptr);
}

int main() {
    char arr[] = "hello hi ";
    int *ptr = (int *)arr;

    printf("sizeof ptr: %zu, sizeof arr: %zu\n", sizeof(ptr), sizeof(arr));
    display(ptr); // display the address in hex and contents using pointer

    return 0;
}

b)sizeof(ptr): This will give the size of the pointer ptr. On most systems, 
this will be 8 bytes on a 64-bit system and 4 bytes on a 32-bit system.This is because ptr is a pointer to an 
integer, and the size of any pointer is determined by the architecture of the system (64-bit or 32-bit).
sizeof(arr): This will give the size of the array arr. Since arr is an array of characters with the string "hello hi ", 
it includes the null terminator \0 at the end. Therefore, the size will be 10 bytes (9 characters + 1 null terminator).
__________________________________________________________________________________________________________________________

2. Refer the code snippet below. int main()

#define MAX 100
#define SUCCESS 0
#define FAILURE 1
int main()
{
char arr[MAX] = “Learning C“;
char*ptr = arr;
char appendstr[3]= “in my org”;
printf(“Address of ptr:%x”, ptr);
int ret = append(ptr, appendstr);// append the string
printf(“Address of ptr:%x”, ptr);
if (ret == SUCCESS)
{
display(ptr); // display the address in hex and contents using pointer
}
}

Perform the following.

a. Implement the append() function to append the contents of the appendstr[] to arr using pointer.

[Note: append() should only use its content and not manipulate it. Contents should be retained even after the call]

Ans: The append function will concatenate appendstr to the string pointed to by ptr. It will return SUCCESS if the operation is
successful and FAILURE if there is an error (e.g., if the resulting string would exceed the maximum size). The display function will
print the address and contents of the pointer.

#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUCCESS 0
#define FAILURE 1

int append(char *ptr, const char *appendstr) {
    if (strlen(ptr) + strlen(appendstr) >= MAX) {
        return FAILURE;
    }
    strcat(ptr, appendstr);
    return SUCCESS;
}

void display(char *ptr) {
    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);
    printf("Contents at ptr: %s\n", ptr);
}

int main() {
    char arr[MAX] = "Learning C";
    char *ptr = arr;
    char appendstr[] = " in my org";

    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);

    int ret = append(ptr, appendstr); // append the string

    printf("Address of ptr: 0x%x\n", (unsigned int)ptr);

    if (ret == SUCCESS) {
        display(ptr); // display the address in hex and contents using pointer
    } else {
        printf("Appending string failed.\n");
    }

    return 0;
}

___________________________________________________________________________________________________________________________________

3. Refer the code in “pointer_prg.c”. The functions swap_nums() and swap_pointers() are expected to swap the numbers and pointers respectively.
But swap_pointers() is currently not giving the expected results. Analyse and the fix the issue.

ans:you need to pass the pointers by reference (i.e., pass pointers to the pointers).
#include <stdio.h>
#include <stdlib.h>

#define MAX 80

// Swap integers by pointer
void swap_nums(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

// Swap pointers to string
void swap_pointers(char **x, char **y)
{
    char *tmp;
    tmp = *x;
    printf("\n swap_pointers: x, y is %p %p, tmp=x:%p \n", (void *)*x, (void *)*y, (void *)tmp);
    printf("\n swap_pointers: x, y is %s %s, tmp=x:%s \n", *x, *y, tmp);
    *x = *y;
    *y = tmp;
    printf("\nswap_pointers :  x, y is %s %s \n", *x, *y);
}

int test_swap_char()
{
    char arr1[MAX] = "ABC";
    char arr2[MAX] = "DEFGH";

    char *s1 = arr1;
    char *s2 = arr2;
    printf("\n s1, s2 address bef  is %p %p", (void *)s1, (void *)s2);

    // Swap the pointers
    swap_pointers(&s1, &s2);
    printf("\n s1, s2 address aft is %p %p", (void *)s1, (void *)s2);

    return 0;
}

int test_swap_num()
{
    int a = 3, b = 4;

    // Swap the numbers using pass by pointer
    swap_nums(&a, &b);
    printf("a is %d\n", a);
    printf("b is %d\n", b);

    return 0;
}

/**************************************************************************
 *
 * FUNCTION NAME: main
 *
 * DESCRIPTION: main function to demonstrate pass by value 
 * and pass by reference  
 *
 * RETURNS: int
 **************************************************************************/
int main()
{
    // Swap 2 numbers
    test_swap_num();
    // Swap two string pointers
    test_swap_char();

    return 0;
}
