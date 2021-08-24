#include<stdio.h>
int main ()
{
    int x,y,z,sum,average,product,smallest,largest;
    printf("Enter three different integers : ");
    scanf("%d%d%d",&x,&y,&z);
    sum = x + y + z;
    average = sum/3;
    product = x*y*z;
        printf("Sum is %d\n",sum);
        printf("Average is %d\n",average);
        printf("Product is %d\n",product);
    if(x<y) //check ig x is less than y
        if(x<z) //check if x is less than z
            printf("Smallest is %d\n",x);
    if(y<x) //check if y ix less than x
        if(y<z) //check if x is less than z
            printf("Smallest is %d\n",y);
    if(z<x) //check if z is less than x
        if(z<y) //check if z is less than y
            printf("Smallest is %d\n",z);
    if(x>y) //check if x is more than y
        if(x>z) //check if x is more than z
            printf("Largest is %d\n",x);
    if(y>x) //check if y is more than x
        if(y>z) //check if y is more than z
            printf("Largest is %d\n",y);
    if(z>x) //check if z is more than x
        if(z>y) //check if z is more than y
            printf("Largest is %d\n",z);
    return 0;
}
