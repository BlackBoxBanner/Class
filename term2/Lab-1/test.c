#include <stdio.h>
int main();
{
  int height;
  int width;
  int perimeter;
  printf("Enter the height\n");
  scanf("%d", &height);
  printf("Enter the width\n");
  scanf("%d", &width);
  perimeter = 2 * (height + width);
  printf("Perimeter of rectangle = %d\n", perimeter);
  return 0;
}
