1./******************************************************************************

                        HEADER
*******************************************************************************/

#include"stdio.h"



/******************************************************************************
*
*     FUNCTION NAME   :    for loop
*
*     DESCRIPTION     :    Desc:to read a number n and to display the cumulative sum of factorial of all numbers upto n . (use for or while)
*
*     RETURNS         : 4!+3!+2!+1! = 32
*
******************************************************************************
 */
 int main()
 {
     int num,iter1,iter2,fact,cuSum=0;
     printf("Enter a number: ");
     scanf("%d",&num);
     for(iter1 = num; iter1>=1; iter1--)
     {

         fact=1;
         for(iter2=1; iter2<=iter1; iter2++)
             fact *=iter2;
         cuSum +=fact;
     }
     printf("%d\n",cuSum);
     return 0;
}

____________________________________________________________________________

2./******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/***********************************************************************
*
*     FUNCTION NAME   :    while loop
*
*     DESCRIPTION     :    to accept "N" integers from the user.
*
*     RETURN          :    Gives no of positive integers, Negative integers and Zeros.
*******************************************************************************//*
  */


 int main() {
    int N, num;
     int positive_count = 0, negative_count = 0, zero_count = 0;
     int result;
     printf("Enter the number of integers (N): ");
     while (scanf("%d", &N) != 1) {
         printf("Invalid input. Please enter an integer for N: ");
         while (getchar() != '\n');
     }
     for (int i = 0; i < N; i++) {
         printf("Enter integer %d: ", i + 1);
         while ((result = scanf("%d", &num)) != 1) {
             printf("Invalid input. Please enter an integer: ");
             while (getchar() != '\n');
         }
         if (num > 0) {
             positive_count++;
         } else if (num < 0) {
 negative_count++;
         } else {
             zero_count++;
         }
     }
     printf("Positive numbers: %d\n", positive_count);
     printf("Negative numbers: %d\n", negative_count);
     printf("Zeros: %d\n", zero_count);
     return 0;
 }

_________________________________________________________________________
3./******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SUCCESS 0;
#define EXIT 1;


/******************************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :    Write a program to continuously read a string of maximum length 80 chars, End the program if string is END, else convert to upper case, display and     continue. (use while)
*
*     RETURN          :    Gives Upper Case
*******************************************************************************/
 int main()
 {
     char str[81];
     while(1)
     {
         printf("Enter a string max 80 characters:");
         fgets(str,sizeof(str),stdin);
         str[strcspn(str,"\n")]='\0';
         if(strcmp(str,"END")==0)
         {
             break;
         }
         for(int iter =0;str[iter] !='\0';iter++)
         {
             str[iter]=toupper(str[iter]);
         }
         printf("uppercase: %s\n",str);
     }
     printf("Program terminated\n");
     return 0;
 }
___________________________________________________________________________

4./******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/***********************************************************************
*
*     FUNCTION NAME   :    display
*
*     DESCRIPTION     :    to run the program with a large value say 255.
*
*
*******************************************************************************//*
  */
 int main()
{
        long double fact=1;
        long double count,num;
        printf("Enter a number:");
        scanf("%Lf",&num);
        for(count = 1;count <= num;count++)
        {
                fact = fact * count;
        }
        printf("factorial of %Lf is :%Lf \n",num,fact);
        return 0;
 }

______________________________________________________________________________
5./******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/***********************************************************************
*
*     FUNCTION NAME   :    while loop
*
*     DESCRIPTION     :   decrements the value 
*
*
*******************************************************************************//*
  */
 int main()
 {
 int x = 5;

 while (x > 0);

 {

 printf( "Value of x :%d \n", x);

x--;
 }
 return 0;
}
 */
 #include <stdio.h>

 int main()
 {
     int x = 5;
     while (x > 0)
     {
         printf( "Value of x :%d \n", x);
         x--;
     }
     return 0;
 }
_______________________________________________________________________
6./******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/***********************************************************************
*
*     FUNCTION NAME   :    while loop
*
*     DESCRIPTION     :   decrements the value
*      
*     RETURN          :   1000.000000
*
*******************************************************************************//*
  */
 int main()

 {

 float cnt = 0, num = 1000;

 do

 {

 printf ("\n%f\n%f", num,cnt);

 num /= cnt;

 } while (cnt --); /* End of while */

 return 0;

}