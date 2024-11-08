#include <stdio.h>

int main()
{
    int number;
    printf("Enter a positive integer:");
    scanf("%d",&number);
    if(number<2)
    {
        printf("No prime pairs can sum up to the given number\n");
    }
    else
    {
        findprimepairs(number);
    }
    return 0;
}

int isPrime(int num)
{
    if(num<=1)
    {
        return 0;
    }
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            return 0;
        }
        
    }
    return 1;
}

void findprimepairs(int number)//(performs)
{
    int count=0;
    for(int i=2;i<=number/2;i++)
    {
        int comp=number-i;
        if(isPrime(i)&&isPrime(comp))
        {
            printf("%d=%d+%d\n",number,i,comp);
            count++;
        }
    }
    printf("Noofways=%d\n",count);
}
