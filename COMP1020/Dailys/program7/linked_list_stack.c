#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"
#include "string.h"

//translate stack to linked list stack
//two structs for stack and node
struct stack
{
    char* data;
    struct stack* next;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
    Stack* pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL)
    {
        pStack->data = NULL;
        pStack->next = NULL;
    }
    else if (pStack == NULL)
    {
        printf("pStack is NULL\n");
        free(pStack);
        return NULL;
    }
    return pStack;
}

Status stack_push(STACK hStack, char* value) //add value to the top of the stack
{
    Stack* pStack = (Stack*)hStack;
    Stack* pNew = (Stack*)malloc(sizeof(Stack));
    if (pNew != NULL)
    {
        pNew->data = value;
        pNew->next = pStack;
        pStack = pNew;
    }
    else if (pNew == NULL)
    {
        printf("pNew is NULL\n");
        free(pNew);
        return FAILURE;
    }
    return SUCCESS;
}


Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    if (hStack == NULL)
    {
        printf("hStack is NULL\n");
        return FAILURE;
    }
    if (pStack->data == NULL)
    {
        printf("pStack->data is NULL\n");
        return FAILURE;
    }
    else if (pStack->data != NULL)
    {
        pStack->data = (char*)realloc(pStack->data, sizeof(char) * (strlen(pStack->data) - 1));
        if (pStack->data == NULL)
        {
            //printf("pStack->data is NULL\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*)hStack;
    if (hStack == NULL)
    {
        printf("hStack is NULL\n");
        return FALSE;
    }
    if (pStack->data == NULL)
    {
        printf("pStack->data is NULL\n");
        return FALSE;
    }
    else if (pStatus != NULL)
    {
        *pStatus = SUCCESS;
    }
    return pStack->data[strlen(pStack->data) - 1];
}

Boolean stack_is_empty(STACK hStack) //check that the stack is empty
{
    Stack* pStack = (Stack*)hStack;  //Cast to the known type
	return (Boolean)(pStack->data <= 0);
}

Boolean stack_balanced(char* expression)
{
    Stack* pStack = (Stack*)stack_init_default();
    Boolean result = FALSE;
    char top; //top of the stack
    char index; //index of the string
    int size; //size of the string

    if (pStack == NULL)
    {
        printf("pStack is NULL\n");
        return FALSE;
    }
    scanf("%c" , &index); //get the first character of the string
    while(index == '(' || index == ')' || index == '[' || index == ']' || index == '{' || index == '}')
    {
        if(index == '(' || index == '[' || index == '{')
        {
            stack_push(pStack, &index); //push the character to the stack if its an open paren
        }
        if(!stack_is_empty(pStack))
        {
            top = stack_top(pStack, NULL); //get the top of the stack if the stack is not empty
        }
        else
        {
            result = FALSE;
        }
        if(index == ')')
        {
            if(top == '(')
            {
                stack_pop(pStack);
            }
            else
            {
                result = FALSE;
            }
        }
        else if(index == ']')
        {
            if(top == '[')
            {
                stack_pop(pStack);
            }
            else
            {
                result = FALSE;
            }
        }
        else if(index == '}')
        {
            if(top == '{')
            {
                stack_pop(pStack);
            }
            else
            {
                result = FALSE;
            }
        }
        scanf("%c" , &index);
    }
    if(stack_is_empty(pStack))
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    return result;
}

void clear_keyboard_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_stack(STACK hStack)
{
   Stack* pStack = (Stack*)hStack;
    if (hStack == NULL)
    {
         printf("hStack is NULL\n");
         return;
    }
    printf("%s\n", pStack->data);
}

void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*)*phStack;
	free(pStack->data);
	free(pStack);
	*phStack = NULL;
}