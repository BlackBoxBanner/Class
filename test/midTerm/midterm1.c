#include<stdio.h>

int separateDigits(int n)
{
    int a , b = 1;
    a = n;
    while (a)
    {
        a /= 10;
        b *= 10;
    }
    while (b > 1)
    {
        b /= 10;
        printf("%d   ", n / b);
        n %= b;
    }
}

int main()
{
    int number;
    scanf("%d",&number);
    //Receive input from keyboard (you can edit the code in main function in this line)

    separateDigits(number); //function for printing your result
    printf("");

    return 0;
}