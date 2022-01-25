#include <stdio.h>


int main()
{
  int buffer1,buffer2,buffer3;
  buffer1 = 1;
  buffer2 = 2;
  buffer3 = 3;
  printf("%d\n",buffer1);
  printf("%d\n",buffer2);
  printf("%d\n",buffer3);
  scanf("%d",&buffer1);
  buffer1 = buffer1 + buffer2;
  printf("%d\n",buffer1);
  return 0;
}
