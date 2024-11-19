Function Parameter Passing and Return Assignments:

1. Refer the code below and find the issue.

#include<stdio.h>
int *func(void);
int main()
{
int num,*ptr = NULL;
ptr = (int *)func();
num = *ptr;
return 1;
}
int *func()
{
int local;
local = 10;
return(&local);
}

In above code is there a way(s) to return local variable address to caller?

Solution: There is a problem in the code

int *func()
{
    int local;  // Local variable
    local = 10;
    return(&local);  // Returning address of a local variable
}
Ways to Return a Valid Pointer to the Caller:

Way 1- Use static Local Variable

#include <stdio.h>

/******************************************************************************
*
*       Function Name   : func()
*       Description     : function that contains a static local variable (local).
*       Returns         : pointer to an integer (int*)
*
*******************************************************************************/

int *func(void);

int main()
{
    int num, *ptr = NULL;

    ptr = func();  // ptr now points to a static variable in func
    num = *ptr;    // Dereference to get the value of the static variable

    printf("%d\n", num);  // Output the value of num

    return 0;
}

int *func()
{
    static int local;  // Declare static variable
    local = 10;        // Assign a value to the static variable
    return &local;     // Return the address of the static variable
}

Way 2- Use Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
*
*       Function Name   : func()
*       Description     : function that dynamically allocates memory on the heap using the malloc() function.
*       Returns         : pointer to an integer (int*)
*
*******************************************************************************/


int *func(void);

int main()
{
    int num, *ptr = NULL;

    ptr = func();  // ptr now points to dynamically allocated memory
    num = *ptr;    // Dereference to get the value of the dynamically allocated memory

    printf("%d\n", num);  // Output the value of num

    free(ptr);  // Free the dynamically allocated memory to prevent memory leak
    return 0;
}

int *func()
{
    int *local = (int *)malloc(sizeof(int));  // Dynamically allocate memory for an integer
    if (local != NULL)
    {
        *local = 10;  // Assign value to the allocated memory
    }
    return local;   // Return the pointer to the dynamically allocated memory
}


______________________________________________________________________________________________________________

2. Write a program with a function read_extract_characters() to read a string (of max length 50 characters) 
from user, extract the characters at odd indices, store in an other array and return to the call. Caller should 
be able to read and display the extracted string.

[Note : do not return a local variable in function to caller]

#include <stdio.h>
#include <string.h>

/*************************************************************************
*                               MACROS
*************************************************************************/

#define MAX_LEN 50

/******************************************************************************
*
*       Function Name   : strcspn()
*       Description     : returns the index of the first occurrence of any character from the second string in the first string.
*       Returns         : index of the first occurrence of any character from the second string in the first string.
*
*******************************************************************************/

// Function to read the string, extract characters at odd indices and store them in another array
void read_extract_characters(char *input_str, char *extracted_str) {
    int i, j = 0;

    // Extract characters at odd indices from the input string
    for (i = 1; i < strlen(input_str); i += 2) {
        extracted_str[j++] = input_str[i];  // Store characters at odd indices
    }
    extracted_str[j] = '\0';  // Null-terminate the extracted string
}

int main() {
    char input_str[MAX_LEN + 1];  // Array to store the input string (max length 50 + null terminator)
    char extracted_str[MAX_LEN + 1];  // Array to store the extracted characters (max length 50 + null terminator)

    // Prompt the user to enter the string
    printf("Enter a string (max length 50 characters): ");
    fgets(input_str, sizeof(input_str), stdin);

    // Remove the newline character if present
    input_str[strcspn(input_str, "\n")] = '\0';

    // Call the function to extract characters at odd indices
    read_extract_characters(input_str, extracted_str);

    // Display the extracted string
    printf("Extracted characters at odd indices: %s\n", extracted_str);

    return 0;
}
_____________________________________________________________________________________________________________________________________

3. Write below functions to extract and return the required inputs from an email id string of max length 80 characters.
Program should be able to detect an invalid email id too based on following validations. Also value returned should be in scope 
and accessible in caller.

a. valid email id will have username, host and domain name (as .com/.edu)

Functions:

char *getuser(char input[]); // return NULL or valid username from email id input

char *gethost(char input[]); //return NULL or valid hostname from email id input

char *getdomain(char input[]); //return NULL or valid domain name from email id input

int isValidDomain(char input[]); // return 1 if domain is “.com” or “.edu” else 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************************************************************
*
*       Function Name   : getuser(), gethost(), and getdomain()
*       Description     : Function checks if the given domain is either .com or .edu.
*       Returns         : int
*
*******************************************************************************/

// Function to extract the username from the email
char *getuser(char input[]) {
    static char username[41];  // To hold the username (max 40 characters + null terminator)
    int i = 0;

    // Check for the '@' symbol
    while (input[i] != '@' && input[i] != '\0') {
        username[i] = input[i];
        i++;
    }
    username[i] = '\0';  // Null terminate the username string

    // If '@' is not found or the username is empty, return NULL
    return (i > 0 && input[i] == '@') ? username : NULL;
}

// Function to extract the host (part before the domain) from the email
char *gethost(char input[]) {
    static char host[41];  // To hold the host (max 40 characters + null terminator)
    int i = 0, j = 0;
    
    // Find the '@' symbol
    while (input[i] != '@' && input[i] != '\0') {
        i++;
    }

    // If '@' is not found, return NULL
    if (input[i] == '\0') {
        return NULL;
    }

    i++;  // Skip the '@' symbol

    // Extract the host part before the domain
    while (input[i] != '.' && input[i] != '\0') {
        host[j++] = input[i++];
    }
    host[j] = '\0';  // Null terminate the host string

    // If host part is empty, return NULL
    return (j > 0) ? host : NULL;
}

// Function to extract the domain (part after the '.') from the email
char *getdomain(char input[]) {
    static char domain[10];  // To hold the domain (max 9 characters + null terminator)
    int i = 0, j = 0;

    // Find the last '.' character in the email (domain starts after the last dot)
    while (input[i] != '\0') {
        if (input[i] == '.') {
            i++;  // Move past the dot
            break;
        }
        i++;
    }

    // Extract the domain part (com or edu)
    while (input[i] != '\0') {
        domain[j++] = input[i++];
    }
    domain[j] = '\0';  // Null terminate the domain string

    // If domain part is empty or not ".com" or ".edu", return NULL
    return (j > 0 && isValidDomain(domain)) ? domain : NULL;
}

// Function to validate the domain to check if it is ".com" or ".edu"
int isValidDomain(char input[]) {
    // Check if the domain is ".com" or ".edu"
    return (strcmp(input, "com") == 0 || strcmp(input, "edu") == 0) ? 1 : 0;
}

int main() {
    char email[81];  // To store the email ID (max 80 characters + null terminator)
    char *username, *host, *domain;

    // Prompt user for an email ID input
    printf("Enter email ID (max length 80 characters): ");
    fgets(email, sizeof(email), stdin);

    // Remove newline character if present (from fgets)
    email[strcspn(email, "\n")] = '\0';

    // Extract the username, host, and domain
    username = getuser(email);
    host = gethost(email);
    domain = getdomain(email);

    // Display the extracted components or error message
    if (username != NULL) {
        printf("Username: %s\n", username);
    } else {
        printf("Invalid or missing username.\n");
    }

    if (host != NULL) {
        printf("Host: %s\n", host);
    } else {
        printf("Invalid or missing host.\n");
    }

    if (domain != NULL) {
        printf("Domain: %s\n", domain);
    } else {
        printf("Invalid or missing domain.\n");
    }

    return 0;
}
