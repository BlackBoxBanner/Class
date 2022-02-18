#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

struct node
{
  char courseName[50];
  char grade[5];
  int credit;
  struct node *next;
};

struct node *build(struct node *thisData)
{
  char courseName[50];
  char grade[5];
  char buff[256];
  int credit;
  struct node *current = NULL;
  struct node *ptr = NULL;

  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%[^\n]s", courseName);

  while (strcmp(courseName, "-") != 0)
  {
    current = (struct node *)malloc(sizeof(struct node));
    strcpy(current->courseName, courseName);
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%[^\n]s", grade);
    strcpy(current->grade, grade);
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d", &current->credit);

    if (thisData == NULL)
    {
      current->next = NULL;
      thisData = current;
    }
    else
    {
      ptr = thisData;
      while (ptr->next != NULL)
      {
        ptr = ptr->next;
      }
      current->next = NULL;
      ptr->next = current;
    }
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%[^\n]s", courseName);
  }
  return thisData;
}

void printList(struct node *thisData)
{
  struct node *ptr = thisData;
  int position = 1;

  // start from the beginning
  while (ptr != NULL)
  {
    printf("%2d %-50s %-3s %3d\n", position, ptr->courseName, ptr->grade, ptr->credit);
    ptr = ptr->next;
    position++;
  }
}

struct node *insert(struct node *thisData)
{
  char courseName[50];
  int credit;
  int position;
  char grade[5];
  char buff[256];

  struct node *current = NULL;
  struct node *ptrA = NULL;
  struct node *ptrB = NULL;

  int i = 0;
  current = (struct node *)malloc(sizeof(struct node));
  ptrA = thisData;
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d", &position);
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%[^\n]s", courseName);
  strcpy(current->courseName, courseName);
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%[^\n]s", grade);
  strcpy(current->grade, grade);
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d", &current->credit);

  if (position == 0)
  {
    current->next = ptrA;
    thisData = current;
    return thisData;
  }
  else
  {
    while (i < position)
    {
      ptrB = ptrA;
      ptrA = ptrA->next;
      i++;
      if (ptrA == NULL)
      {
        break;
      }
    }
  }

  current->next = ptrA;
  ptrB->next = current;

  return thisData;
}

struct node *delete (struct node *thisData)
{
  struct node *ptr = NULL;
  struct node *ptrA = NULL;
  struct node *ptrB = NULL;

  int i = 0;
  int position;
  char buff[256];

  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d", &position);

  ptrA = thisData;

  if (position == 0)
  {
    thisData = thisData->next;
    return thisData;
  }
  else
  {
    while (i < position)
    {
      ptrB = ptrA;
      ptrA = ptrA->next;
      if (ptrA == NULL)
      {
        return thisData;
      }
      i++;
    }
  }
  ptrB->next = ptrA->next;
  ptrA->next = NULL;
  free(ptrA);

  return thisData;
}

int main(int argc, char const *argv[])
{

  struct node *thisData = NULL;

  int option;
  char buff[256];

  thisData = build(thisData);

  while (1)
  {
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d", &option);
    if (option == 1)
    {
      thisData = insert(thisData);
    }
    else if (option == 2)
    {
      thisData = delete (thisData);
    }
    else
    {
      printList(thisData);
      break;
    }
  }
  return 0;
}

/*
ENGINEERING EXPLORATION
B
3
ACADEMIC ENGLISH IN INTERNATIONAL CONTEXTS
A
3
COMPUTER PROGRAMMING FOR ENGINEERS
C+
3
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
-
1
1
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
1
8
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
1
8
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
1
8
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
0
*/

/*
ENGINEERING EXPLORATION
B
3
ACADEMIC ENGLISH IN INTERNATIONAL CONTEXTS
A
3
COMPUTER PROGRAMMING FOR ENGINEERS
C+
3
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
-
2
2
2
10
0
*/

/*
ENGINEERING EXPLORATION
B
3
ACADEMIC ENGLISH IN INTERNATIONAL CONTEXTS
A
3
-
1
5
COMPUTER PROGRAMMING FOR ENGINEERS
C+
3
1
1
DISCRETE MATHEMATICS FOR COMPUTER ENGINEERS
C
3
0
*/