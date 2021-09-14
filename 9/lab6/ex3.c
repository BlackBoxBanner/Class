#include<stdio.h>

double cTf(double cel)
{
    double far;
    far = ( cel * 1.8 ) + 32;
    return far;
}

double fTc(double far)
{
    double cel;
    cel = ( far - 32 ) * 0.5555555;
    return cel;
}

int main()
{
    int i;
    int j;
    double fahrenheit;
    double celsius;
    printf("%10s%15s%5s%15s%10s", "Celsius" , "Fahrenheit" , "|" , "Fahrenheit" , "Celsius\n" );
    j = 32;
    for (i = 0; i < 300; i++)
    {
        if (i <= 100 )
        {
            printf("%10d%15.2lf", i, cTf(i));
        }
        if (j <= 212)
        {
            if (i <= 100)
            {
                printf("%5s", "|");
                printf("%15d%10.2lf\n", j, fTc(j));
                j++;
            }
            else
            {
                printf("%30s", "|");
                printf("%15d%10.2lf\n", j, fTc(j));
                j++;
            }
        }
    }
    return 0;
}
