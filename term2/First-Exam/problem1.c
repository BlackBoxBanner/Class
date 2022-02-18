#include <stdio.h>

void getInteger(int data[])
{
  for (int i = 0; i < 20; i++)
  {
    scanf("%d", &data[i]);
  }
}

int deleteDuplicate(int data[])
{
  int size = 20;

  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (data[i] == data[j])
      {
        for (int k = j; k < size - 1; k++)
        {
          data[k] = data[k + 1];
        }
        size--;
        j--;
      }
    }
  }
  return size;
}

void displayInteger(int data[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", data[i]);
  }
}

int main()
{
  int data[20];
  int dupe;

  getInteger(data);
  dupe = deleteDuplicate(data);
  displayInteger(data, dupe);

  return 0;
}

/*
1
7
4
1
5
6
5
3
9
0
0
7
3
7
3
3
6
1
7
6
*/