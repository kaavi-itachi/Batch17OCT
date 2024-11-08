#include<stdio.h>
void findNthNumber(int n,int*nthNumber)
{
    int digits[]={1,4,6,9.11,14};
    *nthNumber=0;
    int multiplier=1;
    for(;n>0;n=(n-1)/4){
        *nthNumber+=digits[(n-1)%4]*multiplier;
        multiplier*=10;
    }
}
int countDigits(int number)
{
    int count=0;
    for(;number>0;number/=10)
    {
        count++;
    }
    return count;
}
int main()
{
    int t,n;
    printf("Enter number of test cases: ");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter N: ");
        scanf("%d",&n);
        int nthNumber;
        findNthNumber(n,&nthNumber);
        int digitCount=countDigits(nthNumber);
        printf("Output: %d\n",nthNumber);
        printf("Number of digits in %d-th number:%d\n",n,digitCount);
    }
    return 0;
}
