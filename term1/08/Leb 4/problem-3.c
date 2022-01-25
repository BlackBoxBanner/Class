#include<stdio.h>

int main()
{
    int x, y, num ,i = 1, rough ; //declare variable    
    printf("Enter the number : "); 
    scanf("%d",&x ); //scan for user input
    for (num = 2 ; num <= x ; num++ ) //set loop
    {
        /*
        check if number is mob by 2, 3 and get 0 or 2,3,5,7
        */
        if (num%2 != 0 && num%3 != 0 && num%5 != 0 && num%7 != 0 || num == 2 || num == 3 || num == 5 || num == 7)
        {
            printf("%d\t",num); //print the result
            if (!(i%10)) //check if i mod 10 is collect
            {
                printf("\n"); //set a new line
            }
            i++;
        }
    }
    return 0;
}