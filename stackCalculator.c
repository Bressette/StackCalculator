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



/*function used to select mathematical operator to compute on 2 numbers
 *Uses switch statement to choose operator based on char input passed into the function
 *A stack is passed in as a double pointer so that the stack is updated when the stack
 *is changed in the function
 */
struct node *selectOperation(struct node **stack, char userInput)
{
    //variable used to hold the 2 numbers popped off the stack
    int twoNums[2];
    //variable used to hold the computed value from the 2 numbers
    int answer;

     switch(userInput)
            {
            //case when the top 2 numbers on the stack are added
            case '+':
                twoNums[0] = pop(stack);
                twoNums[1] = pop(stack);
                answer = twoNums[1] + twoNums[0];
                printf("%d + %d is: %d\n", twoNums[1], twoNums[0], answer);
                (*stack) = push((*stack), answer);
                break;
            //case when the top 2 numbers on the stack are subtracted
            case '-':
                twoNums[0] = pop(stack);
                twoNums[1] = pop(stack);
                answer = twoNums[1] - twoNums[0];
                printf("%d - %d is: %d\n", twoNums[1], twoNums[0], answer);
                (*stack) = push((*stack), answer);
                break;
            //case when the top 2 numbers on the stack are divided; an exception handling check
            //is added for division by 0 where nothing will be computed
            case '/':
                twoNums[0] = pop(stack);
                twoNums[1] = pop(stack);
                if(twoNums[0] == 0)
                {
                    printf("You cannot divide by 0\n");
                    break;
                }
                answer = twoNums[1] / twoNums[0];
                printf("%d / %d is: %d\n", twoNums[1], twoNums[0], answer);
                (*stack) = push((*stack), answer);
                break;
            //case when the top 2 numbers on the stack are multiplied
            case '*':
                twoNums[0] = pop(stack);
                twoNums[1] = pop(stack);
                answer = twoNums[1] * twoNums[0];
                printf("%d * %d is: %d\n", twoNums[1], twoNums[0], answer);
                (*stack) = push((*stack), answer);
                break;
            }
}

//function that asks the user for 1 character at a time and computes
//math operations when at least 2 numbers are stored in the stack
//and one of the 4 basic math operators is entered by the user
int oneByOne()
{
    //variable used to store stackSize to determine if a value can be computed
    int stackSize = 0;
    //variable used to initialize the stack used for storing numbers
    struct node *stack;
    //variable that holds the character entered by the user
    char userInput;
    //variable used to hold a number to be pushed if the entered character was a number
    int userNum;
    //variable that holds the value popped off the stack at the end of the function and returns it
    int answer;

    //input loop that keeps asking the user for input until q is entered
    while(true)
    {
        printf("Enter a single digit or operator (q to exit)\n");
        scanf(" %c", &userInput);

        //when the user enters q the function stops and returns the top value on the stack
        if(userInput == 'q')
        {
            answer = pop(&stack);
            return answer;
        }

        //when the user enters a number the number is pushed onto the stack
        if((userInput - '0') < 10 && (userInput - '0') >=0)
        {
            userNum = (userInput - '0');
            stack = push(stack, userNum);
            stackSize += 1;
        }

        //when the stack has 2 numbers to be computed and the character entered is not a number
        //selectOperation is called to compute an operation if the character is a valid operator
        else if(stackSize >= 2)
        {
            selectOperation(&stack, userInput);
            stackSize--;
        }
    }

}


//function that takes in a string and computes math operations based on numbers
//and operators that are present in the string that is passed in
int arrayInput(char *inputArray)
{
    //variable used to return final top value on the stack
    int answer;
    //variable used to initialize a stack
    struct node *stack;
    //stackSize used to determine if a value can be computed
    int stackSize = 0;
    //variable used to temporarily hold converted value and push it to the stack
    int number;

    //loop that iterates through the string passed into the function
    for(int i = 0; inputArray[i] != NULL; i++)
    {
        //determines if the character is a number and pushes the number to the stack
        if((inputArray[i] - '0') < 10 && (inputArray[i] - '0') >= 0)
        {
            number = inputArray[i] - '0';
            stack = push(stack, number);
            stackSize++;
        }
        //computes a math operation if there are enough numbers in the stack and the value
        //passed into selectOperation is a valid math operator
        else if(stackSize >= 2)
        {
            selectOperation(&stack, inputArray[i]);
            stackSize--;
        }


    }

    //returns the top value on the stack to return the final computed value
    answer = pop(&stack);
    return answer;
}

int main()
{
    //calls oneByOne to allow user to enter values and prints the top value
    int answer = oneByOne();
    printf("The final answer is: %d\n", answer);

    //calls arrayInput to computes values from an inputArray that holds the string "12+3*5*3-2*2/" and prints the top value
    char inputArray[] = "12+3*5*3-2*2/";
    answer = arrayInput(inputArray);
    printf("The answer from the string is %d\n", answer);
    return 0;
}
