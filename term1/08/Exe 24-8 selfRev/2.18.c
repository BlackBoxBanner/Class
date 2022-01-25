#include<stdio.h>

int main()
{
    int x, y, z;
    printf("Enter 2 intergers in order to compare.(input format 'x y')\n");
    scanf("%d %d", &x, &y);
    printf("User number is %d and %d\n", x, y); 
    if (x == y) //check if x is equal to y
    {
        printf("The number are equal\n\n");
    }
    if(x > y) //check if x is more than y
    {
        printf("%d is larger", x);
    }
        if(x < y) //check if x is less than y
    {
        printf("%d is larger", y);
    }

    return 0;
}
