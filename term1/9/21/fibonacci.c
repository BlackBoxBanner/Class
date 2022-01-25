#include<stdio.h>

int fibonacci_cal(int fib)
{
    int i = 0, a = 0, b = 1, c;
    printf("0 , 1 ");
    for (i = 2; i < fib; i++)
    {
        a += b;
        printf(", %d ", a);
        c = a;
        a = b;
        b = c;
    }
    
}

int main()
{
    int fib;
    printf("Enter the number to fibonacci : ");
    scanf("%d",&fib);
    fibonacci_cal(fib);
    return 0;
}
