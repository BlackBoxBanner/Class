#include<stdio.h>

int main()
{
    int x, i, day, week;
    printf("\t\t\tAugust 2021\n");
    printf("S\tM\tT\tW\tTh\tF\tSa\n\n");
    for(day = 1; day <= 31; day++)
    {
        printf("%d\t", day);
        if (day%7 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}
