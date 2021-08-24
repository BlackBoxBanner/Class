#include<stdio.h>

int main ()
  {
    int x,y,product,sum,difference,quotient,remainder; //declare variable
    printf("Enter two number : ");
    scanf ("%d%d",&x,&y); //scan for input
        sum = x + y; //give value
        product = x * y; 
        difference = x - y ; 
        quotient = x / y ; 
        remainder = x % y ; 
    printf("Sum is %d\n",sum); //print value
    printf("Productis %d\n",product);
    printf("Difference is %d\n",difference);
    printf("Quotient is %d\n",quotient);
    printf("Remainder is %d\n",remainder);
return 0;
}
