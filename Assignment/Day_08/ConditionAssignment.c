1. 

                        HEADER
*******************************************************************************/

#include<stdio.h>



/******************************************************************************
*
*     FUNCTION NAME   :    Ternary Operator
*
*     DESCRIPTION     : Using ternary operato compare 3 numbers and display
                        smallest number
*******************************************************************************/
  
 int main()
 {
      int num1,num2,num3,res;

         printf("Enter num1: ");
         scanf("%d",&num1);

         printf("\nEnter num2: ");
         scanf("%d",&num2);

         printf("\nEnter num3: ");
         scanf("%d",&num3);
         res=(num1<num2)?((num1<num3)?num1:num3):((num2<num3)?num2:num3);
         printf("\n%d is the smallest\n",res);

         return 0;
 }

______________________________________________________________________

2. /******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/******************************************************************************
*
*     FUNCTION NAME   :    if-else,switch
*
*     DESCRIPTION     :    to read a designation code and display his designation as a string. 
  Use the following mapping.
  3 2 – Software Developer
  4 3 – Senior Software Developer
  5 4 – Team Lead
  6 5 – Senior Team Lead
  7 anyother value – incorrect designation code
*******************************************************************************/

 int main()
 {
     int desCode;

         printf("Enter Designation Code:");
         scanf("%d",&desCode);

             if(desCode==2)
                 printf("Designation is Software Developer\n");
             else if(desCode==3)
                 printf("Designation is Senior Software Developer\n");
             else if(desCode==4)
                 printf("Designation is Team Lead\n");
             else if(desCode==5)
                 printf("Designation is Senior Team Lead\n");
             else
                 printf("Incorrect designation code\n");

             return 0;
 }
_____________________________________________________________________________

3.  /******************************************************************************

                        HEADER
*******************************************************************************/

#include<stdio.h>



/******************************************************************************
*
*     FUNCTION NAME   :    if-else, switch
*
*     DESCRIPTION     :    to test the eligibility for deployment post training. 
                           Need to fulfill all the 4 conditions. 
                           Read the score inputs from user at runtime.     
                          (Use if else and switch together).
i. Test1 Score >= 75%

ii. Test2 Score >= 75%

iii. Test3 Score >= 70%

iv. Project Score >=75%

*******************************************************************************/int main()
 {
     int t1Scr,t2Scr,t3Scr,prjtScr;

         printf("Enter test1 Score:");
         scanf("%d",&t1Scr);

         printf("Enter test2 Score:");
         scanf("%d",&t2Scr);

         printf("Enter test3 Score:");
         scanf("%d",&t3Scr);

         printf("Enter project Score:");
         scanf("%d",&prjtScr);

         if((t1Scr>=75) && (t2Scr>=75) && (t3Scr>=70) && (prjtScr>=75))
         {
             printf("Eligible for deployment to Post training\n");
         }
         else
         {
             printf("Not Eligible for deployment to post training\n");
         }

         return 0;
  }
