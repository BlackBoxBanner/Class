#include<stdio.h>

int main()
{
    int n, i, sum = 0, fact = 1;
    scanf(' %d',&n);
    for( i = 1 ; i == n ; i++ )
    {
    sum +=1;
    fact *= sum;
    }
    printf("%d",n);
    return 0;
}
