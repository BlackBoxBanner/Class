#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void getInteger(int nums[]);
void displayInteger(int nums[], int remain);
int deleteDuplicate(int nums[]);

int main()
{
  int nums[20], remain;

  getInteger(nums);
  remain = deleteDuplicate(nums);
  displayInteger(nums, remain);
}

void getInteger(int nums[])
{
  int i;

  for (i = 0; i < 20; i++)
  {
    scanf("%d", &nums[i]);
  }
}

void displayInteger(int nums[], int remain)
{
  int i;

  for (i = 0; i < remain; i++)
  {
    printf("%d ", nums[i]);
  }
}

int deleteDuplicate(int nums[])
{
  int i, j, k, remain = 20;

  for (i = 0; i < remain; i++)
  {
    for (j = i + 1; j < remain; j++)
    {
      if (nums[i] == nums[j])
      {
        for (k = j; k < remain - 1; k++)
        {
          nums[k] = nums[k + 1];
          remain--;
        }
      }
    }
  }

  return remain;
}