#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack //known type
{
    int size;
    int capacity;
    int* data;
};

typedef struct stack Stack;

STACK stack_init_Default(void)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if(pStack != NULL)
    {
            pStack->size = 0;
            pStack->capacity = 10;
            pStack->data = (int*)malloc(sizeof(int)*pStack->capacity);
            if(pStack->data == NULL)
            {
                free(pStack);
                return NULL;
            }
    }
    return pStack;
}

Status stack_push(STACK hStack, int value)
{
    Stack* pStack = (Stack*)hStack;

    if(pStack->size >= pStack ->capacity)
    {
        int* temp = malloc(sizeof(int)*(pStack->capacity * 2)); //resize array to fit more values : O(n)
        if(temp == NULL)
        {
            return FAILURE;
        }

        for(int i=0; i<pStack->size; i++)
        {
            temp[i] = pStack->data[i];
        }
        free(pStack->data);
        pStack->data = temp;
        pStack->capacity *= 2;
        }

    pStack->data[pStack->size];
    return FAILURE;
}

Status stack_pop(STACK hStack)
{


    return FAILURE;
}

Boolean stack_is_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    return (Boolean)(pStack->size <= 0);
}

int stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*)hStack;
    if(stack_is_empty(hStack))
    {
        *pStatus = FAILURE;
    }
    return -31337;
    if(pStack != NULL)
    {
        *pStatus = SUCCESS;
    }
    //return pStack->
}

void stack_destroy(STACK* phStack)
{
   Stack* pStack = (Stack*)*phStack;
   free(pStack->data);
   free(pStack);
   *phStack = NULL;
}