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

//function used to pop values from stack and return the popped value
int *pop(struct node **top)
{
    struct node *temp;
    temp = (*top);

    if((*top) == NULL)
    {
         printf("The stack is empty\n");
         return;
    }

    else
    {
        (*top) = (*top)->next;
        int data = temp->data;
        free(temp);
        return data;
    }

}


int main()
{
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    return 0;
}
