#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>

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
    newNode->stackSize++;
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

int oneByOne()
{
    int stackSize = 0;
    struct node *stack;
    char userInput;
    int userNum;
    int answer;
    int twoNums[2];

    while(true)
    {
        printf("Enter a single digit or operator (q to exit)\n");
        scanf(" %c", &userInput);

        if(userInput == 'q')
        {
            answer = pop(&stack);
            printf("The final answer was %d", answer);
            return answer;
        }


        if((userInput - '0') < 10 && (userInput - '0') >=0)
        {
            userNum = (userInput - '0');
            stack = push(stack, userNum);
            printf("The value pushed is %d\n", stack->data);
            stackSize += 1;
        }

        else if(stackSize >= 2)
        {
            printf("In else if");
            switch(userInput)
            {
            case '+':
                twoNums[0] = pop(&stack);
                twoNums[1] = pop(&stack);
                answer = twoNums[1] + twoNums[0];
                printf("\n Answer is %d\n", answer);
                stack = push(stack, answer);
                stackSize -= 1;
                break;
            case '-':
                twoNums[0] = pop(&stack);
                twoNums[1] = pop(&stack);
                answer = twoNums[1] - twoNums[0];
                printf("\n Answer is %d\n", answer);
                stack = push(stack, answer);
                stackSize -= 1;
                break;
            case '/':
                twoNums[0] = pop(&stack);
                twoNums[1] = pop(&stack);
                answer = twoNums[1] / twoNums[0];
                printf("\n Answer is %d\n", answer);
                stack = push(stack, answer);
                stackSize -= 1;
                break;
            case '*':
                twoNums[0] = pop(&stack);
                twoNums[1] = pop(&stack);
                answer = twoNums[1] * twoNums[0];
                printf("\n Answer is %d\n", answer);
                stack = push(stack, answer);
                stackSize -= 1;
                break;
            }

        }
    }

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
    int answer = oneByOne();
    printf("The final answer is: %d", answer);
    return 0;
}
