1D Array-

1. Refer the code snippet and answer the queries

int main()

{

int array[100];

int *ptr;

// do something

}
1. Can pointer be used in Array-style syntax? e.g. ptr[10], ptr[0]
Yes, pointers can be used in array-style syntax. For example, ptr[10] is equivalent to *(ptr + 10).

2.Can Array be used in Pointer-style syntax? e.g. *array, (array + 0), (array + 10)
Yes, arrays can be used in pointer-style syntax. For example, *array is equivalent to array[0], and *(array + 10) is equivalent to array[10].

3. Is ptr++ valid?
Yes, ptr++ is valid. It increments the pointer to point to the next element in the array or memory block it is pointing to.

4. Is array++ valid?
No, array++ is not valid. Arrays in C are not modifiable lvalues, meaning you cannot change the address they represent.

5. What is sizeof(array)?
sizeof(array) returns the total size of the array in bytes. For an array of 100 integers, it would be 100 * sizeof(int). Assuming sizeof(int) is 4 bytes, sizeof(array) would be 400 bytes.

6. What is sizeof(ptr)?
sizeof(ptr) returns the size of the pointer itself, not the size of the memory it points to. On most systems, this is typically 4 or 8 bytes, depending on whether the system is 32-bit or 64-bit.

_____________________________________________________________________________________________________________________________

2. Refer the code snippet below. Comment on the other elements (other than those that are explicitly initialized) of all array variables in code snippet below.

#define MAX 100

int main()

{

int arr[MAX] = {11,22,33};

int arr1[MAX]={0};

static int arr2[MAX];

}

int arr[MAX] = {11, 22, 33};- The first three elements of arr are explicitly initialized to 11, 22, and 33.
The remaining elements (from arr[3] to arr[99]) are automatically initialized to 0.
int arr1[MAX] = {0};
The first element arr1[0] is explicitly initialized to 0.
The remaining elements (from arr1[1] to arr1[99]) are also automatically initialized to 0.
static int arr2[MAX];
Since arr2 is declared as a static array, all its elements are automatically initialized to 0 by default, even though no explicit initialization is provided.

____________________________________________________________________________________________________________________________________________


3. 3. Refer the program “array_pointer.c”. Add a function getmax() to find the maximum in the array and call in main() and display the result.

Referring the array_pointer.c to find the maximum in the array and call in main() and to display the result used getmax()



#include <stdio.h>

/*************************************************************************
*                               MACROS
*************************************************************************/
#define MAX 5
#define ROW 2
#define COL 3

/******************************************************************************
*
*       Function Name   : getmax
*       Description     : Finds the maximum value in the array
*       Returns         : Maximum value in the array
*
*******************************************************************************/
int getmax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/******************************************************************************
*
*       Function Name   : main
*       Description     : Demonstration of arrays and pointers
*       Returns         : Success or Failure
*
*******************************************************************************/
int main()
{
    int index_1; /* for loop indices */
    int index = 0; /* Stores the index of minimum value */
    int min; /* Variable to keep track of minimum in the array */

    /* 1-d array declaration and initialization */
    int numbers[MAX] = {44,22,11,55,33};

    min = 99; /* Initialized to maximum 2-digit number */ 

    /* Displaying the array */
    for(index_1 = 0; index_1 < MAX; index_1 += 1)
    {
        printf("%d\t", numbers[index_1]);
    }
    printf("\n");

    /* Searching for the minimum and replace that with 0 */
    for(index_1 = 0; index_1 < MAX; index_1 += 1) 
    {
        if(*(numbers + index_1) < min) /* Checking for minimum */
        {
            min = *(numbers + index_1); /* Replacing min with new less value */
            index = index_1; /* Storing the index */
        }
    }
    *(numbers + index) = 0; /* Replacing minimum value with 0 */
  
    /* Displaying the array */
    for(index_1 = 0; index_1 < MAX; index_1 += 1)
    {
        printf("%d\t", numbers[index_1]);
    }
    printf("\n");

    /* Finding and displaying the maximum value in the array */
    int max_value = getmax(numbers, MAX);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}


__________________________________________________________________________________________________________________________

4. Extend the code given below to read N and a start value from the user to perform the given operations.

#define MAX 100

int main()

{

int arr[MAX] = {11,22,33};

}


Add the following functions choosing proper input, output and return.

a. init() - Use the inputs to initialize the first N elements of the array with N consequetive values starting with given start value .

b. update() – increment value of every element in the array

c. display() – display the contents of array


#include <stdio.h>

#define MAX 100

void init(int arr[], int N, int start);
void update(int arr[], int N);
void display(int arr[], int N);

int main() {
    int arr[MAX] = {0}; // Initialize array with zeros
    int N, start;

    // Read N and start value from the user
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);
    printf("Enter the start value: ");
    scanf("%d", &start);

    // Initializing the array
    init(arr, N, start);

    // Update the array
    update(arr, N);

    // Display the array
    display(arr, N);

    return 0;
}

void init(int arr[], int N, int start) {
    for (int i = 0; i < N; i++) {
        arr[i] = start + i;
    }
}

void update(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i]++;
    }
}

void display(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
__________________________________________________________________________________________________________________________