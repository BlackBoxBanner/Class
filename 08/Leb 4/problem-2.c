#include<stdio.h>

int main()
{
    int x, y, z;
    x = y = 1;
    printf("%d",y);
    for (z = 0; z <= 11; z++)
    {
        printf("    %d", x);
        x = x+y;
        y = x - y;
    }
    
    return 0;
}
