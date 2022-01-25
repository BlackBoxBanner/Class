#include <stdio.h>

int main() {
  int number;

  printf( "Enter an integer: \n" ); //get value for number
  scanf( "%d", &number );

  if ( number % 2 == 0 ) { //if mod 2 from number is equal to 0
    printf( "%d is an even number.\n", number );
  } else {
    printf( "%d is an odd number. \n", number );
  }

  return 0;
}