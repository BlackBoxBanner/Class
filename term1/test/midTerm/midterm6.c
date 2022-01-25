#include <stdio.h>

int factorial(int n)
{
    int fact = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int combination(int num1, int num2)
{
    int com;
    do
    {
        com = factorial(num1) / (factorial(num1 - num2) * factorial(num2));
    } while (num1 < num2);

    return com;
}

int main()
{
    int num1, num2, com;
    scanf("%d %d", &num1, &num2);
    if (num1 <= 0 || num1 > 50 || num2 <= 0 || num2 > 50 || num1 <= num2)
    {
        return printf("ERROR");
    }

    printf("%d", combination(num1, num2));

    return 0;
}
