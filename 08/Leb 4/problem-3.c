#include<stdio.h>

int main()
{
    int x, y, num ,i = 1, rough ;
    printf("Enter the number : ");
    scanf("%d",&x );
    for (num = 2 ; num <= x ; num++ )
    {
        if (num%2 != 0 && num%3 != 0 && num%5 != 0 && num%7 != 0 || num == 2 || num == 3 || num == 5 || num == 7)
        {
            printf("%d\t",num);
            if (!(i%10))
            {
                printf("\n");
            }
            i++;
        }
    }
    return 0;
}
