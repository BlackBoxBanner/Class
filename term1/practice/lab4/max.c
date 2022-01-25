// Lab4 
#include <stdio.h>

void recipt(double prices[], int a) //prices is price of items, a is number of items
{
    double finalsum[20];

    printf("Price\n-----------\n"); // Prices
    for(int i = 0; i < a; i++)
    {
        printf("%.2lf\n",prices[i]);
    }
    
    for (int o = 0; o < a; o++)
    {
        finalsum[0] += prices[o]; // finalsum[0] = finalsum[0] + prices[o];
    }
    printf("-----------\n%.2lf", finalsum[0]);
    
    printf("\n\nVAT\n-----------\n");
    for(int h = 0; h < a; h++)
    {
        if(prices[h] >= 100)
        {
        printf("%.2lf\n",(prices[h]*0.07));
        }
        else
        {
        printf("%.2lf\n",(prices[h]*0));
        }
        
    }
    for(int l = 0; l < a; l++)
    {
        if(prices[l] >= 100)
        {
            finalsum[1] += prices[l]*0.07; 
        }
        else
        {
            finalsum[1] += prices[l]*0; 
        }
    }
    printf("-----------\n%.2lf\n",finalsum[1]);
    
    
}

int main()
{
    double prices[20];
    int a; // a is numbers of item.

    printf("How many items in your basket? ");
    scanf("%d",&a);

    if( a <= 20)
    {
        for (int i = 0; i < a; i++)
        {
            printf("Price for item %d? ",i+1);
            scanf("%lf",&prices[i]);
        }
        printf("\nHere is your receipt: \n\n");
        recipt(prices,a);
    }
    else
    {
        printf("This program cannot handle this many item");
        return 0;
    }

    return 0;
}

/*

Price
-----------
1233
12
12
12
112
325
-----------
121
===========

VAT
-----------
12
-----------
12
===========

Item Total
-----------
1231
-----------
1212
===========
*/