#include<stdio.h>

int main()
{
    int x, y, z, i;
    x = y = 1;
    printf("Enter the number ");
    scanf("%d", &i);
    printf("%d",y);
    for (z = 0; z <= i; z++)
    {
        printf("    %d", x);
        x = x+y;
        y = x - y;
    }
    
    return 0;
}
