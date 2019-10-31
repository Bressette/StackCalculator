#include "stdlib.h"
#include "stdio.h"

//definition of linked list used to store stack
struct node
{
    int data;
    struct node *next;
    int stackSize;
};


//function that pushes value onto top of stack by creating a new node
//with the new value and this node points to the previous top node
struct node *push(struct node *top, int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

int main()
{
    struct node *top = NULL;


    return 0;
}
