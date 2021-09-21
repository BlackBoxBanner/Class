#include<stdio.h>
#define MAX 999
void Remove2();
void Remove3();
void Remove5();
void Remove7();

int main()
{
    int num;
    int arr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = i + 2;
    }
    printf("Please enter a number [more than 2]: ");
    scanf("%d", &num);
    Remove2(arr,num);
    return 0;
}

void Remove2(int num[], int i)
{
    int j, k,  Modu2[i/2];
    for (j = 0; j < i - 2; j++)
    {
        if (num[j]%2 == 1||num[j] == 2)
        {
            Modu2[k] = num[j];
        }
    }
    printf("");
    for (int o = 0; o < i/2; o++)
        {
            printf("\n%d" , Modu2[o]);
        }
}
