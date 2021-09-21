#include<stdio.h>
#define SSMax 4

void simpleSort(double num1, double num2, double num3, double num4)
{
    double simsort[SSMax] = { num1 , num2 , num3 , num4 };
    int i, j, temp = 0;
    for (i = 0; i < SSMax; ++i)
    {
        for (j = i + 1; j < SSMax; ++j)
        {
            if (simsort[i] < simsort[j])
            {
                temp =  simsort[i];
                simsort[i] = simsort[j];
                simsort[j] = temp;
            }
        }
    }
    printf("Sort number are : ");
    for (i = 0; i < SSMax; i++)
    {
        printf(" %.2lf", simsort[i] );
    }
    
}

int main()
{
    double num1, num2, num3, num4, finalnum;
    printf("Enter 4 unsorted numbers :");
    scanf("%lf %lf %lf %lf", &num1, &num2, &num3, &num4 );
    simpleSort(num1, num2, num3, num4);
    return 0;
}