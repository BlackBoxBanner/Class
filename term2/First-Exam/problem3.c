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
  char input[500];
  char buffer[500];
  scanf("%[^\n]s", input);
  for (int i = 0; i < strlen(input); i++)
  {
    struct reverse *newNode = (struct reverse *)malloc(sizeof(struct reverse));
    newNode->cherecter = input[i];
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
  }
  return head;
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

struct reverse *deleteSpace(struct reverse *head)
{
  struct reverse *current = head;
  struct reverse *prev = NULL;
  struct reverse *next = NULL;
  while (current != NULL)
  {
    next = current->next;
    if (current->cherecter == ' ')
    {
      if (prev == NULL)
      {
        head = next;
      }
      else
      {
        prev->next = next;
      }
    }
    else
    {
      prev = current;
    }
    current = next;
  }
  return head;
}

struct reverse *insertDash(struct reverse *head)
{
  struct reverse *current = head;
  struct reverse *prev = NULL;
  struct reverse *next = current->next;

  while (next != NULL)
  {
    struct reverse *newNode = (struct reverse *)malloc(sizeof(struct reverse));
    newNode->cherecter = '-';
    newNode->next = next;
    current->next = newNode;
    current = newNode;
    prev = current;
    current = next;
    next = next->next;
  }
  return head;
}

int main()
{
  struct reverse *head = createList();
  head = deleteSpace(head);
  head = insertDash(head);
  printList(head);
  return 0;
}