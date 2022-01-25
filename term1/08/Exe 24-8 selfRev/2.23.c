#include <stdio.h>

int main ()
{
    int num1, num2, num3; 
    //get the calue for num1, num2 and num3
    printf("Enter three different integers: ");
    scanf("%d %d %d", &num1,&num2,&num3);

    if (num1 > num2) //check if num1 is more than num2 and num3
    {
        if (num1 > num3)
        {
            printf("Largest is %d\n",num1);
        }
        else
        {
            printf("Largest is %d\n",num3);
        }
    }
    else if (num2 > num3) //if num2 is more than num3
        printf("Largest is %d\n",num2);
    else
        printf("Largest is %d\n",num3);


        if (num1 < num2) //if num1 is less than  num2 and num3
    {
        if (num1 < num3)
        {
            printf("Smallest is %d\n",num1);
        }
        else
        {
            printf("Smallest is %d\n",num3);
        }
    }
    else if (num2 < num3) //if num2 isless than num3
        printf("Smallest is %d\n",num2);
    else
        printf("Smallest is %d\n",num3);
}




