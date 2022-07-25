#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "status.h"

struct stack  //Known type
{
	int size;
	int capacity;
	char* data;
};

typedef struct stack Stack;

STACK stack_init_default(void)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->size = 0;
		pStack->capacity = 10;
		pStack->data = (char*)malloc(sizeof(char) * pStack->capacity);
		if (pStack->data == NULL)
		{
			free(pStack);
			return NULL;
		}
	}
	return pStack;
}

Status stack_push(STACK hStack, char* value)
{
	Stack* pStack = (Stack*)hStack;

	char* temp;
	int i;

	if (pStack->size >= pStack->capacity) //if there is not room then make room.
	{
		temp = malloc(sizeof(char*) * (pStack->capacity * 2));
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pStack->size; i++)
		{
			temp[i] = pStack->data[i];
		}
		free(pStack->data);
		pStack->data = temp;
		pStack->capacity *= 2;
	}

	pStack->data[pStack->size] = value;
	printf("Pushed %s to the stack\n", value);
	pStack->size++;

	return SUCCESS;
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;  //Cast to the known type
	if (stack_is_empty(hStack))
	{
		return FAILURE;
	}
	pStack->size--;

	return SUCCESS;
}

Boolean stack_is_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;  //Cast to the known type
	return (Boolean)(pStack->size <= 0);
}

char stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;  //Cast to the known type
	if (stack_is_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -31337;	
	}

	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return pStack->data[pStack->size - 1];
}

void clear_keyboard_buffer(void)
{
	char c;
	do {
		c = getchar();
	}	while(c != '\n' && c != EOF);
}

Boolean read_string(void)
{
	char string;
	char top;
	Boolean match_status = TRUE;
	STACK hStack = stack_init_default();
	//initilize the stack
	if (hStack == NULL)
	{
		printf("Failed to allocate space for stack object.\n");
		exit(1);
	}

	scanf("%c", &string);
	while(string == '(' || string == ')' || string == '[' || string == ']' || string == "{" || string == '}')
	{
		if(string == '(' || string == '[' || string == '{') //starts with opening character
		{
			stack_push(hStack, string);
		}
		top = stack_top(hStack, NULL);
		if(string == ')')
		{
			if(top == '(')
			{
				stack_pop(hStack);
			}
			match_status = FAILURE;
		}
		else if(string == ']')
		{
			if(top == '[')
			{
				stack_pop(hStack);
			}
			match_status = FAILURE;
		}

		else if(string == '}')
		{
			if(top == '{')
			{
				stack_pop(hStack);
			}
			match_status = FAILURE;
		}
		scanf("%c", &string);
	}
	if(!stack_is_empty(hStack) && string != '\n')
	{
		match_status = FAILURE;
	}
	stack_destroy(&hStack);
	return match_status;	
}

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;

	free(pStack->data);
	free(pStack);
	*phStack = NULL;
}
