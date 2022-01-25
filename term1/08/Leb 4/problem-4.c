#include<stdio.h>
#include<math.h>

int main(){
	int n, i; //declare variable
	
	printf("Enter the number: ");
	scanf("%d",&n); //scan for user input
	printf("The factor of %d is ",n);
	
	while (n%2 == 0){ //set loop (while)
    	printf("%d*", n);
        n = n/2;
    }

    for (i=3; i <= sqrt(n); i=i+2){ //set loop (for)
        while (n%i == 0){ //while n mod i is equal to 0
            printf("%d*" , i);
            n = n/i;
        }
    }
    if (n > 2){ //check if n is more than 2
    	printf ("%d", n);
	}
	return 0;
}