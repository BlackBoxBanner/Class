#include <stdio.h>

int main() {
  int radius, diameter;
  double constantValue, circumference, area;

  printf( "Radius of the circle: \n" );
  scanf( "%d", &radius ); //scan for radius

  diameter = radius * 2; //give value to determine
  printf( "The diameter is %d\n", diameter );

  constantValue = 3.14159; //give value to constantValue
  circumference = constantValue * diameter; //give value to circumference
  printf( "The circumference is %f\n", circumference );

  area = constantValue * radius * radius; //give value to area
  printf("The area of the circle is %f\n", area );

  return 0;
}   