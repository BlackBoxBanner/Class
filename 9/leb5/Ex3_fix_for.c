#include<stdio.h>

int main()
{
    int i, j, x, c;
    char input, alphabet = 'A'; //10

    printf("Enter the uppercase you want to print in last row: ");
    scanf("%c",&input);//20
    c = input;

    for(i=1; i <= (input-'A'+1); ++i)
    {
        for (x = 0; x<=input-'A'-i; ++x)
        {
            printf(" ");
        }
        
        for(j=1;j<=i;++j)
        {
            printf("%c", alphabet);
        }
        ++alphabet;

        printf("\n");
    }
    return 0;
}