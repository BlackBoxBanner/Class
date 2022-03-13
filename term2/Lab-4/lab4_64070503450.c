#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct node NODE;

struct node {
    char data;
    NODE *link;
};

void addNode(NODE **header, char input);

void createListed(NODE **header,char data[]){
    NODE *new_node,*ptr;
    int i=0;
    while(data[i]!='\0'){
        new_node=(NODE *)malloc(sizeof(NODE));
        new_node->data=data[i];
        if(*header==NULL){
            new_node->link=NULL;
            *header=new_node;
        }
        else{
            ptr=*header;
            while(ptr->link!=NULL){
                ptr=ptr->link;
            }
            new_node->link=NULL;
            ptr->link=new_node;
        }
        i++;
    }
}

void printList(NODE *header)
{
    NODE *ptr;
    ptr = header;
    while(ptr != NULL) {
        printf("%c", ptr->data);
        ptr = ptr->link;
    }
}

void push(NODE **header, char data)
{
    NODE *new_node;
    new_node = (NODE *)malloc(sizeof(NODE));
    new_node->data = data;
    if(*header == NULL){
        new_node->link = NULL;
        *header = new_node;
    }
    else{
        new_node->link = *header;
        *header = new_node;
    }
}

char pop(NODE **header)
{
    char tmp;
    NODE *ptr;
    if(*header == NULL) {
        return 0;
    } else {
        ptr = *header;
        tmp = ptr->data;
        *header = ptr->link;
        free(ptr);
        ptr = NULL;
        return tmp;
    }
}

int oPriority(char input)
{
    if(input == '*' || input == '/' || input == '%'){
        return 4;
    }
    else if(input=='+'||input=='-'){
        return 3;
    }
    else{
        return 2;
    }
}

void convPostfix(NODE **header, NODE *infix)
{
    char popValue, cn;
    NODE *ptr = NULL, *head1 = NULL, *head2 = NULL;
    ptr = infix;
    while(ptr != NULL) {
        cn = ptr->data;
        switch(cn) {
        case '(':
            push(&head1, cn);
            break;
        case ')':
            popValue = pop(&head1);
            while(popValue != '('){
                addNode(&head2, popValue);
                popValue = pop(&head1);
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            if(head1 == NULL){
                push(&head1, cn);
            }
            else{
                while(head1 != NULL && oPriority(head1->data) >= oPriority(cn)){
                    popValue = pop(&head1);
                    addNode(&head2, popValue);
                }
                push(&head1, cn);
            }
            break;
        default:
            addNode(&head2, cn);
            break;
        }
        ptr = ptr->link;
    }
    while(head1 != NULL){
        popValue = pop(&head1);
        addNode(&head2, popValue);
    }
    *header = head2;
}

void reverse(NODE **header)
{
    NODE *ptr, *preptr, *nextNode;
    preptr = NULL;
    nextNode = NULL;
    ptr = *header;
    while(ptr != NULL){
        nextNode = ptr->link;
        ptr->link = preptr;
        preptr = ptr;
        ptr = nextNode;
    }
    *header = preptr;
}

void addNode(NODE **header, char input)
{
    NODE *ptr, *node0;
    node0 = (NODE *)malloc(sizeof(NODE));
    node0->link = NULL;
    node0->data = input;
    ptr = *header;
    if(ptr == NULL){
        *header = node0;
    } else{
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = node0;
    }
}

void convPrefix(NODE **header, NODE *infix)
{
    NODE *ptr = *header, *ptr1 = infix, *ptr2;
    reverse(&ptr1);
    ptr2 = ptr1;
    while(ptr2 != NULL){
        if(ptr2->data == '('){
            ptr2->data = ')';
        } else if(ptr2->data == ')'){
            ptr2->data = '(';
        }
        ptr2 = ptr2->link;
    }
    convPostfix(&ptr, ptr1);
    reverse(&ptr);
    *header = ptr;
}

int main()
{
    char tmp[256], num[256];
    NODE *infix = NULL, *postfix = NULL, *prefix = NULL;
    fgets(tmp, sizeof(tmp), stdin);
    sscanf(tmp, "%s", num);
    createListed(&infix, num);
    convPostfix(&postfix, infix);
    printList(postfix);
    printf("\n");
    convPrefix(&prefix, infix);
    printList(prefix);
    return 0;
}