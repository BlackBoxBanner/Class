/*

*/
#include <stdio.h>
#include <stdlib.h>

void Reci(double a[], int b)
{
    char pp[] = "Price";
    char VV[] = "VAT";
    char TT[] = "Item Total";
    char line[] = "----------";
    double netsum[20];
    
    printf("%9s%10s%14s\n%11s%11s%11s",pp,VV,TT,line,line,line);
    for (int p = 0; p < b; p++)
    {
        printf("\n%11.2lf", a[p]); //price

        if (a[p] < 100) 
        {
            printf("%11.2lf", a[p]*0); //VAT
        }
        else
        {
            printf("%11.2lf", a[p]*0.07); //VAT
        }
        
        if (a[p] < 100) //
        {
            printf("%11.2lf", (a[p]*0)+a[p]); //total
        }
        else
        {
            printf("%11.2lf", (a[p]*0.07)+a[p]); //total
        }
    }
    printf("\n%11s%11s%11s\n",line,line,line);
    
    //========================================================================//

    for (int l = 0; l < b; l++) //total price
    {
        netsum[0] = netsum[0] + a[l];
    }
    printf("%11.2lf",netsum[0]); // Display total price

    for (int l = 0; l < b; l++) //total VAT
    {
        if (a[l] < 100) 
        {
            netsum[1] = netsum[1] + a[l]*0;
        }
        else
        {
            netsum[1] = netsum[1] + a[l]*0.07;
        }
    }
    printf("%11.2lf",netsum[1]); // Display total VAT

    for (int l = 0; l < b; l++) // net Total
    {
        if (a[l] < 100) 
        {
            netsum[2] = netsum[2] + ((a[l]*0)+a[l]);
        }
        else
        {
            netsum[2] = netsum[2] + ((a[l]*0.07)+a[l]);
        }
    }
    printf("%11.2lf",netsum[2]); //Display net total
       
}

int main()
{
    double prices[20];
    int NumberinB;
    system("cls");
    printf("How many items in your basket? ");
    scanf("%d", &NumberinB);
    
    if (NumberinB > 20)
    {
        printf("The program cannot handle this many items");
        return 0;
    }
    else
    {
        for (int i = 0; i < NumberinB; i++)
        {
            printf("Enter the price %d : " ,i+1);   
            scanf("%lf", &prices[i]);
        }
        printf("\n\nHere is your receipt:\n\n");
        Reci(prices, NumberinB);
    }
    return 0;
}