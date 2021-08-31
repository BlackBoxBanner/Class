#include<stdio.h>

int main()
{
    int n, i;
	int sum = 0; 
	long int fact = 1; //declare variable
	
    printf("Enter number: ");
    scanf("%d",&n); //input from user
    
    for( i = 1 ; i <= n ; i++ ) //set loop
    {
		sum += i; //summation ( x += 1 || x = x + 1 )
		fact *= i;
    }
    printf("Summation for 1 to %d  is %d\n",n,sum); //print the result
    printf("Facctorial of %d is %ld.\n",n,fact);
    return 0;
}
