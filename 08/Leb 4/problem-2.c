#include<stdio.h>

int main()
{
    int x, y, z, i; //declare caliable 
    x = y = 1;
    printf("Enter the number ");
    scanf("%d", &i); //scan for user input
    printf("%d",y);
    for (z = 0; z <= i; z++) //set loop
    {
        printf("    %d", x); //print the result
        x = x+y;
        y = x - y;
    }
    
    return 0;
}
