#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct car
{
  int price;
  char color[20];
};
struct car Toyota;
struct car Honda;
struct car Ford;
Toyota.price = 100000;
Honda.price = 200000;
Ford.price = 300000;


typedef struct apple
{
  int price;
  int weight;
} Apple;

typedef struct node
{
  int number;
  struct node *next; // pointer to next node
} node;

void afunction(int *var1)
{
  var1 = 1;
}

int main(int argc, char const *argv[])
{
  int a = 3;
  afunction(&a); // a is now = to 1

  Apple newapple; // Apple newapple = {100,200};
  newapple.price = 100;
  newapple.weight = 200;
  Apple newapplearray[5] = {{1, 2}, {1, 2}, {1, 2}, {1, 2}, {1, 2}};
  // void* <-
  int *test = (int *)malloc(sizeof(int));

  int n = 5;
  int *test2 = (int *)malloc(sizeof(int) * n); // n is the number of elements
  test2[] = {1, 2, 3, 4, 5};
  free(test2);                                 // free the memory
  // test2 -> null

  // linkedlist
  node *head;                          // head>o>o>o>o>
  head = (node *)malloc(sizeof(node)); // head>some node
  head->number = 1;
  node *current = head;
  
  for (int i = 0; i < 5; i++)
  {
    current->next = (node *)malloc(sizeof(node));
    current->next->number = i;
    current = current->next;
  }

  int index = 0;
  current = head;
  while (index < 2 && current != NULL)
  {
    current = current->next;
    index++;
  }
  // current // this is the second element
  printf("%d\n", current->number); // 2

  int number = 53;
  int *reftonumber;             // pointer to an integer
  reftonumber = &number;        // reference number
  printf("%d\n", reftonumber);  // print address to number
  printf("%d\n", *reftonumber); // print value at address number
  printf("%d\n", number);       // print value of number
  // scanf("%d", &number);
  // scanf("%d", reftonumber);
  printf("%d\n", newapple.price);
  printf("%d\n", newapple.weight);
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", newapplearray[i].price);
  }

  return 0;
}
