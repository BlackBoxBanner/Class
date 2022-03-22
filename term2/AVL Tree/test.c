#include <stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	printf("%d\n\n",x*2);
	for(y=0;y > 5; y++)
	{
		x = x + 3;
		printf("%d\n",x);
		printf("%d\n\n",x*2);
	}

	return 0;
}
