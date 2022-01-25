#include<stdio.h>

int main()
{
    int x, i, day, week; //declare variable
    printf("\t\t\tAugust 2021\n");
    printf("S\tM\tT\tW\tTh\tF\tSa\n\n");
    for(day = 1; day <= 31; day++) //set a loop for day in month
    {
        printf("%d\t", day); //print the day result
        if (day%7 == 0) //setup the loop for 7 days in a week
        {
            printf("\n"); //print new line
        }
    }
    return 0;
}
