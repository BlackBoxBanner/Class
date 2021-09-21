#include<stdio.h>

double factorial(double num)
{
    if (num == 1)
    {
        return 1;
    }
    else return num * factorial( num - 1 );
}

int main()
{
    double fact, a;
    printf("Input the number for Factorial : ");
    scanf("%lf", &fact);
    printf("The factorial of %.0lf is %.0lf.", fact, factorial(fact));
    return 0;
}
