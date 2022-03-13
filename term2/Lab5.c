#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display(char queue[], char output[], int front, int rear);
char delete (char queue[], int *front, int *rear);
void insert(char queue[], int *front, int *rear);

void insert(char queue[], int *front, int *rear)
{
  char buffer;
  char input[256];

  fgets(input, 256, stdin);
  sscanf(input, "%c", &buffer);

  if (*front == 0 && *rear == 9)
  {
    return;
  }
  else if (*front == -1 && *rear == -1)
  {
    *front = *rear = 0;
    queue[*rear] = buffer;
  }
  else if (*rear == 9 && *front != 0)
  {
    *rear = 0;
    queue[*rear] = buffer;
  }
  else
  {
    *rear += 1;
    queue[*rear] = buffer;
  }
}

char delete (char queue[], int *front, int *rear)
{
  char data;
  if (*front == -1 && *rear == -1)
  {
    return '\0';
  }

  data = queue[*front];

  if (*front == *rear)
  {
    *front = *rear = -1;
  }
  else
  {
    if (*front == 9)
    {
      *front = 0;
    }
    else
    {
      *front += 1;
    }
  }

  return data;
}

void display(char queue[], char output[], int front, int rear)
{
  int i;
  int j = 0;

  printf("Queue: ");

  if (front == -1 && rear == -1)
  {
    printf("-");
  }
  else if (front != -1 && rear != -1)
  {
    i = front;

    while (i <= 9)
    {
      if (queue[i] == '\0')
      {
        break;
      }

      printf("%-5c", queue[i]);

      i++;
    }
    if (rear < front)
    {
      for (i = 0; i <= rear; i++)
      {
        if (queue[i] == '\0')
        {
          break;
        }
        printf("%-5c", queue[i]);
      }
    }
  }

  printf("\n");
  printf("Data : ");

  while (output[j] != '\0')
  {
    printf("%-5c", output[j]);
    j++;
  }
}

int main()
{
  int i = 0;
  int option;
  int rear = -1;
  int front = -1;
  char input[256];
  char queue[10];
  char output[256];

  for (int i = 0; i < 256; i++)
  {
    output[i] = '\0';
  }
  while (1)
  {
    switch (option)
    {
    case 1:
      insert(queue, &front, &rear);
      break;
    case 2:
      output[i] = delete (queue, &front, &rear);
      if (output[i] == '\0')
      {
        i--;
      }
      i++;
      break;
    case 3:
      display(queue, output, front, rear);
      exit(0);
    }
    fgets(input, 256, stdin);
    sscanf(input, "%d", &option);
  }
}

/*
1
A
1
B
1
C
1
D
1
E
1
F
2
2
1
G
1
H
2
2
2
2
1
I
3
*/
