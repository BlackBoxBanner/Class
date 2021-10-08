#include <stdio.h>

void printUpperHalf(int num)
{
    int i, o, p, z, x;
    for (i = 1; i <= num; i++)
    {
        for (o = 1; o <= num - 1; o++)
        {
            printf(" ");
        }
        
        for (p = num -1; p > 0; p--)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printLowerHalf(int num)
{
    int i, o, p;
    for (i = num; i >= 0; i--)
    {
        for (o = 1; o < num - i + 2; o++)
        {
            printf(" ");
        }
        printf("\n");
        for (p = 3; p <= i - 1; p++)
        {
            printf("*");
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    if (num < 0 || num > 10)
    {
        return printf("ERROR");
    }

    printUpperHalf(num);
    printLowerHalf(num);

    return 0;
}
