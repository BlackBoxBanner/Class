#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _listnode
{
    void* data;                 /* data of this node */
    struct _listnode* next;     /* link to the next node */ 
} LISTNODE_T;

typedef struct
{
    LISTNODE_T* head;           /* first item in list */  
    LISTNODE_T* tail;           /* last item in list */ 
    LISTNODE_T* current;        /* current item in list */  
} LIST_T;

typedef struct
{
    LIST_T* data;
} STACK_T;

/* Create a new list with the specify capacity
 * Return pointer to the list structure if successful
 *        or NULL if the list can't be created
 *        e.g. memory allocation error
 */
LIST_T *listCreate(int capacity) {
  LIST_T *list = (LIST_T *)calloc(1, sizeof(LIST_T));
  if (list == NULL) {
    return NULL;
  }
  return list;
}

/* Remove an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listRemoveAt(LIST_T *list, int index) {
  LISTNODE_T *previousNode = list->head;
  LISTNODE_T *nodeToBeRemove;

  if (index == 0) {
    nodeToBeRemove = list->head;
    list->head = nodeToBeRemove->next;
    free(nodeToBeRemove->data);
    free(nodeToBeRemove);
  } else {
    int i = 0;
    while (i < index - 1) {
      previousNode = previousNode->next;
      i++;
    }

    nodeToBeRemove = previousNode->next;
    previousNode->next = nodeToBeRemove->next;
    if (nodeToBeRemove == list->tail) {
      list->tail = previousNode;
    }
    free(nodeToBeRemove->data);
    free(nodeToBeRemove);
  }
  return 1;
}

/* Returns the number of elements (could be zero)
 * or -1 if the list has not been created
 */
int listSize(LIST_T *list) {
  if (list == NULL) {
    return -1;
  } else {
    int i = 0;
    LISTNODE_T *thisNode = list->head;
    while (thisNode != NULL) {
      i++;
      thisNode = thisNode->next;
    }
    return i;
  }
}

/* Destroy the list and release all memory
 */
void listDestroy(LIST_T *list) {
  int i;
  // remove node
  for (i = 0; i < listSize(list); i++) {
    listRemoveAt(list, 1);
  }
  // remove head
  listRemoveAt(list, 0);
  free(list);
}


/* Insert new element into the list at the specify index
 * Return -1 if the list hasn't been created
 *        -2 if the list is full
 *         1 if the operation is successful
 */
int listInsertAt(LIST_T *list, int index, void *data) {
  if (list == NULL) {
    return -1;
  }

  LISTNODE_T *previousNode = list->head;
  LISTNODE_T *node = (LISTNODE_T *)calloc(1, sizeof(LISTNODE_T));
  if (node == NULL) {
    return -2;
  }
  node->data = data;
  if (index == 0) {
    list->head = node;
    list->tail = node;
  } else {
    int i = 0;
    while (i < index - 1) {
      previousNode = previousNode->next;
      i++;
    }

    node->next = previousNode->next;
    previousNode->next = node;
  }

  return 1;
}

/* Add new element at the end of the list
 * Return -1 if the list hasn't been created
 *        -2 if the memory allocation error
 *         1 if the operation is successful
 */
int listAppend(LIST_T *list, void *data) {
  if (list == NULL) {
    return -1;
  }

  LISTNODE_T *node = (LISTNODE_T *)calloc(1, sizeof(LISTNODE_T));
  if (node == NULL) {
    return -2;
  }
  node->data = data;

  if (list->head == NULL && list->tail == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  return 1;
}

/* Reset the current element return by listGetNext to
 * the first element of the list
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listReset(LIST_T *list) {
  if (list == NULL) {
    return -1;
  }

  list->current = list->head;
  return 1;
}

/* Get an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGet(LIST_T *list, int index, void **data) {
  if (list == NULL) {
    return -1;
  }

  listReset(list);
  int i = 0;
  while (i < index) {
    list->current = list->current->next;
    i++;
  }
  *data = list->current->data;
  return 1;
}


/* Get the current element
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGetNext(LIST_T *list, void **data) {
  if (list == NULL) {
    return -1;
  }
  // if (list -> current -> next == NULL){
  //     *data = list -> current -> data;
  //     return 1;
  // }
  *data = list->current->data;
  list->current = list->current->next;
  return 1;
}

/*
 * Return -1 if the list hasn't been created
 *         0 if there still some elements left to be returned from listGetNext
 *         1 if there isn't any element to be returned from listGetNext
 */
int listAtEnd(LIST_T *list) {
  if (list == NULL) {
    return -1;
  } else if (list->current != NULL) {
    return 0;
  } else {
    return 1;
  }
}

STACK_T* stackCreate(int capacity)
{
    // allocate the stack structure
    STACK_T* stack = (STACK_T*) calloc(1, sizeof(STACK_T));
    if (stack == NULL)
    {
        return NULL;
    }
    // allocate an array to store the data
    stack->data = listCreate(capacity);
    if (stack->data == NULL)
    {
        return NULL;
    }
    return stack;
}

void stackDestroy(STACK_T* stack)
{
    if (stack != NULL)
    {
        listDestroy(stack->data);
        free(stack);
    }
}

int stackPush(STACK_T* stack, void* data)
{
    if (stack == NULL)
    {
        return -1;
    }
    return listAppend(stack->data, data);
}

int stackPop(STACK_T* stack, void** data)
{
    if (stack == NULL)
    {
        return -1;
    }

    int retVal;
    int index = listSize(stack->data) - 1;
    void* tmp;

    retVal = listGet(stack->data, index, &tmp);
    if (retVal != 1)
    {
        return retVal;
    }

    retVal = listRemoveAt(stack->data, index);
    if (retVal != 1)
    {
        return retVal;
    }

    *data = tmp;
    return 1;
}

//Create the function for converting infix notation to postfix notation. The result of conversion must be stored in the postfix variable.


//infix to postfix function using stack
int infixToPostfix1(char* infix, char* postfix)
{
    STACK_T* stack = stackCreate(10);
    if (stack == NULL)
    {
        return -1;
    }

    int i = 0;
    int j = 0;
    char currentChar
}

int main(void) {
  char infix[100];
  char postfix[100];
  char prefix[100];
  //Apply the reverse and postfix conversion for converting infix notation to prefix notation. The result of conversion must be stored in the prefix variable.
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  infixToPrefix(infix, prefix);
  printf("Prefix notation: %s\n", prefix);
  return 0;
}

//A-(B/C+(D%E*F)/G)*H