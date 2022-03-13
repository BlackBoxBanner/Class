#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node NODE; // node is a structure

struct node
{                       // structure
  char course_name[51]; // char array of 50 characters
  char grade[5];        // char array of 4 characters
  int credit;           // integer
  NODE *next;           // pointer to the next node
};

NODE *start = NULL;      // start is a pointer to the first node
NODE *create_ll(NODE *); // function prototype
void display(NODE *);    // function prototype
NODE *delete_at(NODE *); // function prototype
NODE *insert_at(NODE *); // function prototype

int main()
{
  char buff[256];           // char array of 256 characters
  start = create_ll(start); // start is a pointer to the first node
  int i = 0;                // integer
  while (i == 0)
  {                                   // while loop
    int choice;                       // integer
    fgets(buff, sizeof(buff), stdin); // fgets function
    sscanf(buff, "%d", &choice);      // sscanf function
    if (choice == 1)
    {                           // if statement
      start = insert_at(start); // start is a pointer to the first node
    }
    else if (choice == 2)
    {                           // else if statement
      start = delete_at(start); // start is a pointer to the first node
    }
    else
    {
      display(start); // display function
      break;
    }
  }
  return 0;
}

NODE *create_ll(NODE *start)
{
  NODE *new_node, *ptr;               // new_node is a pointer to the first node and ptr is a pointer to the first node
  char buff[256], name[51], grade[5]; // char array of 256 characters and char array of 50 characters and char array of 4 characters
  int i = 0, credit;                  // integer
  fgets(buff, sizeof(buff), stdin);   // fgets function
  sscanf(buff, "%[^\n]s", name);      // sscanf function
  while (strcmp(name, "-") != 0)
  {                                          // while loop
    new_node = (NODE *)malloc(sizeof(NODE)); // new_node is a pointer to the first node

    strcpy(new_node->course_name, name);

    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%[^\n]s", grade); // sscanf function
    strcpy(new_node->grade, grade); // strcpy function

    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d", &new_node->credit);

    if (start == NULL)
    {                        // if statement
      new_node->next = NULL; // new_node is a pointer to the first node
      start = new_node;
    }
    else
    {
      ptr = start; // ptr is a pointer to the first node
      while (ptr->next != NULL)
      {                  // while loop
        ptr = ptr->next; // ptr is a pointer to the first node
      }
      ptr->next = new_node;  // ptr is a pointer to the first node
      new_node->next = NULL; // new_node is a pointer to the first node
    }
    fgets(buff, sizeof(buff), stdin); // fgets function
    sscanf(buff, "%[^\n]s", name);    // sscanf function
  }
  return start;
}

void display(NODE *start)
{
  NODE *ptr;   // ptr is a pointer to the first node
  ptr = start; // ptr is a pointer to the first node
  int i = 1;   // integer
  while (ptr != NULL)
  {
    printf("%2d %-50s %-3s %3d\n", i, ptr->course_name, ptr->grade, ptr->credit); // printf function
    ptr = ptr->next;
    i++;
  }
}

NODE *delete_at(NODE *start)
{
  NODE *ptr, *preptr;               // ptr is a pointer to the first node and preptr is a pointer to the first node
  char buff[256];                   // char array of 256 characters
  int i = 0;                        // integer
  ptr = start;                      // ptr is a pointer to the first node
  preptr = ptr;                     // preptr is a pointer to the first node
  int position;                     // integer
  fgets(buff, sizeof(buff), stdin); // fgets function
  sscanf(buff, "%d", &position);
  if (position == 0)
  {                      // if statement
    start = start->next; // start is a pointer to the first node
    return;
  }
  while (i < position)
  { // while loop
    preptr = ptr;
    ptr = ptr->next; // ptr is a pointer to the first node
    i++;
    if (ptr == NULL)
    {               // if statement
      return start; // return statement
    }
  }
  preptr->next = ptr->next; // preptr is a pointer to the first node
  free(ptr);
  return start;
}

NODE *insert_at(NODE *start)
{
  NODE *new_node, *ptr, *preptr;      // new_node is a pointer to the first node and ptr is a pointer to the first node and preptr is a pointer to the first node
  int position, i = 0;                // integer
  char buff[256], name[51], grade[5]; // char array of 256 characters and char array of 50 characters and char array of 4 characters

  fgets(buff, sizeof(buff), stdin); // fgets function
  sscanf(buff, "%d", &position);    // sscanf function

  new_node = (NODE *)malloc(sizeof(NODE)); // new_node is a pointer to the first node

  fgets(buff, sizeof(buff), stdin);      // fgets function
  sscanf(buff, "%[^\n]s", name);         // sscanf function
  strcpy(new_node->course_name, name);   // strcpy function
  fgets(buff, sizeof(buff), stdin);      // fgets function
  sscanf(buff, "%[^\n]s", grade);        // sscanf function
  strcpy(new_node->grade, grade);        // strcpy function
  fgets(buff, sizeof(buff), stdin);      // fgets function
  sscanf(buff, "%d", &new_node->credit); // sscanf function

  ptr = start;  // ptr is a pointer to the first node
  preptr = ptr; // preptr is a pointer to the first node
  if (position == 0)
  {                       // if statement
    new_node->next = ptr; // new_node is a pointer to the first node
    start = new_node;     // start is a pointer to the first node
    return start;         // return statement
  }
  while (ptr != NULL)
  { // while loop
    if (i < position)
    {                  // if statement
      preptr = ptr;    // preptr is a pointer to the first node
      ptr = ptr->next; // ptr is a pointer to the first node
      i++;
    }
    else
    {
      break;
    }
  }
  preptr->next = new_node; // preptr is a pointer to the first node
  new_node->next = ptr;    // new_node is a pointer to the first node
  return start;            // return statement
}
