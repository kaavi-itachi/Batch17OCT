#include<stdio.h>
void findNthPrimeNumber(int n,int*nthNumber)
{
    int primes[]={2,3,5,7};
    *nthNumber=0;
    int multiplier=1;
    for(;n>0;n=(n-1)/4){
        *nthNumber+=primes[(n-1)%4]*multiplier;
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
        findNthPrimeNumber(n,&nthNumber);
        int digitCount=countDigits(nthNumber);
        printf("Output: %d\n",nthNumber);
        printf("Number of digits in %d-th number:%d\n",n,digitCount);
    }
    return 0;
}