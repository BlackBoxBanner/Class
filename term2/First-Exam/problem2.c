#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reverse
{
  char cherecter;
  struct reverse *next;
};

struct reverse *createList()
{
  struct reverse *head = NULL;
  struct reverse *current = NULL;
  char input;
  char buffer[99];
  fgets(buffer, 99, stdin);
  sscanf(buffer, "%c", &input);
  while (input != '0')
  {
    struct reverse *newNode = (struct reverse *)malloc(sizeof(struct reverse));
    newNode->cherecter = input;
    newNode->next = NULL;
    if (head == NULL)
    {
      head = newNode;
      current = newNode;
    }
    else
    {
      current->next = newNode;
      current = newNode;
    }
    fgets(buffer, 99, stdin);
    sscanf(buffer, "%c", &input);
  }
  return head;
}
struct reverse *reverseList(struct reverse *head)
{
  struct reverse *current = head;
  struct reverse *prev = NULL;
  struct reverse *next = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

void printList(struct reverse *head)
{
  struct reverse *current = head;
  while (current != NULL)
  {
    printf("%c", current->cherecter);
    current = current->next;
  }
}

int main(int argc, char const *argv[])
{
  struct reverse *head = createList();
  head = reverseList(head);
  printList(head);
  return 0;
}

/*
E
X
A
M
P
L
E
0
*/