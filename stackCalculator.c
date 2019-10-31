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
//top is passed in as a double pointer so that the stack is updated
//when pop is called and an int value can be returned from each pop
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

//function used to print values in stack for testing
void printStack(struct node *top)
{
    while(top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


int main()
{
    //test function are working
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    int poppedVal;
    printStack(top);
    poppedVal = pop(&top);
    printf("The value of popped val is %d\n", poppedVal);
    printStack(top);
    return 0;
}
